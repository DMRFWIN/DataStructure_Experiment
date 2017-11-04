#include <iostream>

using namespace std;

#include "Adt_List_Sequence.h"

void Init(SqList &a, SqList &b);

void MergeList(SqList &a, SqList &b);

int main() {
    SqList a;
    SqList b;
    Init(a, b);
    cout<<"a："<<endl;
    ListTraverse(a);
    cout<<"b:"<<endl;
    ListTraverse(b);
    MergeList(a,b);
    cout<<"合并后的a："<<endl;
    ListTraverse(a);
    return 0;
}

void Init(SqList &a, SqList &b) {
    InitList(a);
    InitList(b);
    int k = 1;
    for (int i = 0; i < 20; ++i) {
        if (i % 2 == 0) {
            ListInsert(a, k, i + 1);
        } else {
            ListInsert(b, k++, i + 1);
        }
    }
}

void MergeList(SqList &a, SqList &b) {
    int flag = 0;
    bool f;
    int tempa, tempb;

    for (int i = 0; i < b.length; ++i) {
        f= false;
        tempb=b.elem[i];

        for (int j = flag; j < a.length; ++j) {
            tempa=a.elem[j];
            if (tempb >tempa) {
                continue;
            } else if (tempa == tempb) {
                f= true;
                break;
            } else {
                f= true;
                ListInsert(a, j+1, tempb);
                flag = j;
                break;
            }
        }

        if (f == false) {
            ListInsert(a, a.length+1, tempb);
        }
    }
}