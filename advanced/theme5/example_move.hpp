#include <iostream>
using namespace std;

class MyClass {
private:
  int* data;

public:
  MyClass() : data(new int(0)) {}
  MyClass(int d) : data(new int(d)) {}
  MyClass(MyClass&& other) : data(other.data) {
    other.data = nullptr;
    cout << "move constructor\n";
  }
  ~MyClass() {
    delete data;
    cout << "destructor\n";
  }

  void details() {cout << data << endl;}
};


void example_move() {
  MyClass obj1(7);
  obj1.details();
  MyClass obj2 = std::move(obj1);
  obj1.details();
  obj2.details();
}
