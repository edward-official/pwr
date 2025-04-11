#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;


#define VARIABLE 0
#define OPERATOR_SINGLE 1
#define OPERATOR_DOUBLE 2
#define INTEGER 3
#define DEFAULT_TOKEN "0"


class CNode {
private:
  CNode *leftChild, *rightChild;
  string value; // operator, variable, int
  int type;

  bool isNumber(string value) {
    int length = value.length();
    for(int i=0; i<length; i++) {
      if(!isdigit(value[i])) return false;
    }
    return true;
  }
  int decideType(string value) {
    if(value == "sin" || value == "cos") return OPERATOR_SINGLE;
    else if(value == "+" || value == "-" || value == "*" || value == "/") return OPERATOR_DOUBLE;
    else if(isNumber(value)) return INTEGER;
    else return VARIABLE;
  }


public:
  CNode(string value) {
    this->value = value;
    this->type = decideType(value);
    // cout << "🔴 debug" << value << type << endl;
    leftChild = nullptr;
    rightChild = nullptr;
  }
  string getValue() const {return value;}
  int getType() {return type;}
  CNode** getLeftReference() {return &leftChild;}
  CNode** getRightReference() {return &rightChild;}
};


class CTree {
private:
  CNode *rootNode;
  vector<string> vars;

  void createTree(CNode **rootNode, vector<string> tokens, int &tokenIndex) {
    int type;
    if((*rootNode) == nullptr) {
      if(tokens.size()==tokenIndex) {
        cout << "🔎 tree creation with an error: an argument is missing; program prints an error message and fixes the formula by filling the missing argument in.\n";
        tokens.push_back(DEFAULT_TOKEN);
      }
      (*rootNode) = new CNode(tokens[tokenIndex++]);
      type = (*rootNode)->getType();
    }
    // else type = (*rootNode)->getType();
    
    if(type==INTEGER) return;
    else if(type==VARIABLE) {
      for(int i=0; i<=vars.size(); i++) { // recording variables
        if(i==vars.size()) {
          vars.push_back(tokens[tokenIndex-1]); // index increased by 1 after allocating node
          break;
        }
        if(vars[i]==tokens[tokenIndex-1]) break; // index increased by 1 after allocating node
      }
      return;
    }
    else if(type==OPERATOR_SINGLE) {
      createTree(((*rootNode)->getLeftReference()), tokens, tokenIndex);
    }
    else {
      createTree(((*rootNode)->getLeftReference()), tokens, tokenIndex);
      createTree(((*rootNode)->getRightReference()), tokens, tokenIndex);
    }
  }
  void printTree(CNode *rootNode) {
    if(rootNode->getType() == INTEGER || rootNode->getType() == VARIABLE) cout << rootNode->getValue() << " ";
    else if(rootNode->getType() == OPERATOR_SINGLE) {
      cout << rootNode->getValue() << " ";
      printTree(*rootNode->getLeftReference());
    }
    else {
      cout << rootNode->getValue() << " ";
      printTree(*rootNode->getLeftReference());
      printTree(*rootNode->getRightReference());
    }
  }
  int compute(CNode *node, vector<int> values) {
    if(node->getType()==INTEGER) return stoi(node->getValue());
    else if(node->getType()==VARIABLE) {for(int i=0; i<vars.size(); i++) if(node->getValue()==vars[i]) return values[i];}
    else if(node->getValue()=="sin") {
      // cout << "🔴 debug, sin() called\n";
      return sin(compute(*node->getLeftReference(), values));
    }
    else if(node->getValue()=="cos") return cos(compute(*node->getLeftReference(), values));
    else if(node->getValue()=="+") return compute(*node->getLeftReference(), values) + compute(*node->getRightReference(), values);
    else if(node->getValue()=="-") return compute(*node->getLeftReference(), values) - compute(*node->getRightReference(), values);
    else if(node->getValue()=="*") return compute(*node->getLeftReference(), values) * compute(*node->getRightReference(), values);
    else if(node->getValue()=="/") return compute(*node->getLeftReference(), values) / compute(*node->getRightReference(), values);
    return 0; // just for syntax
  }
  void joinTree(CNode **node, CNode **target) {
    if(*node==nullptr) {return;}
    if((*(*node)->getLeftReference())==nullptr) {return;}
    if((*(*(*node)->getLeftReference())->getLeftReference())==nullptr) {
      *(*node)->getLeftReference() = *target;
    }
    else {joinTree((*node)->getLeftReference(), target);}
  }
  void updateVars(CNode *node) {
    if(node->getType()==VARIABLE) {
      for(int i=0; i<=vars.size(); i++) {
        if(i==vars.size()) vars.push_back(node->getValue());
        if(node->getValue()==vars[i]) break;
      }
    }
    else if(node->getType()==INTEGER) return;
    else if(node->getType()==OPERATOR_SINGLE) {
      updateVars(*(node->getLeftReference()));
    }
    else if(node->getType()==OPERATOR_DOUBLE) {
      updateVars(*(node->getLeftReference()));
      updateVars(*(node->getRightReference()));
    }
  }
  bool processTokens(vector<string> tokens) {
    string operation = tokens[0];
    int tokenIndex = 0;
    tokens.erase(tokens.begin());
    if(operation == "enter") {
      vars.clear();
      createTree(&rootNode, tokens, tokenIndex);
    }
    else if(operation == "vars") {
      vars.clear();
      updateVars(rootNode);
      for(int i=0; i<vars.size(); i++) cout << vars[i] << endl;
    }
    else if(operation == "print") {
      printTree(rootNode);cout<<endl;
    }
    else if(operation == "comp") {
      if(tokens.size()!=vars.size()) {
        cout << "🔎 not enough inputs for computation error\n";
        return false;
      }
      vector<int> values;
      for(int i=0; i<tokens.size(); i++) values.push_back(stoi(tokens[i]));
      cout << compute(rootNode, values) << endl;
    }
    else if(operation == "join") {
      CTree *otherTree = new CTree();
      int tokenIndex = 0;
      otherTree->createTree(otherTree->getRootReference(), tokens, tokenIndex);
      joinTree(&rootNode, otherTree->getRootReference());
    }
    else if(operation == "exit") {
      cout << "🟥 exit by proper termination code\n";
      return false;
    }
    else {cout << "🔎 error: wrong input, enter again\n";}
    return true;
  }
  void free(CNode *node) {
    if(node==nullptr) return;
    if(node->getType()==VARIABLE) delete node;
    else if(node->getType()==INTEGER) delete node;
    else if(node->getType()==OPERATOR_SINGLE) {
      free(*(node->getLeftReference()));
      delete node;
    }
    else if(node->getType()==OPERATOR_DOUBLE) {
      free(*(node->getLeftReference()));
      free(*(node->getRightReference()));
      delete node;
    }
  }
  CNode* copyNode(CNode* node) {
    if (node == nullptr) return nullptr;
    CNode* newNode = new CNode(node->getValue());
    *newNode->getLeftReference() = copyNode(*node->getLeftReference());
    *newNode->getRightReference() = copyNode(*node->getRightReference());
    return newNode;
  }


public:
  CTree() {rootNode=nullptr;}
  CTree& operator=(CTree& other) {
    if (this == &other) return *this;
    freeTree();
    rootNode = copyNode(other.rootNode);
    vars = other.vars;
    return *this;
  }
  CTree& operator+(const CTree& other) {
    CTree* result = new CTree();
    result->rootNode = copyNode(this->rootNode);
    CNode* otherRootCopy = copyNode(other.rootNode);
    result->joinTree(&(result->rootNode), &otherRootCopy);
    return *result;
  }
  void treeUI() {
    string line, token;
    bool bContinue = true;
    while(bContinue) {
      vector<string> tokens;
      cout << "📝 > ";
      getline(cin, line);
      istringstream iss(line);
      while(iss >> token) tokens.push_back(token);
      bContinue = processTokens(tokens);
    }
  }
  CNode **getRootReference() {return &rootNode;}
  void freeTree() {free(rootNode);}
  void optimise(CNode **node) {
    if((*node)->getType()==OPERATOR_SINGLE) {
      optimise((*node)->getLeftReference());
      if((*(*node)->getLeftReference())->getType()==INTEGER) {
        vector<int> t;
        int result = compute(*node, t);
        free(*node);
        *node = new CNode(to_string(result));
      }
    }
    else if((*node)->getType()==OPERATOR_DOUBLE) {
      optimise((*node)->getLeftReference());
      optimise((*node)->getRightReference());
      if ((*(*node)->getLeftReference())->getType() == INTEGER && (*(*node)->getRightReference())->getType() == INTEGER) {
        vector<int> t;
        int result = compute(*node, t);
        free(*node);
        *node = new CNode(to_string(result));
      }
    }
    else return;
  }
  CTree optimised() {
    CTree toReturn = *this;
    toReturn.optimise(toReturn.getRootReference());
    return toReturn;
  }
};