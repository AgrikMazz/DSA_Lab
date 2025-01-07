#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int rightThread; // Flag indicating if the right pointer is a thread (0 = false, 1 = true)
};

struct TreeNode* make_root(int x) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    node->rightThread = 0;
    return node;
}

void init_t(struct TreeNode** t) {
    *t = NULL;
}

bool empty_t(struct TreeNode* t) {
    return t == NULL;
}

int height(struct TreeNode* t) {
    if (empty_t(t)) return 0;
    int lh = height(t->left);
    int rh = height(t->right);
    return (lh >= rh) ? 1 + lh : 1 + rh;
}

void addLeft(struct TreeNode* t, int n) {
    if (empty_t(t)) return;
    struct TreeNode* newNode = make_root(n);
    newNode->right = t;   // Right pointer points to the parent node (for threading)
    newNode->rightThread = 1;  
    t->left = newNode;
}

void addRight(struct TreeNode* t, int n) {
    if (empty_t(t)) return;
    struct TreeNode* newNode = make_root(n);
    if (t->rightThread) {
        t->right = newNode;  
        t->rightThread = 0;  
    } 
    else {
        struct TreeNode* temp = t->right;
        while (temp != NULL && temp->rightThread == 0) {
            temp = temp->right;
        }
        temp->right = newNode;  // Link new node to the thread
        temp->rightThread = 1;  // Mark this node's right as a thread
    }
}

struct TreeNode* deleteLeaf(struct TreeNode* t, int n) {
    if (t == NULL) return NULL;
    if (!t->left && !t->right && t->data == n) return NULL;
    t->left = deleteLeaf(t->left, n);
    t->right = deleteLeaf(t->right, n);
    return t;
}

void preOrder(struct TreeNode* t) {
    if (empty_t(t)) return;
    printf("%d ", t->data);
    preOrder(t->left);
    if (t->rightThread == 0)  
        preOrder(t->right);
}

void inOrder(struct TreeNode* t) {
    if (empty_t(t)) return;
    
    struct TreeNode* current = t;
    while (current->left != NULL) {
        current = current->left; 
    }

    while (current != NULL) {
        printf("%d ", current->data);
        if (current->rightThread == 1) {
            current = current->right;  
        } else {
            current = current->right;  
            while (current != NULL && current->left != NULL) {
                current = current->left;
            }
        }
    }
}

void postOrder(struct TreeNode* t) {
    if (empty_t(t)) return;
    postOrder(t->left);
    if (t->rightThread == 0)  
        postOrder(t->right);
    printf("%d ", t->data);
}

void menu() {
    printf("\nThreaded Binary Tree Menu:\n");
    printf("1. Create a new tree (make root)\n");
    printf("2. Add left child\n");
    printf("3. Add right child\n");
    printf("4. Delete leaf node\n");
    printf("5. Pre-order traversal\n");
    printf("6. In-order traversal\n");
    printf("7. Post-order traversal\n");
    printf("8. Height of the tree\n");
    printf("9. Exit\n");
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data, leafData;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for root: ");
                scanf("%d", &data);
                root = make_root(data);
                printf("Root created with value %d\n", data);
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty. Create a root first.\n");
                    break;
                }
                printf("Enter value to add to left of root: ");
                scanf("%d", &data);
                addLeft(root, data);
                printf("Left child added with value %d\n", data);
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty. Create a root first.\n");
                    break;
                }
                printf("Enter value to add to right of root: ");
                scanf("%d", &data);
                addRight(root, data);
                printf("Right child added with value %d\n", data);
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty. Create a root first.\n");
                    break;
                }
                printf("Enter value of leaf node to delete: ");
                scanf("%d", &leafData);
                root = deleteLeaf(root, leafData);
                printf("Leaf node with value %d deleted (if exists)\n", leafData);
                break;
            case 5:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    break;
                }
                printf("Pre-order traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    break;
                }
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 7:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    break;
                }
                printf("Post-order traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 8:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    break;
                }
                printf("Height of the tree: %d\n", height(root));
                break;
            case 9:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
