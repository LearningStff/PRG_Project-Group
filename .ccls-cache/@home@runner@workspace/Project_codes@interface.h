#pragma once

class Interface {
public:
	//Constructor
	Interface();

	//Destructor (virtual to ensure proper derived class destruction)
	virtual ~Interface();

	//Main function to run the interface
	virtual void run() = 0;

protected:
	//Common utility functions for input validation
	int getIntInput(int min, int max, const char* prompt);
	double getDoubleInput(double min, const char* prompt);
	void getStringInput(char* buffer, int size, const char* prompt);
	void displayErrorMessage(const char* message);
	void clearInputBuffer();
};
