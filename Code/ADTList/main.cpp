#include <iostream>
#include "Adt_List_Sequence.h"

using namespace std;

bool Visit(int i);

bool (*funP)(int);

bool compare(int a, int b);

int main() {
    SqList L;

    /**
     * 函数测试部分
     */

    //创建List
    InitList(L);

    for (int i = 0; i <10 ; ++i) {
        ListInsert(L,i+1,i+1);
    }


    funP = &Visit;

    //遍历函数测试
    ListTraverse(L, funP);

    //删除函数测试
    cout << "删除之前List的当前长度：" << L.length << endl;
    int e;
    ListDelete(L, 1, e);
    cout << "删除List的第0个元素后List的长度：" << L.length << endl;
    cout << "具体元素信息：" << endl;
    ListTraverse(L, funP);
    cout << "删除的元素为： " << e << endl;


    //求前驱函数测试
    cout << "元素3的前驱：" << endl;
    PriorElem(L, 3, e);
    cout << e << endl;

    //求后继函数测试
    cout << "元素3的后继：" << endl;
    NextElem(L, 3, e);
    cout << e << endl;

    //Compare函数测试

    cout<<"list此时是否为空："<<ListEmpty(L)<<endl;



    //清空函数测试

    ClearList(L);
    cout << "调用Clear函数后List的长度：" << endl;
    cout << L.length << endl;





    //销毁List
    if (DestroyList(L)) {
        printf("销毁成功！\n");
    }
    return 0;
}


bool Visit(int i) {
    cout << i << endl;
}

bool compare(int a, int b) {
    if (a > b) {
        return true;
    }
}