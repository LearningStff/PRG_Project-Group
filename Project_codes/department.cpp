#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "product.h"
#include "department.h"

using namespace std;

namespace seneca {
  // Constructor
  Department::Department(){
    char m_name[0] = '\0'; 
    m_products = nullptr;
    m_totalProducts = 0;
  }
  //parameterized constructor

  Department::Department(const char* name, Product* products, int totalProducts){
    strcpy(m_name, name);
    m_products = new Product[totalProducts];
    for (int i = 0; i < totalProducts; i++){
      m_products[i] = products[i];
    }
  }

  // Destructor
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
    return m_name
  }
  
  void Department::addProduct(const Product& product){
    if (m_totalproducts ==){
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
    for (int i = 0; i < m_totalProducts; i++){
      cout << m_products[i].name() << "," << m_products[i].getPrice() << "," << m_products[i].getQuantity() << endl;
    }
  }



  
}
