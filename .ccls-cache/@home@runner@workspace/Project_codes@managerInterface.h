#pragma once

#include "interface.h"
#include "department.h"

//external global variables I want to use in here
extern Department* StoreDepartments; //array of all departments
extern int TotalDepartments; //number of departments
extern const char* csvFile; //path to the CSV file

class ManagerInterface : public Interface { // inherts from Interface
public:
	//Constructor
	ManagerInterface();

	//Destructor
	~ManagerInterface();

	//Main function to run the manager interface
	void run() overrirde();

private:
	//Manager menu functions
	void displayMainMenu();
	void listDepartments();
	void addDepartment();
	void addItemToDepartment();
	void saveChangesToCSV();
};

