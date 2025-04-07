#include "interface.h"
#include <iostream>
#include <cstring>
using namespace std;

//Constructor
Interface::Interface()
{

}

//Destructor
Interface::~Interface()
{

}

//Get integer input within a range
int Interface::getIntInput(int min, int max, const char* prompt) 
{
	int input; // stores the user's input
	bool valid = false; //flag to control loop


	//Start the input loop
	do {
		cout << prompt; // Show prompt to user
		cin >> input; // Take user input

		// If input is not an int
		if (cin.fail()) { //cin enters a fail state as input is not int, cin.fail() returns true
			cin.clear();  //resets cin back a normal working state
			
			char buffer[100];
			cin.getline(buffer, 100); //reads and discards the rest of the user's input
			displayErrorMessage("Invalid input. Please enter a number.");
		}
		else if (input < min || input > max) // If the input is out of range
		{
			displayErrorMessage("Input out of range. Please try again.");
		}
		else 
		{
			valid = true;
		}
	} while (!valid);

	clearInputBuffer(); // clears any leftover newline character after the valid input
	return input;
}


//Get double input with minimum value
double Interface::getDoubleInput(double min, const char* prompt)
{
	//LOOK AT getIntInput FOR EXPLANATIONS
	double input;
	bool valid = false;

	do {
		cout << prompt;
		cin >> input;


		//if input is not a double
		if (cin.fail())
		{
			cin.clear();
			char buffer[100];
			cin.getline(buffer, 100);
			displayErrorMessage("Invalid input. Please enter a number.");
		}
		else if (input < min)
		{
			displayErrorMessage("Input must be positive. Please try again.");
		}
		else
		{
			valid = true; //the flag is now true so loop can end
		}
	} while (!valid);

	clearInputBuffer();
	return input;
}

//Get string input
void Interface::getStringInput(char* buffer, int size, const char* prompt)
{
	bool valid = false;

	do {
		cout << prompt;
		cin.getline(buffer, size);

		//When user types too many characters
		if (cin.fail())
		{
			cin.clear();
			char tempBuffer[100];
			cin.getline(tempBuffer, 100);
			displayErrorMessage("Invalid input. Please try again.");
		}
		else if (strlen(buffer) == 0) //if the string is left empty
		{
			displayErrorMessage("Input cannot be empty. Please try again.");
		}
		else
		{
			valid = true;
		}
	} while (!valid);
}


// Display error message
void Interface::displayErrorMessage(const char* message)
{
	cout << "Error: " << message << endl; // Displays the error message
}

//Clear input buffer
void Interface::clearInputBuffer()
{
	char c; // store one character at a time

	//reads one character at a time from the input buffer until it finds \n OR end of file
	while ((c = cin.get()) != '\n' && c != EOF);
}
