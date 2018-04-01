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

enum class EWordStatus 
{
	Invalid_Status,
	OK, 
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	bool isGameWon() const;
	EWordStatus checkGuessValidity(FString) const;

	void reset(); //TODO make a more rich return value

	// provide a method for counting bulls & cows and increasing try # assuming valid guess
	FBullCowCount SubmitValidGuess(FString);

//Please try and ignore this and focus on the int32erface above
private:
	//see constructor for the initialisation
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
	
};