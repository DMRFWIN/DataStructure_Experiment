//
// Created by dmrf on 17-10-25.
//

#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;
#ifndef ADTLIST_ADT_LIST_SEQUENCE_H
#define ADTLIST_ADT_LIST_SEQUENCE_H
#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量
#define LISTINCREMENT 10//线性表存储空间的分配增量
typedef struct {
    struct LNode *head;//头指针
    int length;//当前长度
} SqList;

typedef struct LNode {
    int date;
    struct LNode *next;
} LNode;

bool InitList(SqList &L) {
    L.head = new LNode();
    L.length = 0;
    cout<<"初始化成功！"<<endl;
    return true;
}


bool DestroyList(SqList &L) {
    LNode *p = L.head->next;
    LNode *q=p->next;
    while (p != NULL) {
        free(p);
        p = q;
        q=p->next;
    }
    free(L.head);//销毁头结点
    L.head = NULL;
    L.length = 0;
    cout<<"销毁成功"<<endl;
    return true;
}


bool ClearList(SqList &L) {
    LNode *p = L.head->next;
    while (p != NULL) {
        free(p);
        p = p->next;
    }
    L.head->next = NULL;
    L.length = 0;
    return true;
}


bool ListEmpty(SqList L) {
    if (L.head == NULL) {
        cout << "链表不存在！" << endl;
    }
    if (L.length==0){
        cout<<"链表为空"<<endl;
    } else{
        cout<<"链表不为空"<<endl;
    }
    return L.length == 0;
}


int ListLength(SqList L) {
    return L.length;
}


bool GetElem(SqList L, int i, int &e) {//将下表为i的元素赋值给e
    if (ListEmpty(L)) {
        cout << "链表为空！" << endl;
    }
    if (i < 1 || i > L.length) {
        cout << "所要获取的数据下标不合法！" << endl;
        return false;
    }
    LNode *p = L.head;
    while (i != 0) {
        p = p->next;
        i--;
    }
    e = p->date;
    return true;
}

int LocateElem(SqList L, int e, bool compare(int a, int b)) {//返回第一个与e符合compare的元素的位序
    if (ListEmpty(L)) {
        cout << "链表为空！" << endl;
        return -1;
    }

    LNode *p = L.head->next;
    for (int i = 0; i < L.length; ++i) {
        if (compare(e, p->date)) {
            cout << "找到符合条件的元素,位序为：" << i+1 << endl;
            return i;
        }
        p = p->next;
    }
    cout << "没有找到符合条件的元素" << endl;
    return -1;
}

bool PriorElem(SqList L, int cur_e, int &pre_e) {//求前驱
    if (ListEmpty(L)) {
        cout << "链表为空！" << endl;
        return false;
    }

    LNode *p = L.head;
    LNode *q = L.head->next;
    if (cur_e == q->date) {
        cout << cur_e << "为首元素，无前驱" << endl;
        return false;
    }

    p = q;
    q = q->next;

    while (q != NULL) {
        if (q->date == cur_e) {
            pre_e = p->date;
            return true;
        }

        p = q;
        q = q->next;
    }

    cout << cur_e << "无前驱" << endl;
    return false;

}

bool NextElem(SqList L, int cur_e, int &next_e) {
    if (ListEmpty(L)) {
        cout << "链表为空！" << endl;
        return false;
    }
    LNode *p, *q;
    p = L.head->next;
    while (p != NULL) {
        q = p->next;
        if (p->date == cur_e) {
            if (q != NULL) {
                next_e = q->date;
                return true;
            } else {
                cout << cur_e << "无后继" << endl;
                return false;
            }
        }
     p=q;
    }
    cout << cur_e << "无后继" << endl;
    return false;
}

bool ListInsert(SqList &L, int i, int q) {//在第i个元素的位置插入元素q

    if (L.head == NULL) {
        printf("L为空！\n");
        return false;
    }

    if (i < 1 || i > L.length + 1) {
        cout << "所要插入的元素的下标不合法！" << endl;
        return false;
    }

    LNode *p;
    p = L.head;
    while (i > 1) {
        p = p->next;
        if (p == NULL) {
            cout << "插入失败" << endl;
            return false;
        }
        i--;
    }

    LNode *lNode = new LNode();
    lNode->date = q;

    lNode->next = p->next;
    p->next = lNode;
    L.length++;
    cout << "插入成功" << endl;
    return true;
}

bool ListDelete(SqList &L, int i, int &e) {//删除第i个数据元素，并用e返回其值
    if (ListEmpty(L)) {
        cout << "链表为空！" << endl;
        return false;
    }

    if (i < 1 || i > L.length) {
        cout << "所要删除的元素的下标不合法！" << endl;
        return false;
    }

    LNode *p;
    LNode *q;
    p = L.head;
    while (i > 1) {//将p指向要删除节点的前一个元素
        p = p->next;
        if (p == NULL) {
            cout << "删除失败" << endl;
            return false;
        }
        i--;
    }

    q = p->next;//q指向要删除的节点
    p->next = q->next;
    free(q);
    L.length--;

    cout << "删除成功" << endl;
    return true;

}


bool ListTraverse(SqList L, bool Visit(int k)) {
    if (ListEmpty(L)) {
        cout << "链表为空！" << endl;
        return false;
    }
    LNode *p;
    p = L.head->next;
    while (p != NULL) {
        Visit(p->date);
        p=p->next;
    }
    return true;
}


#endif //ADTLIST_ADT_LIST_SEQUENCE_H
