#include <iostream>

struct Node {
  int val;
  Node *nextNode;

  // Define the constructor
  Node() : val(0), nextNode(nullptr) {}
  Node(int v, Node *next = nullptr) : val(v), nextNode(next) {}
};
