/********************************************************
// 2807. Insert Greatest Common Divisors in Linked List

Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

TAG: Linked List, Math, Numebr Theory
*********************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans=head;

        while(head->next) {
            // new node
            ListNode* newNode = new ListNode(gcd(head->val, head->next->val));
            // adding node in between
            newNode->next = head->next;
            head->next = newNode;
            // set head in position for next iteration
            head = newNode->next;
        }
        return ans;
    }
};