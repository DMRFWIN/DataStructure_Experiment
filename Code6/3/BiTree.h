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

