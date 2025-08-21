#include<iostream>
#include<fstream>
#include<string>
#include"ArrayImplement.cpp"
//#include"listImplement.cpp"

using namespace std;

int main(){
    int lengthQ,lengthS,capacityQ,capacityS,number;
    int* mainArrayQ;
    int* mainArrayS;
    int* command;

    ifstream inputFile;
    string inSS;


    inputFile.open("input.txt");


     if(inputFile.is_open()){
    getline(inputFile,inSS,' ');
    lengthQ=stoi(inSS);
    getline(inputFile,inSS);
    capacityQ=stoi(inSS);
       mainArrayQ=new int[lengthQ];
       for(int i=0;i<lengthQ;i++){
            if(i==lengthQ-1){
                getline(inputFile,inSS);
            mainArrayQ[i]=stoi(inSS);
            }
            else{
        getline(inputFile,inSS,' ');
        mainArrayQ[i]=stoi(inSS);

            }

       }
       getline(inputFile,inSS,' ');
    lengthS=stoi(inSS);
    getline(inputFile,inSS);
    capacityS=stoi(inSS);
       mainArrayS=new int[lengthS];
       for(int i=0;i<lengthS;i++){
            if(i==lengthS-1){
                getline(inputFile,inSS);
            mainArrayS[i]=stoi(inSS);
            }
            else{
        getline(inputFile,inSS,' ');
        mainArrayS[i]=stoi(inSS);

            }

       }

      getline(inputFile,inSS);
       number=stoi(inSS);
        command=new int[2*number];

       for(int i=0;i<number*2;i++){
       if(i%2==0) getline(inputFile,inSS,' ');
       if(i%2==1)getline(inputFile,inSS);
        command[i]=stoi(inSS);

       }


    }

   Queue<int>obj1(mainArrayQ,lengthQ,capacityQ);
   Stack<int>obj2(mainArrayS,lengthS,capacityS);
    //Queue<int>obj1(mainArrayQ,lengthQ);
     //Stack<int>obj2(mainArrayS,lengthS);
     obj1.print(-2);
     obj2.print(-2);

      int i=0;
      int a;

      while(i<number){
        switch(command[2*i]){
        case 1:
            obj1.Clear();
            obj1.print(-1);
            break;
        case 2:
            obj1.Enqueue(command[2*i+1]);
            obj1.print(-1);
            break;
        case 3:
             a=obj1.dequeue();
            obj1.print(a);
            break;
        case 4:
             a=obj1.Length();
            obj1.print(a);
            break;
        case 5:
            a=obj1.frontValue();
            obj1.print(a);
            break;
        case 6:
            a=obj1.rearValue();
            obj1.print(a);
            break;
        case 7:
            a=obj1.leaveQueue();
            obj1.print(a);
            break;
        case 8:
            obj2.Clear();
            obj2.print(-1);
            break;
        case 9:
            obj2.Push(command[2*i+1]);
            obj2.print(-1);
            break;
        case 10:
            a=obj2.pop();
            obj2.print(a);
            break;
        case 11:
             a=obj2.Length();
            obj2.print(a);
            break;
        case 12:
             a=obj2.topValue();
            obj2.print(a);
            break;

        }
        i++;



      }





    inputFile.close();
}


