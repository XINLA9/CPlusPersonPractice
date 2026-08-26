#include <iostream>
using namespace std;

class Product {
public:
    virtual void Use() = 0;
    virtual ~Product() = default;
};

class ConcreteProductA : public Product {
public:
    void Use() override {
        std::cout << "Using Product A" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void Use() override {
        std::cout << "Using Product B" << std::endl;
    }
};

class Factory {
public:
    static std::unique_ptr<Product> CreateProduct(const std::string& type) {
        if (type == "A") return std::make_unique<ConcreteProductA>();
        if (type == "B") return std::make_unique<ConcreteProductB>();
        return nullptr;
    }
};
