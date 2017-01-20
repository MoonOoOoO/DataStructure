#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include <iostream>
#include <assert.h>

template<class Type>
class Queue;

template<class Type>
class QueueNode {
    friend class Queue<Type>;

private:
    Type data;
    QueueNode<Type> *link;

    QueueNode(Type d = 0, QueueNode *l = NULL) : data(d), link(l) {}
};

template<class Type>
class Queue {
private:
    QueueNode<Type> *front, *rear; //队列指针
public:
    Queue() : rear(NULL), front(NULL) {}

    ~Queue() {
        QueueNode<Type> *p;
        while (front != NULL) {  //逐个结点释放
            p = front;
            front = front->link;
            delete p;
        }
    }

    void enQueue(const Type &item) {
        if (front == NULL) {    //空, 创建第一个结点
            front = rear = new QueueNode<Type>(item, NULL);
        } else {                //队列不空, 插入
            rear = rear->link = new QueueNode<Type>(item, NULL);
        }
    }

    Type deQueue() {        //删去队头结点，并返回队头元素的值
        assert (!IsEmpty());          //判队空的断言
        QueueNode<Type> *p = front;
        Type returnValue = p->data;   //保存队头的值
        front = front->link;          //新队头
        if (front == NULL) rear = NULL;
        delete p;
        return returnValue;
    }

    bool IsEmpty() {
        return front == NULL;
    }
};


#endif //DATASTRUCTURE_QUEUE_H
