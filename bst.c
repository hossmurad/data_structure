#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node with the given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return createNode(key);

    // Otherwise, recur down the tree
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    // Return the (unchanged) node pointer
    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or the key is present at the root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than the root's key
    if (key > root->key)
        return search(root->right, key);

    // Key is smaller than the root's key
    return search(root->left, key);
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the BST
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the BST
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert keys into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search for a key in the BST
    int keyToSearch = 40;
    struct Node* searchResult = search(root, keyToSearch);
    if (searchResult != NULL)
        printf("Key %d found in the BST.\n", keyToSearch);
    else
        printf("Key %d not found in the BST.\n", keyToSearch);

    // Perform various traversals
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

