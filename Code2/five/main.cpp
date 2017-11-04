#include <iostream>

using namespace std;

#include "Adt_List_Sequence.h"


void InsertSort(SqList &L);

void DeleleSame(SqList &L);

int main() {
    SqList L;

    cout << "请输入n：" << endl;
    int n;
    cin >> n;
    InitList(L, n);
    cout << "请输入n个整数：" << endl;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        ListInsert(L, i + 1, t);
    }
    InsertSort(L);
    DeleleSame(L);
    if (L.length % 2 == 0) {
     cout<<"-1"<<endl;
    } else{
        cout<<L.elem[L.length/2]<<endl;
    }
    DestroyList(L);
    return 0;
}


void InsertSort(SqList &L) {
    for (int i = 1; i < L.length; ++i) {
        int temp = i;
        for (int j = i - 1; j >= 0; --j) {
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
            ListInsert(L, temp + 1, e);
        }

    }
}

void DeleleSame(SqList &L) {

    int temp;
    for (int i = 0; i < L.length - 1; ++i) {
        if (L.elem[i] == L.elem[i + 1]) {
            ListDelete(L, i + 1, temp);
        }
    }
}