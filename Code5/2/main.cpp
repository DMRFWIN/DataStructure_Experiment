#include <iostream>
#include "BiTree.h"

using namespace std;

int main() {

    BiTree biTree;

    InitBitree(biTree);

    biTree->data = 1;

    BiTree c;
    InitBitree(c);
    c->data = 4;

    InstertChild(biTree, biTree, 1, c);

    BiTree d;
    InitBitree(d);
    d->data = 3;

    InstertChild(biTree, biTree, 0, d);

    BiTree e;
    InitBitree(e);
    e->data = 2;
    InstertChild(biTree, d, 0, e);

    BiTree f;
    InitBitree(f);
    f->data = 9;
    InstertChild(biTree, d, 1, f);


    BiTree h;
    InitBitree(h);
    h->data = 8;
    InstertChild(biTree, e, 0, h);

    BiTree g;
    InitBitree(g);
    g->data = 10;
    InstertChild(biTree, c, 0, g);

    BiTree k;
    InitBitree(k);
    k->data = 11;
    InstertChild(biTree, g, 1, k);

    cout << "先序遍历:" << endl;
    cout << endl;
    PreOrderTraverse2(biTree);
    cout << endl;

    cout << "中序遍历：" << endl;
    cout << endl;
    InOrderTraverse2(biTree);
    cout << endl;

    cout << "后序遍历：" << endl;
    cout << endl;
    PostOrderTraverse2(biTree);
    cout << endl;
    cout << "层次遍历：" << endl;
    LevelOrderTraverse(biTree);

    cout << endl;
    LevelOrderTraverse2(biTree);
    cout << endl;

    return 0;
}