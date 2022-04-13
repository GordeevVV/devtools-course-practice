// Copyright 2022 Gordeev Viktor

#include "include/AVLTree.h"

unsigned char AVLTree::height(node *p) {
    return p ? p->height : 0;
}

int AVLTree::bfactor(node *p) {
    return height(p->right) - height(p->left);
}

void AVLTree::fixheight(node *p) {
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

AVLTree::node *AVLTree::rotateright(node *p) {
    node *q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

AVLTree::node *AVLTree::rotateleft(node *q) {
    node *p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

AVLTree::node *AVLTree::balance(node *p) {
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}

AVLTree::node *AVLTree::insert(node *p, int k) {
    if (!p) return new node(k);
    if (k < p->key)
        p->left = insert(p->left, k);
    else
        p->right = insert(p->right, k);
    return balance(p);
}

AVLTree::node *AVLTree::findmin(node *p) {
    return p->left ? findmin(p->left) : p;
}

AVLTree::node *AVLTree::removemin(node *p) {
    if (p->left == 0)
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

AVLTree::node *AVLTree::remove(node *p, int k) {
    if (!p) return 0;
    if (k < p->key)
        p->left = remove(p->left, k);
    else if (k > p->key)
        p->right = remove(p->right, k);
    else //  k == p->key
    {
        node *q = p->left;
        node *r = p->right;
        delete p;
        if (!r) return q;
        node *min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}
