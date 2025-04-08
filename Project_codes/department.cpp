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

  // Destructor
  Department::~Department(){
    delete [] m_products;
    m_products = nullptr;
  }

  // set department name
  void Department::setDeptName(const char* name)
  {
    if (name != nullptr && name[0] != '\0'){
      strcpy(m_name, name);
    } else {
      m_name[0] = '\0';
    }
  }

  // display department name
  const char* Department::displayDeptNames() const{
    return m_name;
  }

  // add product to department
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
      m_capacity = m_totalProducts;
      } else {
        m_products[m_totalProducts] = product;
        m_totalProducts++;
      }
  }
  

  // list all products in department
  void Department::listProducts() const {
    if (m_totalProducts == 0){
      cout << "No current products in the department." << endl;
      return;
    }
    for (int i = 0; i < m_totalProducts; i++){
      cout << m_products[i].getName() << ", $" << m_products[i].getPrice() << " per unit, " << m_products[i].getQuantity() << " units in stock." << endl;
    }
  }

  int Department::getTotalProducts() const {
    return m_totalProducts;
  }

  // get product at index
  Product Department::getProductAt(int index) const {
    if (index < 0 || index >= m_totalProducts){
      return Product();
    }
    return m_products[index];
  }


void Department::updateProductAt(int index, const Product& product){
    if (index >= 0 && index < m_totalProducts){
        m_products[index] = product;
    }
    else {
        cout << "Invalid index." << endl;
    }
}

void Department::setDepartmentInfo(const char* name, Product* products, int totalProducts){
    setDeptName(name);
    if (m_products != nullptr){
        delete [] m_products;
    }
  
    m_products = new Product[totalProducts];
    for (int i = 0; i < totalProducts; i++){
        m_products[i] = products[i];
    }

    m_totalProducts = totalProducts;
    m_capacity = totalProducts;
}

Department::Department(const Department& p){
    strcpy(m_name, p.m_name);
    m_totalProducts = p.m_totalProducts;
    m_capacity = p.m_capacity;

  m_products = new Product[m_totalProducts];
  for (int i = 0; i < m_totalProducts; i++){
    m_products[i] = p.m_products[i];
  }
}

Department& Department::operator=(const Department& other){
  if (this != &other) {
    strcpy(m_name, other.m_name);
    m_totalProducts = other.m_totalProducts;
    m_capacity = other.m_capacity;
    delete [] m_products;
    m_products = new Product[m_totalProducts];
    for (int i = 0; i < m_totalProducts; i++){
      m_products[i] = other.m_products[i];
    }
  } 
  return *this;
}