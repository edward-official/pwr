#include<iostream>
#include"task2.hpp"
int main() {
  int** piTable;
  int iRow = 4, iColumn = 5;
  
  //test the function
  if(bAllocationTable2D(&piTable, iRow, iColumn)) {
    std::cout << "✅ Allocation Successful" << std::endl;
    for(int i=0; i<iRow; i++) { //print the array elements
      for(int j=0; j<iColumn; j++) {
        if(j!=0) std::cout << " ";
        std::cout << piTable[i][j];
      }
      std::cout << std::endl;
    }
  }
  else {
    std::cerr << "🔥Allocation Failed" << std::endl;
  }
}