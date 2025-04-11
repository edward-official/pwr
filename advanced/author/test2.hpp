// copy constructor for two different address
#include<iostream>
using namespace std;


class Genotype {
private:
  vector<int> _genotype;
  
public:
  Genotype(vector<int> &genotype) : _genotype(genotype) {}
  void mutate() {
    for(int i=0; i<_genotype.size(); i++) {
      _genotype[i] += 5;
    }
  }
  void viewDetails() {
    cout << "details\n";
    for(int i=0; i<_genotype.size(); i++) cout << " " << _genotype.at(i);
    cout << endl;
  }
};


void test2() {
  vector<int> numbers;
  for(int i=0; i<10; i++) numbers.push_back(i);
  Genotype genotype1(numbers);
  genotype1.mutate();
  genotype1.viewDetails();

  cout << endl;
  for(int i=0; i<numbers.size(); i++) cout << numbers[i];
  cout << endl;
}