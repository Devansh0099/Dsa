#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }

    return root;
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key) {
        return root;
    }

    if (key < root->val) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    int searchKey = 20;
    struct TreeNode* result = search(root, searchKey);
    if (result != NULL) {
        printf("%d found in the BST.\n", searchKey);
    } else {
        printf("%d not found in the BST.\n", searchKey);
    }

    return 0;
}
