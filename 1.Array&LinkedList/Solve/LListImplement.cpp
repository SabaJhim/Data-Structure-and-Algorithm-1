#include<iostream>
#include<fstream>
#include<string>



using namespace std;

template <typename T> class Node{
    public:
        T value;
        Node* next;

        Node(Node* nextVal=NULL){
            next=nextVal;
        }

        Node(const Node& a ){
            value=a.value;
            next=new Node;
            next=a.next;
        }
        ~Node(){delete next;}



};

template <typename T> class MyList{
private:
    Node<T>* head;
    Node<T>* present;
    Node<T>* tail;
    int K;
    int curr;

    void initialize(){
          present=head=tail=new Node<T>;
        K=0;
        curr=0;

    }

void printLList(MyList<int> *OB,int a){

    ofstream outputFile;
    if(a==-2){outputFile.open("list_output.txt");}
    else{
        outputFile.open("list_output.txt",ios_base::app);
    }

    if(head->next==NULL){
        outputFile<<'<'<<'>'<<endl;
    }
    else {

        Node<T>* A=new Node<T>;
         A=head;


     while(A!=NULL){

        if(A==head)outputFile<<'<';
        if(A==present)outputFile<<'|';
        outputFile<<A->value<<" ";

        if(A->next==NULL)
            {outputFile<<'>';
            outputFile<<endl;
            break;
            }
         if(A->next!=NULL)A=A->next;


        }
    }
    if(a!=-2){outputFile<<a<<endl;}
    outputFile.close();

}


public:

    MyList(){
      initialize();
    }
    MyList(int length){
        initialize();
        K=length;
    }

    MyList(T Aray[],int length){

        initialize();

        K=length;

        for(int i=0;i<K;i++){
            present->next=new Node<T>;
            present->value=Aray[i];

            if(i<K-1){
            if(present==tail)tail=present->next;
            present=tail;
            }

            curr=i;
        }
        tail->next=new Node<T>;
         tail->next=NULL;
        present=(head->next)->next;
        curr=2;
        printLList(this,-2);

    }


    ~MyList(){

        while(head!=NULL){
            present=head;
            head=head->next;
        }
        delete present;
    }


   int Size(){
        printLList(this,K);
        return K;
    }


    void push(T e ){

        if(present==head){
            K++;
            present=new  Node<T>;
            present->value=e;
            present->next=head;
            head=present;
            tail= present;
            cout<<head->value<<endl;

        }
        else if(present==tail&&present!=head){
            K++;
             tail->next=new Node<T>;
         tail=tail->next;
         tail->value=e;
         tail->next=NULL;
        }
       else{ K++;
        Node<T>* temp=new Node<T>;
        T tempValue=present->value;
        temp=present->next;

        present->next=new Node<T>;
        present->value=e;
        (present->next)->value=tempValue;
        (present->next)->next=temp;

       }

        printLList(this,-1);


    }


    void pushBack(T e){
          K++;

        Node<T>* temp=new Node<T>;

         temp->value=e;
         temp->next=NULL;
         //tail->next=new Node<T>;
         tail->next=temp;
         tail=tail->next;








         printLList(this,-1);


    }


    T Erase(){
        T temp=present->value;
        Node<T>* tempNode=head;
        Node<T>* tempNode2=head;
        Node<T>* tempNode3=new Node<T>;
        if(present==head){

            tempNode3=head->next;
                head=tempNode3;
                head->value=tempNode3->value;
                head->next=tempNode3->next;
                present=head;
                cout<<head->value<<endl;
         K--;

        }
        else if(present->next==NULL){
            while(tempNode2->next->next!=NULL){
                tempNode2=tempNode2->next;
            }
            present=tempNode2;
            present->next=NULL;
            K--;

        }
        else{

           while(tempNode->next!=present){
                 tempNode=tempNode->next;

           }
           tempNode->next=present->next;
           present=present->next;
           cout<<head->value<<endl;

        K--;
        }

        printLList(this,temp);
        return temp;
    }

   void setToBegin(){
        curr=0;
        present=head;
        printLList(this,-1);
    }

    void setToEnd(){
        curr=K-1;
        while(present->next!=NULL){
            present=present->next;

        }
         printLList(this,-1);
    }

    void prev(){
        Node<T>* temp=new Node<T>;
        if(curr!=0&&present!=head){
            curr=curr-1;
            temp=head;
            while(temp->next!=present){
                temp=temp->next;
            }
            present=temp;
        }
        printLList(this,-1);
    }

    void next(){
        if(present->next!=NULL){curr=curr+1;
        present=present->next;}
        printLList(this,-1);
    }

    int currPos(){
        printLList(this,curr);
        return curr;
    }

    void setToPos(int a){
        curr=a;
        present=head;
        for(int i=0;i<curr;i++){
            present=present->next;
        }
        printLList(this,-1);

    }

    T getValue(){
        printLList(this,present->value);
        return present->value;

    }

    int Find(T a) {
        Node<T>* temp=head;

        for(int i=0;i<K;i++){
            if(temp->value==a){
                    printLList(this,i);
                    return i;

            }
            temp=temp->next;
        }
        printLList(this,-1);
        return -1;
    }

    void clear(){
          while(head!=NULL){
            present=head;
            head=head->next;
        }
        delete present;

        initialize();
        printLList(this,-1);
    }





};

