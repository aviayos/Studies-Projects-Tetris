# Tetris

This project was part of my studies in college. The code written in C++. 

## Description:

This program is reproduction of the old game Tetris. in this game the player need to fill many lines as he can and by that grow
his score, while shapes from above the grid falls down. Each level the speed of the shapes that falls, grow up and the difficult
go up. In the game there are 7 characters: stick, square, zaw, saw, alpha, gamma and pyramid.

## Classes:

*class "Controller": this is the main class which runs the tetris program, it holds a queue of two shapes(the current and the next).
		and Board object. gets the users input and applies the relevant command for his objects.

*class "Board ": this is the grid of the game. it responsible to fill the board after shapes collide. 
	         hold the vector of vector of recangle shape.

*class "Shapes": this class is abstract base class of all the shpaes. it responsible to move each shape and check the collision with 
	          the Board.
*class "StatusBar": this class the player status during the game, shoe the player level, points and the next shape.

*class "Singleton": this class is static class, responsible for the game themes: sounds and screen.

*class Saw, Zaw, Stick, Square, Pyramid, Alpha, Gamma: these classes represent the shpae chracters. 

## List of file created:

directory "themes":
Pokemon.png, gameOver.png - screens of the game
pokemon.ogg - sound track of the game
directory "fonts":
game_font.ttf 

## Main data structures:

vector of vector of unique_ptr<RectangleShape> - member in the board hold the "landed" shapes
queue of unique_ptr<Shape>- member in the Controller, hold the current shape and the next shape
vector of RectangleShape - member in Shapes class, hold the rectangles of each shape consist .
 

