#include<iostream>
#include<cmath>
#define DEFAULT_LENGTH 5
int countDigits(int iTarget) {
  if(iTarget<=0) iTarget = 0 - iTarget;
  int iCount = 0;
  while(iTarget>0) {
    iTarget /= 10;
    iCount++;
  }
  return iCount;
}
class CNumber {
// [private]
private:
  bool bIsPositive;
  int iLength;
  int *piDigits;
// [public]
public:
  // [constructor]
  CNumber() {
    bIsPositive = true;
    iLength = DEFAULT_LENGTH;
    piDigits = new int[iLength];
  }
  CNumber(int iValue) {
    if(iValue<0) {
      bIsPositive = false;
      iValue = 0 - iValue;
    }
    else if(iValue==0) {
      bIsPositive = true;
      iLength = 1;
      piDigits = new int[iLength];
      piDigits[0] = 0;
      return;
    }
    else bIsPositive = true;
    iLength = countDigits(iValue);
    piDigits = new int[iLength];
    for(int i=0; i<iLength; i++) {
      piDigits[iLength-1-i] = (iValue % (int)pow(10,i+1)) / (int)pow(10,i);
    }
  }
  // 💻 task 1: destructor
  // 💻 task 3: remove the destructor
  ~CNumber() {
    delete[] piDigits;
    // std::cout << "\n[number instance deletion completed]\n";
  }

