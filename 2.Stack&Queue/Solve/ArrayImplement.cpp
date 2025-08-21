#include<iostream>
#include<fstream>

using namespace std;

static int defaultSize=10;

template<typename T> class Queue
{
private:
    int length,capacity;
    int Front,Rear;
    T* Arr;

public:

    void print(T a)
    {
        ofstream outputFile;
    if(a==-2){
            outputFile.open("list_output.txt",ios_base::app);
     cout<<'<';
    outputFile<<'<';

         int j=Front;
        for(int i=0; i<length; i++)
        {   if(i==0){cout<<'|';
                      outputFile<<'|';}
            cout<<this->Arr[j]<<" ";
            outputFile<<this->Arr[j]<<" ";
            j=(j+1)%capacity;
        }
        cout<<'>';
        outputFile<<'>'<<endl;
        cout<<endl;
        return;
    }
    else{
        outputFile.open("list_output.txt",ios_base::app);
    }
    cout<<'<';
    outputFile<<'<';

         int j=Front;
        for(int i=0; i<length; i++)
        {   if(i==0){cout<<'|';
                      outputFile<<'|';}
            cout<<this->Arr[j]<<" ";
            outputFile<<this->Arr[j]<<" ";
            j=(j+1)%capacity;
        }
        cout<<'>';
        outputFile<<'>'<<endl;
        cout<<endl;
        cout<<a<<endl;
        outputFile<<a<<endl;
    }


    Queue(T* arr,int C,int X=defaultSize)
    {
        Arr=new T[X];
        capacity=X;
        for(int i=0; i<C; i++)
        {
            Arr[i]=arr[i];
        }
        Front=0;
        Rear=C;
        length=C;
    }

    ~Queue()
    {
        delete [] Arr;
    }

    Enqueue(T a)
    {

        if(length<capacity)
        {
            Arr[Rear]=a;
            Rear=(Rear+1)%capacity;
            length++;

        }

        else if(length>=capacity)
        {
            int X=capacity;
            capacity=2*capacity;

            T* temp=new T[capacity];
            int i=0,j=Front;
            while(i<length)
            {
                temp[i]=Arr[j];
                i++;
                j=(j+1)%X;
            }
            Arr=temp;
            Front=0;
            Rear=length;
            Arr[Rear]=a;
            Rear=(Rear+1)%capacity;
            length++;
        }
    }

 T dequeue(){
     if(length==0){return -1;}
     else{
            int temp=Front;
        Front=(Front+1)%capacity;
        length--;
        return Arr[temp];
     }
 }

 int Length(){
     return length;
 }

 T frontValue(){
     if(length==0){return -1;}
     return Arr[Front];
 }

 T rearValue(){
     if(length==0){return -1;}
     else if(Rear==0){
        return Arr[capacity-1];
     }
     return Arr[Rear-1];
 }

 T leaveQueue(){
     if(length==0){return -1;}
     else if(Rear==0){
        Rear=capacity-1;
        length--;
        return Arr[Rear];
     }
     else{
        Rear=Rear-1;
        length--;
        return Arr[Rear];
     }
 }

 void Clear(){
     delete[] Arr;
     Arr=new T[defaultSize];
     Front=0;
     Rear=0;
     capacity=defaultSize;
     length=0;
 }



};



template<typename T> class Stack{

private:
    int length,capacity;
    int Top;
    T* Arr;

public:

    void print(T a){
        fstream outputFile;
        outputFile.open("list_output.txt",ios_base::app);
        if(a==-2){
            cout<<'<';
        outputFile<<'<';

        for(int i=0;i<length;i++){
                if(i==length-1){
                    cout<<'|';
                    outputFile<<'|';
                }
            cout<<Arr[i]<<" ";
            outputFile<<Arr[i]<<" ";
        }
        cout<<'>'<<endl;
        outputFile<<'>'<<endl;
        return ;
        }

        cout<<'<';
        outputFile<<'<';

        for(int i=0;i<length;i++){
                if(i==length-1){
                    cout<<'|';
                    outputFile<<'|';
                }
            cout<<this->Arr[i]<<" ";
            outputFile<<this->Arr[i]<<" ";
        }
        cout<<'>'<<endl;
        outputFile<<'>'<<endl;
        outputFile<<a<<endl;
        cout<<a<<endl;
    }


    Stack(T* arr,int C,int X=defaultSize){
        Arr=new T[X];
        length=C;
        capacity=X;
        for(int i=0;i<C;i++){
            Arr[i]=arr[i];
        }
        Top=C;
    }

    ~Stack(){
        delete[] Arr;
    }

 void Push(T e){
     if(length<capacity){
        Arr[Top]=e;
        Top++;
        length++;
     }
     else if(length>=capacity){
        int X=capacity;
        capacity=2*capacity;
        T* temp=new T[capacity];
        for(int i=0;i<length;i++){
            temp[i]=Arr[i];
        }
        Top=length;
        Arr=temp;
        Arr[Top]=e;
        Top++;
        length++;
     }
 }

 T pop(){
     if(length==0){return -1;}
     Top--;
     length--;

     if(length<capacity/2){

         capacity=capacity/2;
     }
      return Arr[Top];
 }

 int Length(){
     return length;
 }

 T topValue(){
     if(Top==0){return -1;}
     else{
        return Arr[Top-1];
     }
 }

 void Clear(){
     delete [] Arr;
     Arr=new T[defaultSize];
     length=0;
     capacity=defaultSize;
     Top=0;
 }


};


/*int main()
{

    int a[8];
    Stack<int>obj(a,0,8);

    obj.printArray();
    obj.pop();
    obj.printArray();
    obj.Push(5);
    obj.printArray();
    obj.Push(12);
    obj.printArray();
    obj.Push(27);
    obj.printArray();
    obj.Push(33);
    obj.printArray();
    obj.Push(55);
    obj.printArray();
    obj.Push(34);
    obj.printArray();
    obj.Push(90);
    obj.printArray();
    obj.Push(67);
    obj.printArray();
    obj.Push(88);
    obj.printArray();
    obj.pop();
    obj.printArray();
    obj.pop();
    obj.printArray();
    obj.pop();
    obj.printArray();
    obj.pop();
    obj.printArray();
    obj.pop();
    obj.printArray();
    obj.pop();
    obj.printArray();
    obj.Clear();
    obj.printArray();
    obj.Push(9);
    obj.printArray();



}*/
