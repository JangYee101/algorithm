//二叉树

#include <stdio.h>
#include <stdlib.h>

int data[100]={1,2,3,0,0,4,0,0,5,6,0,0,7,0,0}, data_length=15, index_for_data=0;

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

int maxDepth(struct TreeNode * root)
{
    int left_num, right_num;
    if(root == NULL)
    {
        return 0;
    }
    left_num = maxDepth(root->left) + 1;
    right_num = maxDepth(root->right) + 1;
    return (left_num > right_num)?left_num:right_num;
}

int main()
{
    struct TreeNode * root;
    createTree(&root);
    printf("%d\n", maxDepth(root));
    return 0;
}