  // [class operator overloading]
  // 💻 task 1: assignment operator
  void operator=(int iValue) {
    if(iValue<0) {
      bIsPositive = false;
      iValue = 0 - iValue;
    }
    else if(iValue==0) {
      bIsPositive = true;
      delete[] piDigits;
      iLength = 1;
      piDigits = new int[iLength];
      piDigits[0] = 0;
      return;
    }
    else bIsPositive = true;
    delete[] piDigits;
    iLength = countDigits(iValue);
    piDigits = new int[iLength];
    for(int i=0; i<iLength; i++) {
      piDigits[iLength-1-i] = (iValue % (int)pow(10,i+1)) / (int)pow(10,i);
    }
  }
  // 💻 task 2: define the operator
  // 💻 task 4: fix the assignment operator code
  void operator=(const CNumber &pcOther) {
    if(this == &pcOther) return;
    bIsPositive = pcOther.bIsPositive;
    delete[] piDigits;
    iLength = pcOther.iLength;
    piDigits = new int[iLength];
    for (int i = 0; i < iLength; i++) {
      piDigits[i] = pcOther.piDigits[i];
    }
  }
  CNumber operator+(const CNumber &pcOther) {
    CNumber cNumberToReturn;
    int iArrayLength;
    if(iLength > pcOther.iLength) iArrayLength = iLength + 1;
    else iArrayLength = pcOther.iLength + 1;
    // 0123456789
    // _012345678(1)
    // _____01234(5)
    int *iArray = new int[iArrayLength];
    if(bIsPositive) {
      for(int i=0; i<iLength; i++) {
        iArray[i+(iArrayLength-iLength)] += piDigits[i];
      }
    }
    else {
      for(int i=0; i<iLength; i++) {
        iArray[i+(iArrayLength-iLength)] -= piDigits[i];
      }
    }
    if(pcOther.bIsPositive) {
      for(int i=0; i<pcOther.iLength; i++) {
        iArray[i+(iArrayLength-pcOther.iLength)] += pcOther.piDigits[i];
      }
    }
    else {
      for(int i=0; i<pcOther.iLength; i++) {
        iArray[i+(iArrayLength-pcOther.iLength)] -= pcOther.piDigits[i];
      }
    }
    cNumberToReturn.bIsPositive = true;
    for(int i=0; i<iArrayLength; i++) {
      if(iArray[i]>0) break;
      else if(iArray[i]<0) {
        cNumberToReturn.bIsPositive = false;
        for(int j=i; j<iArrayLength; j++) {
          iArray[j] = 0 - iArray[j];
        }
      }
    }
    for(int i=iArrayLength-1; i>0; i--) {
      if(iArray[i]>9) {
        iArray[i] -= 10;
        iArray[i-1] += 1;
      }
      else if(iArray[i]<0) {
        iArray[i] += 10;
        iArray[i-1] -= 1;
      }
    }
    // length: 5
    // 01234(index)
    // 00041(value)
    int iFirstPlace = -1;
    for(int i=0; i<iArrayLength; i++) {
      if(iArray[i]!=0) {
        iFirstPlace = i;
        break;
      }
    }
    if(iFirstPlace==-1) {
      cNumberToReturn = 0;
      return cNumberToReturn;
    }
    cNumberToReturn.iLength = iArrayLength - iFirstPlace;
    cNumberToReturn.piDigits = new int[cNumberToReturn.iLength];
    for(int i=0; i<cNumberToReturn.iLength; i++) {
      cNumberToReturn.piDigits[i] = iArray[i+iFirstPlace];
    }
    delete[] iArray;
    return cNumberToReturn;
  }
  CNumber operator-(const CNumber &pcOther) {
    // __368
    // _1567
    // [0][-1][-2][0][1]
    // [0][-2][8][0][1]
    // [1][8][8][0][1]

    // [0][-1][-2][0][1]
    // [0][1][2][0][-1]
    // [0][1][1][9][9]
    // [0][1][1][9][9]
    CNumber cNumberToReturn;
    int iArrayLength;
    if(iLength > pcOther.iLength) iArrayLength = iLength + 1;
    else iArrayLength = pcOther.iLength + 1;
    // 0123456789
    // _012345678(1)
    // _____01234(5)
    int *iArray = new int[iArrayLength];
    if(bIsPositive) {
      for(int i=0; i<iLength; i++) {
        iArray[i+(iArrayLength-iLength)] += piDigits[i];
      }
    }
    else {
      for(int i=0; i<iLength; i++) {
        iArray[i+(iArrayLength-iLength)] -= piDigits[i];
      }
    }
    if(pcOther.bIsPositive) {
      for(int i=0; i<pcOther.iLength; i++) {
        iArray[i+(iArrayLength-pcOther.iLength)] -= pcOther.piDigits[i];
      }
    }
    else {
      for(int i=0; i<pcOther.iLength; i++) {
        iArray[i+(iArrayLength-pcOther.iLength)] += pcOther.piDigits[i];
      }
    }
    cNumberToReturn.bIsPositive = true;
    for(int i=0; i<iArrayLength; i++) {
      if(iArray[i]>0) break;
      else if(iArray[i]<0) {
        cNumberToReturn.bIsPositive = false;
        for(int j=i; j<iArrayLength; j++) {
          iArray[j] = 0 - iArray[j];
        }
      }
    }
    for(int i=iArrayLength-1; i>0; i--) {
      if(iArray[i]>9) {
        iArray[i] -= 10;
        iArray[i-1] += 1;
      }
      else if(iArray[i]<0) {
        iArray[i] += 10;
        iArray[i-1] -= 1;
      }
    }
    // length: 5
    // 01234(index)
    // 00041(value)
    int iFirstPlace = -1;
    for(int i=0; i<iArrayLength; i++) {
      if(iArray[i]!=0) {
        iFirstPlace = i;
        break;
      }
    }
    if(iFirstPlace==-1) {
      cNumberToReturn = 0;
      return cNumberToReturn;
    }
    cNumberToReturn.iLength = iArrayLength - iFirstPlace;
    cNumberToReturn.piDigits = new int[cNumberToReturn.iLength];
    for(int i=0; i<cNumberToReturn.iLength; i++) {
      cNumberToReturn.piDigits[i] = iArray[i+iFirstPlace];
    }
    delete[] iArray;
    return cNumberToReturn;
  }
  CNumber operator*(const CNumber &pcOther) {
    CNumber cNumberToReturn;
    int iArrayLength;
    iArrayLength = iLength + pcOther.iLength;
    int *iArray = new int[iArrayLength];
    if(bIsPositive == pcOther.bIsPositive) cNumberToReturn.bIsPositive = true;
    else cNumberToReturn.bIsPositive = false;
    // [0][0][2][4][1] 3
    // [0][0][0][7][5] 2
    // [0][0][10][20][5]
    // [0][14][28][7][0]
    // [0][14][38][27][5]
    // [1][8][0][7][5]
    for(int i=0; i<pcOther.iLength; i++) {
      int iMultiplier = pcOther.piDigits[pcOther.iLength-1-i];
      for(int j=0; j<iLength; j++) {
        iArray[iArrayLength-1-j-i] += iMultiplier * piDigits[iLength-1-j];
      }
    }
    // std::cout << "📝 debug\n";
    // for(int i=0; i<iArrayLength; i++) {
    //   std::cout << iArray[i] << std::endl;
    // }
    for(int i=0; i<iArrayLength; i++) {
      int iValue = iArray[iArrayLength-1-i];
      iArray[iArrayLength-2-i] += iValue/10;
      iArray[iArrayLength-1-i] = iValue%10;
    }
    int iFirstPlace;
    for(int i=0; i<iArrayLength; i++) {
      if(iArray[i]!=0) {
        iFirstPlace = i;
        break;
      }
    }
    cNumberToReturn.iLength = iArrayLength - iFirstPlace;
    cNumberToReturn.piDigits = new int[cNumberToReturn.iLength];
    for(int i=0; i<cNumberToReturn.iLength; i++) {
      cNumberToReturn.piDigits[i] = iArray[i+iFirstPlace];
    }
    delete[] iArray;
    return cNumberToReturn;
  }
  CNumber operator/(const CNumber &pcOther) {
    CNumber cNumberToReturn, cNumberCopyThis, cNumberCopyOther;
    cNumberCopyThis = *this;
    cNumberCopyThis.bIsPositive = true;
    cNumberCopyOther = pcOther;
    cNumberCopyOther.bIsPositive = true;
    if(iLength < pcOther.iLength) {
      cNumberToReturn = 0;
      if(this->bIsPositive == pcOther.bIsPositive) cNumberToReturn.bIsPositive = true;
      else cNumberToReturn.bIsPositive = false;
      return cNumberToReturn;
    }
    else if(iLength == pcOther.iLength) {
      // using cnumbertoreturn as temporal instance
      // cNumberToReturn = *this;
      int iCount = 0;
      while(true) {
        // debug
        // cNumberToReturn.viewNumber();
        cNumberCopyThis = cNumberCopyThis - cNumberCopyOther;
        if(cNumberCopyThis.bIsPositive!=true) {
          cNumberToReturn = iCount;
          if(this->bIsPositive == pcOther.bIsPositive) cNumberToReturn.bIsPositive = true;
          else cNumberToReturn.bIsPositive = false;
          return cNumberToReturn;
        }
        iCount++;
      }
      // return cNumberToReturn;
    }
    // [1][4][8][9][3][0][2]
    // [4][7][7][1][5][0][0] 2
    // [0][0][0][0][_][0][0]
    // [0][0][0][0][0][0][0]

    // [1][4][8][9][3][0][2]
    // [0][4][7][7][1][5][0] 1
    // [0][0][0][0][0][_][0]
    // [0][0][0][0][0][3][0]
    
    // [1][4][8][9][3][0][2] - 3 * [0][4][7][7][1][5][0]
    // [0][0][4][7][7][1][5] 0
    // [0][0][0][0][0][3][_]
    // [0][0][0][0][0][3][1]

    int iArrayLength = iLength + 1 - pcOther.iLength;
    int *iArray = new int[iArrayLength];
    CNumber cNumberTen;
    cNumberTen = 10;
    for(int i=iLength-pcOther.iLength; i>=0; i--) {
      CNumber cNumberReduction;
      cNumberReduction = cNumberCopyOther;
      for(int j=0; j<i; j++) cNumberReduction = cNumberReduction * cNumberTen;
      int iCount = 0;
      while(true) {
        cNumberCopyThis = cNumberCopyThis - cNumberReduction;
        // this->viewNumber();
        // std::cout << (this->bIsPositive!=true) << std::endl;
        // std::cout << (this->iLength==1 && this->piDigits[0]==0) << std::endl;
        // std::cout << "🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴\n"; exit(0);
        if(cNumberCopyThis.bIsPositive!=true) {
          cNumberCopyThis = cNumberCopyThis + cNumberReduction;
          break;
        }
        else if(cNumberCopyThis.iLength==1 && cNumberCopyThis.piDigits[0]==0) {
          iCount++;
          break;
        }
        iCount++;
      }
      iArray[iArrayLength-1-i] = iCount;
    }
    int iFirstPlace;
    for(int i=0; i<iArrayLength; i++) {
      if(iArray[i]!=0) {
        iFirstPlace = i;
        break;
      }
    }
    cNumberToReturn.iLength = iArrayLength - iFirstPlace;
    cNumberToReturn.piDigits = new int[cNumberToReturn.iLength];
    for(int i=0; i<cNumberToReturn.iLength; i++) {
      cNumberToReturn.piDigits[i] = iArray[i+iFirstPlace];
    }
    if(this->bIsPositive == pcOther.bIsPositive) cNumberToReturn.bIsPositive = true;
    else cNumberToReturn.bIsPositive = false;
    delete[] iArray;
    return cNumberToReturn;
  }
  CNumber operator<<(const int unsigned iBit) {
    // ❗️WELCOME 1❗️
    /*
    CNumber copyThis = *this, numberDWA(2);
    for(int i=0; i<iBit; i++) {copyThis = copyThis * numberDWA;}
    return copyThis;
    */
    int *iArray;
    int iArrayLength = iLength + iBit / 3 + 1;
    iArray = new int[iArrayLength];
    for(int j=0; j<iLength; j++) {
      iArray[j+iBit/3+1] += this->piDigits[j] * (int)pow(2,iBit);
    }
    for(int i=0; i<iBit/3+1; i++) {
      for(int j=i; j<iArrayLength-1; j++) {
        iArray[iArrayLength-2-j] += iArray[iArrayLength-1-j] / 10;
        iArray[iArrayLength-1-j] %= 10;
      }
    }
    int iFirstPlace;
    for(int i=0; i<iArrayLength; i++) {
      if(iArray[i]!=0) {
        iFirstPlace = i;
        break;
      }
    }
    CNumber cNumberToReturn;
    cNumberToReturn.bIsPositive = bIsPositive;
    cNumberToReturn.iLength = iArrayLength - iFirstPlace;
    cNumberToReturn.piDigits = new int[cNumberToReturn.iLength];
    for(int i=0; i<cNumberToReturn.iLength; i++) {
      cNumberToReturn.piDigits[i] = iArray[i+iFirstPlace];
    }
    return cNumberToReturn;
  }
  CNumber operator<<(const CNumber &pcOther) {
    // ❗️WELCOME 2❗️
    CNumber cNumberToReturn, cNumberCopyOther, cNumberDivider, cNumberGap;
    cNumberCopyOther = pcOther;
    cNumberDivider = iLength;
    cNumberGap = cNumberCopyOther - (cNumberCopyOther / cNumberDivider) * cNumberDivider;
    int iGap = 0;
    for(int i=cNumberGap.iLength; i>0; i--) {
      iGap += cNumberGap.piDigits[cNumberGap.iLength-i] * (int)pow(10,i-1);
    }
    int *iArray;
    int iArrayLength = iLength;
    iArray = new int[iArrayLength];
    for(int i=0; i<iArrayLength; i++) {
      iArray[(i+iArrayLength-iGap)%iArrayLength] = piDigits[i];
    }
    cNumberToReturn.bIsPositive = bIsPositive;
    cNumberToReturn.iLength = iArrayLength;
    cNumberToReturn.piDigits = new int[cNumberToReturn.iLength];
    for(int i=0; i<cNumberToReturn.iLength; i++) {
      cNumberToReturn.piDigits[i] = iArray[i];
    }
    return cNumberToReturn;
  }
  friend std::ostream& operator<<(std::ostream& out, const CNumber& pcThis) {
    // ❗️WELCOME 3❗️
    if (!pcThis.bIsPositive) out << "-";
    for (int i = 0; i < pcThis.iLength; i++) {
      out << pcThis.piDigits[i];
    }
    return out;
  }

