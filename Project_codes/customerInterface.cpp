#define CRT_SECURE_NO_WARNINGS
#include "customerInterface.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
CustomerInterface::CustomerInterface() 
{

}

// Destructor
CustomerInterface::~CustomerInterface()
{
    
}

// Main function to run the customer interface - overrides the base class method
void CustomerInterface::run()
{
    displayMainMenu();
}


//Displays the main customer menu
void CustomerInterface::displayMainMenu()
{
    bool exitProgram = false; //flag

    //Loop until customer chooses to exit
    while (!exitProgram) {
        cout << "\n===== Customer Interface - Main Menu =====" << endl;
        cout << "1. Show Cart" << endl;
        cout << "2. Browse Departments" << endl;
        cout << "3. Exit" << endl;

        //Asks the customer for a choice and validate input
        int choice = getIntInput(1, 3, "Enter your choice [1, 2, 3]: ");

        //Based on the choice, the relevant function is called
        switch (choice) {
        case 1:
            showCartMenu();
            break;
        case 2:
            browseDepartments();
            break;
        case 3:
            exitProgram = true; //the flag is changed to true which ends the loop
            break;
        }
    }
}


//Displays the cart menu
void CustomerInterface::showCartMenu() {
    bool goBack = false; //flag

    while (!goBack) {
        cout << "\n===== Cart Menu =====" << endl;
        cout << "1. List Items" << endl;
        cout << "2. Checkout" << endl;
        cout << "3. Return to Main Menu" << endl;

        int choice = getIntInput(1, 3, "Enter your choice [1, 2, 3]: ");

        switch (choice) {
        case 1:
            listCartItems();
            break;
        case 2:
            checkout();
            break;
        case 3:
            goBack = true;
            break;
        }
    }
}


//This function displays all the items in the cart and calculates total including tax
void CustomerInterface::listCartItems()
{
    cout << "\n====== Cart Items =======" << endl;

    if (m_cart.isEmpty()) //if the cart is empty
    {
        cout << "Your cart is empty." << endl;
    }
    else //if the cart is not empty
    {
        m_cart.displayItems(); //it shows the list of items in the cart
        cout << "\nTotal Cost (with 13% tax): $" << m_cart.getTotalCost() << endl; //Calculates the total cost of items in the cart, including the tax, and displays the total
    }
}

//Function for handling the checkout process
void CustomerInterface::checkout()
{
    cout << "\n===== Checkout =====" << endl;

    if (m_cart.isEmpty()) {
        cout << "No items in the cart." << endl;
    }
    else {
        cout << "Thank you for your purchase!" << endl;
        m_cart.clear(); //clears the cart for next purchases
    }
}


//This function allows the customer to browse through different departments
void CustomerInterface::browseDepartments()
{
    bool goBack = false; //flag

    while (!goBack)
    {
        listDepartments(); //displays list of all available departments

        cout << "\n===== Browse Departments Menu =====" << endl;
        cout << "1. List Items of a Department" << endl;
        cout << "2. Go Back to Main Menu" << endl;

        //get the customer's choice
        int choice = getIntInput(1, 2, "Enter your choice [1, 2]: ");

        switch (choice) {
        case 1: {
            //Select the department
            int departmentNumber = getIntInput(0, TotalDepartments, "Enter department number [0 to go back]: ");

            //If the department choice is valid
            if (departmentNumber > 0) {
                //adjust indexing
                int departmentIndex = departmentNumber - 1;
                listItemsInDepartment(departmentIndex); //list the items in the department
            }
            break;
        }
        case 2:
            goBack = true;
            break;
        }
    }
}


//This function displays all available departments
void CustomerInterface::listDepartments() {
    cout << "\n===== Departments =====" << endl;

    if (TotalDepartments == 0) {
        cout << "No departments available." << endl;
    }
    else { //lists all departments with their index number
        for (int i = 0; i < TotalDepartments; i++) {
            cout << (i + 1) << ". " << StoreDepartments[i].displayDeptNames() << endl;
        }
    }
}


//Function to display all the items in a specific department, including details
void CustomerInterface::listItemsInDepartment(int departmentIndex) {
    cout << "\n===== Items in " << StoreDepartments[departmentIndex].displayDeptNames() << " =====" << endl; //display the name of the department that the customer has selected

    // Show items in the department
    Department& dept = StoreDepartments[departmentIndex]; //reference to the department object
    int itemCount = dept.getTotalProducts(); //get the total number of products in the department


    //If there are no items in the department
    if (itemCount == 0) {
        cout << "No items available in this department." << endl;
        return;
    }

    //iterate through the department and display products with their prices
    for (int i = 0; i < itemCount; i++) {
        Product product = dept.getProductAt(i); //make copies for each product
        cout << (i + 1) << ". " << product.getName() //display the name of the product with index
            << " - $" << product.getPrice() //display price of the item
            << " (Available: " << product.getQuantity() << ")" << endl; //shows how many units are available in stock 
    }

    // Display options menu
    bool goBack = false; //flag
    while (!goBack) {
        cout << "\n===== Item Options =====" << endl;
        cout << "1. Add to Cart an Item" << endl;
        cout << "2. Go Back to Browse Departments Menu" << endl;

        int choice = getIntInput(1, 2, "Enter your choice [1, 2]: ");

        switch (choice) {
        case 1: { //If the customer chooses to add to cart
            //Prompt the customer to select an item
            int itemNumber = getIntInput(0, itemCount, "Enter item number to buy [0 to go back]: ");

            //If the item number is valid
            if (itemNumber > 0) { 
                // Adjust indexing
                int itemIndex = itemNumber - 1;

                // Get available quantity of the selected product
                int availableQuantity = dept.getProductAt(itemIndex).getQuantity();

                // Get quantity to buy
                int quantity = getIntInput(1, availableQuantity, "Enter quantity to buy (max " + to_string(availableQuantity) + "): ");

                // Add item to cart
                addItemToCart(departmentIndex, itemIndex, quantity);
            }
            break;
        }
        case 2:
            goBack = true;
            break;
        }
    }
}



//This function handles the process of locating and adding items to cart, and inventory updates
void CustomerInterface::addItemToCart(int departmentIndex, int ItemIndex, int quantity)
{
    //create a reference to the department object at index departmentIndex
    /*the reference gives us direct access to the Department object at the specific index. This allows us to modify the department's state or calling its methods*/
    Department& dept = StoreDepartments[departmentIndex];

    //Get the product at the given index from the department object
    Product product = dept.getProductAt(itemIndex); /*this copy of the Product object is used to add the item in the cart and later to update the department's inventory*/

    //add item to cart
    if (m_cart.addItem(product, quantity)) //check if the item can be added to the cart based on quantity
    {
        cout << "Item added to cart." << endl;

        //Update the inventory quantity using the reference
        Product updatedProduct = product; //create a copy of the product
        updatedProduct.setQuantity(product.getQuantity() - quantity); //update the quantity to reflect the new stock after the sale
        dept.updateProductAt(ItemIndex, updatedProduct); //update the department's inventory
    }
}
