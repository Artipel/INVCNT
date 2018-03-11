//
// Created by Arti on 2018-03-10.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H


#include "Node.h"

class Tree {

private:
    Node * root;
    unsigned long long inversions = 0;
    bool raw;

public:
    Tree(){
        raw = true;
        root = nullptr;
    }

    Tree(long long v){
        root = new Node(v);
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
    }

    void addNode(long long v){
        if(raw) {
            raw = false;
            root = new Node(v);
            root->parent = nullptr;
            root->left = nullptr;
            root->right = nullptr;
            return;
        }
        Node * temp = root;
        while(1)
        {
            if(v > temp->value) {
                ++temp->ancestors;
                if(temp->right != nullptr)
                    temp = temp->right;
                else {
                    temp->right = new Node(v);
                    temp->right->parent = temp;
                    return;
                }
            }
            else if(v == temp->value)
            {
                ++(temp->count);
                if(temp->right != nullptr)
                    inversions+=(temp->right->ancestors + temp->right->count);
                return;
            }
            else if(v < temp->value) {
                inversions+=(temp->ancestors + temp->count);
                ++(temp->ancestors);
                if (temp->left != nullptr) {
                    temp = temp->left;
                    inversions -= (temp->ancestors + temp->count);
                }
                else {
                    temp->left = new Node(v);
                    temp->left->parent = temp;
                    return;
                }
            }
        }
    }

    int getInversions(){
        return inversions;
    }

    void eraseAll(Node * n){
        if(n->left != nullptr)
            eraseAll(n->left);
        if(n->right != nullptr)
            eraseAll(n->right);
        delete n;
    }

    ~Tree(){
        eraseAll(root);
    }

};


#endif //BINARYTREE_TREE_H
