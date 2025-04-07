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
    Department();
    Department(const char* name, Product* products, int totalProducts);
    ~Department();


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

    

    

    

    
  
}


#endif
