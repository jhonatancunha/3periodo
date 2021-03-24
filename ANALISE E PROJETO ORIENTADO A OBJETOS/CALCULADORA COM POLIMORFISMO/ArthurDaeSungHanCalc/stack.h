#pragma once

class Node{
private:
    int value;
    Node *next;

public:
    Node(int value);
    int getValue();
    Node *getNext();
    void setNext(Node *next);
};

class Stack{
private:
    Node *top;
    int size;
    void setTop(Node *node);

public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int value);
    void pop();
    void popStack(int *v);
    int elementOnTop();
    Node *getTop();
    int getSize();
};