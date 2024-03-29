#include "pch.h"
#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	//chars
	char words[10] = "classical";
	char lettersGuessed[20] = "";
	char wrongGuesses[24] = "";
	char inputUser;
	
	//array index
	int wrongCount = 0;

	//array index
	int rightCount = 0;

	//how many guesses
	int guessLimit = 7;

	//array index
	int counter = 0;

	//introduction
	cout << "Let's play hangman!" << endl;

	cout << "Your word has " << strlen(words)<< " letters in it\n" << endl;

	//game loop
	while (true)
	{

		cout << "What letter do you guess next? ";

		//input from user
		cin >> inputUser;

		//if already guessed keep asking for new letter
		while ((strchr(lettersGuessed, inputUser)))
		{
			cout << "Sorry "<< inputUser << " has already been used" << endl;
			cout << "Please enter a different letter: ";
			cin >> inputUser;
			cout << endl;
		}

		//if guess isn't in word, subtract a life
		if (!strchr(words, inputUser)) 
		{
			guessLimit--;
			wrongGuesses[wrongCount] = inputUser;
			wrongCount++;
		}
		else
			rightCount++;
	
		
		//letter guessed in
		lettersGuessed[counter] = inputUser;
		counter++;

		cout << "Guess: " << inputUser << endl;

		//display the hangman
		showGallows(guessLimit);

		
		//displays wrong guesses
		cout << "Wrong Guesses: ";
		for (int i = 0; i < wrongCount; i++) 
		{
			cout << wrongGuesses[i];
		}

		//show the solved words
		showSolved(words, lettersGuessed);
		
		//will break out of the loop
		if (guessLimit <= 0) {
			cout << "Sorry you Lost " << endl;
			cout << "The word was: " << words << endl;
			break;
		}
		if (rightCount >= 5) {
			cout << "You Win!!!" << endl;
			break;
		}
	}//end of while loop                                                                  

	return 0;
}//end of main

void showGallows(int guessLimit)
{
	//recieves guess limit as parameter
	//draw hangman

	cout << "_______" << endl;
	if (guessLimit < 7) {
		cout << "|   |" << endl;
	}
	else
		cout << "|" << endl;

	if (guessLimit < 6) {
		cout << "|   O" << endl;
	}
	else
		cout << "|" << endl;

	if (guessLimit < 5)
	{
		if (guessLimit < 4) {

			if (guessLimit < 3) {
				cout << "|  /|";
				cout << '\\' << endl;
			}
			else
				cout << "|  /|" << endl;
		}
		else
			cout << "|   |" << endl;
	}

	if (guessLimit < 2)
	{
		if (guessLimit < 1)
		{
			cout << "|  / \\" << endl;
		}
		else
			cout << "|  /" << endl;
	}

	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;

}//end of showGallows


void showSolved(char word[], char guesses[])
{
	//give some room
	cout << endl;

	//number of letters left
	int holder = strlen(word);

	cout << "Word to solve: ";
	for (int i = 0; i < strlen(word); i++)
	{
		if (strchr(guesses, word[i]) && word[i] != '\0')
		{
			cout << word[i];
			holder--;
		}
		else {
			cout << "_";
		}

	}//end of for loop

	cout << endl << endl; 
	cout << holder << " letters left to guess" << endl;

}//end of showSovled