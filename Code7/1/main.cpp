#include <iostream>
#include "AdtGraph.h"

void ShortestPath(MGraph G);

using namespace std;


int main() {

    /*
 *
a f 100
a e 30
a c 10
b c 5
c d 50
e f 60
e d 20
d f 10
 */
    MGraph G;
    CreateDN(G);
    ShortestPath(G);
    return 0;
}

void ShortestPath(MGraph G) {
    int len[G.vexnum + 1];
    bool flag[G.vexnum + 1];
    for (int i = 1; i <= G.vexnum; ++i) {
        len[i] = G.arcs[1][i].adj;
        flag[i] = false;
    }
    flag[1] = true;


    int min = 1000000;
    int index = 0;

    while (true) {
        min = 1000000;
        index = 0;
        for (int i = 1; i <= G.vexnum; ++i) {
            if (len[i] < min && !flag[i] && len[i] != -1) {
                min = len[i];
                index = i;
            }
        }
        if (index == 0) {
            break;
        }
        flag[index] = true;
        for (int j = 1; j <= G.vexnum; ++j) {
            if (!flag[j] && G.arcs[index][j].adj != -1) {

                if (len[j] > len[index] + G.arcs[index][j].adj || len[j] == -1) {
                    len[j] = len[index] + G.arcs[index][j].adj;
                }
            }
        }

    }


    cout << "最短路径结果如下：" << endl;
    for (int k = 2; k <= G.vexnum; ++k) {
        cout << "1到" << k << ":";
        if (!flag[k]) {
            cout << "不存在路径～" << endl;
        } else {
            cout << "最短距离为" << len[k] << endl;
        }
    }
}