#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { reset(); }

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 8;
	myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant"; //constexpr is too strong here.
	myHiddenWord = HIDDEN_WORD;
	
	myCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EWordStatus FBullCowGame::checkGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guess isn't an isogram, 
	{
		return EWordStatus::Not_Isogram; //TODO write function
	}
	else if (!IsLowercase(Guess)) // if the guess isn't all lowercase 
	{
		return EWordStatus::Not_Lowercase; //TODO write function
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
		
	if (BullCowCount.Bulls == wordLenght) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString word) const
{
	//treat 0 and 1 letter words as isograms
	if (word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto letter : word) //for all letters of the word
	{
		letter = tolower(letter);

			// if the letter is in the map
		if (LetterSeen[letter]) {
			return false; // we do NOT have an isogram
		}
		else 
		{
			LetterSeen[letter] = true; // add a letter to the map
		}
				
	}
	
	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString word) const
{
	for (auto letter : word) {
		if (letter == '\0' || isspace(letter)) {
			return false;
		}
		else {
			return true;
		}
	}
	return true;
}
