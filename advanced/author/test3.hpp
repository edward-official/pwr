// vector assignment logic
// for example
// >> vector<Numbers> numbers1, numbers2;
// >> /*initializing Numbers2 instance*/
// >> Numbers1 = Numbers2
// in this situation we have to make sure the copying operation of Numbers class works properly
// if my assumption is right
// >> in vector assignment like the example, operation inside would be copying all the elements one by one to the target vector elements (maybe)
// then I have to make sure that copying individual instances will work properly
#include<iostream>
using namespace std;

class Person {
private:
  vector<string> name;
  int size;
public:
  Person(string _name, int _size) : size(_size) {for(int i=0; i<_size; i++) name.push_back(_name);}

  void viewDetails() {
    for(int i=0; i<size; i++) cout << name[i];
    cout << endl;
  }
};

void test3() {
  vector<Person> persons1, persons2;
  Person p1("one", 4), p2("two", 4);
  persons1.push_back(p1);
  persons1.push_back(p2);
  persons2 = persons1;

  for(int i=0; i<persons2.size(); i++) persons2[i].viewDetails();
}