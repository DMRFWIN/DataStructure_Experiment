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


void Insertfirstchild(BiTree &biNode, BiNode *biNode1) {
    biNode->firstchild = biNode1;
}

void Insertnextsibling(BiTree &biNode, BiNode *biNode1) {
    biNode->nextsibling = biNode1;
}

void Traverse(BiTree biTree) {

    queue<BiNode> sib;

    int n = 1;

    if (biTree == NULL) {
        return;
    }

    sib.push(*biTree);
    bool flag = true;

    cout << endl << "第" << n << "层:" << endl;
    n++;
    while (!sib.empty()) {
        BiNode *node = &sib.front();
        sib.pop();


        int flag = 0;
        while (node) {
            if (sib.empty() && flag == 0) {

                flag = 1;
            }
            cout << node->data << " ";
            if (node->firstchild) {
                sib.push(*node->firstchild);
            }
            node = node->nextsibling;


        }
        if (flag == 1&&!sib.empty()) {

            cout << endl << "第" << n << "层:" << endl;
        }
        n++;

    }


}

#endif //INC_1_BITREE_H

