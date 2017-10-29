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
    int *elem;//存储空间基地址
    int length;//当前长度
    int listsize;//当前分配的存储容量（以sizeof(int)为单位）

} SqList;

bool InitList(SqList &L) {
    L.elem = new int[LIST_INIT_SIZE];
    if (L.elem == NULL) {
        printf("分配空间失败！\n");
        return false;
    }
    L.length = 0;
    cout << "初始化成功！" << endl;
    return true;
}


bool DestroyList(SqList &L) {
    if (L.elem == NULL) {
        cout << "顺序表为空，无法销毁！" << endl;
        return false;
    }
    free(L.elem);
    L.elem = NULL;
    L.listsize = 0;
    L.length = 0;
    return true;
}


bool ClearList(SqList &L) {
    if (L.elem == NULL) {
        cout << "顺序表为空，无法清空！" << endl;
        return false;
    }
    L.length = 0;
    cout << "清空成功！" << endl;
    return true;
}


bool ListEmpty(SqList L) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return false;
    }
    if (L.length == 0) {
        cout << "顺序表为空！" << endl;
        return true;
    }
    cout << "顺序表不为空！" << endl;
    return false;
}


int ListLength(SqList L) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return -1;
    }
    cout << "顺序表的长度为" << L.length << endl;
    return L.length;
}


bool GetElem(SqList L, int i, int &e) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return false;
    }
    if (i < 1 || i > L.length) {
        cout << "所要获取的数据下标不合法！" << endl;
        return false;
    }
    e = L.elem[i - 1];
    return true;
}

int LocateElem(SqList L, int e, bool compare(int a, int b)) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return -1;
    }

    for (int i = 0; i < L.length; ++i) {
        if (compare(e, L.elem[i])) {
            cout << "和" << e << "满足条件compare的第一个元素的序号为" << i + 1 << endl;
            return i + 1;
        }
    }
    cout << "不存在和" << e << "满足条件compare的元素" << endl;
    return -1;
}

bool PriorElem(SqList L, int cur_e, int &pre_e) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return false;
    }
    if (cur_e == L.elem[0]) {
        cout << "该元素为首元素，无前驱！" << endl;
        return false;
    }
    for (int i = 1; i < L.length; ++i) {
        if (L.elem[i] == cur_e) {
            pre_e = L.elem[i - 1];
            cout << "该元素的前驱为" << pre_e << endl;
            return true;
        }
    }
    cout << "该元素无前驱！" << endl;
    return false;
}

bool NextElem(SqList L, int cur_e, int &next_e) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return false;
    }
    if (cur_e == L.elem[L.length - 1]) {
        cout << "该元素为摸元素，无后继！" << endl;
        return false;
    }
    for (int i = 0; i < L.length - 1; ++i) {
        if (L.elem[i] == cur_e) {
            next_e = L.elem[i + 1];
            cout << "该元素的后继为" << next_e << endl;
            return true;
        }
    }
    cout << "该元素无后继！" << endl;
    return false;
}

bool ListInsert(SqList &L, int i, int q) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return false;
    }
    if (i < 1 || i > L.length+1) {
        cout << "所要插入的元素的下标不合法！" << endl;
        return false;
    }
    if (L.length == L.listsize) {
        L.elem = static_cast<int *>(realloc(L.elem, (LISTINCREMENT + L.listsize) * sizeof(int)));
        if (L.elem == NULL) {
            cout << "新增空间失败！" << endl;
            return false;
        }
    }

    for (int j = L.length - 1; j >= i - 1; --j) {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = q;
    L.length++;
    cout << "插入元素成功！" << endl;
    return true;
}

bool ListDelete(SqList &L, int i, int &e) {//删除序号为i的元素
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return false;
    }
    if (i < 1 || i > L.length) {
        cout << "所要删除元素的下标不合法！" << endl;
        return false;
    }

    e = L.elem[i - 1];
    for (int j = i - 1; j < L.length; ++j) {
        L.elem[j] = L.elem[j + 1];
    }
    L.length--;
    cout << "删除成功！" << endl;
    return true;
}


bool ListTraverse(SqList L, bool Visit(int k)) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
        return false;
    }
    for (int i = 0; i < L.length; ++i) {
        Visit(L.elem[i]);
    }
    return true;
}


#endif //ADTLIST_ADT_LIST_SEQUENCE_H
