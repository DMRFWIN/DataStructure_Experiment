//
// Created by dmrf on 17-11-20.
//

#ifndef INC_1_BITREE_H
#define INC_1_BITREE_H
#define TElemType int

#include <queue>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;


typedef struct BiNode {
    struct BiNode *firstchild;
    struct BiNode *nextsibling;
    char data;
} BiNode, *BiTree;


int Depth(BiTree biTree);

void LevelOrderTraversePrint(BiTree biTree, int depth);

void InitBitree(BiTree &biTree) {
    biTree = new BiNode();
    biTree->firstchild = NULL;
    biTree->nextsibling = NULL;
    biTree->data = 0;
    cout << "初始化成功～" << endl;
}


void Destroy(BiTree &biTree) {
    if (biTree == NULL) {
        return;
    }
    BiNode *n = biTree;
    BiNode *c = biTree->firstchild;
    BiNode *s = biTree->nextsibling;


    free(biTree);

    if (c != NULL) {
        Destroy(c);
    }

    if (s != NULL) {
        Destroy(s);
    }
    cout << "销毁成功～" << endl;
}

void Insertfirstchild(BiTree &biNode, BiNode *biNode1) {
    cout << "插入firstchild成功～" << endl;
    biNode->firstchild = biNode1;
}

void Insertnextsibling(BiTree &biNode, BiNode *biNode1) {
    cout << "插入nextsibling成功～" << endl;
    biNode->nextsibling = biNode1;
}

void Traverse(BiTree biTree) {

    cout << "层次遍历：" << endl;
    queue<BiNode> sib;

    if (biTree == NULL) {
        return;
    }

    sib.push(*biTree);

    while (!sib.empty()) {
        BiNode *node = &sib.front();
        sib.pop();
        cout << node->data << " ";
        node = node->firstchild;
        if (node != NULL) {
            sib.push(*node);

            BiNode *node2 = node->nextsibling;
            while (node2 != NULL) {
                sib.push(*node2);
                node2 = node2->nextsibling;
            }
        }

    }


}

#endif //INC_1_BITREE_H

