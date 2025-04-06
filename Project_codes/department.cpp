#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "product.h"
#include "department.h"

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

    
  }



  
}
