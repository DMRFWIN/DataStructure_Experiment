//
// Created by dmrf on 17-10-25.
//
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;
#ifndef ADTLIST_ADT_LIST_SEQUENCE_H
#define ADTLIST_ADT_LIST_SEQUENCE_H
#define LIST_INIT_SIZE 20//线性表存储空间的初始分配量
typedef struct {
    bool NoUse[6];
    int CanUse;
} Seat;

typedef struct {
    Seat *elem;//存储空间基地址
    int SeatNum;
} SqList;

bool InitList(SqList &L) {
    L.elem = new Seat[LIST_INIT_SIZE];
    if (L.elem == NULL) {
        printf("分配空间失败！\n");
        return false;
    }
    for (int i = 0; i < 20; ++i) {
        L.elem[i].CanUse = 5;
        L.elem[i].NoUse[0] = L.elem[i].NoUse[1] = L.elem[i].NoUse[2] = L.elem[i].NoUse[3] = L.elem[i].NoUse[4] = true;
    }
    L.SeatNum=100;
    cout << "初始化成功！" << endl;
    return true;
}


bool DestroyList(SqList &L) {
    if (L.elem == NULL) {
        cout << "顺序表为空，无法销毁！" << endl;
        return false;
    }
    free(L.elem);
    L.elem = NULL;
    return true;
}



#endif //ADTLIST_ADT_LIST_SEQUENCE_H
