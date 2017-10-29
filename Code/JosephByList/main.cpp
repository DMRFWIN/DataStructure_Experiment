#include <iostream>
#include "Adt_List_L.h"
#include "JosephByList.h"


using namespace std;

int main() {
    cout << "n(n个人),s(从s开始报数),m(报到m的人出列)" << endl;
    int n, s, m;
    cin >> n >> s >> m;
    SqList L;

    InitList(L);
    for (int i = 0; i < n; i++) {
        ListInsert(L, i + 1, i + 1);
    }

    int a = GetResultByList(L, s, m);

    cout << endl;
    cout << "最后一个人是：" << a << endl;

    DestroyList(L);

    return 0;
}
