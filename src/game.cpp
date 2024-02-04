#include "game.h"
#include "interactions.h"

game::game()
    : the_background(0.0f, 0.0f),  
      theBall(constants::window_width / 2.0f, constants::window_height / 2.0f),  
      thePaddle(constants::window_width / 2.0f, constants::window_height - constants::paddleHeight) 
{
    for (int i = 0; i < constants::brickCols; ++i) 
    {

        for (int j = 0; j < constants:: brickRows; ++j) 
        {
            
            float x = constants::brickOffset + (i + 1) * constants::brickWidth;
            float y = (j + 1) * constants::brickHeight;

            // Create the brick object cpp11 without copying
            bricks.emplace_back(x, y);
        }
    }

    state = gameState::running;
    game_window.setFramerateLimit(30);  
}

void game::reset()
{
    for (int i = 0; i < constants::brickCols; ++i) 
    {

        for (int j = 0; j < constants:: brickRows; ++j) 
        {
            
            float x = constants::brickOffset + (i + 1) * constants::brickWidth;
            float y = (j + 1) * constants::brickHeight;

            // Create the brick object cpp11 without copying
            bricks.emplace_back(x, y);
        }
    }
}

void game::run()
{
    bool pause_key_active{false};

    while (game_window.isOpen()) 
    {
        game_window.clear(sf::Color::Black);

        sf::Event event;
    
        while (game_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            game_window.close();
        }
        
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        // game_window.close();

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

        if( state != gameState::paused)
        {
            // Calculate the updated graphics
            the_background.update();
            theBall.update();
            thePaddle.update();

            for (auto& b : bricks)
            {
                b.update();
            }

            handleCollisions(theBall, thePaddle);

            for(auto & b : bricks)
            {
                handleCollisions(theBall, b);
            }

            bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
                    [](const brick& b){ return b.is_destroyed(); }),
                    std::end(bricks));
        }
        
        // Display the updated graphics
        the_background.draw(game_window);
        theBall.draw(game_window);
        thePaddle.draw(game_window);

        for (auto b : bricks)
            b.draw(game_window);
        
        game_window.display();
  }


}
