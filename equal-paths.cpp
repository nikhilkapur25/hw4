#ifndef RECCHECK
#include <iostream>
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
bool equalPaths(Node * root);
bool checkLengths(Node* node, int currD, int& leafD);

bool checkLengths(Node* node, int currD, int& leafD) {
  if(!node) return true; 

  if (!node->left && !node->right) {
    if(leafD == -1) {
      leafD = currD; 
    }

    return currD == leafD;
  }

  bool leftCheck = checkLengths(node->left, currD + 1, leafD);
  bool rightCheck = checkLengths(node->right, currD + 1, leafD); 

  return leftCheck && rightCheck;
}

bool equalPaths(Node * root) {
  int num = -1; 
  return checkLengths(root, 0, num);
}

// int main() {
//   Node* root = new Node(1);
//   root->left = new Node(2);
//   root->right = new Node(3):

//   root->left->left = new Node(4);
//   root->right->right = new Node(5);
// }