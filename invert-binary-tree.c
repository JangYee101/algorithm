//title num:226

#include <stdio.h>
#include <stdlib.h>

int data1[100]={4,2,1,0,0,3,0,0,7,6,0,0,9,0,0}, data_length=15;
int *data=data1, index_for_data=0;

struct TreeNode
{
    int val;
    struct TreeNode * right;
    struct TreeNode * left;
};

void createTree(struct TreeNode **root)
{
    if(data[index_for_data] == 0 || index_for_data >= data_length)
    {
        index_for_data++;
        *root =  NULL;
        return ;
    }
    *root = calloc(1, sizeof(struct TreeNode));
    if(*root == NULL)
    {
        printf("calloc faild! exit.........\n");
        exit(1);
    }
    (*root)->val = data[index_for_data];
    index_for_data++;
    createTree(&((*root)->left));
    createTree(&((*root)->right));
    return ;
}

void travers_first(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\n", root->val);
    travers_first(root->left);
    travers_first(root->right);
    return;
}

void travers_middle(struct TreeNode * root)
{
    if(root == NULL)
        return;
    travers_middle(root->left);
    printf("%d\n", root->val);
    travers_middle(root->right);
    return;
}

void travers_last(struct TreeNode * root)
{
    if(root == NULL)
        return;
    travers_last(root->left);
    travers_last(root->right);
    printf("%d\n", root->val);
    return;
}

struct TreeNode * tmp;
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return NULL;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main()
{
    struct TreeNode * root1;
    createTree(&root1);
    travers_first(root1);
    invertTree(root1);
    printf("=========================\n");
    travers_first(root1);
    return 0;
}
