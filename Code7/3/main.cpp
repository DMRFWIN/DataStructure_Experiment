#include <iostream>
#include "AdtGraph.h"
#include <queue>

using namespace std;

bool TopologicalSort(MGraph G);

int main() {
    MGraph G;
    CreateGraph(G);
    TopologicalSort(G);

    return 0;
}


bool TopologicalSort(MGraph G) {
    queue<char> Q;
    bool f[G.vexnum + 1];

    for (int i = 1; i <= G.vexnum; ++i) {
        f[i] = false;
        bool flag = false;
        for (int j = 1; j <= G.vexnum; ++j) {
            if (G.arcs[j][i].adj != -1) {//判断点i是否入度为0
                flag = true;
                break;
            }
        }

        if (!flag) {
            Q.push(G.vexs[i]);
            f[i] = true;
        }
    }

    int num = 0;//记录拓扑排序后的点的个数，检测有向图G是否有回路，如果有葫回路则拓扑路径上的点少于G的顶点个数

    queue<char> sort;

    while (!Q.empty()) {
        char c = Q.front();
        num++;
        Q.pop();
        sort.push(c);
        int m = LocateVex(G, c);

        for (int j = 1; j <= G.vexnum; ++j) {
            G.arcs[m][j].adj = -1;
        }
        for (int i = 1; i <= G.vexnum; ++i) {
            bool flag = false;
            if (!f[i]) {
                for (int j = 1; j <= G.vexnum; ++j) {
                    if (G.arcs[j][i].adj != -1) {
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    Q.push(G.vexs[i]);
                    f[i] = true;
                }
            }

        }

    }
    cout << "拓扑排序的顺序：" << endl;
    while (sort.size() != 1 && !sort.empty()) {
        cout << sort.front() << "-->";
        sort.pop();
    }
    cout << sort.front() << endl;

    if (num < G.vexnum) {
        cout << "该图含有有向回路～" << endl;
        return false;
    }
    return true;
}