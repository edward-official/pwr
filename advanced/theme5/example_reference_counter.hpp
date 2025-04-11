#include<iostream>
using namespace std;


class CRefCounter {
private:
  int i_count;

public:
  CRefCounter() {i_count;}
  int iAdd() {return (++i_count);}
  int iDec() {return (--i_count);}
  int iGet() {return (i_count);}
};


template <typename T>
class CMySmartPointer {
private:
  T *pc_data;
  CRefCounter *pc_counter;

public:
  CMySmartPointer(T *pc_data) {
    this->pc_data = pc_data;
    pc_counter = new CRefCounter();
    pc_counter->iAdd();
  }
  CMySmartPointer(const CMySmartPointer &pc_other) {
    pc_data = pc_other.pc_data;
    pc_counter = pc_other.pc_counter;
    pc_counter->iAdd();
  }
  ~CMySmartPointer() {
    if (pc_counter->iDec() == 0) {
      delete pc_data;
      delete pc_counter;
      cout << "destructor\n";
    }
  }

  T& operator*() {return (*pc_data);}
  T* operator->() {return (pc_data);}
};


void example_reference_counter() {
  int *balance = new int(0);
  CMySmartPointer<int> bank(balance);
}