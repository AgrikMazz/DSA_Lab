#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int x){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void init_t(struct TreeNode** root) {
    *root = NULL;
}

int empty_t(struct TreeNode* root){
    return root == NULL;
}

int searchNode(struct TreeNode* root, int x){
    if(empty_t(root)){
        return 0;
    }
    if(root->data == x){
        return 1;
    }
    else if(root->data < x){
        return searchNode(root->right, x);
    }
    return searchNode(root->left, x);
}

struct TreeNode* insertNode(struct TreeNode* root, int x){
    if(empty_t(root)){
        root = createNode(x);
        return root;
    }
    if(root->data == x){
        return root;
    }
    else if(root->data < x){
        root->right = insertNode(root->right, x);
    }
    else{
        root->left = insertNode(root->left, x);
    }
    return root;
}

int findMax(struct TreeNode* root){
    if(empty_t(root)) return -1;

    struct TreeNode* curr = root;
    while(curr->right){
        curr = curr->right;
    }
    return curr->data;
}

int findMin(struct TreeNode* root){
    if(empty_t(root)) return -1;

    struct TreeNode* curr = root;
    while(curr->left){
        curr = curr->left;
    }
    return curr->data;
}

struct TreeNode* deleteNode(struct TreeNode* root, int x){
    if(empty_t(root)) return NULL;

    if(root->data < x){
        root->right = deleteNode(root->right, x);
    }
    else if(root->data > x){
        root->left = deleteNode(root->left, x);
    }
    else{
        if(!root->left && !root->right){  // Leaf node
            root = NULL;
        }
        else if(!root->left && root->right){  // No left child
            struct TreeNode* temp = root->right;
            root->right = NULL;
            root = temp;
        }
        else if(root->left && !root->right){  // No right child
            struct TreeNode* temp = root->left;
            root->left = NULL;
            root = temp;
        }
        else{
            int successor = findMin(root->right);
            root->data = successor;  // Replace value with inorder successor
            root->right = deleteNode(root->right, successor); // Delete the successor
        }
    }
    return root;
}

void inorder(struct TreeNode* root){
    if(empty_t(root)) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct TreeNode* root){
    if(empty_t(root)) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct TreeNode* root){
    if(empty_t(root)) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct TreeNode* root;
    init_t(&root);
    int choice, data;

    while(1){
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Find Maximum value\n");
        printf("5. Find Minimum value\n");
        printf("6. Inorder Traversal\n");
        printf("7. Preorder Traversal\n");
        printf("8. Postorder Traversal\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if(searchNode(root, data))
                    printf("Node found.\n");
                else
                    printf("Node not found.\n");
                break;
            case 4:
                printf("Maximum value: %d\n", findMax(root));
                break;
            case 5:
                printf("Minimum value: %d\n", findMin(root));
                break;
            case 6:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 7:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 8:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
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