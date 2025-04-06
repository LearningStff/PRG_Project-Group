#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "product.h"

namespace seneca {
    // member functions' definitions go here
  Product::Product(){
    // constructor to initalizes member variables to safe empty state
    m_name[0] = '\0';
    m_price = 0.0;
    m_quantity = 0;
  }
  Product::Product(const char* name, double price, int quantity){
    // constructor to initalizes member variables to the values of the parameters
    strcpy(m_name, name);
    m_price = price;
    m_quantity = quantity;
  }


  // Getters functions
  void Product::name(const char* name){
    // sets the name of the product
    strcpy(m_name, name);
  }

  void Product::setPrice(double price){
    // sets the price of the product
    m_price = price;
  }

  void Product::setQuantity(int quantity){
    // sets the quantity of the product
    m_quantity = quantity;
  }

  // Setters functions
  const char* Product::name() {
    return m_name;
  }

  double Product::getPrice(){
    return m_price;
  }

  int Product::getQuantity(){
    return m_quantity;
  }

  // other member functions
  bool isAvailable() const{
    // returns true if the quantity is greater than zero, false otherwise
    if(m_quantity > 0) {
      return true
    } else
      return false;
    }
  }
};