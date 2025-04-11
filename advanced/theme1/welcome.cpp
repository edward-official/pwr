#include<iostream>
class Person {
private:
  std::string sName;
  int iMaxColleagueNumber, iCurrentColleagueNumber;
  Person **pPersonList;

public:
  Person() {
    sName = "default"; //🔎debug
    const int iMaxNumber = 256;
    iMaxColleagueNumber = iMaxNumber;
    iCurrentColleagueNumber = 0;
    pPersonList = new Person*[iMaxColleagueNumber];
    // std::cout << "✅default create: " << sName << std::endl;
  }
  Person(std::string sName, int iMaxColleagueNumber) {
    if(iMaxColleagueNumber<=0) {
      std::cerr << "🔥Array size should be greater than zero\n";
      return;
    }
    this->sName = sName;
    this->iMaxColleagueNumber = iMaxColleagueNumber;
    iCurrentColleagueNumber = 0;
    pPersonList = new Person*[iMaxColleagueNumber];
    // std::cout << "✅parametered created: " << sName << std::endl;
  }
  Person(const Person* pPersonToCopy) {
    sName = pPersonToCopy->sName + "Copy"; //❗️accessible?(private?)
    iMaxColleagueNumber = pPersonToCopy->iMaxColleagueNumber; //❗️accessible?(private?)
    iCurrentColleagueNumber = pPersonToCopy->iCurrentColleagueNumber; //❗️accessible?(private?)
    pPersonList = new Person*[iMaxColleagueNumber];
    //📝comment, independent
    // for(int i=0; i<iCurrentColleagueNumber; i++) {
    //   pPersonList[i] = pPersonToCopy->pPersonList[i]; //❗️accessible?(private?)
    // }
    std::cout << "✅clone create: " << sName << std::endl;
  }
  //📝deconstructor
  ~Person() {
    std::cout << "📝📝📝📝[deconstruction]name: " << sName << ", current colleague: " << iCurrentColleagueNumber << std::endl;
    if(iCurrentColleagueNumber==0) {
      std::cout << "❌0 colleague: deletion completed\n\n";
      return;
    }
    //First, find all [this]'s friends and delete their information about [this], update the colleague list
    for(int i=0; i<iCurrentColleagueNumber; i++) { //Check [this]'s [i]th friend.
      std::cout << "📝checking [" << sName << "]'s [" << i+1 << "]th friend.\n";
      int iLoop = pPersonList[i]->iGetCurrentNumber();
      for(int j=0; j<iLoop; j++) {
        //If the [j]th friend in the [this]'s [i]th friend’s list is [this], then delete it.
        if(pPersonList[i]->pPersonList[j] == this) { //❗️accessible?(private?)
          std::cout << "📝[" << j+1 << "]th friend of [" << sName << "]'s [" << i+1 << "]th friend is [" << sName << "].\n";
          // std::cout << "📝updating his/her friend list.\n";
          if(j==pPersonList[i]->iCurrentColleagueNumber-1) {
            pPersonList[i]->pPersonList[j] = nullptr; //❗️deallocation of class instance?
            pPersonList[i]->iCurrentColleagueNumber--;
          }
          else {
            pPersonList[i]->pPersonList[j] = pPersonList[i]->pPersonList[pPersonList[i]->iCurrentColleagueNumber-1];
            pPersonList[i]->pPersonList[pPersonList[i]->iCurrentColleagueNumber-1] = nullptr;
            pPersonList[i]->iCurrentColleagueNumber--;
          }
        }
      }
    }
    delete[] pPersonList;
    std::cout << "❌deletion completed\n\n";
  }

  //📝getter
  std::string sGetName() {
    return sName;
  }
  int iGetMaxNumber() {
    return iMaxColleagueNumber;
  }
  int iGetCurrentNumber() {
    return iCurrentColleagueNumber;
  }
  //📝setter
  void vModifyName(std::string sName) {
    this->sName = sName;
  }
  void vModifyCurrentNumber(int increment) {
    iCurrentColleagueNumber+=increment;
  }
  bool bIsFull() {
    if(iCurrentColleagueNumber==iMaxColleagueNumber) return true;
    else if(iCurrentColleagueNumber>iMaxColleagueNumber) {
      std::cerr << "🔥ERROR: Colleague number exceeded maximum.\n";
      exit(0);
    }
    else return false;
  }
  void vPutColleague(Person *target) {
    if(this->bIsFull()) {
      std::cerr << "🔥ERROR: Not enough space in array.\n";
      return;
    }
    pPersonList[iCurrentColleagueNumber] = target;
    iCurrentColleagueNumber++;
    // std::cout << "🔎DEBUG: " << sName << ", " << iCurrentColleagueNumber << std::endl;
  }

  //📝check method
  void vCheck() {
    std::cout << "🔴Check: " << sName << ", " << iCurrentColleagueNumber << std::endl;
    for(int i=0; i<iCurrentColleagueNumber; i++) {
      std::cout << "[" << i << "]: " << pPersonList[i]->sGetName() << std::endl;
    }
  }

  //📝introduce method
  void vIntroduce(Person *target) { //void Person::introduce?
    this->vPutColleague(target);
    target->vPutColleague(this);
  }
};

int main() {
  Person pDefault0;
  pDefault0.vModifyName("default0");
  Person pDefault1(&pDefault0);
  pDefault1.vModifyName("copyDefault1");
  Person pDefault2(&pDefault1);
  pDefault2.vModifyName("copyDefault2");

  const int iDefaultSize = 16;
  Person pParametered0("parameter0", iDefaultSize);
  Person pParametered1(&pParametered0);
  pParametered1.vModifyName("copyParameter1");
  Person pParametered2(&pParametered1);
  pParametered2.vModifyName("copyParameter2");
  Person pParametered3(&pParametered2);
  pParametered3.vModifyName("copyParameter3");
  Person pParametered4(&pParametered3);
  pParametered4.vModifyName("copyParameter4");

  pDefault1.vIntroduce(&pParametered1);
  pDefault1.vIntroduce(&pParametered2);
  pDefault1.vIntroduce(&pParametered3);
  pDefault1.vIntroduce(&pParametered4);
  pDefault2.vIntroduce(&pParametered1);
  pDefault2.vIntroduce(&pParametered2);
  pDefault2.vIntroduce(&pParametered3);
  pDefault2.vIntroduce(&pParametered4);

}