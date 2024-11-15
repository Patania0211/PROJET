#pragma once
#define PADDLE_DEFAULT_VELOCITY .1f

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define PADDLE_DEFAULT_X (WINDOW_WIDTH/2)
#define PADDLE_DEFAULT_Y 500

#define PADDLE_WIDTH (WINDOW_WIDTH * 0.25f)  // 25% of screen width
#define PADDLE_HEIGHT (WINDOW_HEIGHT * 0.05f)  // 5% of screen height

#define BALL_DEFAULT_X 100
#define BALL_DEFAULT_Y 100

#define BALL_RADIUS (WINDOW_WIDTH * 0.02f)  // 2% of screen width
#define BALL_DEFAULT_VELOCITY_X (WINDOW_WIDTH * 0.4f)  // 40% of screen width per second
#define BALL_DEFAULT_VELOCITY_Y (WINDOW_HEIGHT * 0.4f)  // 40% of screen height per second

#define PADDING 0
#define DEFAULT_VELOCITY_CLAMP .1f

#define MAX_ENTITIES 700


//#define BRICKS_ROW 5
//#define BRICKS_COL 10
//
//#define BRICK_WIDTH 60
//#define BRICK_HEIGHT 20
//#define BRICK_PADDING 20
//
//#define BRICK_GRID_OFFSET 175
//
//#define BRICK_OFFSET_X 45
//#define BRICK_OFFSET_Y 40

#define BRICK_OFFSET_Y (WINDOW_HEIGHT * 0.01f)
// Brick settings
#define BRICK_WIDTH (WINDOW_WIDTH * 0.08f)  // 8% of screen width
#define BRICK_HEIGHT (WINDOW_HEIGHT * 0.03f)  // 3% of screen height
#define BRICK_OFFSET_X (WINDOW_WIDTH * 0.01f)  // 1% of screen width for spacing
#define BRICK_GRID_OFFSET (WINDOW_WIDTH * 0.05f)  // 5% of screen width for grid margin

// Calculate number of columns based on screen width and brick size
#define BRICKS_COL ((int)((WINDOW_WIDTH - 2 * BRICK_GRID_OFFSET + BRICK_OFFSET_X) / (BRICK_WIDTH + BRICK_OFFSET_X)))

#define BRICK_PADDING (WINDOW_HEIGHT * 0.05f)  // 5% of screen height padding between rows
#define BRICKS_ROW 5  // Fixed number of rows, can adjust based on screen size or make dynamic











