#include<iostream>
void vAllocateTableFill34(int iSize) {
  if(iSize<=0) {
    std::cerr << "🔥vAllocateTableFill34: size of array should be larger than 0." << std::endl;
    return; //If there's improper iSize input, the function terminates so there will be no prints of array elements.
  }
  int* iTable1D = new int[iSize];
  const int FILLER = 34;
  for(int i=0; i<iSize; i++) iTable1D[i] = FILLER;
  std::cout << "✅array elements" << std::endl;
  for(int i=0; i<iSize; i++) std::cout << "[" << i+1 << "]: " << iTable1D[i] << std::endl;
}
void vAllocateTable(int iSize, int iFiller) { //We can improve usability using iFiller parameter. (Can control array element's default value)
  if(iSize<=0) {
    std::cerr << "🔥vAllocateTableFill34: size of array should be larger than 0." << std::endl;
    return; //If there's improper iSize input, the function terminates so there will be no prints of array elements.
  }
  int* iTable1D = new int[iSize];
  for(int i=0; i<iSize; i++) iTable1D[i] = iFiller;
  std::cout << "✅array elements" << std::endl;
  for(int i=0; i<iSize; i++) std::cout << "[" << i+1 << "]: " << iTable1D[i] << std::endl;
}