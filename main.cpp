/* This is a console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#pragma once

/*importem la llibreria estandard iostream, que conté 
* els objectes basics com FText o std(standar)
*/
#include <iostream>

/*icluim aquesta llibreria perquè el operador >> no
* és inclos per defecte
*/
#include <string>

//Incluim la nostra llibreria
#include "FBullCowGame.h";

/*Utilitzem el namespace per evitar cridar al objecte
*std cada cop que volem usar una funció seva
*/
//using namespace std;

/*Deixem d'utilitzarlo perquè es poden sobre
escriure funcions i perjudicarnos en apps complexes
*/

//make sintax unreal friendly
using FText = std::string;
using int32 = int;

//function prototypes
void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();

void PrintBack(FText Guess);

FBulllCowGame BCGame; //instantiate a new game

//the main project
int main() 
{
	
	bool bPlayAgain = false;

	

	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	
	
	return 0;//exit app
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses
	//is NOT won and there are still tries remainig
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{

		FText Guess = GetValidGuess();
			

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		
		
		//PrintBack(Guess);
	}

	//summarise game
	PrintGameSummary();

	return;
}


void PrintIntro()
{
	//introduce the game

	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;

	return;
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do{
		int32 MaxTries = BCGame.GetMaxTries();
		int32 CurrentTry = BCGame.GetCurrentTry();
		//get a guess from the player
		std::cout << "Try " << CurrentTry << " of " << MaxTries << ". Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length: 
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength()<< " letter word. \n\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			return Guess;
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //Keep looping until we get valid input
	
	
	
}

void PrintBack(FText Guess)
{
	//repeat the guess back to them
	std::cout << "Your guess is: " << Guess << std::endl << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same word (y/n)?";
	FText Response = "";
	std::getline(std::cin, Response);

	// chars in single quotes, std::strings double quotes
	return (Response[0] == 'y' || Response[0] == 'Y');

}

void PrintGameSummary() 
{
	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE- YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time! \n";
	}

	return;
}
