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
    QueueNode<Type> *front, *rear; //����ָ��
public:
    Queue() : rear(NULL), front(NULL) {}

    ~Queue() {
        QueueNode<Type> *p;
        while (front != NULL) {  //�������ͷ�
            p = front;
            front = front->link;
            delete p;
        }
    }

    void enQueue(const Type &item) {
        if (front == NULL) {    //��, ������һ�����
            front = rear = new QueueNode<Type>(item, NULL);
        } else {                //���в���, ����
            rear = rear->link = new QueueNode<Type>(item, NULL);
        }
    }

    Type deQueue() {        //ɾȥ��ͷ��㣬�����ض�ͷԪ�ص�ֵ
        assert (!IsEmpty());          //�жӿյĶ���
        QueueNode<Type> *p = front;
        Type returnValue = p->data;   //�����ͷ��ֵ
        front = front->link;          //�¶�ͷ
        if (front == NULL) rear = NULL;
        delete p;
        return returnValue;
    }

    bool IsEmpty() {
        return front == NULL;
    }
};


#endif //DATASTRUCTURE_QUEUE_H
