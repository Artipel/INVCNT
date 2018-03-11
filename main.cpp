#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    /*long long t, n, v;
    cin>>t;

    for(t; t>0; --t){
        Tree *tree = new Tree();
        cin>>n;
        for(n; n > 0; --n){
            scanf("%d",&v)!=EOF;
            tree->addNode(v);
        }
        cout<<tree->getInversions()<<endl;
        delete tree;
    }*/
    Tree *tree = new Tree();
    for(long long l = 0; l < 200000; ++l){
        tree->addNode(l%20000);
    }
    cout<<tree->getInversions();

    return 0;
}