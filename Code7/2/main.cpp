#include <iostream>
#include "AdtGraph.h"
#include <vector>

using namespace std;

void Prim(MGraph G);

int main() {
    MGraph G;
    CreateUDN(G);
    Prim(G);

    return 0;
}


void Prim(MGraph G) {

    int min;
    vector<int> a;
    vector<int> b;
    vector<int> minvalue;
    vector<int> index;

    index.push_back(1);

    a.push_back(1);
    bool flag[G.vexnum + 1];

    for (int k = 1; k <= G.vexnum; ++k) {
        flag[k] = false;
    }
    int min_index;

    for (int i = 2; i <= G.vexnum; ++i) {
        if (G.arcs[1][i].adj != -1) {
            min = G.arcs[1][i].adj;
            min_index = i;
            break;
        }

    }

    for (int j = min_index + 1; j <= G.vexnum; ++j) {
        if (G.arcs[1][j].adj != -1 && G.arcs[1][j].adj < min) {
            min = G.arcs[1][j].adj;
            min_index = j;
        }
    }

    flag[1] = true;
    flag[min_index] = true;
    b.push_back(min_index);
    minvalue.push_back(min);
    index.push_back(min_index);

    while (index.size() != G.vexnum) {
        int n = index[0];
        int f = 0;
        min = 1000000;

        for (int l = 0; l < index.size(); ++l) {

            for (int k = 1; k <= G.vexnum; ++k) {
                if (G.arcs[index[l]][k].adj != -1 && G.arcs[index[l]][k].adj < min && !flag[k]) {
                    min = G.arcs[index[l]][k].adj;
                    min_index = k;
                    f = l;
                }
            }
        }

        flag[min_index] = true;
        a.push_back(index[f]);
        b.push_back(min_index);
        index.push_back(min_index);
        minvalue.push_back(min);


    }


    int va = 0;
    for (int m = 0; m < minvalue.size(); ++m) {
        va += minvalue[m];
    }

    cout << va << endl;
    cout << "建立以下" << a.size() << "条水渠：";
    for (int i1 = 0; i1 < a.size() - 1; ++i1) {
        cout << "麦田" << a[i1] << "与麦田" << b[i1] << "、";
    }
    cout << "麦田" << a[a.size() - 1] << "与麦田" << b[a.size() - 1] << "。";
    cout << endl;
    for (int j1 = 0; j1 < index.size(); ++j1) {
        cout << index[j1] << " ";
    }

}
