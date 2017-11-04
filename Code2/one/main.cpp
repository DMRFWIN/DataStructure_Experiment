#include <iostream>

using namespace std;

#include "Adt_List_Sequence.h"

void Init(SqList &L);

void InsertSort(SqList &L) ;

int main() {
    SqList L;
    Init(L);
    cout<<"排序前："<<endl;
    ListTraverse(L);
    InsertSort(L);
    cout<<"排序后："<<endl;
    ListTraverse(L);
    DestroyList(L);
    return 0;
}

void Init(SqList &L) {//初始化顺序表
    InitList(L);
    for (int i = 0; i < 20; ++i) {
        ListInsert(L, i + 1, 20 - i);
    }

}

void InsertSort(SqList &L) {
    for (int i = 1; i < L.length; ++i) {
        int temp = i;
        for (int j = i-1; j >= 0; --j) {
            if (L.elem[j] > L.elem[i]) {
                temp = j;
                continue;
            } else {
                break;
            }
        }

        if (temp == i) {
            continue;
        } else {
            int e;
            ListDelete(L, i + 1, e);
            ListInsert(L, temp+1, e);
        }

    }
}