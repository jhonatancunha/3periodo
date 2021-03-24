#include "stack.h"
#include <iostream>

Node::Node(int value){
    this->value = value;
    this->next = NULL;
}

int Node::getValue(){
    return this->value;
}

Node *Node::getNext(){
    return this->next;
}

void Node::setNext(Node *next){
    this->next = next;
}

void Stack::setTop(Node *node){
    this->top = node;
}

Stack::Stack(){
    this->top = NULL;
    this->size = 0;
}

Stack::~Stack(){
    while (!this->isEmpty()) this->pop();
}

bool Stack::isEmpty(){
    return (this->size > 0) ? false : true;
}

void Stack::push(int value){
    Node *node = new Node(value);
    node->setNext(this->getTop());
    this->setTop(node);
    this->size++;
}

void Stack::pop(){
    Node *removed = this->getTop();
    this->setTop(removed->getNext());
    this->size--;
    delete removed;
}

void Stack::popStack(int *v){
    if (this->isEmpty()) return;
    int size = this->getSize();
    for (int i = 0; i < size; i++){
        v[i] = this->elementOnTop();
        this->pop();
    }
    this->~Stack();
}

int Stack::elementOnTop(){
    int element;
    Node *aux = this->getTop();
    element = aux->getValue();
    return element;
}

Node *Stack::getTop(){
    return this->top;
}

int Stack::getSize(){
    return this->size;
}