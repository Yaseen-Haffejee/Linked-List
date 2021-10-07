#include <iostream>


using namespace std;

//Link defines a node that will contain data and a pointer to the next link in the LinkedList
class Link {
    public:

    int value ;
    Link * next;
    Link(int val){
        value = val;
    }

};

class LinkedList{
    public:
    //We only ever need the head
    Link * Head = nullptr;

    //Return the tail of the LinkedList
    Link * getLastLink(){

        Link * curr = Head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        return curr;
    }

    // Returns the number of elements in the linked list
    int getLength(){
        int length = 0;
        Link * curr = Head;
        while(curr->next != nullptr){
            length ++; 
            curr = curr->next;
        }
        // We add 1 to the length since the while loop terminates when curr->next == nullptr 
        // as a result the tail is not included in the length so we add it before we return 
        length++;
        return length;

    }

    // Adding to the front of the LinkedList
    void PushFront(int val){
        if(Head == nullptr){
            Head = new Link(val);
        }
        else{
            Link * Node = new Link(val);
            Node->next = Head;
            Head = Node;
        }
    }
    //Adding to the back of the LinkedList
    void PushBack(int val){
        if(Head == nullptr){
            Head = new Link(val);
        }
        else{
            Link * tail = getLastLink();
            Link * node = new Link(val);
            tail->next = node;
        }
    }
    //Removing the first link
    void PopFront(){
        Link * temp = Head->next;
        Head->next = nullptr;
        delete Head;
        Head = temp ;
    }
    //Removing the Last link
    void PopBack(){
        //Traverse until the second last Link 
        Link * curr = Head;
        //Prev will hold the second last link
        Link * prev = Head;

        while(curr->next != nullptr){
            prev = curr;
            curr = curr->next;
        }

        delete curr;
        //Set next to null since second last link becomes the last link
        prev->next = nullptr;
    }

    //Getting a link at a certain index
    Link * getLink(int index){
        Link * curr ;
        //Get how many elements in the linked list
        int length = getLength();
        if(index == length ){
            //If they want the laste element we call call getlastLink method
            curr = getLastLink();
        }
        else if (index ==0){
            //If index is 0, we return the head
            curr = Head;
        }
        else{
            //Counnt and update curr until count == index
            int count = 0;
            curr = Head;
            while(count != index ){
                curr = curr->next;
                count++;
            }
        }
        return curr;

    }

    // Inserting a new link at a given index
    void insertAt(int index, int value){
        int length = getLength();
        //Insert at the front of the LinkedList
        if(index ==0){
            PushFront(value);
        }
        // Insert at the end of the LinkedList
        else if (index == length){
            PushBack(value);
        }
        else{
            Link * curr = Head;
            Link * prev;
            int position = 0;
            //loop until the index they want to insert
            while(position < index ){
                prev = curr;
                curr = curr->next;
                position++;
            }
            Link * toBeAdded = new Link(value);
            //set prev->next to the new link and make the new link point to curr
            prev->next = toBeAdded;
            toBeAdded->next = curr;

        }
    }

    //Removing a link at a given index
    void deleteAt(int index){

        int length = getLength();
        //Removing the first element of linked list
        if(index == 0){
            PopFront();
        }
        //Removing the last element of linked list
        else if(index == length){
            PopBack();
        }
        //Removing at an index
        else{
            int position = 0;
            Link * curr = Head;
            Link * Prev = Head;
            while(position < index){
                Prev = curr;
                curr = curr->next;
                position++;
            }
            Prev->next = curr->next;
            delete curr;
        }

    }

    void PrintLinkedList(){
        Link * curr = Head;

        while(curr->next != nullptr){
            cout<<curr->value << " -> ";
            curr = curr -> next;
        }
        cout<<curr->value<<endl;
    }

};


int main(){

    LinkedList  myList =  LinkedList();

    for(int i=1;i<10;i++){
        myList.PushBack(i);
    }
    myList.PrintLinkedList();
    cout<<myList.getLength()<<endl;
    myList.deleteAt(3);
    myList.PrintLinkedList();



    return 0;
}