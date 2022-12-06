#include "linkedListFuncs.h"
#include <stddef.h>

using namespace std;

/*All functions MUST be implemented recursively
* No credit will be given for non-recursive solutions
*/


//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) {
  // base case 1: list is null.
  if(head == nullptr) {
    return 0;
  }
  // base case 2: list only contains one node.
  if(head->next == nullptr) {
    return head->data;
  }
  // recursive case: find the sum of the sublist and add its sum to the data of the head node.
  return recursiveSum(head->next) + head->data;
}


//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
  // base case 1: the list has only one element. 
  if (head->next == nullptr) {
    return head->data;
  }
  // recursive case: store the largest value of the rest of the list as curr_large, and compare to the head value.
  int curr_large = recursiveLargestValue(head->next);
  if(head->data > curr_large) {
    return head->data;
  } else {
    return curr_large;
  }
}


/*Given the head of a linked list, find and return the kth node of the linked list
 *Assume head is the first node
 *If k is larger than the size of the linked list, return NULL
 *
 * Example: n1 -> n2 -> n3 -> n4 -> n5, k = 3
 * Return &n3
 */
Node* recursiveFindKthNode(Node *head, int k){
  //base case 1: we have an empty list, head is null.
  if (head == nullptr) {
    return NULL;
  }
  // base case 2: the node we want to delete is the first node.
  if (k == 1) {
    return head;
  }
  
  return recursiveFindKthNode(head->next, k-1);
  /*go deeper into the linkedlist until we reach:
      1. head is a null pointer (k is larger than the length of the linkedlist, return null).
      2. k=1, we get to the kth node we want to find. return a pointer to that node which is head of that sub linkedlist.
  */ 

}


/*Given the head of a linked list, delete the kth node from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n2 and return &n1
* New list should look like this: n1 -> n3 -> n4
*/
Node* recursiveDeleteKthNode(Node *head, int k) {
  // base case: the head node is the node we want to delete.
  if (k == 1) {
    Node* tmp = head->next; // store the second node in temporary node pointer.
    delete head; // delete the head node.
    return tmp; // retuen the pointer to the second node.
  }
  // recursive case: find and delete the node in the sublist.
  Node*p = recursiveDeleteKthNode(head->next, k-1); // store the pointer to the next node of the deleted node in p.
  head->next = p; // connect head to the rest of the list.
  return head;
}


/*Given the head of a linked list, delete the first k nodes from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n1, n2 and return &n3
*/
Node* recursiveRemoveKFromFront(Node *head, int k) {
  // base case: when k=1, just delete head and return head->next as the new head.
  if (k == 1) {
    Node* tmp = head->next; //store head->next in a temporary node pointer so we can delete head and return head->next.
    delete head;
    return tmp;
  }
  return recursiveRemoveKFromFront(head->next, k-1); 
  //Go deeper into the linked list till k reaches one, which means the last element we need to delete. Return a pointer to the next node.
}


/*Given two linked lists, return a NEW linked-list where each element is the sum of the corresponding elements of the input
 * If a linked list has a longer length than the other, treat the corresponding NULL element as a node with value 0
 * 
 * Example: List 1: 1 -> 2 -> 3 -> 12
 * 	    List 2: 4 -> 5 -> 6
 * Return &head of the linked list 5 -> 7 -> 9 -> 12
 */
Node* recursiveElementwiseSum(Node *head1, Node *head2) {
  // base case 1: both heads are nullptr, return nullptr.
  if (head1 == nullptr && head2 == nullptr){
    return nullptr;
  }
  // base case 2: if one list contains 1 non-empty node and the other contains a null node, return a pointer to the node that has data.
  if (head1 == nullptr && head2 != nullptr){
    return head2;
  }
  if (head1 != nullptr && head2 == nullptr){
    return head1;
  }
  // calling the recursive function to compute the sum of the sub linkedlist.
  Node* p = recursiveElementwiseSum(head1->next, head2->next);
  int sum = head1->data + head2->data;
  Node* h = new Node{sum, p}; 
  /* create a new node: 1. data is the sum of the corresponding elements.
                        2. the next pointer is the node pointer p that got returned by last recursive call. */

  return h; //return the new node tp previous fucntion call to create the new linkedlist of sum.

}
  
  
  

/*BONUS: Given the heads of two linked lists, splice the second linked list into the first, alternating elements from each list
 * 
 * The first element of the newly arranged linked list will always be head1, unless head1 is NULL (in which case just return head2)
 *
 * You MUST modify the linked lists themselves and DO NOT create another list or any new nodes
 *
 * Example: List 1: 1->2->3, List 2: 4 -> 5 -> 6
 * Return &head of 1 -> 4 -> 2 -> 5 -> 3 -> 6
 */
Node* recursiveSplice(Node *head1, Node *head2) {
  // base case 1: head 1 is NULL.
  if (!head1) {
    return head2;
  }
  if (!head1->next && !head2->next) {
    head1->next = head2;
    return head1;
  }
  // base case 2: list 2 only contains one element.
  if (head2->next == nullptr) {
    head2->next = head1->next;
    head1->next = head2;
    return head1;
  }
  // recursive case: splice the second sub linked list into the first sub linked list.
  Node* p = recursiveSplice(head1->next, head2->next);
  head2->next = p; 
  head1->next = head2;
  // make sure the linked list strart with list 1 and alternate between list 1 and 2.

  return head1;
}
