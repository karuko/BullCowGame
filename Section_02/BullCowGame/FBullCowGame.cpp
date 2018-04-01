#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { reset(); }

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
int32 FBullCowGame::getBullCount() const { return bullCount; }

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 8;
	myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant"; //constexpr is too strong here.
	myHiddenWord = HIDDEN_WORD;
	
	myCurrentTry = 1;
	bullCount = 0;
	return;
}


bool FBullCowGame::isGameWon() const
{
	if (getBullCount() == myHiddenWord.length()) {
		return true;
	}
	else { return false; }
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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	myCurrentTry++;
	FBullCowCount BullCowCount;
	int32 wordLenght = getHiddenWordLength(); // assuming same length as guess
	
	// loop through all letters in the hidden word
	for (int32 i = 0; i < wordLenght; i++) {
		//compare letters against the guess
		for (int32 j = 0; j < wordLenght; j++) {
			//if they match then
			if (Guess[j] == myHiddenWord[i]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else { BullCowCount.Cows++; }
			}

		}
		
	}
		
	bullCount = BullCowCount.Bulls;
	return BullCowCount;
}
