#include <iostream>
#include "BiTree.h"

using namespace std;

int main() {

    BiTree biTree;

    InitBitree(biTree);
    BiTreeEmpty(biTree);

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
    PreOrderTraverse(biTree);
    cout << endl;
    PreOrderTraverse2(biTree);
    cout << endl;

    cout << "中序遍历：" << endl;
    InOrderTraverse(biTree);
    cout << endl;
    InOrderTraverse2(biTree);
    cout << endl;

    cout << "后序遍历：" << endl;
    PostOrderTraverse(biTree);
    cout << endl;
    PostOrderTraverse2(biTree);
    cout << endl;
    cout << "层次遍历：" << endl;
    LevelOrderTraverse(biTree);

    cout << endl;
    LevelOrderTraverse2(biTree);
    cout << endl;

    int depth = Depth(biTree);
    cout << "深度：" << depth << endl;

    IsCompteteTree(biTree);




    BiTreeEmpty(biTree);

    BiNode biNode = Root(biTree);
    cout << "根节点的数值：" << biNode.data << endl;

    BiNode biNode2 = Value(biTree, g);
    cout << "g节点的数值为：" << biNode2.data << endl;

    BiNode biNode3 = Parent(biTree, g);
    cout << "g的双亲节点的值为：" << biNode3.data << endl;


    BiNode *biNode7 = LeftChild(biTree, g);
    if (biNode7 == NULL) {
        cout << "g的左孩子的值为null" << endl;
    } else {
        cout << "g的左孩子的值为：" << biNode7->data << endl;
    }

    BiNode *biNode4 = RightChild(biTree, g);
    if (biNode4 == NULL) {
        cout << "g的右孩子的值为null" << endl;
    } else {
        cout << "g的右孩子的值为：" << biNode4->data << endl;
    }

    BiNode *biNode5 = LeftSibling(biTree, f);
    if (biNode5 == NULL) {
        cout << "f的左兄弟的值为null" << endl;
    } else {
        cout << "f的左兄弟的值为：" << biNode5->data << endl;
    }

    BiNode *biNode6 = RightChild(biTree, f);
    if (biNode6== NULL) {
        cout << "f的右兄弟的值为null" << endl;
    } else {
        cout << "f的右兄弟的值为：" << biNode6->data << endl;
    }


    PreOrderTraverse(biTree);
    cout << endl;
    DeleteChild(biTree, g, 0);
    PreOrderTraverse(biTree);
    cout << endl;



    cout << "Assign之前遍历：" << endl;
    PreOrderTraverse(biTree);
    cout << endl;

    Assign(biTree, biTree, 6);

    cout << "Assign之后遍历：" << endl;
    PreOrderTraverse(biTree);
    cout << endl;

    cout << "清空之前遍历：" << endl;
    PreOrderTraverse(biTree);
    cout << endl;

    ClearBiTree(biTree);

    cout << "清空之后遍历：" << endl;
    PreOrderTraverse(biTree);
    cout << endl;

    DestroyBiTree(biTree);

    return 0;
}