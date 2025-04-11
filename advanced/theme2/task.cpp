#include<iostream>
#include"task.hpp"

int main() {
  CNumber cNumber0, cNumber1, cNumberResult;
  // 💻 task 2: why the result?
  // freeing the same instance twice
  // cNumber0 = 368;
  // cNumber1 = 1567;
  // cNumber0 = cNumber1;
  
  // 💻 task 3: remove the destructor
  // nothing is visible in console but memory leak happens.

  // 💻 task 4: fix the assignment operator code
  // cNumber0 = 368;
  // cNumber1 = 1567;
  // cNumber0 = cNumber1;

  // 💻 task 5: write a sToString method
  // cNumber0 = 368;
  // std::cout << "string converting method: " << cNumber0.sToString() << std::endl;

  // 💻 task 6: operation, extension to negative
  // [1][4][8][9][3][0][2]
  // [4][7][7][1][5][0][0]
  // cNumber0 = 1489302;
  // cNumber1 = 47715;
  // cNumber0 = 3;
  // cNumber1 = -9;
  // cNumberResult = cNumber0 / cNumber1;
  // cNumber0.viewNumber();
  // cNumber1.viewNumber();
  // cNumberResult.viewNumber();

  // 💻 welcome task 1: bitwise operation
  // (CNumber(732)<<2).viewNumber();
  
  // 💻 welcome task 2: digitwise operation
  // (CNumber(732) << CNumber(2)).viewNumber();

  // 💻 welcome task 3: stream operation
  // std::cout << CNumber(0xd) << std::endl;
}