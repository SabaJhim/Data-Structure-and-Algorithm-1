#include<iostream>
#include<fstream>
using namespace std;



template <typename T> class MyList{

private:
    int K,X,curr;
    T* Array;



    void printArray(MyList<int> *ob,int a){

    ofstream outputFile;
    if(a==-2){outputFile.open("list_output.txt");}
    else{
        outputFile.open("list_output.txt",ios_base::app);
    }

    if(K==0){
        outputFile<<'<'<<'>'<<endl;
    }
    else {

     for(int i=0;i<K;i++){

        int* A=new int[K];
         A=Array;

        if(i==0)outputFile<<'<';
        if(i==curr)outputFile<<'|';
        outputFile<<A[i]<<" ";
        if(i==K-1){
                outputFile<<'>';
                outputFile<<endl;
                 break;}

    }
    }
    if(a!=-2){outputFile<<a<<endl;}
    outputFile.close();

}




public:

//***Constructor***
    MyList(){
        K=2;
        X=2;
        curr=0;
        *Array=NULL;
    }

//***Constructor***

    MyList(T Aray[],int length,int capacity){
        K=length;
        X=capacity;
        curr=2;
        Array=new T[X];
        for(int i=0;i<K;i++){
            Array[i]=Aray[i];
        }
        printArray(this,-2);

    }
//***Copy Constructor***

    MyList(const MyList& o){
          K=o.K;
        X=o.X;
        curr=o.curr;
        Array=new T[X];
        for(int i=0;i<K;i++){
            Array[i]=o.Array[i];
        }

    }

//***Destructor***

    ~MyList(){delete [] Array;}

//***Returns  the number of Elements***
//Time complexity->Order of 1
    int Size(){
        printArray(this,K);
        return K;
    }
//***Push an element in current position***
//Time complexity->Order of n

    void push(T e ){
        if(K<=X){
        for(int i=K;i>curr;i--){
            Array[i]=Array[i-1];
        }
        Array[curr]=e;
        ++K;
        }

        else if(K>X){

                T* temp;
                X=2*X;
            temp=new T[X];
            for(int i=0;i<K;i++){
                temp[i]=Array[i];
            }
        Array=temp;

        for(int i=K;i>curr;i--){
            Array[i]=Array[i-1];
        }
        Array[curr]=e;
        ++K;


        }
        printArray(this,-1);
    }

    //***Push an element at the back***
    //Time complexity->Order of 1

    void pushBack(T e){
          if(K<=X){
        Array[K]=e;
        ++K;
        }

       else if(K>X){
                T* temp;
                X=2*X;
            temp=new T[X];
            for(int i=0;i<K;i++){
                temp[i]=Array[i];
            }
        Array=temp;
        Array[K]=e;
       ++K;

        }
        printArray(this,-1);

    }

    //***Erase and return the current element
    //Time complexity->Order of n

    T Erase(){

        T temp=Array[curr];
        if(K>X/2){
        for(int i=curr;i<K;i++){
            Array[i]=Array[i+1];
        }
        K--;
        }
        else{
            for(int i=curr;i<K;i++){
            Array[i]=Array[i+1];
        }
        for(int i=K+1;i<X;i++){
            delete (Array+i);
        }
        X=K;
        K--;

        }
        printArray(this,temp);
        return temp;
    }

    //***Makes beginning of the list as current position***
    //Time complexity->Order of 1

    void setToBegin(){
        curr=0;
        printArray(this,-1);
    }
   //***Makes end of the list as current position***
    //Time complexity->Order of 1


    void setToEnd(){
        curr=K-1;
        printArray(this,-1);
    }

    //Moves the current position one step left
    //Time Complexity->Order of 1

    void prev(){
        if(curr!=0)curr=curr-1;
        printArray(this,-1);
    }

    //***Moves the current position one step right***
    //Time complexity->Order of 1

    void next(){
        if(curr<K-1)curr=curr+1;
        printArray(this,-1);
    }
    //***Return the position of the current element***
    //Time complexity->Order of 1

    int currPos(){
        printArray(this,curr);
        return curr;
    }

//***Set current position***
//Time complexity->Order of 1
    void setToPos(int a){
        curr=a;
        printArray(this,-1);
    }

//***Return Current element***
//Time complexity->Order of 1

    T getValue(){
        printArray(this,Array[curr]);
        return Array[curr];
    }

//***Return the position of item if it exists. Else returns -1***
//Time complexity->Order of n

    int Find(T a) {
        for(int i=0;i<K;i++){
            if(Array[i]==a){
                printArray(this,i);
                    return i;
        }
        }
        printArray(this,-1);
        return -1;
    }

//***Clears the List
//Time complexity->Order of n

    void clear(){
        delete[] Array;
        K=0;
        curr=0;
        Array=new T[X];
        printArray(this,-1);
    }





};



