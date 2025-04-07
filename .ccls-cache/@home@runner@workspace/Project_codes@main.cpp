#include <iostream>
#include "managerInterface.h"
#include "customerInterface.h"
#include "fileHandling.h" 
using namespace std;

// Define the global variables
Department* StoreDepartments = nullptr; //array of departments
int TotalDepartments = 0; //total number of departments
const char* csvFile = "grocery.csv"; //Path to the CSV file

int main() {
    // Load data from the CSV file if it exists
    if (loadDataFromCsv(csvFile) != 0) {
        cerr << "Failed to load data from CSV." << endl;
        return 1;  // If loading the CSV fails, exit the program
    }

    // Role selection (Manager or Customer)
    int roleChoice = 0;
    while (roleChoice != 3) {
        cout << "Select your role:" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice [1, 2, 3]: ";
        cin >> roleChoice;

        if (roleChoice == 1) {
            // Initialize the Manager Interface
            ManagerInterface managerInterface;
            managerInterface.run();  // Run the manager interface
        }
        else if (roleChoice == 2) {
            // Initialize the Customer Interface
            CustomerInterface customerInterface;
            customerInterface.run();  // Run the customer interface
        }
        else if (roleChoice == 3) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    // Save any changes to the CSV file before exiting
    saveChangesToCSV();  // Ensure changes are saved to CSV

    return 0;
}
