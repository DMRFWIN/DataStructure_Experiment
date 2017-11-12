#include <iostream>

using namespace std;

#include "Train_List_Sequence.h"

bool HandlingData(SqList &L, int num);

int main() {

    SqList L;
    InitList(L);

    cout << "请输入购票指令的数量：" << endl;
    int n;
    cin >> n;
    cout << "请输入" << n << "条购入票的数目：" << endl;
 int num;   int Num[n];
    for (int i = 0; i < n; ++i) {
        cin >> Num[i];
    }

    for (int j = 0; j < n; ++j) {
        HandlingData(L, Num[j]);
    }


    DestroyList(L);
    return 0;
}


bool HandlingData(SqList &L, int num) {

    for (int i = 0; i < 20; ++i) {
        if (L.elem[i].CanUse >= num) {
            L.elem[i].CanUse -= num;
            L.SeatNum -= num;
            for (int j = 1; j <= 5; ++j) {
                if (L.elem[i].NoUse[j]) {
                    for (int k = 0; k < num; ++k) {
                        L.elem[i].NoUse[j + k] = false;
                        cout << i * 5 + j + k << " ";
                    }
                    break;
                }
            }
            cout << endl;
            return true;
        } else {
            continue;
        }
    }


    int n = num;
    if (L.SeatNum >= num) {
        for (int i = 0; i < 20; ++i) {
            if (L.elem[i].CanUse > 0) {
                for (int j = 0; j < 5; ++j) {
                    if (L.elem->NoUse[j]) {
                        L.elem->NoUse[j] = false;
                        L.SeatNum--;
                        cout << i * 5 + j << " ";
                        n--;
                        if (n == 0) {
                            cout << endl;
                            return true;
                        }
                    }
                }
            }
        }
    }


}