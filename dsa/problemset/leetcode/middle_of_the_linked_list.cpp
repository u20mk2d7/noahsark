// https://leetcode.com/problems/middle-of-the-linked-list/

#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode_ver01(ListNode *head);
  ListNode *middleNode_ver02(ListNode *head);
};

// Approach: Two-Pointer Technique (Fast and Slow Pointers)
ListNode *Solution::middleNode_ver01(ListNode *head) {
  if (head == nullptr)
    return nullptr;

  return nullptr;
}

ListNode *middleNode_ver02(ListNode *head) {}
