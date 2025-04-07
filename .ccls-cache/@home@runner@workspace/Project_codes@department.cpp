#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "product.h"
#include "department.h"

using namespace std;


  // Constructor
  Department::Department(){
    m_name[0] = '\0'; 
    m_products = nullptr;
    m_totalProducts = 0;
    m_capacity = 0;
  }
  //parameterized constructor

  Department::Department(const char* name, Product* products, int totalProducts){
    strcpy(m_name, name);
    m_products = new Product[totalProducts];
    for (int i = 0; i < totalProducts; i++){
      m_products[i] = products[i];
    }
    m_totalProducts = totalProducts;
    m_capacity = totalProducts;
  }

  // Destructord
  Department::~Department(){
    delete [] m_products;
    m_products = nullptr;
  }

  void Department::setDeptName(const char* name)
  {
    if (name != nullptr && name[0] != '\0'){
      strcpy(m_name, name);
    } else {
      m_name[0] = '\0';
    }
  }
  
  const char* Department::displayDeptNames() const{
    return m_name;
  }
  
  void Department::addProduct(const Product& product){
    if (m_totalProducts == m_capacity){
      Product* temp = new Product[m_totalProducts + 1];
      for (int i = 0; i < m_totalProducts; i++){
        temp[i] = m_products[i];
      } 
      temp[m_totalProducts] = product;
      m_totalProducts++;
      delete [] m_products;
      m_products = temp;
    }
  }
  
  void Department::listProducts() const {
    if (m_totalProducts == 0){
      cout << "No current products in the department." << endl;
    }
    for (int i = 0; i < m_totalProducts; i++){
      cout << m_products[i].getName() << "," << m_products[i].getPrice() << "per unit, " << m_products[i].getQuantity() << " units in stock." << endl;
    }
  }



