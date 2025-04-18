#ifndef product_h
#define product_h

class Product {
  private:
    char m_name[30];
    double m_price;
    int m_quantity;

  public:
    // Constructors
    Product();
    Product(const char* name, double price, int quantity);

    // Setters Functions
    void set(const char* name, double price, int quantity);
    void setName(const char* name);  
    void setPrice(double price);
    void setQuantity(int quantity);

    // Getters Functions
    const char* getName() const;
    double getPrice() const;
    int getQuantity() const;
      
    // other functions (maybe useful)
    void getTotalPrice();
    bool isAvailable();
};

#endif