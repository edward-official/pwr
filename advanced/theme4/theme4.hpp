#include<iostream>
#include<sstream>
#include<cmath>
#include<fstream>
#include<vector>


#define VARIABLE 0
#define OPERATOR_SINGLE 1
#define OPERATOR_DOUBLE 2
#define INTEGER 3
#define DEFAULT_TOKEN "0"
using namespace std;


class CError {
private:
  string description;
public:
  CError(const string &description) : description(description) {}
  string getDescription() const {return description;}
};


template <typename T, typename E>
class CResult {
private:
  T *pc_value;
  vector<E*> v_errors;

  void deallocate() {
    if(pc_value) delete[] pc_value;
    if(v_errors.size()>0) {
      for(int i=0; i<v_errors.size(); i++) delete[] v_errors[i];
      v_errors.clear();
    }
  }
  void copy(const CResult<T, E>& other) {
    deallocate();
    pc_value = other.pc_value ? new T(*other.pc_value) : 0;
    for (int i = 0; i<other.v_errors.size(); i++) v_errors.push_back(other.v_errors[i] ? new E(*other.v_errors[i]) : 0);
  }


public:
  CResult(const T& cValue) : pc_value(new T(cValue)), v_errors(0) {}
  CResult(E* pcError) : pc_value(0) {v_errors.push_back(pcError);}
  CResult(vector<E*>& vErrors) : pc_value(0), v_errors(vErrors) {}
  CResult(const CResult<T, E>& cOther) {copy(cOther);}
  ~CResult() {deallocate();}

  static CResult<T, E> cOk(const T& cValue) {return CResult(cValue);}
  static CResult<T, E> cFail(E* pcError) {return CResult(pcError);}
  static CResult<T, E> cFail(vector<E*>& vErrors) {return CResult(vErrors);}

  CResult<T, E>& operator=(const CResult<T, E>& cOther) {copy(cOther);}

  bool bIsSuccess() {return pc_value;}
  T cGetValue() const {return *pc_value;}
  vector<E*> vGetErrors() const {return v_errors;}
  bool bHasValue() const {return pc_value != 0;}
};


template <typename E>
class CResult<void, E> {
private:
  vector<E*> v_errors;

  void deallocate() {
    for(int i=0; i<v_errors.size(); i++) delete[] v_errors[i];
    v_errors.clear();
  }
  void copy(const CResult<void, E>& other) {
    deallocate();
    for (int i = 0; i<other.v_errors.size(); i++) v_errors.push_back(other.v_errors[i] ? new E(*other.v_errors[i]) : 0);
  }


public:
  CResult() : v_errors(0) {}
  CResult(E *pcError) {v_errors.push_back(pcError);}
  CResult(vector<E*>& vErrors) : v_errors(vErrors) {}
  CResult(const CResult<void, E>& cOther) {copy(cOther);}
  ~CResult() {deallocate();}

  static CResult<void, E> cOk() {return CResult();}
  static CResult<void, E> cFail(E* pcError) {return CResult(pcError);}
  static CResult<void, E> cFail(vector<E*>& vErrors) {return CResult(vErrors);}

  CResult<void, E>& operator=(const CResult<void, E>& cOther) {copy(cOther);}

  bool bIsSuccess() {
    if(v_errors.size()==0) return true;
    else return false;
  }
  vector<E*>& vGetErrors() {return v_errors;}
  bool bHasValue() const {return false;}
};


CResult<double, CError> eDivide(double dDividend, double dDivisor) {
  if (dDivisor == 0) return CResult<double, CError>::cFail(new CError("cannot divide by zero"));
  return CResult<double, CError>::cOk(dDividend / dDivisor);
}
CResult<void, CError> simpleTask(bool isPermitted) {
  if(isPermitted) {
    cout << "processing simple task without return type\n";
    cout << "completed the task\n";
    return 0;
  }
  else return CResult<void, CError>(new CError("not permitted error"));
}


class CNode {
private:
  int data_;


public:
  CNode() : data_(0) {}
  CNode(int data) : data_(data) {}
};


class CTree {
private:
  CNode* rootNode;
  bool insert() {
    
  }


public:
  CTree() : rootNode(0) {}
  CResult<CTree&, CError> createTree(vector<int> datas) {

  }
};


template<typename T>
class CResultSaver {
private:
  string filename_;

public:
  CResultSaver(const string &filename) : filename_(filename) {}

  bool saveToFile(const CResult<T, CError> &result) {
    ofstream outFile(filename_.c_str(), ios::app); // Open file in append mode
    if (!outFile.is_open()) {
      cerr << "Failed to open file: " << filename_ << endl;
      return false;
    }

    if (result.bHasValue()) {
      outFile << "Value: " << result.cGetValue() << endl;
    } else {
      outFile << "Errors:" << endl;
      const vector<CError *> &errors = result.vGetErrors();
      for (size_t i = 0; i < errors.size(); ++i) {
        outFile << "  - " << errors[i]->getDescription() << endl;
      }
    }

    outFile.close();
    return true;
  }
};