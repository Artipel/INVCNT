//
// Created by Arti on 2018-03-10.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H


class Node {

public:
    Node *parent, *left, *right;
    long long ancestors, count, value;

    Node(int v, int c = 1, int a = 0) : value(v), count(c), ancestors(a){
        left = nullptr;
        right = nullptr;
    }
};


#endif //BINARYTREE_NODE_H
