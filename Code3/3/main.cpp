#include <iostream>
#include <iostream>

using namespace std;

#include "CircleQueue.h"

int main() {

    SqQueue S;
    InitSqQueue(S);
    cout<<"请输入目标数据个数：";
    int n;
    cin>>n;
    cout<<"请输入目标数据："<<endl;
    int x;
    for (int i = 0; i <n; ++i) {
        cin>>x;
        EnQueue(S, x);
    }

    Traverse(S);
    cout<<"max is :"<<getMax(S)<<endl;
    return 0;
}