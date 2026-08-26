
#include <iostream>
using namespace std;

class Singleton {
private:
    Singleton() {}  
    static Singleton* instance;

public:
    static Singleton* GetInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    void DoSomething() {
        std::cout << "Singleton doing something." << std::endl;
    }
};


Singleton* Singleton::instance = nullptr;
