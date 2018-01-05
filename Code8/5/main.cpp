#include <iostream>
#include "BiTree.h"

using namespace std;

bool SearchX(BiTree biTree, int x);

int main() {

    BiTree biTree;

    InitBitree(biTree);

    biTree->data = 20;

    BiTree c;
    InitBitree(c);
    c->data = 10;

    InstertChild(biTree, biTree, 0, c);

    BiTree d;
    InitBitree(d);
    d->data = 30;

    InstertChild(biTree, biTree, 1, d);

    BiTree e;
    InitBitree(e);
    e->data = 25;
    InstertChild(biTree, d, 0, e);

    BiTree f;
    InitBitree(f);
    f->data = 35;
    InstertChild(biTree, d, 1, f);


    BiTree h;
    InitBitree(h);
    h->data = 5;
    InstertChild(biTree, c, 0, h);

    BiTree g;
    InitBitree(g);
    g->data = 15;
    InstertChild(biTree, c, 1, g);

    BiTree k;
    InitBitree(k);
    k->data = 1;
    InstertChild(biTree, h, 0, k);


    BiTree k2;
    InitBitree(k2);
    k2->data = 6;
    InstertChild(biTree, h, 1, k2);

    BiTree k3;
    InitBitree(k3);
    k3->data = 8;
    InstertChild(biTree, g, 0, k3);

    cout << "层次遍历：" << endl;
    LevelOrderTraverse(biTree);

    cout << endl << "请输入要查找的数：";
    int x;
    cin >> x;

    SearchX(biTree, x);
    return 0;
}

bool SearchX(BiTree biTree, int x) {
    if (x == biTree->data) {
        cout << "成功找到节点" << x << endl;
        return true;
    } else {

        bool flag_l, flag_r;
        flag_l = flag_r = false;


        if (x > biTree->data) {
            if (biTree->rchild == NULL) {
                return false;
            } else {
                flag_r = SearchX(biTree->rchild, x);
                if (flag_r) {
                    return true;
                }
            }
        } else {
            if (biTree->lchild == NULL) {
                return false;
            } else {
                flag_l = SearchX(biTree->lchild, x);
                if (flag_l) {
                    return true;
                }
            }
        }

        if (biTree->parent == NULL) {
            cout << "距离" << x << "最近的一个节点是" << biTree->data << endl;
        } else {
            cout << "距离" << x << "最近的两个节点是" << biTree->parent->data << " " << biTree->data << endl;
        }
        return true;
    }
}