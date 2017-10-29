#include <iostream>
#include "Adt_List_Sequence.h"

void (*funVisit)(int);

void Visit(int k);

void ReverseSequence(SqList &L);

void swap(int &a, int &b);

int main() {

    SqList L;
    InitList(L);
    funVisit = &Visit;


    for (int i = 0; i <=10; ++i) {
        ListInsert(L, i + 1, i + 1);
    }
    cout << "未逆置的顺序表：" << endl;
    ListTraverse(L, funVisit);
    ReverseSequence(L);
    cout << "逆置后的顺序表：" << endl;
    ListTraverse(L, funVisit);
    DestroyList(L);

    return 0;
}

void Visit(int k) {
    cout << k << " ";
}


void ReverseSequence(SqList &L) {
    if (L.elem == NULL) {
        cout << "顺序表为空！" << endl;
    }

    for (int i = 0; i < L.length / 2; ++i) {
        swap(L.elem[i], L.elem[L.length - 1 - i]);
    }
    cout << "逆置成功！" << endl;

}


void swap(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}