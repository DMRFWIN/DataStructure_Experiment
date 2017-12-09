#include <iostream>

using namespace std;

#include "AdtGraph.h"

int main() {
    MGraph G;
    CreateGraph(G);

    cout<<endl<<"a的下标："<<  LocateVex(G,'a')<<endl;

    cout<<endl<<"标号为2的节点值为："<< GetVex(G,2)<<endl;

    cout<<endl<<"c的第一个邻接点为："<<FirstAdjVex(G,'c')<<endl;

    cout<<endl<<"广度优先遍历："<<endl;
    BFDTraverse(G);
    cout<<endl<<"深度优先遍历："<<endl;
    DFSTraverse(G);


    return 0;
}