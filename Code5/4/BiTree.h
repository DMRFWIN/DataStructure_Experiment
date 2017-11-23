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
    struct BiNode *lchild;
    struct BiNode *rchild;
    struct BiNode *parent;
    int data;
} BiNode, *BiTree;



void InitBitree(BiTree &biTree) {
    biTree = new BiNode();
    biTree->lchild = NULL;
    biTree->rchild = NULL;
    biTree->parent = NULL;
    biTree->data = 0;
   // cout << "初始化成功～" << endl;
}

void DestroyBiTree(BiTree biTree) {

    if (biTree == NULL) {
        return;
    }
    if (biTree->lchild != NULL) {
        DestroyBiTree(biTree->lchild);
    }

    if (biTree->rchild != NULL) {
        DestroyBiTree(biTree->rchild);
    }

    //cout << "销毁" << biTree->data << "成功～" << endl;
    free(biTree);
}


bool InstertChild(BiTree biTree, BiNode *e, int LR, BiTree c) {
    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    if (biNode == e) {

        if (LR == 1) {//插入右边
            BiNode *q = biNode->rchild;
            biNode->rchild = c;
            c->parent = biNode;
            c->rchild = q;
        } else {

            BiNode *q = biNode->lchild;
            biNode->lchild = c;
            c->parent = biNode;
            c->lchild = q;
        }

        return true;
    }


    while (biNode != NULL) {

        if (biNode->lchild != NULL) {
            queue1.push(biNode->lchild);
        }

        if (biNode->rchild != NULL) {
            queue1.push(biNode->rchild);
        }

        biNode = queue1.front();
        queue1.pop();
        if (biNode == e) {
            if (LR == 1) {//插入右边
                BiNode *q = biNode->rchild;
                biNode->rchild = c;
                c->parent = biNode;
                c->rchild = q;
            } else {

                BiNode *q = biNode->lchild;
                biNode->lchild = c;
                c->parent = biNode;
                c->lchild = q;
            }
            return true;
        }
    }

    cout << "没找到节点p" << endl;
    return false;


}



bool DeleteChild(BiTree biTree, BiNode *e, int LR) {
    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    if (biNode == e) {

        if (LR == 1) {//删除右边
            BiNode *q = biNode->rchild;
            DestroyBiTree(q);
            biNode->rchild = NULL;
        } else {

            BiNode *q = biNode->lchild;
            DestroyBiTree(q);
            biNode->lchild = NULL;
        }

        return true;
    }


    while (biNode != NULL) {

        if (biNode->lchild != NULL) {
            queue1.push(biNode->lchild);
        }

        if (biNode->rchild != NULL) {
            queue1.push(biNode->rchild);
        }

        biNode = queue1.front();
        queue1.pop();
        if (biNode == e) {
            if (LR == 1) {//插入右边
                BiNode *q = biNode->rchild;
                DestroyBiTree(q);
                biNode->rchild = NULL;
            } else {
                BiNode *q = biNode->lchild;
                DestroyBiTree(q);
                biNode->lchild = NULL;
            }
            return true;
        }
    }

    cout << "没找到节点p" << endl;
    return false;


}


void PreOrderTraverse2(BiTree biTree) {//先序遍历
    stack<BiNode *> stack1;
    BiNode *biNode = biTree;

    stack1.push(biNode);


    while (biNode != NULL && !stack1.empty()) {
        biNode = stack1.top();
        stack1.pop();
        cout << biNode->data << " ";

        if (biNode->rchild != NULL) {
            stack1.push(biNode->rchild);
        }

        if (biNode->lchild != NULL) {
            stack1.push(biNode->lchild);
        }


    }


}



bool IsCompteteTree(BiTree biTree) {
    queue<BiNode *> q;
    BiNode *biNode;
    // 进行广度优先遍历（层次遍历），并把NULL节点也放入队列
    q.push(biTree);


    while ((biNode = q.front()) != NULL) {
        q.pop();
        q.push(biNode->lchild);
        q.push(biNode->rchild);
    }

    // 判断是否还有未被访问到的节点
    while (!q.empty()) {
        biNode = q.front();
        q.pop();

        // 有未访问到的的非NULL节点，则树存在空洞，为非完全二叉树
        if (NULL != biNode) {
            cout << "不是完全二叉树～" << endl;
            return false;
        }
    }
    cout << "是完全二叉树～" << endl;
    return true;
}

#endif //INC_1_BITREE_H

