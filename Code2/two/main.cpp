#include <iostream>

using namespace std;

#include "Adt_List_L.h"

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
    for (int i = 0; i < 25; ++i) {
        ListInsert(L, i + 1, 20 - i);
    }

}

void InsertSort(SqList &L) {
    for (int i = 1; i < L.length; ++i) {
        int temp = i;
        for (int j = i-1; j >= 0; --j) {
            int a;
            GetElem(L,j+1,a);
            int b;
            GetElem(L,i+1,b);
            if (a > b) {
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
