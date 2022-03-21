# CPPND: Capstone Project

### Like [Checkers](https://en.wikipedia.org/wiki/Checkers)

This is a checkers game that allows two players to play against one another or one play against a not so strong AI. 

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./HelloWorld`.

## Rules of the game

Players take turn playing one by one. These are the rules that govern how to play this game
* Pieces can only move diagonally forward, no backward movement is allowed
* Pieces are only allowed to move one step at a time except when the piece is about to capture another piece
* You can capture an opponent's piece, if
  * The piece is one move away from you
  * You can "jump" over the piece and land at an empty square just by the captured piece.

You can read [here](https://www.ultraboardgames.com/checkers/game-rules.php) to get more details about checkers.

All rules listed in the url are implemented, except there is no King and you cannot capture backwards.

## How to play?

Each square in the board is given a coordinate which is a combination of the row number and column number.
A move consists of the position of the piece you want to move and the destination of the piece. For example 2,5 3,4 moves a piece at (2,5) to (3,4)
You can only move a piece to a position that is EMPTY
