/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all 
user interaction. For game logic see the FBullCowGame class.
	
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main() 
{

	do {
		PrintIntro();
		PlayGame();
		
	} while (AskToPlayAgain());
	
	return 0; //exit the app

}

void PrintIntro() {
	//introduce the game
	constexpr int32 WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n " << std::endl;
	return;
}

void PlayGame()
{
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();

	//loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 i = 0; i < maxTries; i++)
	{
		FText guess = GetGuess(); //TODO make loop checking valid 

		// submit valid guess to the game
		// print number of bulls and cows

		std::cout << "Guess: " << guess << std::endl;
		std::cout << std::endl;
	}
	//TODO add a game summary

}

FText GetGuess() {
	//get a guess from the player
	int32 currentTry = BCGame.getCurrentTry();
	std::cout << "Try " << currentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
