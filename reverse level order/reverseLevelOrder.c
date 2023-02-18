//C program to print binary tree reverse level order traversal
#include <stdio.h>
#include <stdlib.h>
//A binary tree node has data, pointer to left and right child
struct treeNode
{
int data;
struct treeNode* leftptr;
struct treeNode* rightptr;
};
//Function prototypes
void reverseLevelOrder(struct treeNode* root);
struct treeNode* newNode(int data);
int height(struct treeNode* node);
//Function to print reverse level order traversal a binary tree
void reverseLevelOrder(struct treeNode* root)
{
    int h = height(root);
    int i;
    for (i=h; i>=1; i--) {//THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        printGivenLevel(root, i);
    }
         if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(struct treeNode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
//Insert new node to the binary tree
struct treeNode* newNode(int data)
{
struct treeNode* treeNode = (struct treeNode*) malloc(sizeof(struct
treeNode));
treeNode->data = data;
treeNode->leftptr = NULL;
treeNode->rightptr = NULL;
return(treeNode);
}
int main()
{
struct treeNode *root = newNode(9);
root->leftptr = newNode(12);
root->rightptr = newNode(21);
root->leftptr->leftptr = newNode(15);
root->leftptr->rightptr = newNode(8);
root->rightptr->leftptr = newNode(7);
root->rightptr->rightptr = newNode(11);
printf("Level Order traversal of binary tree is \n");
reverseLevelOrder(root);
return 0;
}