// Copyright 2022 Gordeev Viktor

#ifndef MODULES_GORDEEV_AVL_TREE_INCLUDE_AVLTREE_H_
#define MODULES_GORDEEV_AVL_TREE_INCLUDE_AVLTREE_H_

#include <iostream>

class AVLTree {
public:
    struct node // struct to image tree knots and root
    {
        node() {
            left = right = nullptr;
            height = 1;
        }

        int key;
        unsigned char height;
        node *left;
        node *right;

        explicit node(int k) {
            key = k;
            left = right = nullptr;
            height = 1;
        }
    };

    AVLTree() = default;;

    unsigned char height(node *p);

    int bfactor(node *p);

    void fixheight(node *p);

    node *rotateright(node *p);

    node *rotateleft(node *q);

    node *balance(node *p);

    node *insert(node *p, int k);

    node *findmin(node *p);

    node *removemin(node *p);

    node *remove(node *p, int k);
};

#endif //MODULES_GORDEEV_AVL_TREE_INCLUDE_AVLTREE_H_
