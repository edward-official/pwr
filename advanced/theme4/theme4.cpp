#include<iostream>
#include"theme4.hpp"
using namespace std;


void task1() {
  CError error("description example");
  cout << error.getDescription() << endl;
}
void task2() {
  cout << eDivide(3, 4).cGetValue() << endl;
  cout << eDivide(3, 0).vGetErrors().at(0)->getDescription() << endl;
}
void task3() {
  bool isPermitted = true;
  CResult<void, CError> test = simpleTask(true);
  if(!isPermitted) cout << test.vGetErrors()[0]->getDescription() << endl;
  else cout << "operation success\n";
}
void task4() {
  CTree tree;
  vector<string> dataList;
  dataList.push_back("+");
  dataList.push_back("1");
  dataList.push_back("2");
  int index = 0;
  CResult<CTree, CError> createResult = tree.setTree(dataList, index);
}
void task5() {
  CResultSaver<double> saver("results.txt");

  CResult<double, CError> result1 = eDivide(3, 4);
  CResult<double, CError> result2 = eDivide(3, 0);

  saver.saveToFile(result1);
  saver.saveToFile(result2);
}


int main() {
  task4();
}