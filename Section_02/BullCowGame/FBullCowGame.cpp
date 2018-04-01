#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { reset(); }

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }

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

EWordStatus FBullCowGame::checkGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't an isogram, 
	{
		return EWordStatus::Not_Isogram;
	}
	else if (false) // if the guess isn't all lowercase
	{
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != getHiddenWordLength()) // if the guess length is wrong
	{
		return EWordStatus::Wrong_Length;
	}
	else 
	{
		return EWordStatus::OK;
	}

}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	myCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 hiddenWordLenght = getHiddenWordLength();
	for (int32 i = 0; i < hiddenWordLenght; i++) {
		//compare letters against the hidden word
		for (int32 j = 0; j < hiddenWordLenght; j++) {
			//if they match then
			if (Guess[i] == myHiddenWord[j]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else { BullCowCount.Cows++; }
			}

		}
		
	}
		

	return BullCowCount;
}
