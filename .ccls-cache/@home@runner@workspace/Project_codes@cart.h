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
    ~Cart();

    // necessary public functions
    // Add to cart function

    void addProductToCart(const Product& product, int quantity);

    // list items in cart function
    void listItemsInCart() const;

    // checkout function'
    bool checkout();

    // clear cart function
    void clearCart();

    // other functions (maybe useful)
    double calculateTotalPrice() const;
    int getTotalItems() const;
}

#endif