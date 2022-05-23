/*Dimas Prihady Setyawan NRP:5025211184*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

typedef struct bstnode_t {
    int data;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_tree;
    unsigned int _size;
} BST;

/* Utility Function */

BSTNode*__bst__buatNode(int value)
{
    BSTNode *baruNode = (BSTNode*) malloc(sizeof(BSTNode));
    baruNode->data = value;
    baruNode->left = baruNode->right = NULL;
    return baruNode;
}

BSTNode* __bst__masuk(BSTNode *tree, int value) {
    if (tree == NULL)
        return __bst__buatNode(value);

    if (value < tree->data)
        tree->left = __bst__masuk(tree->left, value);
    else if (value > tree->data)
        tree->right = __bst__masuk(tree->right, value);

    return tree;
}

BSTNode* __bst__cari(BSTNode *tree, int value) {
    while (tree != NULL) {
        if (value < tree->data)
            tree = tree->left;
        else if (value > tree->data)
            tree = tree->right;
        else
            return tree;
    }
    return tree;
}

void _preOrder(BSTNode*tree)
{
    if (tree!=NULL)
    {
        printf("%d ", tree->data);
        _preOrder(tree->left);
        _preOrder(tree->right);
    }
}

void _inOrder(BSTNode*tree)
{
    if (tree!=NULL)
    {
        _inOrder(tree->left);
        printf("%d ", tree->data);
        _inOrder(tree->right);
    }
}

void _postOrder(BSTNode*tree)
{
    if (tree!=NULL)
    {
        _postOrder(tree->left);
        _postOrder(tree->right);
        printf("%d ", tree->data);
    }
}

/*Primary Function*/

void init(BST *bst) {
    bst->_tree = NULL;
    bst->_size = 0u;
}

int isEmpty(BSTNode*tree)
{
    if (tree == NULL) return 1;
    else return 0;
}

bool bst_cari(BST *bst, int value) {
    BSTNode *temp = __bst__cari(bst->_tree, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void bst_masuk(BST *bst, int value) {
    if (!bst_cari(bst, value)) {
        bst->_tree = __bst__masuk(bst->_tree, value);
        bst->_size++;
    }
}

void bst_preOrder(BST *bst) {
    _preOrder(bst->_tree);
}
void bst_inOrder(BST *bst) {
    _inOrder(bst->_tree);
}
void bst_postOrder(BST *bst) {
    _postOrder(bst->_tree);
}

int main()
{
    BST input;
    init(&input);

    int i,j,k;
    printf("Berapa input yang akan dimasukan: ");
    scanf("%d", &j);
    printf("Angka yang dimasukan: ");
    for (i = 0;i < j;i++)
    {
        scanf("%d", &k);
        bst_masuk(&input, k);
    }
    printf("Dalam bentuk pre-order: ");
    bst_preOrder(&input);
    printf("\n");
    printf("Dalam bentuk in-order: ");
    bst_inOrder(&input);
    printf("\n");
    printf("Dalam bentuk post-order: ");
    bst_postOrder(&input);
    return 0;
}

//Test: 5 2 1 4 3 6 7



