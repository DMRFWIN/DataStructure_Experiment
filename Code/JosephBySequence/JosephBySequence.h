//
// Created by dmrf on 17-10-29.
//

#ifndef JOSEPH_JOSEPHBYSEQUENCE_H
#define JOSEPH_JOSEPHBYSEQUENCE_H

#include "Adt_List_Sequence.h"

int GetResultBySequence(SqList L, int s, int m) {

    int i = 0;
    s--;
    int e;

    while (L.length != 1) {
        i++;
        s++;
        if (s > L.length) {
            s = s - L.length;
        }

        if (i % m == 0) {
            ListDelete(L, s, e);
            s--;
        }
    }

    return L.elem[0];
}


#endif //JOSEPH_JOSEPHBYSEQUENCE_H
