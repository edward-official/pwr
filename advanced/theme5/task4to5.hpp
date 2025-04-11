#include <iostream>
using namespace std;


class Node {
private:
  int data;
  Node* left;
  Node* right;


public:
  Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
  }

  int getData() {return data;}
  Node* getLeft() {return left;}
  Node* getRight() {return right;}
  void setLeft(Node* node) {left = node;}
  void setRight(Node* node) {right = node;}
};


class CMyTree {
private:
  Node* root;
  void free(Node* node) {
    if(node!=nullptr) {
      free(node->getLeft());
      free(node->getRight());
      delete node;
    }
  }
  Node* copyTree(Node* node) {
    if(node==nullptr) return nullptr;
    Node* newNode = new Node(node->getData());
    newNode->setLeft(copyTree(node->getLeft()));
    newNode->setRight(copyTree(node->getRight()));
    return newNode;
  }
  void mergeTrees(CMyTree& tree, Node* node) {
    if(node!=nullptr) {
      tree.insert(node->getData());
      mergeTrees(tree, node->getLeft());
      mergeTrees(tree, node->getRight());
    }
  }

public:
  CMyTree() {root = nullptr;}
  CMyTree(CMyTree& other) {root = copyTree(other.root);}
  CMyTree(CMyTree&& other) : root(other.root) {
    other.root = nullptr;
    std::cout << "move constructor\n";
  }
  ~CMyTree() {free(root);}

  CMyTree& operator=(const CMyTree& other) {
    if(this!=&other) {
      free(root);
      root = copyTree(other.root);
    }
    cout << "basic assignment operator\n";
    return *this;
  }
  CMyTree& operator=(CMyTree&& other) {
    if(this!=&other) {
      free(root);
      root = other.root;
      other.root = nullptr;
      std::cout << "move assignment operator\n";
    }
    return *this;
  }
  CMyTree operator+(const CMyTree& other) {
    CMyTree result;
    mergeTrees(result, root);
    mergeTrees(result, other.root);
    return result;
  }

  Node* getRoot() {return root;}
  void insert(int value) {root = insert(root, value);}
  Node* insert(Node* node, int value) {
    if(node==nullptr) return new Node(value);

    if(value < node->getData()) node->setLeft(insert(node->getLeft(), value));
    else if(value > node->getData()) node->setRight(insert(node->getRight(), value));
    return node;
  }
  bool search(Node* node, int value) {
    if(node==nullptr) return false;
    if(node->getData()==value) return true;
    else if(value < node->getData()) return search(node->getLeft(), value);
    else return search(node->getRight(), value);
  }

  void inorder(Node* node) {
    if(node!=nullptr) {
      inorder(node->getLeft());
      cout << node->getData() << " ";
      inorder(node->getRight());
    }
  }
};


void task4() {
  CMyTree originalTree;
  int list[] = {28, 26, 30, 33, 9, 42, 17, 13, 50, 41, 8, 23, 43, 5, 38, 24, 27, 13, 29, 43};
  int length = sizeof(list)/sizeof(list[0]);
  for(int i=0; i<length; i++) originalTree.insert(list[i]);

  cout << "original tree\n> ";
  originalTree.inorder(originalTree.getRoot());
  cout << endl << endl;

  // CMyTree movedTree(std::move(originalTree));
  // CMyTree movedTree = std::move(originalTree);
  CMyTree movedTree;movedTree = std::move(originalTree);
  
  cout << "original tree\n> ";
  originalTree.inorder(originalTree.getRoot());
  cout << endl << endl;

  cout << "moved tree\n> ";
  movedTree.inorder(movedTree.getRoot());
  cout << endl << endl;
}


void task5() {
  CMyTree tree0, tree1, tree2;

  int list1[] = {40, 35, 12, 31, 35, 18, 10, 22, 7, 41};
  int length1 = sizeof(list1)/sizeof(list1[0]);
  for(int i=0; i<length1; i++) tree1.insert(list1[i]);

  int list2[] = {42, 50, 50, 7, 49, 17, 46, 25, 48, 21};
  int length2 = sizeof(list2)/sizeof(list2[0]);
  for(int i=0; i<length2; i++) tree2.insert(list2[i]);

  tree0 = tree1 + tree2; // rvalue -> move operator
  cout << "merged tree\n> ";
  tree0.inorder(tree0.getRoot());
  cout << endl << endl;
  
  tree0 = tree1;
  cout << "copied tree\n> ";
  tree0.inorder(tree0.getRoot());
  cout << endl << endl;
}
