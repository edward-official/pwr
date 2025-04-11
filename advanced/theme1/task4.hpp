#include<iostream>
class CTable {
private:
  std::string stringName;
  int iTableLength;
  int* iTable;
public:
  //Constructor with no parameter
  CTable() {
    stringName = "defaultName"; //default name
    iTableLength = 7; //default length
    iTable = new int[iTableLength];
    std::cout << "✅none-parameter: " << stringName << std::endl;
  }
  //Constructor with parameter
  CTable (std::string sName, int iTableLength) {
    if(iTableLength < 1) {
      std::cerr << "🔥ERROR: Table size should be greater than zero." << std::endl;
      return;
    }
    stringName = sName;
    this->iTableLength = iTableLength;
    iTable = new int[iTableLength];
    std::cout << "✅parameter: " << stringName << std::endl;
  }
  //Constructor copying a class instance
  CTable (const CTable &pcOther) {
    stringName = pcOther.stringName + "Copy";
    iTableLength = pcOther.iTableLength;
    iTable = new int[iTableLength];
    for(int i=0; i<iTableLength; i++) {
      iTable[i] = pcOther.iTable[i];
    }
    std::cout << "✅copy: " << stringName << std::endl;
  }
  //Destructor
  ~CTable() {
    delete[] iTable;
    std::cout << "❌deleting: " << stringName << std::endl;
  }

  //Method to set name
  void vSetName(std::string sName) {
    stringName = sName;
  }
  //Method to set size
  bool bSetNewSize(int iTableLength) {
    if(iTableLength<1) {
      std::cerr << "🔥ERROR: Table length should be over zero." << std::endl;
      return false;
    }
    //🔥dynamic allocation right after the deallocation (valid?)
    int* toDelete = iTable;
    iTable = new int[iTableLength];
    this->iTableLength = iTableLength;
    int iLoop = (this->iTableLength>iTableLength) ? iTableLength : this->iTableLength;
    for(int i=0; i<iLoop; i++) {
      iTable[i] = toDelete[i];
    }
    delete[] toDelete;
    return true;
  }
  //Method to clone a class instance
  CTable* pcClone() { //using the ready made copy constructor without copy pasting the same code
    return new CTable(*this);
  }

  //just for debugging
  void vShowInfo() {
    std::cout << "📝INFO: " << this << ", NAME: " << stringName << ", LENGTH: " << iTableLength << std::endl;
  }
};

void vModifyTable(CTable *pcTable, int iNewSize) {
  if(pcTable->bSetNewSize(iNewSize)) {
    std::cout << "📝Dynamically changed the table size\n";
  }
  else {
    std::cout << "📝Failed dynamically changing the table size\n";
  }
}
void vModifyTable(CTable cTable, int iNewSize) {
  if(cTable.bSetNewSize(iNewSize)) {
    std::cout << "📝Statically changed the table size\n";
  }
  else {
    std::cout << "📝Failed statically changing the table size\n";
  }
}