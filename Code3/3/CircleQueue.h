//
// Created by dmrf on 17-11-11.
//

#ifndef INC_2_ADTQUEUE_H
#define INC_2_ADTQUEUE_H
#define QUEUE_SIZE 10

#include <iostream>

using namespace std;
typedef struct {
    int *base;
    int front;
    int rear;
    int length;
    int max;
    int index;
} SqQueue;

bool InitSqQueue(SqQueue &S) {
    S.base = new int[QUEUE_SIZE];
    if (S.base == NULL) {
        cout << "内存分配失败，无法创建队列！" << endl;
        return false;
    }

    S.length = 0;
    S.rear = 0;
    S.front = 0;
    S.max = 0;
    S.index = 0;
}


bool EnQueue(SqQueue &S, int e) {
    if (S.base == NULL) {
        cout << "入队失败！" << endl;
        return false;
    }

    if (S.length == 10) {
        S.length = 0;
        S.rear = 0;
        S.front = (S.front + 1) % QUEUE_SIZE;
        S.base[S.rear] = e;
        if (e > S.max) {
            S.max = e;
            S.index = S.rear;
        } else {
            S.index--;
        }
        S.rear++;
    } else {
        S.base[S.rear] = e;

        if (e > S.max) {
            S.max = e;
            S.index = S.rear;
        }

        S.rear++;
        S.length++;
    }

    cout << "入队成功～" << endl;
}


bool Traverse(SqQueue S) {
    for (int i = 0; i < 10; ++i) {
        cout << S.base[i] << " ";
    }

    cout << endl;
}

int getMax(SqQueue S) {
    cout << "index is " << S.index << endl;
    return S.max;
}

#endif //INC_2_ADTQUEUE_H
