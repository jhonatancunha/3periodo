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

class Queue{
  private:
    Node* front;
    Node* end;
    int size;

  public:
    Queue(){
      this->front = NULL;
      this->end = NULL;
      this->size = 0;
    }

    ~Queue(){
      while(!this->isEmpty())
        this->dequeue();
    }

    int isEmpty(){
      return (this->size > 0) ? false : true;
    }

    void enqueue(int value){
      Node *node = new Node(value);

      if(this->isEmpty()){
        this->front = node;
      }else{
        this->end->setNext(node);
      }

      this->end = node;
      this->size++;
    }

    void dequeue(){
      if(this->isEmpty()) return;

      Node *removed = this->getFront();
      this->front = removed->getNext();
      

      delete removed;
      this->size--;
    }

    Node *getFront(){
      return this->front;
    }


    int getSize(){
      return this->size;
    }


    void print(){
      if(this->isEmpty()){
        std::cout << "Queue is Empty!" << '\n';
        return;
      }

      std::cout << "Front -> ";
      Node *aux = this->getFront();
      for(int i = 0; i < this->getSize(); i++){
        std::cout << aux->getValue() << ' ';
        aux = aux->getNext();
      }
      std::cout << '\n';
    } 
};




int main(int argc, char *argv[]){
  Queue *p = new Queue();

  p->enqueue(2);
  p->enqueue(10);
  p->enqueue(50);
  p->enqueue(99);
  p->enqueue(3);

  p->print();
  

  delete p;
  p->print();
  
  return 0;
}