  // [getter, setter]
  void setNumber() {
    std::cout << "\n[set number method called]" << std::endl;
    std::cout << "...total length: " << iLength << std::endl;
    for(int i=0; i<iLength; i++) {
      std::cout << "enter " << i+1 << "th digit: ";
      std::cin >> piDigits[i];
      if(piDigits[i] >= 10 || piDigits[i] < 0) {
        std::cerr << "error: digit out of range\n";
        return;
      }
    }
  }

  // [additional method]
  void viewNumber() {
    std::cout << "\n[view number method called]\n";
    std::cout << "📝 address: " << this << std::endl;
    std::cout << "📝 positive: " << bIsPositive << std::endl;
    std::cout << "📝 length: " << iLength << std::endl;
    std::cout << "📝 value: ";
    if(bIsPositive!=true) std::cout << "-";
    for(int i=0; i<iLength; i++) {
      if(0<=piDigits[i] && piDigits[i]<10) std::cout << piDigits[i];
      else {
        std::cerr << "error: digit out of range\n";
        return;
      }
    }
    std::cout << std::endl;
  }
  // 💻 task 5: write a sToString method
  std::string sToString() {
    std::string sToReturn = "";
    if(bIsPositive!=true) sToReturn += "-";
    for(int i=0; i<iLength; i++) {
      sToReturn += std::to_string(piDigits[i]);
    }
    return sToReturn;
  }
};