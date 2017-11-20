#include <iostream>

using namespace std;
#define MAXSIZE 100
typedef struct {
    int h, l;//非0元的行和列
    int val;//非0元的值
} Triple;

typedef struct {
    Triple *data;
    int num_h, num_l, num_val;//矩阵行、列、非0元的个数
} TsMatrix;

void InputTsMatrix(TsMatrix t, int *pInt, int *pInt1, TsMatrix param);

void HandlingTsMatrix(TsMatrix &t, TsMatrix &pInt, int *cpot, int *pInt1);

int main() {
    int *num;
    int *cpot;
    TsMatrix T;
    TsMatrix M;
    InputTsMatrix(T, num, cpot, M);
    // cout<<num[0]<<" "<<cpot[0]<<endl;
    // HandlingTsMatrix(T, M, num, cpot);
    //free(T.data);
    //free(M.data);
    //free(num);
    //free(cpot);
    return 0;
}

void HandlingTsMatrix(TsMatrix &t, TsMatrix &m, int *num, int *cpot) {

    cpot[1] = 1;
    for (int i = 2; i <= t.num_l; ++i) {
        cpot[i] = cpot[i - 1] + num[i - 1];
    }

    m.data = new Triple[t.num_val];
    m.num_l = t.num_h;
    m.num_h = t.num_l;
    m.num_val = t.num_val;

    for (int j = 0; j < t.num_val; ++j) {
        int temp_l = t.data[j].l;
        int index = cpot[temp_l];
        index--;

        m.data[index].l = t.data[j].h;
        m.data[index].h = t.data[j].l;

        /*m.data[cpot[t.data[j].l] - 1].l = t.data[j].h;
        m.data[cpot[t.data[j].l] - 1].h = t.data[j].l;
        */

        cpot[temp_l]++;
    }

    for (int k = 0; k < t.num_val; ++k) {
        cout << t.data[k].h << " " << t.data[k].l << " " << t.data[k].val << endl;
    }

    cout << endl;
    for (int k = 0; k < t.num_val; ++k) {
        cout << m.data[k].h << " " << m.data[k].l << " " << m.data[k].val << endl;
    }

}

void InputTsMatrix(TsMatrix t, int *num, int *cpot, TsMatrix m) {

    cout << "请输入矩阵行数：" << endl;
    cin >> t.num_h;
    cout << "请输入矩阵列数：" << endl;
    cin >> t.num_l;

    num = new int[t.num_l + 1];
    cpot = new int[t.num_l + 1];
    for (int j = 1; j <= t.num_l; ++j) {
        num[j] = 0;
    }
    cout << "请输入三元组的个数：" << endl;
    cin >> t.num_val;
    t.data = new Triple[t.num_val];

    cout << "请依次输入要逆置的稀疏矩阵对应的三元组：" << endl;
    for (int i = 0; i < t.num_val; ++i) {
        cin >> t.data[i].h >> t.data[i].l >> t.data[i].val;
        num[t.data[i].l]++;
    }
    cpot[1] = 1;
    for (int i = 2; i <= t.num_l; ++i) {
        cpot[i] = cpot[i - 1] + num[i - 1];
    }

    m.data = new Triple[t.num_val];
    m.num_l = t.num_h;
    m.num_h = t.num_l;
    m.num_val = t.num_val;

    for (int j = 0; j < t.num_val; ++j) {
        int temp_l = t.data[j].l;
        int index = cpot[temp_l];
        index--;

        m.data[index].l = t.data[j].h;
        m.data[index].h = t.data[j].l;
        m.data[index].val = t.data[j].val;

        cpot[temp_l]++;
    }

    for (int k = 0; k < t.num_val; ++k) {
        cout << t.data[k].h << " " << t.data[k].l << " " << t.data[k].val << endl;
    }

    cout << endl;
    for (int k = 0; k < t.num_val; ++k) {
        cout << m.data[k].h << " " << m.data[k].l << " " << m.data[k].val << endl;
    }
/*
 * 1 2 12
1 3 9
3 1 -3
3 6 14
4 3 24
5 2 18
6 1 15
6 4 -7
 */
}