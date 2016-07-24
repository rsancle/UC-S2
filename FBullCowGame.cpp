#include "FBullCowGame.h"



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
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "and";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBulllCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBulllCowGame::CheckGuessValidity(FString Guess) const
{
	
	//if the guess isn't an isofram, return an error
	//if the guess isn't all llowercase, return error
	//if the guess lengt is wrong return error
	//else return OK
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}else{
		return EGuessStatus::OK;
	}
}
//recives a valid guess, increments
FBullCowCount FBulllCowGame::SubmitGuess(FString Guess)
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


	return BullCowCount;
}
