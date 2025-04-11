#include<iostream>
#include"task4.hpp"
//Symbol(✅) means that a class instance is created/allocated.
//Symbol(❌) means that a class instance is deleted/deallocated.
int main() {
  //USING 3 CONSTRUCTORS (none-parameter, parameter, clone)
  CTable npTable; //expectedTableSize: 7
  CTable pTable("parameteredName", 10); //expectedTableSize: 10
  CTable copiedTable(npTable); //expectedTableSize: 7, 🔥Class instance name is address itself?
  
  //USING 3 METHODS (vSetName, bSetNewSize, pcClone)
  npTable.vSetName("changedDefaultName");
  if(npTable.bSetNewSize(20)) {
    std::cout << "📝MODIFY-SIZE: SUCCESS" << std::endl; //expectedTableSize: 20
  }
  else {
    std::cerr << "📝MODIFY-SIZE: FAIL" << std::endl;
  }

  CTable* pCloneMethodTable = pTable.pcClone(); //expectedTableSize: 10
  
  // vModifyTable(&npTable, 7); //expectedTableSize: 7
  // vModifyTable(npTable, 7); //table created but only inside the method(COPY CREATED)

  //JUST FOR DEBUGGING
  npTable.vShowInfo();
  pTable.vShowInfo();
  copiedTable.vShowInfo();
  pCloneMethodTable->vShowInfo();
  
  // pCloneMethodTable->~CTable(); //Not a great way
  delete pCloneMethodTable; //PREFERRED WAY
}