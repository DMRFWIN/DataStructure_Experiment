#include <iostream>

using namespace std;

#include "MyStack.h"


int n = 0;
#define N 8

void Search(SqStack s);

void Recursive(SqStack &S, int y);

bool judge(SqStack S, int x, int y);

int num = 0;


int main() {

    SqStack S;
    InitStack(S);
    Search(S);
    cout << endl;
    DestroyStack(S);

    cout << num << endl;
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

void Search(SqStack s) {

    int i = 1;
    bool flag;

    Coord e;
    e.x = 0;
    e.y = 1;

    while (i <= 8) {

        if (flag) {
            e.x = 0;
        }
        if (Full(s)) {
            e = Pop(s);

        }
        flag = false;

        for (int j = e.x + 1; j <= 8; j++) {
            if (judge(s, j, i)) {
                Coord e2;
                e2.x = j;
                e2.y = i;
                Push(s, e2);
                //  cout << "a" << i << "(" << e.y << "," << e.x << ") ";
                flag = true;
                break;
            }
        }


        if (flag) {
            if (i == 8) {
                StackTraverse(s);
                num++;

            } else {
                i++;
            }
        } else {
            i--;
            e = Pop(s);
            if (i == 0) {
                break;
            }
        }

    }
}