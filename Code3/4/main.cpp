#include <iostream>

using namespace std;

#include "Window_List_Sequence.h"

void ChangeWindows(SqList S, int x, int y, int n);

bool IsInWindow(Win e, int x, int y);


int main() {
    SqList S;
    int n, m;
    cout << "请输入窗口数目：" << endl;
    cin >> n;
    cout << "请输入点击次数：" << endl;
    cin >> m;


    InitList(S, n);
    int x1, y1, x2, y2;
    cout << "请输入" << n << "个窗口的坐标信息：" << endl;
    for (int i = 0; i < n; ++i) {
        Win w;
        cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
        w.index = i + 1;
        ListInsert(S, i + 1, w);
    }

    cout << "请输入" << m << "个点击点的坐标：" << endl;
    int c[m];
    int v[m];
    for (int j = 0; j < m; ++j) {
        int a, b;
        cin >> a >> b;
        c[j]=a;
        v[j]=b;

    }

    for (int k = 0; k <m ; ++k) {
        ChangeWindows(S, c[k], v[k], n);
    }
    return 0;
}

void ChangeWindows(SqList S, int x, int y, int n) {

    Win e;

    for (int i = n; i > 0; --i) {
        GetElem(S, i, e);
        if (IsInWindow(e, x, y)) {
            cout << e.index << endl;
            ListDelete(S, i, e);
            ListInsert(S, n, e);
            return;
        }
    }
    cout << "IGNORED" << endl;

}

bool IsInWindow(Win e, int x, int y) {//判断坐标是否在窗口内
    if ((x >= e.x1 && x <= e.x2) && (y >= e.y1 && y <= e.y2)) {
        return true;
    }
    return false;
}


