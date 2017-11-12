#include <iostream>
#include "ADTQueue.h"

void TestQueue();

using namespace std;

int main() {
    TestQueue();
    return 0;
}


void TestQueue() {

    /*
     * 当队列为空的时候测试
     */

    int e;

    LinkQueue Q;
    InitQueue(Q);

    cout << endl << "测试一个空的队列：" << endl;


    cout << "获取长度：" << endl;
    QueueLength(Q);

    cout << "判空：" << endl;
    QueueEmpty(Q);

    cout << "获取队头：" << endl;
    GetHead(Q, e);

    cout << "删除队头：" << endl;
    DeQueue(Q, e);

    cout << "遍历：" << endl;
    QueueTraverse(Q);

    cout << "清空：" << endl;
    ClearQueue(Q);


    /*
     * 非空队列测试
     */

    cout << endl << "入队元素并测试：" << endl;

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);


    cout << "遍历：" << endl;
    QueueTraverse(Q);

    cout << "获取长度：" << endl;
    QueueLength(Q);

    cout << "判空：" << endl;
    QueueEmpty(Q);

    cout << "获取队头：" << endl;
    GetHead(Q, e);

    cout << "删除队头：" << endl;
    DeQueue(Q, e);

    cout << "遍历：" << endl;
    QueueTraverse(Q);

    cout << "清空：" << endl;
    ClearQueue(Q);

    cout << "遍历：" << endl;
    QueueTraverse(Q);

    DestroyQueue(Q);
}