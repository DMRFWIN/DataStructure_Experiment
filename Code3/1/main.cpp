#include <iostream>
#include "MyStack.h"

void TestSqStack();

using namespace std;

int main() {
    TestSqStack();
    return 0;
}

void TestSqStack() {
    SqStack S;
    InitStack(S);
    /**
     * 在栈为空的情况下测试
     */
    int e;
    cout << "栈为空时ClearStack:" << endl;
    ClearStack(S);

    cout << "栈为空时StackEmpty:" << endl;
    StackEmpty(S);

    cout << "栈为空时StackLength:" << endl;
    StackLength(S);

    cout << "栈为空时StackTraverse:" << endl;
    StackTraverse(S);

    GetTop(S, e);
    cout << "栈为空时GetTop返回的值为：" << e << endl;

    Pop(S, e);
    cout << "栈为空时POP返回的值为：" << e << endl;


    /**
     * 插入元素后进行测试
     */

    cout << endl << "以下是栈非空时的测试：" << endl;

    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);


    cout << "栈不为空时StackEmpty:" << endl;
    StackEmpty(S);

    cout << "栈不为空时StackLength:" << endl;
    StackLength(S);

    cout << "栈不为空时StackTraverse:" << endl;
    StackTraverse(S);

    GetTop(S, e);
    cout << "栈不为空时GetTop返回的值为：" << e << endl;

    Pop(S, e);
    cout << "栈不为空时POP返回的值为：" << e << endl;

    cout << "栈不为空时ClearStack:" << endl;
    ClearStack(S);

    DestroyStack(S);
}