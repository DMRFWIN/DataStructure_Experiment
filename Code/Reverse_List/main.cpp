#include <iostream>
#include "Adt_List_L.h"

void (*funVisit)(int);

void Visit(int k);

void ReverseSequence(SqList &L);


int main() {

    SqList L;
    InitList(L);
    funVisit = &Visit;


    for (int i = 0; i <= 10; ++i) {
        ListInsert(L, i + 1, i + 1);
    }

    cout << "未逆置的链表：" << endl;
    ListTraverse(L, funVisit);
    cout<<endl;

    ReverseSequence(L);
    cout << "逆置后的链表：" << endl;
    ListTraverse(L, funVisit);
    cout<<endl;

    DestroyList(L);

    return 0;
}

void Visit(int k) {
    cout << k << " ";
}


void ReverseSequence(SqList &L) {

    if (L.head->next == NULL) {
        cout << "链表为空，无法逆置！" << endl;
    }

    LNode *p, *q, *h;
    p = L.head->next;


    q = p->next;
    p->next = NULL;

    while (q != NULL) {
        p = L.head->next;
        L.head->next = q;
        h = q->next;
        q->next = p;
        q = h;
    }
    cout << "逆置成功！" << endl;

}


