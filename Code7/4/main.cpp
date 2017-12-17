#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#include "AdtGraph.h"

void CriticalPath(MGraph G);

int main() {
    MGraph G;
    CreateGraph(G);
   /* G.arcs[1][2].adj = 3;
    G.arcs[1][3].adj = 2;
    G.arcs[2][5].adj = 3;
    G.arcs[2][4].adj = 2;
    G.arcs[3][4].adj = 4;
    G.arcs[3][6].adj = 3;
    G.arcs[4][6].adj = 2;
    G.arcs[5][6].adj = 1;

    G.arcs[1][2].s = "a1";
    G.arcs[1][3].s = "a2";
    G.arcs[2][5].s = "a4";
    G.arcs[2][4].s = "a3";
    G.arcs[3][4].s = "a5";
    G.arcs[3][6].s = "a6";
    G.arcs[4][6].s = "a7";
    G.arcs[5][6].s = "a8";

    G.arcs[2][1].s = "a1";
    G.arcs[3][1].s = "a2";
    G.arcs[5][1].s = "a4";
    G.arcs[4][2].s = "a3";
    G.arcs[4][3].s = "a5";
    G.arcs[6][3].s = "a6";
    G.arcs[6][4].s = "a7";
    G.arcs[6][5].s = "a8";

*/
    CriticalPath(G);

    return 0;
}

void CriticalPath(MGraph G) {
    int V1[G.vexnum + 1];
    int V2[G.vexnum + 1];
    int L1[G.arcnum + 1];
    int L2[G.arcnum + 1];
    vector<string> s;

    for (int k = 1; k <= G.vexnum; ++k) {
        V1[k] = 0;
        V2[k] = 0;
    }

    queue<int> Q;
    Q.push(1);
    V1[1] = 0;

    while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        for (int i = 1; i <= G.vexnum; ++i) {
            if (G.arcs[p][i].adj != -1) {
                if (V1[i] < V1[p] + G.arcs[p][i].adj) {//取最晚完工的时间节点
                    V1[i] = V1[p] + G.arcs[p][i].adj;
                    Q.push(i);
                }

            }
        }
    }

    cout << "V1：" << endl;
    for (int j = 1; j <= G.vexnum; ++j) {
        cout << V1[j] << " ";
    }


    V2[G.vexnum] = V1[G.vexnum];
    queue<int> P;
    P.push(G.vexnum);

    while (!P.empty()) {
        int p = P.front();
        P.pop();
        for (int i = G.vexnum; i >= 1; --i) {
            if (G.arcs[i][p].adj != -1) {
                if (V2[i] > V2[p] - G.arcs[i][p].adj || V2[i] == 0) {//取最早开始的时间点
                    V2[i] = V2[p] - G.arcs[i][p].adj;
                    P.push(i);
                }
            }
        }
    }
    cout << endl;
    cout << "V2：" << endl;
    for (int j = 1; j <= G.vexnum; ++j) {
        cout << V2[j] << " ";
    }

    for (int l = 1; l <= G.vexnum; ++l) {
        for (int i = l + 1; i <= G.vexnum; ++i) {
            bool flag = false;

            if (G.arcs[l][i].s.compare("")) {
                for (int j = 0; j < s.size(); ++j) {
                    if (G.arcs[l][i].s == s[j]) {
                        L1[j + 1] = V1[l];
                        L2[j + 1] = V2[i] - G.arcs[l][i].adj;
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    s.push_back(G.arcs[l][i].s);
                    int j = s.size();
                    L1[j] = V1[l];
                    L2[j] = V2[i] - G.arcs[l][i].adj;
                }
            }

        }
    }


    cout << endl;
    cout << "L1：" << endl;
    for (int m = 1; m <= G.arcnum; ++m) {
        cout << L1[m] << " ";

    }


    cout << endl;
    cout << "L1：" << endl;
    for (int m = 1; m <= G.arcnum; ++m) {
        cout << L2[m] << " ";
    }
    cout << endl;

    cout << "关键路径：" << endl;
    for (int n = 1; n < G.arcnum; ++n) {
        if (L1[n] == L2[n]) {
            cout << s[n-1] << " ";
        }
    }


}