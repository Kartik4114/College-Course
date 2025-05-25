// here we are constructing a binary tree and performing certain operations on it.
// the function we are operating are adding ,deleting,searching,printing the tree.
// binary tree has one root node and 2 children.

#include <stdio.h>
#include <stdlib.h>  // library used for using dynamic memory allocation.
#include <stdbool.h> // library used for using bool function.

// defining the structure of binarytree.
typedef struct BinaryTreenode
{
    int data;                     // data of the node.
    struct BinaryTreenode *left;  // it is for left child.
    struct BinaryTreenode *right; // it is for right child.
} binarynode;

// initialising the binarytree.
void initialise_tree(binarynode *b1)
{
    b1->left = NULL;
    b1->right = NULL;
}

// function for inerting new node in tree.
// here i am firstly adding rootnode and then linking the leftchild and
// rightchild to the rootnode.
// and then calling the recursion.
binarynode *add()
{
    int rootdata;
    printf("Enter the data: ");
    scanf("%d", &rootdata); // inputing the rootdata

    // defining the base case.
    if (rootdata == -1)
    {
        return NULL;
    }

    binarynode *root = (binarynode *)malloc(sizeof(binarynode));
    root->data = rootdata; // storing rootdata in rootnode.

    printf("Enter the left child of %d: \n", root->data);
    binarynode *leftchild = add(); // calling recursion for left child.

    printf("Enter the right child of %d: \n", root->data);
    binarynode *rightchild = add(); // calling recursion for right child.

    root->left = leftchild;   // linking the leftchild with rootnode.
    root->right = rightchild; // linking the rightchild with rootnode.

    return root;
}

// it is a boolean function for searching the desired element.
bool search(binarynode *root, int element)
{
    // base case.
    if (root == NULL)
    {
        return false;
    }
    if (root->data == element)
    {
        return true;
    }
    return search(root->left, element) || search(root->right, element); // calling recursion and returning.
}

// function for deleting the desired node.
bool delete_tree(binarynode *root, int element)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == element)
    {
        free(root);
        return true;
    }
    return delete_tree(root->left, element) || delete_tree(root->right, element);
}

// function which will print the tree.
void printtree(binarynode *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    printf("%d : ", root->data);
    if (root->left != NULL)
    {
        printf("%d ", root->left->data);
    }
    if (root->right != NULL)
    {
        printf("%d ", root->right->data);
    }
    printf("\n");

    // recursion calling
    printtree(root->left);
    printtree(root->right);
}

int main()
{
    // declaring b1.
    binarynode *b1 = (binarynode *)malloc(sizeof(binarynode));

    initialise_tree(b1); // initialising the tree.

    binarynode *root = add(); // taking inputing the tree.

    printf("The desired binary tree is:\n");
    printf("firstly root is given and then after : its children are given\n");
    printtree(root);

    // inputing the element to be searched.
    int element;
    printf("enter the element you want to search :\n");
    scanf("%d", &element);

    // calling the deleting function.
    bool deleted = delete_tree(root, element);
    if (deleted)
    {
        printf("Element %d deleted from the tree.\n", element);
    }
    else
    {
        printf("Element %d not found in the tree.\n", element);
    }

    bool found = search(root, element); // calling the searching fuction.
    if (found)
    {
        printf("Element %d is present in the tree.\n", element);
    }
    else
    {
        printf("Element %d is not present in the tree.\n", element);
    }

    free(root); // freeing the memory.
    free(b1);

    return 0;
}

