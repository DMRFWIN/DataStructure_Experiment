//
// Created by dmrf on 17-11-20.
//

#ifndef INC_1_BITREE_H
#define INC_1_BITREE_H

#include <queue>
#include <stack>
#include <iostream>

using namespace std;


typedef struct {
    struct BiNode *lchild;
    struct BiNode *rchild;
    BiNode *parent;
    int data;
} BiNode, *BiTree;

void InitBitree(BiTree &biTree) {
    biTree->lchild = NULL;
    biTree->rchild = NULL;
    biTree->parent = NULL;
    biTree->data = 0;
    cout << "初始化成功～" << endl;
}

void DestroyBiTree(BiTree biTree) {
    if (biTree->rchild != NULL) {
        DestroyBiTree(biTree->rchild);
    } else {
        free(biTree);
    }

    if (biTree->lchild != NULL) {
        DestroyBiTree(biTree->lchild);
    } else {
        free(biTree);
    }

    cout << "销毁成功～" << endl;
}


bool CreateBiTree(BiTree biTree) {
    biTree = new BiNode();
    biTree->rchild = NULL;
    biTree->rchild = NULL;
    biTree->data = NULL;
    biTree->parent = NULL;
    return true;
}


void ClearBiTree(BiTree biTree) {
    if (biTree->rchild != NULL) {
        ClearBiTree(biTree->rchild);
    } else {
        biTree->data = 0;

    }

    if (biTree->lchild != NULL) {
        ClearBiTree(biTree->lchild);
    } else {
        biTree->data = 0;
    }

    cout << "清空成功～" << endl;

}

bool BiTreeEmpty(BiTree biTree) {
    if (biTree != NULL) {
        if (biTree->lchild == NULL && biTree->rchild == NULL && biTree->data == NULL) {
            cout << "该数为空～" << endl;
            return true;
        } else {
            cout << "该数不为空～" << endl;
            return false;
        }
    } else {
        cout << "该树不存在，无法判空！" << endl;
    }

}

int BiTreeDepth(BiTree biTree) {
    if (biTree == NULL) {
        cout << "该树为空，无法求深度！" << endl;
    }

    int depth = 0;
    if (biTree->rchild != NULL) {
        depth += BiTreeDepth(biTree->rchild);
    }

    if (biTree->lchild != NULL) {
        depth += BiTreeDepth(biTree->lchild);
    }
    if (biTree->lchild == NULL && biTree->rchild == NULL) {
        depth = 1;
    }

    return depth;
}


BiNode Root(BiTree biTree) {
    if (biTree == NULL) {
        cout << "该树不存在！" << endl;
    }

    return *biTree;
}


BiNode Value(BiTree biTree, BiNode e) {

    queue<BiNode> queue1;
    queue1.push(*biTree);
    BiNode *biNode;
    *biNode = queue1.front();
    queue1.pop();
    cout << biNode->data << " ";


    while (biNode != NULL) {

        BiNode *biNode2 = reinterpret_cast<BiNode *>(biNode->lchild);
        if (biNode->lchild != NULL) {
            queue1.push(*biNode2);
        }

        if (biNode->rchild != NULL) {
            BiNode *biNode1 = reinterpret_cast<BiNode *>(biNode->rchild);
            queue1.push(*biNode1);
        }

        *biNode = queue1.front();
        queue1.pop();
        if (biNode->rchild == e.rchild && biNode->lchild == e.lchild && biNode->parent == e.parent) {
            return *biNode;
        }

    }

}


void Assign(BiTree biTree, BiNode &e, BiTree value) {
    queue<BiNode> queue1;
    queue1.push(*biTree);
    BiNode *biNode;
    *biNode = queue1.front();
    queue1.pop();
    cout << biNode->data << " ";


    while (biNode != NULL) {

        BiNode *biNode2 = reinterpret_cast<BiNode *>(biNode->lchild);
        if (biNode->lchild != NULL) {
            queue1.push(*biNode2);
        }

        if (biNode->rchild != NULL) {
            BiNode *biNode1 = reinterpret_cast<BiNode *>(biNode->rchild);
            queue1.push(*biNode1);
        }

        *biNode = queue1.front();
        queue1.pop();
        if (biNode->rchild == e.rchild && biNode->lchild == e.lchild && biNode->parent == e.parent) {
            biNode->data = e.data;
        }

    }
}

BiNode Parent(BiTree biTree, BiNode e) {
    queue<BiNode> queue1;
    queue1.push(*biTree);
    BiNode *biNode;
    *biNode = queue1.front();
    queue1.pop();
    cout << biNode->data << " ";


    while (biNode != NULL) {

        BiNode *biNode2 = reinterpret_cast<BiNode *>(biNode->lchild);
        if (biNode->lchild != NULL) {
            queue1.push(*biNode2);
        }

        if (biNode->rchild != NULL) {
            BiNode *biNode1 = reinterpret_cast<BiNode *>(biNode->rchild);
            queue1.push(*biNode1);
        }

        *biNode = queue1.front();
        queue1.pop();
        if (biNode->rchild == e.rchild && biNode->lchild == e.lchild && biNode->parent == e.parent) {
            return *biNode->parent;
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
            biNode=biNode->lchild;
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
    BiNode *biNode;

    while (biNode != NULL&&!queue1.empty()) {

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

#endif //INC_1_BITREE_H
