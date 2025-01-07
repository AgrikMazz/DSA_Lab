#include "linkedlistfunc.h"

void displayMenu() {
    printf("\nLinked List operations menu:\n");
    printf("1. Build List\n");
    printf("2. Print List\n");
    printf("3. Print List (Reverse Order)\n");
    printf("4. Find Size of List\n");
    printf("5. Check if Two Lists are Equal\n");
    printf("6. Append Two Lists\n");
    printf("7. Search Key in Unordered List\n");
    printf("8. Search Key in Ordered List\n");
    printf("9. Delete nth Node\n");
    printf("10. Check if List is Sorted\n");
    printf("11. Merge Two Sorted Lists\n");
    printf("12. Remove Duplicates (Unsorted)\n");
    printf("13. Remove Duplicates (Sorted)\n");
    printf("14. Insert Before a Node\n");
    printf("15. Insert at End\n");
    printf("16. Swap Elements Pairwise\n");
    printf("17. Move Last Element to Front\n");
    printf("18. Rotate List\n");
    printf("19. Delete Alternate Nodes\n");
    printf("20. Delete List\n");
    printf("21. Reverse List\n");
    printf("22. Sort List\n");
    printf("0. Exit\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, size, key, pos, rot;
    struct Node* result = NULL;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size of the list: ");
                scanf("%d", &size);
                list1 = BuildList(size);
                printf("List created successfully.\n");
                break;
            case 2:
                Print_list(list1);
                break;
            case 3:
                printf("Elements of list in reverse order:\n");
                Print_list_Reverse(list1);
                printf("\n");
                break;
            case 4:
                printf("Size of the list: %d\n", findSize(list1));
                break;
            case 5:
                printf("Creating a second list for comparison.\n");
                printf("Enter size of the second list: ");
                scanf("%d", &size);
                list2 = BuildList(size);
                if (checkListsEqual(list1, list2))
                    printf("The lists are equal.\n");
                else
                    printf("The lists are not equal.\n");
                break;
            case 6:
                printf("Appending another list.\n");
                printf("Enter size of the second list: ");
                scanf("%d", &size);
                list2 = BuildList(size);
                list1 = appendTwoLists(list1, list2);
                printf("Lists appended successfully.\n");
                break;
            case 7:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = searchUnordered(list1, key);
                if (result) {
                    printf("Key found: %d\n", result->val);
                    free(result);
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = searchOrdered(list1, key);
                if (result) {
                    printf("Key found: %d\n", result->val);
                    free(result);
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 9:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                list1 = deleteNode(list1, pos);
                printf("Node deleted successfully.\n");
                break;
            case 10:
                if (isSorted(list1))
                    printf("The list is sorted.\n");
                else
                    printf("The list is not sorted.\n");
                break;
            case 11:
                printf("Merging with another list.\n");
                printf("Enter size of the second list: ");
                scanf("%d", &size);
                list2 = BuildList(size);
                list1 = mergeList(list1, list2);
                printf("Lists merged successfully.\n");
                break;
            case 12:
                list1 = removeDuplicatesUnsorted(list1);
                printf("Duplicates removed from the list.\n");
                break;
            case 13:
                list1 = removeDuplicatesSorted(list1);
                printf("Duplicates removed from the sorted list.\n");
                break;
            case 14:
                printf("Enter value to insert: ");
                scanf("%d", &key);
                
                printf("Enter value of the node before which to insert: ");
                int beforeValue;
                scanf("%d", &beforeValue);
                struct Node* before = list1;

                while(before){
                    if(before->val == beforeValue){
                        break;
                    }
                    before = before->next;
                }

                if (before) {
                    list1 = insertBefore(list1, createNode(key), before);
                    printf("Node inserted successfully.\n");
                } else {
                    printf("Target node not found.\n");
                }
                break;
            case 15:
                printf("Enter value to insert at end: ");
                scanf("%d", &key);
                list1 = insertEnd(list1, createNode(key));
                printf("Node inserted at the end.\n");
                break;
            case 16:
                swapElementsbyPairs(list1);
                printf("Elements swapped pairwise.\n");
                break;
            case 17:
                list1 = moveLasttoFirst(list1);
                printf("Last element moved to front.\n");
                break;
            case 18:
                printf("Enter number of rotations: ");
                scanf("%d", &rot);
                list1 = rotateList(list1, rot);
                printf("List rotated successfully.\n");
                break;
            case 19:
                list1 = deleteAlternateNodes(list1);
                printf("Alternate nodes deleted.\n");
                break;
            case 20:
                deleteList(list1);
                list1 = NULL;
                printf("List deleted successfully.\n");
                break;
            case 21:
                list1 = reverseList(list1);
                printf("List reversed successfully.\n");
                break;
            case 22:
                sort(list1);
                printf("List sorted successfully.\n");
                break;
            case 0:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
