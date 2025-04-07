#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "product.h"

using namespace std;

    // member functions' definitions go here
  Product::Product(){
    // constructor to initalizes member variables to safe empty state
    m_name[0] = '\0';
    m_price = 0.0;
    m_quantity = 0;
  }

  Product::Product(const char* name, double price, int quantity){
    // constructor to initalizes member variables to the values of the parameters
    if (name != nullptr && name[0] != '\0') {
      strcpy(m_name, name);
    } else {
      m_name[0] = '\0';
    }
    if (price > 0) {
      m_price = price;
    } else {
      m_price = 0.0;
    }
    if (quantity > 0){
      m_quantity = quantity;
    } else {
      quantity = 0;
    }
  }


  // Getters functions
  void Product::setName(const char* name){
    // sets the name of the product
    if (name != nullptr && name[0] != '\0'){
      strcpy(m_name, name);
    } else {
      m_name[0] = '\0';
    }
  }

  void Product::setPrice(double price){
    // sets the price of the product
    if (price < 0) {
      price = 0.0;
    }
    m_price = price;
  }

  void Product::setQuantity(int quantity){
    // sets the quantity of the product
    if (quantity < 0){
      quantity = 0;
    }
    m_quantity = quantity;
  }

  // Setters functions
  const char* Product::getName() const {
    return m_name;
  }

  double Product::getPrice() const {
    return m_price;
  }

  int Product::getQuantity() const {
    return m_quantity;
  }

  void Product::set(const char* name, double price, int quantity){
    setName(name);
    setPrice(price);
    setQuantity(quantity);
 }
