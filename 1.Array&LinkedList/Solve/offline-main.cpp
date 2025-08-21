#include<fstream>
#include<iostream>
#include<string>
#include"ArrayImplement.cpp"
//#include "LListImplement.cpp"

using namespace std;






int main(){
    int length,capacity,number;
    int* mainArray;
    int* command;

    ifstream inputFile;
    ofstream outputFile;
    string inSS;


    inputFile.open("list_input.txt");


     if(inputFile.is_open()){
    getline(inputFile,inSS,' ');
    length=stoi(inSS);
    getline(inputFile,inSS);
    capacity=stoi(inSS);
       mainArray=new int[length];
       for(int i=0;i<length;i++){
            if(i==length-1){
                getline(inputFile,inSS);
            mainArray[i]=stoi(inSS);
            }
            else{
        getline(inputFile,inSS,' ');
        mainArray[i]=stoi(inSS);

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

    //MyList<int>ob(mainArray,length);
    MyList<int> ob(mainArray,length,capacity);
      int i=0;

      while(i<number){
        switch(command[2*i]){
        case 1:
            ob.Size();
            break;
        case 2:
            ob.push(command[2*i+1]);
            break;
        case 3:
            ob.pushBack(command[2*i+1]);
            break;

        case  4:
            ob.Erase();
            break;
        case 5:
            ob.setToBegin();
            break;
        case 6:
            ob.setToEnd();
            break;
        case 7:
            ob.prev();
            break;
        case 8:
            ob.next();
            break;
        case 9:
            ob.currPos();
            break;
        case 10:
            ob.setToPos(command[2*i+1]);
            break;
        case 11:
            ob.getValue();
            break;
        case 12:
            ob.Find(command[2*i+1]);
            break;
        case 13:
            ob.clear();

        }
        i++;



      }





    inputFile.close();
}



