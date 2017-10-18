//
//  GameBoard.hpp
//

#pragma once

#include <stdexcept>

#include "ExtendableVector.h"

const int OUTSIDE_BOARD = -1;
const int BOARD_SIZE = 101;

class GameBoard {
public:   
   enum Ladders { ONE = 1, FOUR = 4, NINE = 9, TWENTY_ONE = 21, TWENTY_EIGHT = 28, THIRTY_SIX = 36, FIFTY_ONE = 51, SEVENTY_ONE = 71, EIGHTY = 80 };
   
   enum Chutes { SIXTEEN = 16, FORTY_SEVEN = 47, FORTY_NINE = 49, FIFTY_SIX = 56, SIXTY_TWO = 62, SIXTY_FOUR = 64, EIGHTY_SEVEN = 87, NINETY_THREE = 93, NINETY_FIVE = 95, NINETY_EIGHT = 98 };
   
   // Build the gameboard
   // TO DO: implement this function
   void buildBoard();
   
   GameBoard() {
      // TODO: implement this function properly
	   buildBoard();
    //throw std::logic_error("not implemented yet");
   }
   
   // If player lands on chutes or ladders, returns the new position.
   // Otherwise, returns the player's current position.
   // If the player's position is outside of the gameboard, throws index out of bounds exception
   // TO DO: implement this function properly
   int checkChutesLadders(int position) {
      if ((position < 0) || (position >= BOARD_SIZE)) {
         throw range_error("index out of bounds");
      }
	  switch (position) {
		  //ladders
	  case 1: return 38;
	  case 4: return 14;
	  case 9: return 31;
	  case 21: return 42;
	  case 28: return 84;
	  case 36: return 44;
	  case 51: return 67;
	  case 71: return 91;
	  case 80: return 100;
		  //chutes
	  case 16: return 6;
	  case 47: return 26;
	  case 49: return 11;
	  case 56: return 53;
	  case 62: return 19;
	  case 64: return 60;
	  case 87: return 24;
	  case 93: return 73;
	  case 95: return 75;
	  case 98: return 78;
	  }
	  return position;
	  }
            
      // TODO: implement this function properly
      //throw std::logic_error("not implemented yet");

   
private:
   // TO DO: add storage for squares including square of chutes and ladders
	ExtendableVector<int> Board[BOARD_SIZE];
   //int square = 0;
   // Requirement: use ExtendableVector to store the square
};
