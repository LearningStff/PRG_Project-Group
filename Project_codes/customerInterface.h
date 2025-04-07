#pragma once
#include "interface.h"
#include "cart.h"
#include "department.h"

class CustomerInterface : public Interface {
public:
	//Constructor
	CustomerInterface();

	//Destructor
	~CustomerInterface();

	//Main function to run the customer interface
	void run() override; //polymorphism ensures that run() will be handled by the CustomerInterface version of run()

private:
	//Shopping cart for the customer
	Cart m_cart;

	//Customer menu functions
	void displayMainMenu();

	//Cart menu functions
	void showCartMenu(); //displays cart options like view cart, checkout
	void listCartItems(); //lists items in the cart
	void checkout(); //handles the checkout process

	// Department browsing functions
	void browseDepartments();
	void listDepartments();
	void listItemsInDepartment(int departmentIndex); //After selecting a department, this function shows the items in that department
	void addItemToCart(int departmentIndex, int itemIndex, int quantity);
};
