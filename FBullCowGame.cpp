#include "FBullCowGame.h"
#include <map>
#define TMap std::map



FBulllCowGame::FBulllCowGame()
{
	Reset();

}

int32 FBulllCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBulllCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBulllCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void FBulllCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBulllCowGame::IsGameWon() const
{
	return BGameIsWon;
}

EGuessStatus FBulllCowGame::CheckGuessValidity(FString Guess) const
{
	
	//if the guess isn't an isofram, return an error
	//if the guess isn't all llowercase, return error
	//if the guess lengt is wrong return error
	//else return OK
	if (!IsIsogram(Guess)) //If guess isn't a isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}
//recives a valid guess, increments
FBullCowCount FBulllCowGame::SubmitValidGuess(FString Guess)
{
	//increments the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;
	//loop  through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				//if they're in the same place
				if (GChar == MHWChar) {
					//increment bulls
					BullCowCount.Bulls++;
				}else {
					//increment cows if not
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == HiddenWordLength) {
		BGameIsWon = true;
	}
	else 
	{
		BGameIsWon = false;
	}

	return BullCowCount;
}

bool FBulllCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }
	
	//setup our map
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) //for all letters of the word
	{ 
		Letter = tolower(Letter);
			//if the letter is in the map
		if (LetterSeen[Letter]) {
			return false; // we do NOT have an isogram
		} else {
			// add the letter to the map as seen
			LetterSeen[Letter] = true;
		}
		
	}
	return true;
}

bool FBulllCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))//if not a lower case letter
		{
			return false;
		}
	}
	return true;
}
