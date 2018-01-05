#include <iostream>
#include <vector>
using namespace std;

void HeapAdjust(vector<int> &v, int s, int m);


int main() {

    system("time");
    // getNum();
    return 0;
}



/*
 * 堆排序
 * T(n)=O(nlog2-->n)
 * S(n)=O(1)
 * 不稳定
 */

void HeapSort(vector<int> v) {
    vector<int> n_v;
    int size = v.size();
    for (int k = v.size(); k > 0; --k) {
        v[k] = v[k - 1];
    }
    //建堆
    for (int i = size / 2; i > 0; --i) {
        HeapAdjust(v, i, size);
    }

    for (int j = size; j > 1; --j) {
        int t;
        t = v[1];
        n_v.push_back(t);
        v[1] = v[j];
        v[j] = t;
        HeapAdjust(v, 1, j - 1);
    }

    /*
     * n_v即为排好序的vector
     */

}

void HeapAdjust(vector<int> &v, int s, int m) {
    /*
     * 已知v[s..m]除v[s]之外均满足堆的定义，本函数调整v[s]，使得v[s..m]成为一个大顶堆
     */

    int rc;
    rc = v[s];
    for (int i = 2 * s; i <= m; i = 2 * i) {
        if (i < m && v[i] > v[i + 1]) {
            i++;//i为较小数据的下标
        }
        if (rc <= v[i]) {
            break;
        }

        v[s] = v[i];
        s = i;
    }
    v[s] = rc;
}
