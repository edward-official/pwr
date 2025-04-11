#include <iostream>
using namespace std;

class MyClass {
private:
  int* data;

public:
  MyClass() : data(new int(-1)) {}
  MyClass(int d) : data(new int(d)) {}
  MyClass(MyClass&& other) : data(other.data) {
    if(other.data==nullptr) {
      cout << "target instance is no longer available\n";
      cout << "closing the move contructor...\n";
      return;
    }
    other.data = nullptr;
    cout << "move constructor\n";
  }
  ~MyClass() {
    delete data;
    cout << "destructor\n";
  }

  MyClass& operator=(MyClass&& other) {
    if(other.data==nullptr) {
      cout << "target instance is no longer available, closing the move operation...\n";
      return *this;
    }
    delete[] data; // from smart pointer ❌
    this->data = other.data;
    other.data = nullptr;
    cout << "move operator\n";

    return *this;
  }

  void details() {
    if(data==nullptr) {
      cout << "address: " << data << endl;
      cout << "this instance no longer is available\n";
      return;
    }
    cout << "address: " << data << endl;
    cout << "value: " << *data << endl;
  }
};


void welcome_run() {
  MyClass obj1(1);
  cout << "[object 1]\n";
  obj1.details(); cout << endl;

  MyClass obj2 = std::move(obj1);
  cout << "[object 1]\n";
  obj1.details();
  cout << "[object 2]\n";
  obj2.details(); cout << endl;

  obj2 = std::move(obj1);
  cout << "[object 1]\n";
  obj1.details();
  cout << "[object 2]\n";
  obj2.details(); cout << endl;

  MyClass obj0(0);
  obj0.details();
  obj0 = std::move(obj2 = std::move(obj1));
  cout << "[object 0]\n";
  obj0.details(); cout << endl;
}
