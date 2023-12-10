


#include <iostream>
using namespace std;


class Node{
    private:
        int data;
        Node *nextnode;
    public:
        Node(): data(0), nextnode(nullptr){};
        Node(int _data): data(_data),nextnode(nullptr){};
        ~Node(){};

        Node * getNextNode();
        void setNextNode(Node *newNode);
        void setData(int _data);
        int getData(){
            return data;
        }
};

class LinkedList : public Node{
    private: 
        Node * headptr;
        Node *pushptr;
        int count;

    public:
        LinkedList(): headptr(nullptr), pushptr(nullptr), count(0){
            headptr = new Node();
            pushptr = headptr;
        }
        ~LinkedList(){};

        static LinkedList *getHandle();
        void push(int _data);
        void findMelement(int m);
        void printelem();

};

Node* Node::getNextNode(){
    return nextnode;
}
void Node :: setData(int _data){
    data = _data;
}
void Node::setNextNode(Node *newNode){
    nextnode = newNode;
}
LinkedList * LinkedList::getHandle(){
    LinkedList * hdl = new LinkedList();
    return hdl;
}

void LinkedList::printelem(){
    Node* temp = headptr;
    cout << "all elements are: ";
    while(temp != nullptr){
        cout << temp->getData()<<", ";
        temp = temp->getNextNode();
    }
    cout <<endl;
}

void LinkedList::push(int _data){
     if(count == 0){
        //this is the first element;
        pushptr ->setData(_data);
        count++;
        return;
     }
     Node *tempNode = new Node(_data);
     pushptr->setNextNode(tempNode);
     pushptr = pushptr->getNextNode();
     count++;
     return;
}

void LinkedList::findMelement(int m){
      int h=0,l=m-1;
      Node *l_node = headptr;
      Node *m_node = headptr;
      bool found = 0;
      
      while(l_node != nullptr){       
        if((h-l) > 0 ){
            //update m 
            m_node = m_node->getNextNode();
            l++;
        }
        else if((h-l)== 0) found = 1;

        l_node = l_node->getNextNode();
        h++;
      }
        if(h - m > 0){
        cout <<"found? "<<found << " mth element "<< m_node->getData() << "from L "<<l <<endl;}

        else cout<< "m "<< m<<" outside range of l "<<l<<endl;

        return;
}


int main(){

    LinkedList *list = LinkedList::getHandle();

    for (int i = 1 ; i<6;i++){
        list->push(i*5);
    }

    list->printelem();
    list->findMelement(6);
    return 0;


}


