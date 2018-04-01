#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { reset(); }

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 8;
	myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet"; //constexpr is too strong here.
	myHiddenWord = HIDDEN_WORD;

	myCurrentTry = 1;
	return;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::checkGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	myCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
		//compare letters against the hidden word
			//if they match then
				//if they're in the same place
					//incriment bulls
				//else
					// incriment cows

	return BullCowCount;
}
