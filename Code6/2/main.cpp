#include <iostream>
#include <vector>
#include "BiTree.h"

using namespace std;


void HuffmanCode();

void Select(BiNode *b, int i, int &s1, int &s2);

int main() {
    HuffmanCode();
    return 0;
}

void HuffmanCode() {
    int n = 0;
    cout << "请输入点的个数：" << endl;
    cin >> n;

    int m = 2 * n;

    BiNode *biNode = new BiNode[2 * n];


    cout << "请输入点的编号和权值：" << endl;


    for (int k = 1; k <= n; ++k) {
        biNode[k].lchild = NULL;
        biNode[k].rchild = NULL;
        biNode[k].parent = NULL;
        cin >> biNode[k].c >> biNode[k].v;
    }

    for (int i = n; i < m; ++i) {
        biNode[i].lchild = NULL;
        biNode[i].rchild = NULL;
        biNode[i].parent = NULL;
    }

    for (int j = n + 1; j <m; ++j) {
        int s1;
        int s2;
        Select(biNode, j, s1, s2);
        biNode[j].v = biNode[s1].v + biNode[s2].v;
        biNode[j].lchild = &biNode[s1];
        biNode[j].rchild = &biNode[s2];
        biNode[s1].parent = &biNode[j];
        biNode[s2].parent = &biNode[j];
    }

    PreOrderTraverse(&biNode[m-1], "");

    free(biNode);
}

void Select(BiNode *b, int i, int &s1, int &s2) {

    int m2, m1;

    m2 = 10000;
    m1 = m2;
    i--;
    while (i > 0) {
        if (b[i].v < m1 && b[i].parent == NULL) {
            m2 = m1;
            s2 = s1;
            m1 = b[i].v;
            s1 = i;
        }
        i--;

    }
}