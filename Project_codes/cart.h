#ifndef cart_h
#define cart_h
#include "product.h"

class Cart{
  private:
    Product *m_products;
    int *m_quantities;
    int m_totalItems;
    double m_totalPrice;

  public:
    Cart();
    Cart(Product* products, int* quantities, int totalItems, double totalPrice);
    ~Cart();

    // necessary public functions
  
}

#endif