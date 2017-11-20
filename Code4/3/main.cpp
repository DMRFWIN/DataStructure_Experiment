#include <iostream>
#include <cmath>

using namespace std;

#include "MyStack.h"


int n = 0;
#define N 8


void Recursive(SqStack &S, int y);

bool judge(SqStack S, int x, int y);

int main() {

    SqStack S;
    InitStack(S);


    Recursive(S, 1);
    cout << "n:" << n << endl;

    DestroyStack(S);
    return 0;
}


void Recursive(SqStack &S, int y) {

    if (StackEmpty(S)) {
        for (int i = 1; i <= N; ++i) {
            Coord e;
            e.x = i;
            e.y = 1;
            Push(S, e);
            Recursive(S, 2);
            Pop(S);
        }
    } else if (Full(S)) {
        StackTraverse(S);
        n++;
        return;
    } else {
        for (int i = 1; i <= N; ++i) {
            if (judge(S, i, y)) {
                Coord e;
                e.x = i;
                e.y = y;
                Push(S, e);
                Recursive(S, y + 1);
                Pop(S);
            }
        }
    }
}


bool judge(SqStack S, int x, int y) {
    SqStack m = S;
    while (!StackEmpty(m)) {
        Coord e;
        e = Pop(m);
        if ((e.x == x) || (abs(e.x - x) == abs(e.y - y))) {
            return false;//如果不行返回false
        }
    }

    return true;//如果可以返回true
}