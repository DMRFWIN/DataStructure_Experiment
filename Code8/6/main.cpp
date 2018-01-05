#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int GetMaxBit(vector<int> v);
void radixSort(vector<int> v);

int main() {
     vector<int> v;
    v.push_back(456);
    v.push_back(34);
    v.push_back(29);
    v.push_back(199);
    v.push_back(5);
    radixSort(v);
    return 0;
}

void show(vector<int> v) {
     for (int i = 0; i < v.size(); ++i) {
         cout << v[i] << " ";
     }
     cout << endl;
}
/*
 * 基数排序
 * T(n)=O(d*n) d为排序数中最大数的位数
 * S(n)=O(n)
 * 稳定
 *
 */

void radixSort(vector<int> v) {

    int d = GetMaxBit(v);

    int *count = new int[10];
    queue<int> q[10];

    int radix = 1;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < v.size(); ++j) {
            int t;
            t = (v[j] / radix) % 10;
            q[t].push(v[j]);
        }

        int p = 0;
        for (int k = 0; k < 10; ++k) {
            while (!q[k].empty()) {
                v[p++] = q[k].front();
                q[k].pop();
            }
        }
        radix *= 10;
    }
    show(v);

}

int GetMaxBit(vector<int> v) {
    int max = v[0];
    for (int i = 1; i < v.size(); ++i) {
        max = v[i] > max ? v[i] : max;
    }

    int d = 1;
    while (max >= 10) {
        max /= 10;
        d++;
    }
    return d;

}


