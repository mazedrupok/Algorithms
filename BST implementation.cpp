#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;

///BST implementation

struct BstData {
    int f;
    int s;
    BstData() {
        f = s = 0;
    }
    BstData(int f, int s) {
        this->f = f;
        this->s = s;
    }
    bool operator < (BstData r) {
        if (f == r.f) return s < r.s;
        return f < r.f;
    }
    bool operator == (BstData r) {
        return (f == r.f && s == r.s);
    }
};
struct BstNode {
    BstData data;
    int numberOfSubNode;
    int height;
    BstNode *left;
    BstNode *right;
};
BstNode *Root;
BstNode* newBstNode(BstData data) {
    BstNode *node = new BstNode;
    node->numberOfSubNode = 1;
    node->height = 1;
    node->data = data;
    node->left = node->right = 0;
    return node;
}
BstNode* updateNode(BstNode *node) {
    node->numberOfSubNode = 1;
    node->height = 0;
    if (node->left) {
        node->numberOfSubNode += node->left->numberOfSubNode;
        node->height = max(node->height, node->left->height);
    }
    if (node->right) {
        node->numberOfSubNode += node->right->numberOfSubNode;
        node->height = max(node->height, node->right->height);
    }
    node->height++;
    return node;
}
BstNode* bstInsert(BstNode *root, BstData key) { // insert key
    if (root == 0) {
        return root = newBstNode(key); //Inserted
    }
    if (key == root->data) return root; // duplicate
    else if (key < root->data) {
        root->left = bstInsert(root->left, key);
    }
    else {
        root->right = bstInsert(root->right, key);
    }
    root = updateNode(root);
    return root;
}
BstNode* getMinNode(BstNode *root) {
    BstNode *cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}
BstNode* bstDelete(BstNode *root, BstData key) {
    if (root == 0) {
        return root;
    }
    if (key < root->data) {
        root->left = bstDelete(root->left, key);
    }
    else if (root->data < key) {
        root->right = bstDelete(root->right, key);
    }
    else {
        if (root->left == 0) {
            BstNode *temp = root->right;
            delete root; // found and delete, replaced with right
            root = 0;
            return temp;
        }
        if (root->right == 0) {
            BstNode *temp = root->left;
            delete root; // found and delete, replaced with left
            root = 0;
            return temp;
        }
        BstNode *minNode = getMinNode(root->right);
        root->data = minNode->data; // found and replaced by min value
        root->right = bstDelete(root->right, minNode->data); // delete min value to avoid duplicate
    }
    root = updateNode(root);
    return root;
}
BstNode* bstNthNode(BstNode* root, int n) {
    int cnt = n;
    int sizeOfLeft = 0;
    while (root) {
        sizeOfLeft = 0;
        if (root->left) {
            sizeOfLeft = root->left->numberOfSubNode;
        }
        if (sizeOfLeft + 1 == cnt) {
            return root;  // found is n'th
        }
        else if (sizeOfLeft + 1 < cnt) {
            cnt -= (sizeOfLeft + 1);
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return 0; // Not found nth, bst size is less than n
}
void bstInorder(BstNode *root) {
    if (root == 0) return;
    printf("Start of (%d %d)\n", root->data.f, root->data.s);
    if(root->left) {
        printf("Go left\n");
        bstInorder(root->left);
    }
    printf("%d %d %d %d\n", root->data.f, root->data.s, root->numberOfSubNode, root->height);
    if (root->right) {
        printf("Go right\n");
        bstInorder(root->right);
    }
    printf("Stop of (%d %d)\n", root->data.f, root->data.s);
}
int main ()
{
    BstNode* root = 0;
    root = bstInsert(root, BstData(10, 3));
    root = bstInsert(root, BstData(3, 7));
    root = bstInsert(root, BstData(11, 3));
    root = bstInsert(root, BstData(5, 5));
    root = bstInsert(root, BstData(1, 3));
    root = bstInsert(root, BstData(7, 3));
    root = bstInsert(root, BstData(5, 6));

    root = bstDelete(root, BstData(3, 8));
    bstInorder(root);

    for (int i = 1; i < 8; i++) {
        BstData data = bstNthNode(root, i)->data;
        printf("%d -> %d %d\n", i, data.f, data.s);
    }
    return 0;
}

/*
        (10,3)
        /  \
    (3,7)   (11,3)
     / \
(1,3)  (5,5)
         \
          (7,3)
          /
        (5,6)
*/
