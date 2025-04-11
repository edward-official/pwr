#include<iostream>
#include"task.hpp"
int main() {
  CTree sumTree, tree1, tree2;
  tree1.treeUI();
  tree2 = tree1;
  (tree1 + tree2).treeUI();
  // tree2.treeUI();

  // CTree tree;
  // tree.treeUI();
  // CTree optimisedTree = tree.optimised();
  // optimisedTree.treeUI();

  // CTree tree;
  // tree.optimise(tree.getRootReference());
  // tree.treeUI();

  tree1.freeTree();
  tree2.freeTree();
  // tree.freeTree();
  // optimisedTree.freeTree();
  // ❗️free X
}