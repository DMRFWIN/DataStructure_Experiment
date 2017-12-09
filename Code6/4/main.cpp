#include <iostream>

using namespace std;

#include "BiTree.h"

int main() {
    BiTree biTree = new BiNode();
    biTree->data='r';


    BiNode *a = new BiNode();
    a->data = 'a';

    BiNode *b = new BiNode();
    b->data = 'b';

    BiNode *c = new BiNode();
    c->data = 'c';

    BiNode *d = new BiNode();
    d->data = 'd';

    BiNode *e = new BiNode();
    e->data = 'e';

    BiNode *f = new BiNode();
    f->data = 'f';

    BiNode *g = new BiNode();
    g->data = 'g';

    BiNode *h = new BiNode();
    h->data = 'h';

    BiNode *k = new BiNode();
    k->data = 'k';

    Insertfirstchild(biTree, a);
    Insertnextsibling(biTree, NULL);

    Insertfirstchild(a, d);
    Insertnextsibling(a, b);

    Insertfirstchild(b, NULL);
    Insertnextsibling(b, c);

    Insertfirstchild(c, f);
    Insertnextsibling(c, NULL);

    Insertfirstchild(d, NULL);
    Insertnextsibling(d, e);

    Insertfirstchild(e, NULL);
    Insertnextsibling(e, NULL);

    Insertfirstchild(f, g);
    Insertnextsibling(f, NULL);

    Insertfirstchild(g, NULL);
    Insertnextsibling(g, h);


    Insertfirstchild(h, NULL);
    Insertnextsibling(h, k);


    Insertfirstchild(k, NULL);
    Insertnextsibling(k, NULL);

    Traverse(biTree);



    return 0;
}