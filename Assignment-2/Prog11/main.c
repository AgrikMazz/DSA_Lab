#include "llarray.h"

void displayMenu() {
    printf("\nLinked List Operations Menu:\n");
    printf("1. Build List\n");
    printf("2. Build List in Reverse\n");
    printf("3. Print List\n");
    printf("4. Print List in Reverse\n");
    printf("5. Find Size\n");
    printf("6. Search and Delete Key\n");
    printf("7. Append Lists\n");
    printf("8. Delete Nth Node\n");
    printf("9. Check if List is Ordered\n");
    printf("10. Merge Sorted Lists\n");
    printf("11. Insert Target Node\n");
    printf("12. Remove Duplicates\n");
    printf("13. Swap Pairwise Nodes\n");
    printf("14. Move Last Node to Front\n");
    printf("15. Delete Alternate Nodes\n");
    printf("16. Rotate List\n");
    printf("17. Reverse List\n");
    printf("18. Sort List\n");
    printf("19. Delete List\n");
    printf("20. Exit\n");
}

int main() {
    LinkedList list1, list2, result;
    int choice, size, value, key, pos, before, k;

    initList(&list1);
    initList(&list2);
    initList(&result);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size of list: ");
                scanf("%d", &size);
                Build_list(&list1, size);
                break;

            case 2:
                printf("Enter size of list: ");
                scanf("%d", &size);
                Build_list_reverse(&list1, size);
                break;

            case 3:
                printf("List: ");
                printList(&list1);
                break;

            case 4:
                printf("List (Reverse): ");
                printListReverse(&list1, list1.head);
                printf("\n");
                break;

            case 5:
                printf("Size of List: %d\n", findSize(&list1));
                break;

            case 6:
                printf("Enter key to search and delete: ");
                scanf("%d", &key);
                if (searchKey(&list1, key, false)) {
                    printf("Key %d found and deleted.\n", key);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;

            case 7:
                printf("Enter size of second list: ");
                scanf("%d", &size);
                buildList(&list2, size);
                appendList(&list1, &list2);
                printf("Lists appended.\n");
                break;

            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteNthNode(&list1, pos);
                printf("Node at position %d deleted.\n", pos);
                break;

            case 9:
                if (isOrdered(&list1)) {
                    printf("List is ordered.\n");
                } else {
                    printf("List is not ordered.\n");
                }
                break;

            case 10:
                printf("Enter size of second sorted list: ");
                scanf("%d", &size);
                buildList(&list2, size);
                mergeSortedLists(&list1, &list2, &result);
                printf("Lists merged.\n");
                break;

            case 11:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter value before which to insert: ");
                scanf("%d", &before);
                insertTargetNode(&list1, value, before);
                printf("Node with value %d inserted before %d.\n", value, before);
                break;

            case 12:
                removeDuplicates(&list1, false);
                printf("Duplicates removed.\n");
                break;

            case 13:
                swapPairwise(&list1);
                printf("Nodes swapped pairwise.\n");
                break;

            case 14:
                moveLastToFront(&list1);
                printf("Last node moved to front.\n");
                break;

            case 15:
                deleteAlternateNodes(&list1);
                printf("Alternate nodes deleted.\n");
                break;

            case 16:
                printf("Enter number of positions to rotate: ");
                scanf("%d", &k);
                rotateList(&list1, k);
                printf("List rotated.\n");
                break;

            case 17:
                reverseList(&list1);
                printf("List reversed.\n");
                break;

            case 18:
                sortList(&list1);
                printf("List sorted.\n");
                break;

            case 19:
                deleteList(&list1);
                printf("List deleted.\n");
                break;

            case 20:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}