#ifndef GAME_H
#define GAME_H

#include "background.h"
#include "ball.h"
#include "brick.h"
#include "constants.h"
#include "paddle.h"

class game {

    sf::RenderWindow game_window{{constants::window_width, constants::window_height},
			       "Simple Breakout Game Version 1",};

    background the_background;

    ball theBall;
    paddle thePaddle;

    std::vector<brick> bricks;

    enum class gameState {
        paused,
        running,
    };

    gameState state;
    public:

    game();
    void reset();
    void run();

};







#endif // GAME_H