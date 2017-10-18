//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// TODO: implement the constructor with all your team members
// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
   // TODO: implement this function properly
	playerQueue = new ArrayQueue<Player>(nPlayers);
	string names[2]{ "Player 1", "Player 2"};
	for (int i = 0; i < nPlayers; i++)
	{
		Player player;
		player.setName(names[i]);
		playerQueue->enqueue(player);
	}
   //throw std::logic_error("not implemented yet");
}

// TODO: implement the destructor
// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
   // TODO: implement this function properly
	int temp = playerQueue->size();
	for (int i = 0; i < temp; i++) {
		playerQueue->dequeue();
	}
	delete [] playerQueue;
	playerQueue = NULL;
  // throw std::logic_error("not implemented yet");
}

// TO DO: implement this function properly
// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
   // TODO: implement this function properly
	winner = "no winner";

	for (int i = 0; i < getNumberOfPlayers(); i++)
	{
		Player temp = playerQueue->front();
		temp.setPosition(0);
		playerQueue->dequeue();
		playerQueue->enqueue(temp);
	}
	for (int i = 0; i < getNumberOfPlayers() - 1; i++)
	{
		Player temp = playerQueue->front();
		playerQueue->dequeue();
		playerQueue->enqueue(temp);
	}
   //throw std::logic_error("not implemented yet");
}

// TO DO: implement this function properly
// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {
   // TODO: implement this function properly
	while (getWinner() == "no winner")
	{
		//ROLL
		Player temp = playerQueue->front();
		temp.setPosition(gameBoard.checkChutesLadders(temp.rollDieAndMove()));
	//	cout << "after check" << endl;
	//	cout << temp.getName() << endl;
	//	cout << temp.getPosition() << endl;

		if (playerQueue->front().getPosition() == 100)
		{
			winner = playerQueue->front().getName();
		}
		playerQueue->dequeue();
		playerQueue->enqueue(temp);
	}
	cout << "Winner is "<< getWinner()<<endl;
   //throw std::logic_error("not implemented yet");
   
}
//a
