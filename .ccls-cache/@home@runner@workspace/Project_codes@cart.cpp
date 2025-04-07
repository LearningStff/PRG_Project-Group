#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "cart.h"
using namespace std;

Cart::Cart(){
  m_products = nullptr;
  m_quantities = nullptr;
  m_totalItems = 0;
  m_totalPrice = 0.0;
}

Cart::~Cart(){
  delete [] m_products;
  delete [] m_quantities;
  m_products = nullptr;
  m_quantities = nullptr;
}

bool Cart::addItem(const Product& product, int quantity){
  // add a product to the cart
  if (quantity > 0){
    m_products[m_totalItems] = product;
    m_quantities[m_totalItems] = quantity;
    m_totalItems++;
    return true;
  } else {
    cout << "Invalid quantity." << endl;
    return false;
  }
}


void Cart::listItemsInCart() const {
    // list all items in the cart
    // display the name, price, quantity, and total price of each item
    for (int i = 0; i < m_totalItems; i++){
      cout << m_products[i].getName() << "," << m_quantities[i] << " units, $"
           << m_products[i].getPrice() << " per unit" << endl; 
    }
}

// checkout function'
bool Cart::checkout() {
  if (m_totalItems == 0) {
    return false;  // return false if the cart is empty 
  } else {
    return true;
  }
   clearCart();
}

// clear cart function
void Cart::clearCart() {
  m_totalItems = 0;
  m_totalPrice = 0.0;
}

// other functions (maybe useful)
double Cart::calculateTotalPrice() const {
    // calculate the total price of all items in the cart
  double subtotal = 0.0;
  for (int i = 0; i < m_totalItems; i++){
     double totalItems = m_products[i].getPrice() * m_quantities[i]; 
     subtotal = subtotal + totalItems;
  }
  return subtotal * 1.13;
}

int Cart::getTotalItems() const {
  // return the total number of items in the cart
  return m_totalItems;
}

bool Cart::isEmpty() const{
  // return true if the cart is empty, false otherwise
  if (m_totalItems == 0) {
    return true;
  }
  return false;
}
