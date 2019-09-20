//title num:617

#include <stdio.h>
#include <stdlib.h>

int data1[100]={1,3,5,0,0,0,2,0,0}, data_length=9;
int data2[100]={2,1,0,4,0,0,3,0,7,0,0}, data_length2=11;
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

struct TreeNode * mergeTrees(struct TreeNode * t1, struct TreeNode * t2)
{
    if(t1 == NULL)
    {
        return t2;
    }
    if(t2 == NULL)
    {
        return t1;
    }
    //struct TreeNode * T = calloc(1, sizeof(struct TreeNode));
    t1->val = t1->val + t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

int main()
{
    struct TreeNode * root1, *root2;
    createTree(&root1);
    //travers_first(root1);
    data = data2;
    data_length = data_length2;
    index_for_data=0;
    createTree(&root2);
    //travers_first(root2);
    struct TreeNode *T = mergeTrees(root1, root2);
    travers_first(T);
    return 0;
}
