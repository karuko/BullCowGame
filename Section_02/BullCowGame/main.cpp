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
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();
void setWordtoGame();
FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main() 
{

	do {
		setWordtoGame();
		PrintIntro();
		PlayGame();
		
	} while (AskToPlayAgain());
	
	return 0; //exit the app

}

void setWordtoGame() {
	FText word;
	std::cout << "Set a word for play the game: ";
	getline(std::cin, word);
	BCGame.setHiddenWord(word);
	system("cls");
}

void PrintIntro() {
	//introduce the game
	const int32 WORLD_LENGTH = BCGame.getHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
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
	{ 
		FText guess = GetValidGuess();

		// submit valid guess to the game and receive the counts
		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(guess);
		
		std::cout << "Bulls = " << bullCowCount.Bulls << " ";
		std::cout << "Cows = " << bullCowCount.Cows << "\n\n";

	}

	PrintGameSummary();
	return;

}

void PrintGameSummary()
{
	if (BCGame.isGameWon())
	{
		std::cout << "DAMN IT you win \n";
	}
	else {
		std::cout << "YOU ARE A STUPID PLAYER. I WIN THIS TIME :D \n";
	}

}

// loop continually until the user gives a valid guess
FText GetValidGuess() { 
	FText Guess = "";
	EWordStatus Status = EWordStatus::Invalid_Status;

	do {
		int32 currentTry = BCGame.getCurrentTry();
		std::cout << "Try " << currentTry << " of " << BCGame.getMaxTries();
		std::cout << ". Enter your guess: ";

		
		std::getline(std::cin, Guess);

		Status = BCGame.checkGuessValidity(Guess);
		switch (Status)
		{
		case EWordStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word.\n\n";
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Please enter the word in lowercase.\n\n";
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
