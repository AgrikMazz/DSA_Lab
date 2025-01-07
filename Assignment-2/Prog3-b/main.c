#include "list.h"

int main() {
    List* list = NULL;
    int choice, value, index, capacity;

    while (1) {
        printf("\n--- List Operations ---\n");
        printf("1. Create List\n");
        printf("2. Append Element\n");
        printf("3. Insert Element\n");
        printf("4. Modify Element\n");
        printf("5. Pop Element\n");
        printf("6. Remove Element\n");
        printf("7. Print List\n");
        printf("8. Reverse List\n");
        printf("9. Sort List\n");
        printf("10. Get List Length\n");
        printf("11. Get Element\n");
        printf("12. Delete List and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (list != NULL) {
                    deleteList(list);
                }
                printf("Enter the capacity of the list: ");
                scanf("%d", &capacity);
                list = createList(capacity);
                printf("List created with capacity %d.\n", capacity);
                break;

            case 2:
                printf("Enter value to append: ");
                scanf("%d", &value);
                append(list, value);
                break;

            case 3:
                printf("Enter index and value to insert: ");
                scanf("%d %d", &index, &value);
                insertElement(list, index, value);
                break;

            case 4:
                printf("Enter index and new value to modify: ");
                scanf("%d %d", &index, &value);
                modify(list, index, value);
                break;

            case 5:
                value = pop(list);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                } else {
                    printf("List is empty.\n");
                }
                break;

            case 6:
                printf("Enter value to remove: ");
                scanf("%d", &value);
                removeElement(list, value);
                break;

            case 7:
                printf("List elements: ");
                printList(list);
                break;

            case 8:
                reverse(list);
                printf("List reversed.\n");
                break;

            case 9:
                sort(list);
                printf("List sorted.\n");
                break;

            case 10:
                printf("List length: %d\n", length(list));
                break;

            case 11:
                printf("Enter index to get element: ");
                scanf("%d", &index);
                value = getElement(list, index);
                if (value != -1) {
                    printf("Element at index %d: %d\n", index, value);
                } else {
                    printf("Index out of bounds.\n");
                }
                break;

            case 12:
                deleteList(list);
                printf("List deleted. Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}
