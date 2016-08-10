/* program to check if a tree is height-balanced or not */
#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node* left;
  struct node* right;
};
bool isBalanced(struct node *root, int* height) {
  int lh = 0, rh = 0; //lh = height of left subtree, rh
  int l = 0, r = 0;
  if(root == NULL) { //true if root is NULL
    *height = 0;
     return 1;
  }
  /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in l and r */
  l = isBalanced(root->left, &lh);
  r = isBalanced(root->right,&rh);
  *height = max(lh, rh) + 1;
  if((lh - rh >= 2) || (rh - lh >= 2)) return 0; //not balanced
  else return l&&r; //balanced if left & right is balanced
}
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main()
{
  int height = 0;
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);

  if(isBalanced(root, &height)) printf("Tree is balanced");
  else printf("Tree is not balanced");
  return 0;
}
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */
