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

int Depth(BiTree biTree);

void LevelOrderTraversePrint(BiTree biTree, int depth);

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

   // cout << "销毁" << biTree->data << "成功～" << endl;
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



void LevelOrderTraverse(BiTree biTree) {
    for (int i = 1; i <= Depth(biTree); ++i) {
        LevelOrderTraversePrint(biTree, i);
    }


}

void LevelOrderTraversePrint(BiTree biTree, int depth) {
    if (biTree == NULL) {
        cout << "该树为空，无法遍历！" << endl;
    }
    if (depth == 1) {
        cout << biTree->data << " ";
        return;
    } else {
        if (biTree->lchild != NULL) {
            LevelOrderTraversePrint(biTree->lchild, depth - 1);
        }


        if (biTree->rchild != NULL) {
            LevelOrderTraversePrint(biTree->rchild, depth - 1);
        }
    }


}


void InOrderTraverse2(BiTree biTree) {
    if (biTree == NULL) {
        cout << "该树为空，无法遍历！" << endl;
    }

    stack<BiNode *> stack1;
    BiNode *biNode = biTree;

    while (biNode != NULL || !stack1.empty()) {
        if (biNode != NULL) {
            stack1.push(biNode);
            biNode = biNode->lchild;
        } else {
            biNode = stack1.top();
            stack1.pop();
            cout << biNode->data << " ";
            biNode = biNode->rchild;
        }
    }
}


void PostOrderTraverse2(BiTree biTree) {
    if (biTree == NULL) {
        cout << "该树为空，无法遍历！" << endl;
    }

    stack<BiNode *> s;
    BiNode *cur;                      //当前结点
    BiNode *pre = NULL;                 //前一次访问的结点
    s.push(biTree);

    while (!s.empty()) {
        cur = s.top();
        if ((cur->lchild == NULL && cur->rchild == NULL) ||
            (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            cout << cur->data << " ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过
            s.pop();
            pre = cur;
        } else {
            if (cur->rchild != NULL)
                s.push(cur->rchild);
            if (cur->lchild != NULL)
                s.push(cur->lchild);
        }
    }
}


void LevelOrderTraverse2(BiTree biTree) {
    if (biTree == NULL) {
        cout << "该树为空，无法遍历！" << endl;
    }

    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode=biTree;

    while (biNode != NULL && !queue1.empty()) {

        biNode = queue1.front();
        queue1.pop();
        cout << biNode->data << " ";

        if (biNode->lchild != NULL) {
            queue1.push(biNode->lchild);
        }

        if (biNode->rchild != NULL) {
            queue1.push(biNode->rchild);
        }

    }

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

int Depth(BiTree biTree) {

    if (biTree == NULL) {
        return 0;
    }

    int u = Depth(biTree->lchild);
    int v = Depth(biTree->rchild);

    return u > v ? u + 1 : v + 1;
}


#endif //INC_1_BITREE_H

