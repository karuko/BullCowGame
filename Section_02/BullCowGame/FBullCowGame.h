#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// two values initialised to zero
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	bool isGameWon() const;

	void reset(); //TODO make a more rich return value
	bool checkGuessValidity(FString); //TODO make a more rich return value.

	// provide a method for counting bulls & cows and increasing try # assuming valid guess
	FBullCowCount SubmitGuess(FString);

//Please try and ignore this and focus on the int32erface above
private:
	//see constructor for the initialisation
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
};