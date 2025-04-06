#ifndef department_h
#define department_h
#include "product.h"

class Department{
  private:
    char m_name[50];
    Product *m_products;
    int m_totalProducts;


  public:
    Department();
    Department(const char* name, Product* products, int totalProducts);
    ~Department();

    // necessarry public functions
}


#endif
