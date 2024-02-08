#include <algorithm>

#include "game.h"
#include "interactions.h"

void EntityManager::refresh()
{
    //chceck if destroyed
    for (auto& [type, aliasVector] : groupedEntities)
    {

        aliasVector.erase(std::remove_if(  //remove pointers from vector, objects are not destroyed
                              std::begin(aliasVector),
                              std::end(aliasVector),
                              [](auto p){ return p->is_destroyed(); }
                              ),
                        std::end(aliasVector));

    }

    allEntities.erase(std::remove_if(//remove unique pointers from vector, owned objects are destroyed
                          std::begin(allEntities),
                          std::end(allEntities),
                          [](const auto& p){ return p->is_destroyed(); }
                          ),
                      std::end(allEntities));


}

void EntityManager::clear()
{
    groupedEntities.clear();
    allEntities.clear();
}

void EntityManager::update()
{
    for ( auto& e : allEntities)
        e->update();
}

void EntityManager::draw(sf::RenderWindow &window)
{
    for ( auto& e : allEntities)
        e->draw(window);
}

game::game()
{
    state = gameState::running;
    game_window.setFramerateLimit(30);

    veranda.loadFromFile("C:/Windows/Fonts/Veranda");

    textState.setFont(veranda);
    textState.setPosition(constants::window_width/2.0f - 100.0f, constants::window_height/2 - 100);
    textState.setCharacterSize(35);
    textState.setFillColor(sf::Color::White);
    textState.setString("Paused");

    textLives.setFont(veranda);
    textLives.setPosition(constants::window_width/2.0f - 65.0f, constants::window_height/2 - 50);
    textLives.setCharacterSize(35);
    textLives.setFillColor(sf::Color::White);
    textLives.setString("Lives: " + std::to_string(lives));


}

void game::reset()
{
    state = gameState::paused;
    lives = constants::playerLives;

    manager.clear();

    manager.create<background>(0.0f, 0.0f);
    manager.create<ball>(constants::window_width / 2.0f, constants::window_height / 2.0f);
    manager.create<paddle>(constants::window_width / 2.0f, constants::window_height - constants::paddleHeight);

    for (int i = 0; i < constants::brickCols; ++i)
    {

        for (int j = 0; j < constants:: brickRows; ++j) 
        {
            
            float x = constants::brickOffset + (i + 1) * constants::brickWidth;
            float y = (j + 1) * constants::brickHeight;

            manager.create<brick>(x,y);
        }
    }

    game_window.setFramerateLimit(30);
}

void game::run()
{
    bool pause_key_active{false};
    state = gameState::running;

    while (game_window.isOpen()) 
    {
        game_window.clear(sf::Color::Black);

        sf::Event event;
    
        while (game_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            game_window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        game_window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) 
        {
			if (!pause_key_active) {
				if (state == gameState::paused)
                    state = gameState::running;
				else
                    state = gameState::paused;
			}
			pause_key_active = true;
		}
		else
		    pause_key_active = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		    reset();

        if(state == gameState::paused)
        {
            manager.draw(game_window);
        }

        if (state != gameState::running) {
            switch (state) {
            case gameState::paused:
                textState.setString("   Paused   ");
                break;
            case gameState::gameOver:
                textState.setString("  Game Over!");
                break;
            case gameState::playerWins:
                textState.setString("Player Wins!");
                break;
            default:
                break;
            }

            game_window.draw(textState);
            game_window.draw(textLives);
        }

        else/*( state != gameState::paused)*/
        {
            if(manager.getAll<ball>().empty())
            {
                manager.create<ball>(constants::window_width / 2.0f, constants::window_height / 2.0f);
                --lives;

                state = gameState::paused;
            }

            if(manager.getAll<brick>().empty())
                state = gameState::playerWins;

            if(lives <= 0)
                state = gameState::gameOver;

            textLives.setString("Lives: " + std::to_string(lives));


            manager.update();

            manager.applyAll<ball>([this](auto& theBall)
                                   {
                                       manager.applyAll<brick>([&theBall] (auto& theBrick)
                                            {
                                                handleCollisions(theBall, theBrick);
                                            });

                                   });

            manager.applyAll<ball>([this](auto& theBall)
                                   {
                                        manager.applyAll<paddle>([&theBall] (auto& thePaddle)
                                        {
                                            handleCollisions(theBall, thePaddle);
                                    });

                                });

            manager.refresh();
            manager.draw(game_window);
        }


        game_window.display();
    }


}


