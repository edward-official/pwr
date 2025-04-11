// returning instance is deleted after test method
#include<iostream>
using namespace std;

class Person {
private:
  string name;
public:
  Person() {name = "bukayo saka";}
  Person(string name) {this->name = name;}
  ~Person() {cout << "deleted\n";}

  string getName() {return name;}
};

Person test() {return Person();}

int main() {
  cout << test().getName() << endl;
}