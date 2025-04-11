#include<iostream>
using namespace std;


class CRefCounter {
private:
  int i_count;

public:
  CRefCounter() : i_count(0) {}
  int iAdd() {return ++i_count;}
  int iDec() {return --i_count;}
  int iGet() const {return i_count;}
};


template <typename T>
class CMySmartPointer {
private:
  T* pc_pointer;
  CRefCounter* pc_counter;
  void free() {
    if(pc_pointer && pc_counter->iDec()==0) {
      delete pc_pointer;
      delete pc_counter;
      cout << "destructed\n";
    }
  }


public:
  CMySmartPointer(T* pcPointer = nullptr) : pc_pointer(pcPointer), pc_counter(new CRefCounter()) {
    if(pc_pointer) pc_counter->iAdd();
  }
  CMySmartPointer(const CMySmartPointer<T>& pcOther) : pc_pointer(pcOther.pc_pointer), pc_counter(pcOther.pc_counter) {
    if(pc_pointer) pc_counter->iAdd();
  }
  ~CMySmartPointer() {free();}
  
  CMySmartPointer& operator=(const CMySmartPointer<T> &pcOther) {
    if(this != &pcOther) {
      free();
      pc_pointer = pcOther.pc_pointer;
      pc_counter = pcOther.pc_counter;
      if(pc_pointer) pc_counter->iAdd();
    }
    return *this;
  }

  T& operator*() {return *pc_pointer;}
  T* operator->() {return pc_pointer;}
};


class Player {
private:
  string name_;
  int number_;

public:
  Player(string name, int number) : name_(name), number_(number) {}
  void info() {std::cout << "name: " << name_ << "[" << number_ << "]" << std::endl;}
};


void task1() {
  CMySmartPointer<Player> bukayo1(new Player("bukayo", 7));
  bukayo1->info();
}


void task2() {
  CMySmartPointer<Player> bukayo(new Player("bukayo", 7));
  bukayo->info();

  CMySmartPointer<Player> blankPlayer(new Player("blank", 0));
  blankPlayer->info();
  
  blankPlayer = bukayo;
  blankPlayer->info();
}


void task3() {
  cout << "Consider what happens when a smart pointer stores a pointer to statically allocated memory.\n";
  cout << "error occurs when they meet delete keyword at deconstructor\n";
}