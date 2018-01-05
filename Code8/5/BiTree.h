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
    cout << "初始化成功～" << endl;
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

    cout << "销毁" << biTree->data << "成功～" << endl;
    free(biTree);
}


bool CreateBiTree(BiTree biTree) {
/*
 * 未测试...
 */
    biTree = new BiNode();
    biTree->rchild = NULL;
    biTree->rchild = NULL;
    biTree->data = NULL;
    biTree->parent = NULL;
    return true;
}


void ClearBiTree(BiTree biTree) {
    // cout << "清空" << biTree->data << "成功～" << endl;

    if (biTree->rchild != NULL) {
        ClearBiTree(biTree->rchild);
    }

    if (biTree->lchild != NULL) {
        ClearBiTree(biTree->lchild);
    }
    biTree->data = 0;


}

bool BiTreeEmpty(BiTree biTree) {
    if (biTree != NULL) {
        if (biTree->lchild == NULL && biTree->rchild == NULL && biTree->data == NULL) {
            cout << "该树为空～" << endl;
            return true;
        } else {
            cout << "该树不为空～" << endl;
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


BiNode Value(BiTree biTree, BiNode *e) {


    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    if (biNode == e) {
        return *biNode;
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
            return *biNode;
        }
    }


}


void Assign(BiTree biTree, BiNode *e, int value) {

    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    if (biNode == e) {
        biNode->data = value;
        return;
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
            BiNode *q = reinterpret_cast<BiNode *>(biNode->lchild);
            DestroyBiTree(q);
            biNode->lchild = NULL;
            biNode->data = value;
            return;
        }
    }

    cout << "没找到节点e" << endl;
}

BiNode Parent(BiTree biTree, BiNode *e) {
    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    /* if (biNode == e) {
         return NULL;
     }*/


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
            return *biNode->parent;
        }
    }

    cout << "没找到节点e" << endl;
//    return NULL;

}


BiNode *LeftChild(BiTree biTree, BiNode *e) {
    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    if (biNode == e) {
        return biNode->lchild;
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
            return biNode->lchild;
        }
    }

    cout << "没找到节点e" << endl;
    return NULL;

}


BiNode *RightChild(BiTree biTree, BiNode *e) {
    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    if (biNode == e) {
        return biNode->rchild;
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
            return biNode->rchild;
        }
    }

    cout << "没找到节点e" << endl;
    return NULL;

}


BiNode *RightSibling(BiTree biTree, BiNode *e) {
    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    if (biNode == e) {
        cout << "根节点没有兄弟" << endl;
        return NULL;
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
            BiNode *p = biNode->parent;
            if (p->rchild != NULL && p->lchild == e) {
                return p->rchild;
            } else {
                cout << "右兄弟为空！" << endl;
                return NULL;
            }
        }
    }

    cout << "没找到节点e" << endl;
    return NULL;

}


BiNode *LeftSibling(BiTree biTree, BiNode *e) {
    queue<BiNode *> queue1;
    queue1.push(biTree);
    BiNode *biNode;
    biNode = queue1.front();
    queue1.pop();
    if (biNode == e) {
        cout << "根节点没有兄弟" << endl;
        return NULL;
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
            BiNode *p = biNode->parent;
            if (p->lchild != NULL && p->rchild == e) {
                return p->lchild;
            } else {
                cout << "左兄弟为空！" << endl;
                return NULL;
            }
        }
    }

    cout << "没找到节点e" << endl;
    return NULL;

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

void PreOrderTraverse(BiTree biTree) {//先序遍历
    if (biTree == NULL) {
        cout << "该树为空，无法遍历！" << endl;
    }
    cout << biTree->data << " ";
    if (biTree->lchild != NULL) {
        PreOrderTraverse(biTree->lchild);
    }

    if (biTree->rchild != NULL) {
        PreOrderTraverse(biTree->rchild);
    }

}

void InOrderTraverse(BiTree biTree) {
    if (biTree == NULL) {
        cout << "该树为空，无法遍历！" << endl;
    }

    if (biTree->lchild != NULL) {
        InOrderTraverse(biTree->lchild);
    }
    cout << biTree->data << " ";
    if (biTree->rchild != NULL) {
        InOrderTraverse(biTree->rchild);
    }
}


void PostOrderTraverse(BiTree biTree) {
    if (biTree == NULL) {
        cout << "该树为空，无法遍历！" << endl;
    }

    if (biTree->lchild != NULL) {
        PostOrderTraverse(biTree->lchild);
    }
    if (biTree->rchild != NULL) {
        PostOrderTraverse(biTree->rchild);
    }
    cout << biTree->data << " ";

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
    BiNode *biNode;

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


int GetLeveNum(BiTree biTree, int depth) {
    if (biTree == NULL) {
        cout << "该树为空，无法遍历！" << endl;
    }
    int num = 0;
    if (depth == 1) {

        return 1;
    } else {
        if (biTree->lchild != NULL) {
            num += GetLeveNum(biTree->lchild, depth - 1);
        }


        if (biTree->rchild != NULL) {
            num += GetLeveNum(biTree->rchild, depth - 1);
        }
    }
    return num;

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

