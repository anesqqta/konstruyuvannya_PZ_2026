#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//інтерфейси
class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() {}
};

class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

//конкретний суб'єкт
class Product : public Subject {
private:
    string name;
    bool inStock;
    vector<Observer*> observers;

public:
    Product(const string& name) : name(name), inStock(false) {}

    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }
    void removeObserver(Observer* observer) override {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }
    void notifyObservers() override {
        for (auto* obs : observers) {
            obs->update("Товар \"" + name + "\" тепер у наявності!");
        }
    }
    void setInStock(bool status) {
        if (!inStock && status) { //зміна з фолс на тру
            inStock = true;
            notifyObservers();
        } else {
            inStock = status;
        }
    }
};

//конкретний спостерігач
class Customer : public Observer {
private:
    string name;

public:
    Customer(const string& name) : name(name) {}

    void update(const string& message) override {
        cout << name << ", сповіщення: " << message << endl;
    }
};

int main() {
    system("chcp 65001 > nul");
    Product phone("Iphone 17");

    Customer c1("Владислав");
    Customer c2("Анастасія");
    Customer c3("Вікторія");

    //підписуємо двох клієнтів
    phone.registerObserver(&c1);
    phone.registerObserver(&c2);

    cout << "\tЗміна статусу: товар у наявності.\n";
    phone.setInStock(true);

    //відписуємо одного
    phone.removeObserver(&c1);

    cout << "\n\tТовар знову зник і з’явився.\n";
    phone.setInStock(false); //зник
    phone.setInStock(true);  //знову з’явився

    return 0;
}
