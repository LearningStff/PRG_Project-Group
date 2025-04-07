#pragma once

#include "interface.h"
#include "department.h"

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

