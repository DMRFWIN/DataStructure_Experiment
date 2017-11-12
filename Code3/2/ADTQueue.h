//
// Created by dmrf on 17-11-11.
//

#ifndef INC_2_ADTQUEUE_H
#define INC_2_ADTQUEUE_H

#include <iostream>

using namespace std;

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QNode *front;//队头指针
    QNode *rear;//队尾指针
    int size;
} LinkQueue;

bool InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = new QNode();
    if (!Q.front) {
        cout << "创建队列失败！" << endl;
        return false;
    }

    Q.size=0;
    Q.front->next = NULL;
    return true;
}

bool DestroyQueue(LinkQueue &Q) {
    if (!Q.front) {
        cout << "队列尚未创建，无法销毁！" << endl;
        return false;
    }
    QNode *p;
    while (Q.front) {
        p = Q.front;
        Q.front = p->next;
        free(p);
    }
    Q.front = Q.rear = NULL;
    Q.size=0;
    cout << "销毁队列成功～" << endl;
    return true;
}

bool ClearQueue(LinkQueue &Q) {
    if (!Q.front) {
        cout << "队列尚未创建，无法清空！" << endl;
        return false;
    }
    Q.rear = Q.front;
    Q.size=0;
    cout << "清空队列成功～" << endl;
    return true;
}

bool QueueEmpty(LinkQueue Q) {
    if (!Q.front) {
        cout << "队列尚未创建，无法判空！" << endl;
        return false;
    }
    if (Q.front == Q.rear) {
        cout << "队列为空～" << endl;
        return true;
    }
    cout << "队列不为空～" << endl;
    return false;
}

int QueueLength(LinkQueue Q) {
    if (!Q.front) {
        cout << "队列尚未创建，无法获取长度！" << endl;
        return -1;
    }

    cout<<"当前队列长度为："<<Q.size<<endl;
    return Q.size;
}

bool GetHead(LinkQueue Q, int &e) {
    if (!Q.front) {
        cout << "队列尚未创建，无法获取队队头！" << endl;
        return -1;
    }
    if(Q.front==Q.rear){
        cout<<"队列为空，无法获取队头！"<<endl;
        return false;
    }
    e = Q.front->next->data;
    cout << "成功获取队头：" << e << endl;
    return true;
}

bool EnQueue(LinkQueue &Q, int e) {

    if (!Q.front) {
        cout << "队列尚未创建，入队失败！" << endl;
        return false;
    }


    QNode *q = new QNode();
    q->data = e;
    q->next = NULL;

    /*
     * 因为插入第一个元素时Q.front=Q.rear,所以第一次元素入队时相当于Q.front->next=q;
     */
    Q.rear->next= q;
    Q.rear=q;
    Q.size++;
    cout<<"入队成功～"<<endl;
    return true;

}

bool DeQueue(LinkQueue &Q, int e) {
    if (!Q.front) {
        cout << "队列尚未创建，无法删除队头！" << endl;
        return false;
    }
    if (Q.front == Q.rear) {
        cout << "队列为空，无法删除队头！" << endl;
        return false;
    }

    QNode *p;
    p = Q.front;
    Q.front = Q.front->next;
    cout << "删除队头" << Q.front->data << "成功～" << endl;
    free(p);
    Q.size--;
    return true;
}

bool QueueTraverse(LinkQueue Q) {
    if (!Q.front) {
        cout << "队列尚未创建，无法遍历！" << endl;
        return false;
    }
    if (Q.front == Q.rear) {
        cout << "队列为空，没有元素可以被遍历～" << endl;
        return false;
    }
    QNode *p;
    p = Q.front->next;
    cout << "从队头到队尾遍历队列中的元素如下：" << endl;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }

    cout<<endl;
    return true;


}


#endif //INC_2_ADTQUEUE_H
