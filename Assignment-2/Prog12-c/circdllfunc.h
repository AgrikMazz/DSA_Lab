#ifndef CIRCDLLFUNC_H
#define CIRCDLLFUNC_H

#include "circdll.h"

struct Node* BuildList(int size);
struct Node* BuildList_Reverse(int size);
void Print_list(struct Node* head);
int findSize(struct Node* head);
bool checkListsEqual(struct Node* head1, struct Node* head2);
struct Node* appendTwoLists(struct Node* head1, struct Node* head2);
struct Node* searchUnordered(struct Node* head, int key);
struct Node* searchOrdered(struct Node* head, int key);
struct Node* deleteNode(struct Node* head, int pos);
bool isSorted(struct Node* head);
struct Node* mergeList(struct Node* head1, struct Node* head2);
struct Node* removeDuplicatesUnsorted(struct Node* head);
struct Node* removeDuplicatesSorted(struct Node* head);
struct Node* insertBefore(struct Node* head, struct Node* target, struct Node* before);
struct Node* insertEnd(struct Node* head, struct Node* target);
void swapElementsbyPairs(struct Node* head);
struct Node* moveLasttoFirst(struct Node* head);
struct Node* rotateList(struct Node* head, int rot);
struct Node* deleteAlternateNodes(struct Node* head);
void deleteList(struct Node* head);
struct Node* reverseList(struct Node* head);
void sort(struct Node* head);

#endif