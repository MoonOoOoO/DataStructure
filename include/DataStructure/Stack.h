#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <iostream>
#include <assert.h>

template<class Type>
class Stack {
private:
    int top;          //栈顶数组指针
    Type *elements;   //栈数组，栈不空时elements[0]是栈中第一个元素
    int maxSize;      //栈最大可容纳元素个数
public:
    Stack(int n) : top(-1), maxSize(n) {    //建立一个最大尺寸为s的空栈，若分配不成功则错误处理
        elements = new Type[maxSize];
        assert(elements != 0);
    }

    ~Stack() {
        delete[] elements;
    }

    void push(const Type &item) {
        elements[++top] = item;    //加入新元素
    }

    Type pop() {
        return elements[top--];      //退出栈顶元素
    }

    Type getTop() {
        return elements[top];        //取出栈顶元素
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == maxSize - 1;
    }
};

#endif //DATASTRUCTURE_STACK_H
