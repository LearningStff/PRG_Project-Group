# PRG_Project-Group

Members:
Nathaniel Jacoben
Md. Mustafizur Rahman Fahim


Project Instructions
[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/zHkMrg7S)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=18621794)

## Project Title: Grocery Store Management System

### Introduction
In this project you are going to implement a basic Grocey Store Management System. The purpose of this software is to streamline the operations of a grocery store. This system involves two distinct interfaces: one for managers and one for customers, each interface is tailored to meet their specific needs. The customer interface allows users to browse departments, add items to their cart, and proceed to checkout. The manager interface, on the other hand, provides tools for adding departments and items, setting prices, and saving modifications to a CSV file.

The system involves object-oriented programming principles, including inheritance and polymorphism, to create a modular and maintainable codebase.

---

## Section 1: User Interfaces
In a real application, there are different links for login for employees and customers. However, for simplicity, you will show an initial menu that will allow user to choose the role.
### Initial Menu
- **Options:**
  - Customer \[1\]
  - Manager \[2\]
  - Exit \[3\]
- **Prompt:** `Enter your choice [1, 2, 3]:`
- **Validation:** Only accept valid inputs (1, 2, or 3). If invalid, print the same prompt again.
### Manager Interface
This interface handles the management part of the grocery store and presents the user with appropriate actions
#### Main Menu
- **Options:**
  - List Departments \[1\]
  - Add Department \[2\]
  - Add Item to Department \[3\]
  - Save Changes to CSV \[4\]
  - Exit \[5\]
- **Prompt:** `Enter your choice [1, 2, 3, 4, 5]:`
- **Validation:** Only accept valid inputs (1, 2, 3, 4 or 5). If invalid, print the same prompt again.

#### 1. List Departments
- **Displays:** Numbered list of all available department names.
- Show the Main Menu again
  
#### 2. Add Department
- **Prompt:** `Enter department name:`
- **Validation:** Ensure the department name is not empty. If invalid, print the same prompt again.
- **Action:** Adds the new department to the list of departments.
- **Message:** Prints "Department added successfully."
- **Return:** Returns to the main menu.

#### 3. Add Item to Department
- **Displays:** Numbered list of all available department names.
- **Prompt:** `Enter department number [0 to go back]:`
- **Validation:** Only accept valid department numbers. If invalid, print the same prompt again.
- **Displays:** Numbered list of all available items in the selected department.
- **Action:** Prompt for item details.
  - **Prompt:** `Enter item name:`
  - **Validation:** Ensure the item name is not empty. If invalid, print the same prompt again.
  - **Prompt:** `Enter item price:`
  - **Validation:** Only accept valid positive numbers for price. If invalid, print the same prompt again.
  - **Prompt:** `Enter item quantity:`
  - **Validation:** Only accept valid positive integers for quantity. If invalid, print the same prompt again.
  - **Action:** Adds the item to the selected department.
  - **Message:** Prints "Item added successfully."
  - **Return:** Returns to the main menu.

#### 4. Save Changes to CSV
- **Action:** Writes all modifications (departments and items) to the CSV file.
- **Message:** Prints "Changes saved successfully."
- **Return:** Returns to the main menu.

#### 5. Exit Program
- Exits the program.
  
### Customer Interface

#### Main Menu
- **Options:**
  - Show Cart \[1\]
  - Browse Departments \[1\]
  - Exit \[1\]
- **Prompt:** `Enter your choice [1, 2, 3]:`
- **Validation:** Only accept valid inputs (1, 2, or 3). If invalid, print the same prompt again.

#### 1. Show Cart Menu
- **Options:**
  - List Items \[1\]
  - Checkout \[2\]
  - Return to Main Menu \[3\]
- **Prompt:** `Enter your choice [1, 2, 3]:`
- **Validation:** Only accept valid inputs (1, 2, or 3). If invalid, print the same prompt again.
  - **1. List Items:** 
    - Prints all items in the cart with item number, name, quantity, and price.
    - Displays the same menu again.
  - **2. Checkout:** 
    - If the cart is not empty, prints "Thank you for your purchase," clears the shopping cart, and returns to the main menu.
    - If the cart is empty, prints "No items in the cart" and displays the same menu again.
  - **3. Return to Main Menu:** 
    - Returns to the main menu.

#### 2. Browse Departments
- **Displays:** Numbered list of all available department names.
- **Options:**
  - List Items of a Department \[1\]
  - Go Back to Main Menu \[2\]
