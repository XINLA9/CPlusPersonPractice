#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void OnNotify(int data) = 0;
    virtual ~Observer() = default;
};

class Subject {
private:
    std::vector<std::weak_ptr<Observer>> observers;

public:
    void Attach(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }

    void Notify(int data) {
        for (auto it = observers.begin(); it != observers.end();) {
            if (auto obs = it->lock()) {
                obs->OnNotify(data);
                ++it;
            }
            else {
                it = observers.erase(it); // 清除已释放的观察者
            }
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void OnNotify(int data) override {
        std::cout << "Observer received: " << data << std::endl;
    }
};
