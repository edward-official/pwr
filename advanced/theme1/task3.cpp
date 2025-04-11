#include"task3.hpp"
int main() {
  int** piTable;
  int iRow = 5, iColumn = 6;
  //Allocating the memory with function
  if(bAllocationTable2D(&piTable, iRow, iColumn)) {
    std::cout << "✅Allocation completed\n";
    for(int i=0; i<iRow; i++) { //print the array elements
      for(int j=0; j<iColumn; j++) {
        if(j!=0) std::cout << " ";
        std::cout << piTable[i][j];
      }
      std::cout << std::endl;
    }
    //Deallocating the memory with function
    if(bDeallocateTable2D(&piTable, iRow)) {
      std::cout << "❌Deallocation completed\n";
    }
    else {
      std::cout << "🔥Deallocation failed\n";
    }
  }
  else {
    std::cerr << "🔥Allocation Failed" << std::endl;
  }
}