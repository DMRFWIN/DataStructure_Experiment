#include <iostream>
#include <vector>
#include "BiTree.h"

using namespace std;


void HuffmanCode();

int main() {
    HuffmanCode();
    return 0;
}

void HuffmanCode() {
    int n = 0;
    cout << "请输入点的个数：" << endl;
    cin >> n;

    cout << "请输入点的编号和权值：" << endl;

    vector<BiNode> vex;

    BiTree biTree;
    InitBitree(biTree);

    biTree->parent = NULL;
    biTree->rchild = NULL;
    biTree->lchild = NULL;
    biTree->v = 0;
    biTree->c = NULL;

    Vex v;
    for (int i = 0; i < n; ++i) {
        cin >> v.a >> v.v;
        BiNode b;
        b.c = v.a;
        b.v = v.v;
        vex.push_back(b);
    }

    BiNode bv;
    for (int j = 0; j < vex.size() - 1; ++j) {
        for (int i = j + 1; i < vex.size(); ++i) {
            if (vex[j].v > vex[i].v) {
                bv.c = vex[j].c;
                bv.v = vex[j].v;

                vex[j].c = vex[i].c;
                vex[j].v = vex[i].v;


                vex[i].c = bv.c;
                vex[i].v = bv.v;

            }
        }
    }


    while (vex.size() != 1) {
        BiNode *l = new BiNode();
        BiNode *r = new BiNode();

        l->c = vex[0].c;
        l->v = vex[0].v;


        r->c = vex[1].c;
        r->v = vex[1].v;
        vex.pop_back();
        vex.pop_back();

        BiNode *t = new BiNode();
        t->v = l->v + r->v;


        t->lchild = l;
        t->rchild = r;
        l->parent = t;
        r->parent = t;

        t->flag = true;
        vex.push_back(*t);

        if (l->flag) {
            if (biTree->rchild == l) {
                biTree->rchild = t;
            }
            if (biTree->lchild == l) {
                biTree->lchild = t;
            }
        }


        if (r->flag) {
            if (biTree->rchild == r) {
                biTree->rchild = t;
            }
            if (biTree->lchild == r) {
                biTree->lchild = t;
            }
        }

        if (biTree->lchild->v > biTree->rchild->v) {
            BiNode *b = biTree->lchild;
            biTree->lchild = biTree->rchild;
            biTree->rchild = b;
        }

        for (int j = 0; j < vex.size() - 1; ++j) {
            for (int i = j + 1; i < vex.size(); ++i) {
                if (vex[j].v < vex[i].v) {
                    bv.c = vex[j].c;
                    bv.v = vex[j].v;

                    vex[j].c = vex[i].c;
                    vex[j].v = vex[i].v;


                    vex[i].c = bv.c;
                    vex[i].v = v.v;

                }
            }
        }

    }

    PreOrderTraverse(&vex.front(), "0");
    // DestroyBiTree(&vex.front());

}

