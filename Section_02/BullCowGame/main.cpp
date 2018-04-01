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
FText GetValidGuess();
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
	const int32 WORLD_LENGTH = BCGame.getHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n " << std::endl;
	return;
}

void PlayGame()
{
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();

	//loop asking for guesses while the game is NOT won
	// and there are still tries remaining

	while (!BCGame.isGameWon() && BCGame.getCurrentTry() <= maxTries)
	{ 	// TODO change from FOR to WHILE
		FText guess = GetValidGuess();

		// submit valid guess to the game and receive the counts
		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(guess);
		
		std::cout << "Bulls = " << bullCowCount.Bulls << " ";
		std::cout << "Cows = " << bullCowCount.Cows << "\n\n";

	}
	//TODO add a game summary
	std::cout << "Congrats you win! \n";

}

// loop continually until the user gives a valid guess
FText GetValidGuess() { 
	FText Guess = "";
	EWordStatus Status = EWordStatus::Invalid_Status;

	do {
		int32 currentTry = BCGame.getCurrentTry();
		std::cout << "Try " << currentTry << ". Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.checkGuessValidity(Guess);
		switch (Status)
		{
		case EWordStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word.\n";
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Please enter the word in lowercase.\n";
			break;

		default:
			//assume the guess is valid
			break;
		}
		std::cout << std::endl;
		
	} while (Status != EWordStatus::OK); //Keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
