#include<iostream>
bool bAllocationTable2D(int ***piTable, int iSizeX, int iSizeY) {
  if(iSizeX < 1 || iSizeY < 1) { // check if the given size of array is valid
    std::cerr << "❌ERROR: Size of the table cannot be smaller than 1." << std::endl;
    return false;
  }
  *piTable = new int*[iSizeX];
  // check if the allocation completed properly
  if(*piTable == nullptr) return false;
  for(int i=0; i<iSizeX; i++) {
    (*piTable)[i] = new int[iSizeY];
    // assigning the values for later check/debug
    for(int j=0; j<iSizeY; j++) {
      (*piTable)[i][j] = i * iSizeY + j + 1;
    }
    // check if the allocation completed properly
    if((*piTable)[i] == nullptr) { // deallocating memories when the allocation fails
      for(int j=0; j<i; j++) delete[] (*piTable)[i];
      delete[] *piTable;
      return false;
    }
  }
  return true;
}
bool bDeallocateTable2D(int ***piTable, int iSizeX) { // There's no need for the column size of array in deallocation.
  if(piTable == nullptr || *piTable == nullptr) { // check if the pointer is valid
    std::cerr << "🔥The given pointer isn't valid." << std::endl;
    return false;
  }
  else if(iSizeX<=0) { // check if the row size is valid
    std::cerr << "🔥The given row size of array isn't valid" << std::endl;
    return false;
  }
  // deallocating the memory
  for(int i=0; i<iSizeX; i++) delete[] (*piTable)[i];
  delete[] *piTable;
  return true;
}