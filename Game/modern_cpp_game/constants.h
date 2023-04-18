#ifndef CONSTANTS_H
#define CONSTANTS_H

// Code for a "breakout" game
// Based on a talk by Vittorio Romeo
// Uses the SFML graphics library

struct constants {
  static constexpr int window_width{520};
  static constexpr int window_height{450};
  static constexpr float ballSpeed{6.0f}; 
  static constexpr float paddleWidth{60.0f}; 
  static constexpr float paddleHeight{20.0f}; 
};

#endif // CONSTANTS_H
