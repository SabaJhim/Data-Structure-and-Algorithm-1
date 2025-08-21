#include<iostream>
#include<fstream>

using namespace std;

template<typename T>class Node{
public:
    T element;
    Node* next;

    Node(const T& value,Node* nextT=NULL){
        element=value;
        next=nextT;
    }
    Node(Node* nextT=NULL){
        next=nextT;
    }

   Node(const Node& a ){
            element=a.element;
            next=new Node;
            next=a.next;
        }



};

template <typename T>class Queue{
private:
    int length;
    Node<T>* Front;
    Node<T>* Rear=new Node<T>();
    Node<T>* temp=new Node<T>();
    Node<T>* RearPrev=new Node<T>();

public:

    void print(T a){
        ofstream outputFile;
        outputFile.open("list_output1.txt",ios_base::app);
        if(a==-2){

            cout<<'<';
            outputFile<<'<';
              temp=Front;
        for(int i=0;temp->next!=NULL;i++){
                if(i==0){
                    cout<<'|';
                    outputFile<<'|';
                }
            cout<<temp->element<<" ";
            outputFile<<temp->element<<" ";
            temp=temp->next;
        }
        cout<<'>'<<endl;
        outputFile<<'>'<<endl;
        return;

    }
            cout<<'<';
            outputFile<<'<';
              temp=Front;
        for(int i=0;temp->next!=NULL;i++){
                if(i==0){
                    cout<<'|';
                    outputFile<<'|';
                }
            cout<<temp->element<<" ";
            outputFile<<temp->element<<" ";
            temp=temp->next;
        }
        cout<<'>'<<endl;
        outputFile<<'>'<<endl;
        cout<<a<<endl;
        outputFile<<a<<endl;



}
    Queue(T* arr,int C){
        Front=new Node<T>;
        Front->next=NULL;
        Rear=Front;
        length=0;
        for(int i=0;i<C;i++){
                Enqueue(arr[i]);
        }
        length=C;

    }
    ~Queue(){
         while(temp->next!=NULL){
                temp=Front;
            Front=Front->next;
            delete temp;
        }
        delete Front;
    }



    void Enqueue(T e){
        Rear->element=e;
        RearPrev=Rear;
        Rear->next=new Node<T>;
        Rear=Rear->next;
        Rear->next=NULL;
        length++;
    }

    T dequeue(){
       if(length==0){return -1;}
       else{
            temp=Front;
        Front=Front->next;
        length--;
       }
       return temp->element;
    }

    int Length(){
        return length;
    }

    T frontValue(){
        if(length==0){return -1;}
        else{
            return Front->element;
        }
    }
    T rearValue(){
        if(length==0){return -1;}
        else{
            return RearPrev->element;
        }
    }
    T leaveQueue(){
        if(length==0){
            return -1;}
        if(length==1){
                Rear=RearPrev;
                Rear->next=NULL;
                length--;
                return RearPrev->element;}
        temp=Front;
        for(int i=0;temp->next!=RearPrev;temp=temp->next){
            cout<<""<<endl;
        }
        RearPrev=temp;
        Rear=temp->next;
        Rear->next=NULL;
        length--;
        return (temp->next)->element;
    }
    void Clear(){
         while(temp->next!=NULL){
                temp=Front;
            Front=Front->next;
            delete temp;
        }
        Front=new Node<T>;
         Front->next=NULL;
        Rear=Front;
        length=0;
    }



};

template<typename T>class Stack{
private:
    int length;
    Node<T>* Top=new Node<T>;
    Node<T>*TopPrev=new Node<T>;
    Node<T>* Head=new Node<T>;
    Node<T>* temp=new Node<T>;

public:
    void print(T a){
         ofstream outputFile;
         outputFile.open("list_output1.txt",ios_base::app);
        if(a==-2){
            cout<<'<';
            outputFile<<'<';
              temp=Head;
        for(int i=0;temp->next!=NULL;temp=temp->next){
                if(i==length-1){
                    cout<<'|';
                    outputFile<<'|';
                }
            cout<<temp->element<<" ";
            outputFile<<temp->element<<" ";
            i++;
        }
        cout<<'>'<<endl;
        outputFile<<'>'<<endl;
        return;

    }
    else{
            cout<<'<';
            outputFile<<'<';
              temp=Head;
        for(int i=0;temp->next!=NULL;temp=temp->next){
                if(i==length-1){
                    cout<<'|';
                    outputFile<<'|';
                }
            cout<<temp->element<<" ";
            outputFile<<temp->element<<" ";
            i++;
        }
        cout<<'>'<<endl;
        outputFile<<'>'<<endl;
        cout<<a<<endl;
        outputFile<<a<<endl;
    }


}


    Stack(T* arr,int C){
        length=0;
        Head=Top;
        for(int i=0;i<C;i++){
            Push(arr[i]);
        }
        length=C;

    }
    ~Stack(){
        while(Head->next!=NULL){
            temp=Head;
            Head=Head->next;
            delete temp;
        }
        delete Head;

    }

    void Push(T e){
        Top->element=e;
        TopPrev=Top;
        Top->next=new Node<T>;
        Top=Top->next;
        Top->next=NULL;
        length++;
    }

    T pop(){

        if(length==0){return -1;}
        if(length==1){
            Top=TopPrev;
            Top->next=NULL;
            length--;
            return Top->element;
        }
        else{
           temp=Head;
           for(int i=0;temp->next!=TopPrev;i++){
               temp=temp->next;
           }
           Top=TopPrev;
           Top->next=NULL;
           TopPrev=temp;
           length--;
           return Top->element;
        }
    }
    int Length(){
        return length;
    }
    T topValue(){
        if(length==0){return -1;}
        else{
            return TopPrev->element;
        }
    }

    void Clear(){
        while(Head->next!=NULL){
            temp=Head;
            Head=Head->next;
            delete temp;
        }
        Head=new Node<T>;
        Head->next=NULL;
        Top=Head;
        TopPrev=Head;
        length=0;
    }
};


/*int main(){
    int a1[4];

    Stack<int> ob(a1,0);
    ob.printList();
    ob.Push(5);
    ob.printList();
    ob.Push(6);
    ob.printList();
    int a=ob.pop();
    cout<<a<<endl;
    ob.printList();
    a=ob.pop();
    cout<<a<<endl;
    ob.printList();
    cout<<ob.pop()<<endl;
    ob.printList();
    cout<<ob.Length()<<endl;
    cout<<ob.topValue()<<endl;
    ob.Push(90);
    ob.printList();
    ob.Push(33);
    ob.printList();
    cout<<ob.Length()<<endl;
    cout<<ob.topValue()<<endl;
    ob.Push(78);
    ob.Push(65);
    ob.Clear();
    ob.printList();
    ob.Push(45);
    ob.printList();
    cout<<ob.Length()<<endl;
    cout<<ob.topValue()<<endl;
    ob.pop();
    ob.printList();



}*/
