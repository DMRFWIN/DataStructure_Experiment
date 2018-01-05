#include <iostream>
#include <vector>

using namespace std;

int ChooseMin(int *a, int len);

int main() {
    return 0;
}


/*
 * 选择排序
 * S(n)=O(1)
 * T(n)=O(n^2)
 * 不稳定
 */

void SelectSort(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        int min;
        min = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        int t;
        t = v[min];
        v[min] = v[i];
        v[i] = v[min];
    }
}


/*
 * 归并排序
 * T(n)=O(nlog2-->n)
 * S(n)=O(n)
 * 稳定
 */


void MSort(vector<int> v) {


    vector<int> h;
    h = v;

    int start, seg;


    for (seg = 1; seg < v.size(); seg *= 2) {
        int k = 0;
        for (start = 0; start < v.size(); start = start + seg * 2) {
            int end;
            end = start + seg;
            int low = start;
            while (low < start + seg && end < start + seg + seg && low < v.size() && end < v.size()) {
                if (v[low] <= v[end]) {
                    h[k++] = v[low];
                    low++;
                } else {
                    h[k++] = v[end];
                    end++;
                }
            }

            while (low < start + seg && low < v.size()) {
                h[k++] = v[low++];
            }
            while (end < start + seg + seg && end < v.size()) {
                h[k++] = v[end++];
            }

        }

        v = h;
    }


}




//交换排序
void ExchangeSort(int *a, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (a[i] > a[j]) {
                int t;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }

    }

    for (int k = 0; k < len; ++k) {
        cout << a[k] << " ";
    }
    cout << endl;
}

