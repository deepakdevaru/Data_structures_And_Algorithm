/*------------------------------------------------------------------------------------------
    -------------------------- STACK IMPLEMENTATION ------------------------------------
----------------------------------------------------------------------------------------------*/

#include <iostream>
  class Node{
    private:
      int data;
      Node *nextnode;
   public:
     Node(): data(0), nextnode(NULL){};
     Node(const int & _data) : data(_data),nextnode(NULL){};
     ~Node(){ 
     };

     Node * GetNextNode()const;
     void SetNextNode(Node *node);
     int GetData()const;
     void SetData(int &_data);
  };

     class StackElement: public Node{
      private:
         Node *headptr;
         int count;
      public:
         StackElement():headptr(nullptr), count(0){
            headptr = new Node();
         };
         ~StackElement()
          {
            while(headptr != nullptr){
               Node *node = headptr;
               headptr = headptr ->GetNextNode();
               delete node;
            }
            count = 0;
          };
         static StackElement * Gethandle(void);
          void push ( int data );
          void pop();
          int GetCount(void)const;
          void PrintStack()const;
     };

   void Node::SetData(int &_data){
      data = _data;
   }

   Node * Node::GetNextNode(void)const{
      
       return nextnode;
    }
   void Node::SetNextNode(Node *data){
      nextnode = data;
   }

   int Node::GetData()const{
      return data;
   }

   StackElement * StackElement::Gethandle(){
      StackElement *handle = new StackElement();
      return handle;
   }

   void StackElement::push( int data){
      Node *oldhead = headptr;
      Node *dataptr = new Node(data);

      if(count == 0){
         headptr->SetData(data);
         count++;
         return;
      }
      headptr = dataptr;
      dataptr->SetNextNode(oldhead);
      count++;
   }

   void StackElement::pop(){
      Node *oldhead = headptr;
      if(count == 0) return;

      headptr = oldhead->GetNextNode();

      delete oldhead;
      count --;
   }

   void StackElement::PrintStack()const{

        std::cout<<"count: "<<count <<std::endl;
        Node *traverseptr = headptr;

        while(traverseptr!=nullptr){
         std::cout<<traverseptr->GetData()<<", ";
         traverseptr = traverseptr->GetNextNode();
        }
        std::cout<<std::endl;
   }

    int main()
    {
      StackElement *stackptr = StackElement::Gethandle();
      stackptr->push(9);
      stackptr->push(10);
      stackptr->push(11);
      stackptr->push(12);

      stackptr->PrintStack();

      stackptr->pop();
      stackptr->pop();

      stackptr->PrintStack();


      return 0;
    }

