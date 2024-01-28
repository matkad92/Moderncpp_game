#include <SFML/Graphics.hpp>

#include <string>

#include "constants.h"
#include "background.h"
#include "ball.h"
#include "paddle.h"
#include "interactions.h"
#include "brick.h"

using namespace std::literals;

int main() {

  background the_background(0.0f, 0.0f);

  ball theBall(constants::window_width / 2.0f, constants::window_height / 2.0f); //putting in the middle of the screen
  paddle thePaddle(constants::window_width / 2.0f, constants::window_height - constants::paddleHeight);

  std::vector<brick> bricks;

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
  
  sf::RenderWindow game_window{{constants::window_width, constants::window_height},
			       "Simple Breakout Game Version 1"s,};
  
  game_window.setFramerateLimit(30);    

  while (game_window.isOpen()) {
    game_window.clear(sf::Color::Black);

    sf::Event event;
   
    while (game_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        game_window.close();
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
      game_window.close();
    
    // Calculate the updated graphics
    the_background.update();
    theBall.update();
    thePaddle.update();

    for (auto& b : bricks)
      b.update();

    handleCollisions(theBall, thePaddle);
    
    // Display the updated graphics
    the_background.draw(game_window);
    theBall.draw(game_window);
    thePaddle.draw(game_window);

    for (auto b : bricks)
      b.draw(game_window);
    
    game_window.display();
  }
}
