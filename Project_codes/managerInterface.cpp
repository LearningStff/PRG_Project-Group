#define CRT_SECURE_NO_WARNINGS
#include "managerInterface.h"
#include <iostream>
#include <cstring>
using namespace std;

// Global variables
extern Department* StoreDepartments; // Pointer to the array of departments
extern int TotalDepartments; //total number of departments
extern const char* csvFile; //the path of th CSV file

// Constructor
ManagerInterface::ManagerInterface()
{

}

//Destructor
ManagerInterface::~ManagerInterface()
{

}

//Main function to run the manager interface
void ManagerInterface::run()
{
	displayMainMenu();
}


// Main menu loop where the manager selects their choice
void ManagerInterface::displayMainMenu() {
    bool exitProgram = false; //flag

    while (!exitProgram) {
        //There are 5 options
        cout << "\n===== Manager Interface - Main Menu =====" << endl;
        cout << "1. List Departments" << endl;
        cout << "2. Add Department" << endl;
        cout << "3. Add Item to Department" << endl;
        cout << "4. Save Changes to CSV" << endl;
        cout << "5. Exit" << endl;

        //The choice is validated using getIntInput and stored in choice
        int choice = getIntInput(1, 5, "Enter your choice [1, 2, 3, 4, 5]: ");


        //based on the choice, the relevant function is called
        switch (choice) {
        case 1:
            listDepartments();
            break;
        case 2:
            addDepartment();
            break;
        case 3:
            addItemToDepartment();
            break;
        case 4:
            saveChangesToCSV();
            break;
        case 5:
            exitProgram = true;
            break;
        }
    }
}

//Displays all departments
void ManagerInterface::listDepartments()
{
    cout << "\n===== Departments =====" << endl;

    //If there are no departments
    if (TotalDepartments == 0) {
        cout << "No departments available." << endl;
    }
    else { //otherwise, it iterates through StoreDepartments array
        for (int i = 0; i < TotalDepartments; i++) {
            cout << (i + 1) << ". " << StoreDepartments[i].displayDeptNames() << endl; // and prints each department's name using displayDeptNames()
        }
    }
}



//Function to add a new department
void ManagerInterface::addDepartment() {
    cout << "\n===== Add Department =====" << endl;

    char departmentName[100]; // Assuming maximum department name length of 100

    //Prompt the user for a name, and then validate
    getStringInput(departmentName, 100, "Enter department name: ");

    /*Dynamically create a new array that can hold one more department than the current StoreDepartments array. This declares a pointer of type Department*, meaning it will point to an array of Department objects*/
    Department* newDepartments = new Department[TotalDepartments + 1];

    // Copy existing departments to the new array
    for (int i = 0; i < TotalDepartments; i++) {
        newDepartments[i] = StoreDepartments[i];
    }

    // Add the new department
    newDepartments[TotalDepartments].setDeptName(departmentName);

    // Delete old array and update the pointer
    if (StoreDepartments != nullptr) {
        delete[] StoreDepartments;
    }

    StoreDepartments = newDepartments;
    TotalDepartments++;

    cout << "Department added successfully." << endl;
}


//Function to add an item to a department
void ManagerInterface::addItemToDepartment() {
    cout << "\n===== Add Item to Department =====" << endl;

    //Check if there are departments
    if (TotalDepartments == 0) {
        cout << "No departments available. Please add a department first." << endl;
        return;
    }

    //List available departments
    listDepartments();

    //Select the department to add item to (0 to go back to main menu)
    int departmentNumber = getIntInput(0, TotalDepartments, "Enter department number [0 to go back]: ");

    //Go back if manager types 0
    if (departmentNumber == 0) {
        return;
    }

    // Adjust for 0-based indexing
    int departmentIndex = departmentNumber - 1;

    // Show existing items in the department
    cout << "\nCurrent items in department: " << endl;
    StoreDepartments[departmentIndex].listProducts();

    // Get item details
    char itemName[100]; // Assuming maximum item name length of 100
    getStringInput(itemName, 100, "Enter item name: ");

    double itemPrice = getDoubleInput(0.01, "Enter item price: ");
    int itemQuantity = getIntInput(1, INT_MAX, "Enter item quantity: ");

    // Create a new product and add it to the department
    Product newProduct(itemName, itemPrice, itemQuantity);
    StoreDepartments[departmentIndex].addProduct(newProduct);

    cout << "Item added successfully." << endl;
}



//Saves all changes made to the departments and their products
void ManagerInterface::saveChangesToCSV() {
    cout << "\n===== Save Changes to CSV =====" << endl;

    // Open file for writing
    FILE* file = fopen(csvFile, "w");

    //If the file couldn't be opened
    if (!file) {
        displayErrorMessage("Could not open file for writing.");
        return;
    }

    // Write the number of departments
    fprintf(file, "%d\n", TotalDepartments);

    // Write each department and its items
    for (int i = 0; i < TotalDepartments; i++) {
        Department& dept = StoreDepartments[i];

        // Write department info (name and item count)
        fprintf(file, "%s,%d\n", dept.displayDeptNames(), dept.getTotalProducts());

        // List all products and write to file
        for (int j = 0; j < dept.getTotalProducts(); j++) {
            Product product = dept.getProductAt(j);
            fprintf(file, "%s,%.2f,%d\n", product.getName(), product.getPrice(), product.getQuantity());
        }
    }

    fclose(file); // close the file
    cout << "Changes saved successfully." << endl;
}
