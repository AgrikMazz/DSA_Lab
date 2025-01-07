#include <stdio.h>
#include "set.h"

int main() {
    Set *set1 = NULL, *set2 = NULL, *result = NULL;
    int choice, element, capacity;

    while (1) {
        printf("\n--- Set Operations ---\n");
        printf("1. Create Set\n");
        printf("2. Insert Element\n");
        printf("3. Remove Element\n");
        printf("4. Print Set\n");
        printf("5. Union of Sets\n");
        printf("6. Intersection of Sets\n");
        printf("7. Delete Set and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (set1 != NULL) {
                    deleteSet(set1);
                }
                printf("Enter capacity of the set: ");
                scanf("%d", &capacity);
                set1 = createSet(capacity);
                printf("Set created with capacity %d.\n", capacity);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertElement(set1, element);
                break;

            case 3:
                printf("Enter element to remove: ");
                scanf("%d", &element);
                removeElement(set1, element);
                break;

            case 4:
                printf("Set elements: ");
                printSet(set1);
                break;

            case 5:
                printf("Creating second set for union operation.\n");
                printf("Enter capacity of the second set: ");
                scanf("%d", &capacity);
                set2 = createSet(capacity);
                printf("Enter elements for second set (type -1 to end): ");
                while (1) {
                    scanf("%d", &element);
                    if (element == -1) break;
                    insertElement(set2, element);
                }
                result = unionSet(set1, set2);
                printf("Union of sets: ");
                printSet(result);
                deleteSet(set2);
                deleteSet(result);
                break;

            case 6:
                printf("Creating second set for intersection operation.\n");
                printf("Enter capacity of the second set: ");
                scanf("%d", &capacity);
                set2 = createSet(capacity);
                printf("Enter elements for second set (type -1 to end): ");
                while (1) {
                    scanf("%d", &element);
                    if (element == -1) break;
                    insertElement(set2, element);
                }
                result = intersectionSet(set1, set2);
                printf("Intersection of sets: ");
                printSet(result);
                deleteSet(set2);
                deleteSet(result);
                break;

            case 7:
                deleteSet(set1);
                printf("Set deleted. Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
