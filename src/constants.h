#ifndef CONSTANTS_H
#define CONSTANTS_H

struct constants {
  static constexpr int window_width{520};
  static constexpr int window_height{450};
  static constexpr float ballSpeed{6.0f}; 
  static constexpr float paddleSpeed{8.0f}; 
  static constexpr float paddleWidth{60.0f}; 
  static constexpr float paddleHeight{20.0f};

  static constexpr float brickWidth{43.0f}; 
  static constexpr float brickHeight{20.0f}; 
  static constexpr float brickOffset{brickWidth/2}; 
  static constexpr int brickCols{10}; 
  static constexpr int brickRows{4}; 
};

#endif // CONSTANTS_H