- **Prompt:** `Enter your choice [1, 2]:`
- **Validation:** Only accept valid inputs (1 or 2). If invalid, print the same prompt again.
  - **1. List Items of a Department:** 
    - Prompts: `Enter department number [0 to go back]:`
    - **Validation:** Only accept valid department numbers. If invalid, print the same prompt again.
    - If the entered department number is correct, lists all numbered items in the department with price per unit item.
    - Displays the following menu:
      - Add to Cart an Item \[1\]
      - Go Back to Browse Departments Menu \[2\]
    - **Prompt:** `Enter your choice [1, 2]:`
    - **Validation:** Only accept valid inputs (1 or 2). If invalid, print the same prompt again.
      - **1. Add to Cart an Item:** 
        - Prompts: `Enter item number to buy [0 to go back]:`
        - **Validation:** Only accept valid item numbers. If invalid, print the same prompt again.
        - If the item number is correct, asks for quantity to buy.
        - **Validation:** Only accept positive integers for quantity. If invalid, print the same prompt again.
        - If the quantity is a positive integer, adds item quantity and price to the shopping cart, prints "Item added to cart," and goes back to the items menu.
      - **2. Go Back to Browse Departments Menu:** 
        - Returns to the Browse departments menu.
  - **2. Go Back to Main Menu:** 
    - Returns to the main menu.

#### 3. Exit Program
- Exits the program.

---

## Section 2: Implementation Requirements
Here are implementation requirements for this project:
### Classes
Your project must have the classes given below. **All data members of all the classes must be private**. I have listed only necessary data members, you can use more data members if you feel necessary.
1. **Class: `Product`**
   <br>Class that will save information of each item, it should have:
   - Necessary private data members
   - Constructor to initialize the data members
   - Necessary public functions
2. **Class: `Department`**
   <br>Class that will save all items of one department, it hould have:
   - Character array for deparment name
   - Dynamically allocated array of Product class items to save items in this deparment
   - Total number of items in the deparment
   - Constructor and other necessary public member functions.
   - Destructor to clear the items array
     
3. **Class: `Cart`**
   <br>This class will have items selected by customer for buying, it should have:
   - Dynamically allocated array of Product class, and a corresponding int array to save quantity of each item selected by the customer
   - Total count of items in the cart and total cost of the cart along with 13% tax.
   - Necessary functions
   - Destructor to clear the memory
4. **Interface Classes**
   <br>Since there are two types of user interfaces in this project (one for Manager and other for Customer) with some commonalities and some differences. You must implement interface classes through inheritance. You should have one base `Interface` class (with common function declarations) and two derived `ManagerInterface` and `CustomerInterface`. Input validation and error message methods can also go in the base class since they are common.

### main.cpp
This is the file that will have the main function. To make the implementation simpler you can declare following three global variables in this file and can access them in other cpp files using `extern` keyword
- Department * StoreDepartments = nullptr;
- int TotalDepartments = 0;
- const char * csvFile = "Your/Path/To/CSVFile.cs";

The main function should also:
- Read the csv file if it exists at start and should load data in the `StoreDepartments` array (see the format of this csv file outlined below)
- Have a pointer of `Interface` class and be initialized with the appropirate derived class object based on the selected role (Manager or Customer) (it will be the polymorphism here)

### Other Implementation Requirements
Here are additional implementation considrations:
- Manager can add items in an existing deparment in any order (for example first in first deparment, then in second department and then again in first deparment) make sure that you properly implement code to update the Products array in each department.
- All classes must be implemented in their corressponding .h and .cpp files
- You can store data in csv file in the following format:
  ```
  <Total Departmnets>
  <Department 1 Name>, <Total Items In Department 1>
  <Item 1 name>, <Price>, <Quantity>
  <Item 2 name>, <Price>, <Quantity>
  ...
  <Department 2 Name>, <Total Items In Department 2> 
  <Item 1 name>, <Price>, <Quantity>
  ...
  ```
 - If user enters a wrong input show a helpful error message
 - Thoroughly comment your code
 - You **Must** use only the concepts taught in the class (stl lists or vectors should **NOT** be used for Products and Departments)
 - LLM based code will be graded zero
## Submission Details
- This is a group project, a group consists of two students.
- The project must be done on GitHub CodeSpaces and regular commits should be made on GitHub. One of you should add your partner as collaborator.
- You must plan and work on this project every week. A bulk commit  in the last week raises suspicion!
- In week 13, I will conduct interviews. Each group will have 10 minutes to present their project, demonstrate its functionality, and answer questions about their code. Remember, a programmer can explain their code clearly and fluently!
## Rubric
- Maximum marks without inheritance: 70% 
- Maximum marks without polymorphism: 90%
- Maximum marks for implementing only one of two interfaces: 50%
- 100% marks depend on project interview
