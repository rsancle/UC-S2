#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//two integers initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBulllCowGame{
public: 
	//constructor
	FBulllCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	
	
	void Reset(); //TODO make a more rich return value
	
	//counts bulls and cows, and increasses turn a number assuming valid guess
	FBullCowCount SubmitGuess(FString);

private:
	//les inicialitzem al constuctor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};