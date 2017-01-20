#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <iostream>
#include <assert.h>

template<class Type>
class Stack {
private:
    int top;          //ջ������ָ��
    Type *elements;   //ջ���飬ջ����ʱelements[0]��ջ�е�һ��Ԫ��
    int maxSize;      //ջ��������Ԫ�ظ���
public:
    Stack(int n) : top(-1), maxSize(n) {    //����һ�����ߴ�Ϊs�Ŀ�ջ�������䲻�ɹ��������
        elements = new Type[maxSize];
        assert(elements != 0);
    }

    ~Stack() {
        delete[] elements;
    }

    void push(const Type &item) {
        elements[++top] = item;    //������Ԫ��
    }

    Type pop() {
        return elements[top--];      //�˳�ջ��Ԫ��
    }

    Type getTop() {
        return elements[top];        //ȡ��ջ��Ԫ��
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == maxSize - 1;
    }
};

#endif //DATASTRUCTURE_STACK_H
