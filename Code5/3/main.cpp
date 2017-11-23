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

    PreOrderTraverse2(biTree);
    cout << endl;


    Delete(biTree, c);



    PreOrderTraverse2(biTree);

    cout << endl;


    return 0;
}