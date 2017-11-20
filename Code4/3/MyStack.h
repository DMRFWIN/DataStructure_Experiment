//
// Created by dmrf on 17-11-11.
//

#ifndef INC_1_MYSTACK_H
#define INC_1_MYSTACK_H
#define STACK_INIT_SIZE 8
#define STACKINCREMENT 10


#include <iostream>

using namespace std;
typedef struct {
    int x;
    int y;

} Coord;

typedef struct {
    Coord *base;//栈底
    Coord *top;//栈顶
    int length;
    int stacksize;//栈已分配的存储空间
} SqStack;

bool InitStack(SqStack &S) {
    S.base = new Coord[STACK_INIT_SIZE];
    if (S.base == NULL) {
        cout << "分配空间失败！" << endl;
        return false;
    }


    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    S.length = 0;
    cout << "初始化栈成功～" << endl;
    return true;

}

bool DestroyStack(SqStack &S) {

    if (S.base == NULL) {
        cout << "该栈不存在，无法销毁！" << endl;
        return false;
    }

    delete S.base;
    S.base = NULL;
    S.top = NULL;
    S.stacksize = 0;
    cout << "销毁成功～" << endl;
    return true;
}

bool ClearStack(SqStack &S) {

    if (S.base == NULL) {
        cout << "该栈不存在，无法清空！" << endl;
        return false;
    }

    S.top = S.base;
    cout << "清空成功～" << endl;
    return true;
}


int StackLength(SqStack S) {
    if (S.base == NULL) {
        cout << "该栈不存在，无法获取长度！" << endl;
        return -1;
    }

    int length = (S.top - S.base);
    return length;
}

bool GetTop(SqStack S, Coord &e) {
    if (S.base == NULL) {

        cout << "该栈不存在，无法获取栈顶！" << endl;
        return false;
    }
    if (S.base == S.top) {

        cout << "该栈为空，无法获取栈顶！" << endl;
        return false;
    }

    e.x = (*(S.top - 1)).x;
    e.y = (*(S.top - 1)).y;
    return true;
}

bool Push(SqStack &S, Coord e) {
    *S.top = e;
    S.top++;
    S.length++;
    return true;
}

Coord Pop(SqStack &S) {
    Coord e;
    S.top--;
    e.y = (*S.top).y;
    e.x = (*S.top).x;
    S.length--;
    return e;
}

bool Full(SqStack S) {
    return StackLength(S) == STACK_INIT_SIZE;
}

bool StackTraverse(SqStack S) {
    if (S.base == NULL) {
        cout << "该栈不存在，无法遍历！" << endl;
        return false;
    }
    if (S.base == S.top) {
        cout << "该栈为空，无法遍历！" << endl;
        return false;
    }

    Coord *i = S.top - 1;
    while (i - S.base >= 0) {
        cout << "(" << (*i).x << " , " << (*i).y << ")" << endl;
        i--;
    }

    cout << endl;
    return true;
}


bool StackEmpty(SqStack S) {
    if (S.base == NULL) {
        cout << "该栈不存在，无法判空！" << endl;
        return false;
    }
    if (S.top != S.base) {
        //    cout << "该栈不为空～" << endl;
        return false;
    }
    //cout << "该栈为空～" << endl;
    return true;
}

#endif //INC_1_MYSTACK_H
