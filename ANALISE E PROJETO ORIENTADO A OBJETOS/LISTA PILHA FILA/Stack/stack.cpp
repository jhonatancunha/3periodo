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

    void setTop(Node *node){
      this->top = node;
    }


  public:
    Stack(){
      this->top = NULL;
      this->size = 0;
    }

    ~Stack(){
      while(!this->isEmpty())
        this->pop();
    }

    int isEmpty(){
      return (this->size > 0) ? false : true;
    }

    void push(int value){
      Node *node = new Node(value);
      node->setNext(this->getTop());
      this->setTop(node);
      this->size++;
    }

    void pop(){
      Node *removed = this->getTop();
      this->setTop(removed->getNext());
      this->size--;
      delete removed;
    }

    Node *getTop(){
      return this->top;
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
  Stack *s = new Stack();

  s->push(2);
  s->push(10);
  s->push(50);
  s->push(99);
  s->push(3);


  s->pop();
  s->print();

  delete s;
  return 0;
}