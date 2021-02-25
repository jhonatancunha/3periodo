#include <iostream>

class Node {
  private:
    int value;
    Node* next;

  public:
    Node(int value){
      this->value = value;
      this->next = NULL;
    }

    int getValue(){
      return this->value;
    }

    Node* getNext(){
      return this->next;
    }

    void setNext(Node* next){
      this->next = next;
    }
};

class Stack{
  private:
    Node* top;
    int size;

    void addSize(){
      this->size++;
    }

    void removeSize(){
      this->size--;
    }

  public:
    Stack(){
      this->top = NULL;
      this->size = 0;
    }

    ~Stack(){
      Node* top = this->getTop();
      while(!this->isEmpty()){
        setTop(top->getNext());
        delete top;
        top = this->getTop();
        this->removeSize();
      }
    }

    int isEmpty(){
      return (this->size > 0) ? false : true;
    }

    void push(int value){
      Node *node = new Node(value);
      node->setNext(this->getTop());
      this->setTop(node);
      this->addSize();
    }

    void pop(){
      Node *removed = this->getTop();
      this->setTop(removed->getNext());
      this->removeSize();
      delete removed;
    }

    Node *getTop(){
      return this->top;
    }

    void setTop(Node *node){
      this->top = node;
    }

    int getSize(){
      return this->size;
    }


    void print(){
      if(this->isEmpty()){
        std::cout << "Stack is Empty!" << '\n';
        return;
      }

      std::cout << "Top -> ";
      Node *aux = this->getTop();
      for(int i = 0; i < this->getSize(); i++){
        std::cout << aux->getValue() << ' ';
        aux = aux->getNext();
      }

      std::cout << "<- Base" << '\n';
    } 
};




int main(int argc, char *argv[]){

  Stack *p = new Stack();

  p->push(2);
  
  p->push(10);
  p->push(50);
  p->push(99);
  p->push(3);

  p->print();

  p->pop();
  p->print();

  p->~Stack();
  p->print();
  return 0;
}