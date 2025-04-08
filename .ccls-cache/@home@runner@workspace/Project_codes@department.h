#ifndef department_h
#define department_h
#include "product.h"

class Department{
  private:
    char m_name[50];
    Product *m_products;
    int m_capacity;
    int m_totalProducts;


  public:

    // rule of three constructor, destructor and copy constructor
    Department();
    Department(const char* name, Product* products, int totalProducts);
    ~Department();
    // copy constructor
    Department(const Department& other);

    // assignment operator
    Department& operator=(const Department& other);


    // necessarry public functions
    // For manager necessary functions
    // Prompt: Enter department name:
    void setDeptName(const char* name);

    //Displays: Numbered list of all available department names.
    const char *displayDeptNames() const;

    //  Add Item to Department
    void addProduct(const Product& product);

    // Displays: Numbered list of all available items in the selected department.
    void listProducts() const;

    // Action: Writes all modifications (departments and items) to the CSV file.
    int getTotalProducts() const; // Add this line to get the total number of products in the department

    //get a product at a specific index in the department array of products
    Product getProductAt(int index) const;

    //update a product at a specific index with a new product object 
    void updateProductAt(int index, const Product& product);

    // set department information for manager interface 
    void setDepartmentInfo(const char* name, Product* products, int totalProducts);
};


#endif
