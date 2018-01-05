#include <iostream>
#include <vector>

using namespace std;

void QSort(vector<int> &v, int low, int high);

int Partition(vector<int> &v, int low, int high);

int main() {
    std::cout << "Hello, Wo速排序算法rld!" << std::endl;
    return 0;
}

/*
 * 快速排序
 * T(n)=O(nlog2->n)
 * S(n)=O(log2->n)
 * 不稳定
 */

void QuickSort(vector<int> v) {
    QSort(v, 0, v.size() - 1);
}

void QSort(vector<int> &v, int low, int high) {
    int t = Partition(v, low, high);
    QSort(v, low, t - 1);
    QSort(v, t + 1, high);
}

int Partition(vector<int> &v, int low, int high) {
    int pivotkey;
    pivotkey = v[low];

    while (low < high) {
        while (low < high && v[high] > pivotkey) {
            --high;
        }
        int t;
        t = v[low];
        v[low] = v[high];
        v[high] = t;

        while (low < high && v[low] < pivotkey) {
            ++low;
        }
        t = v[low];
        v[low] = v[high];
        v[high] = t;
    }

    return low;
}

