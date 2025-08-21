
#include<iostream>
#include<fstream>
#include<string>
#include"LListImplement.cpp"

using namespace std;




template <typename E>class LRUCache{
private:
    int capacity;
    int current;
    MyList<E> objectValue;
    MyList<E> objectKey;


public:
    LRUCache(int capacity){
        this->capacity=capacity;
        current= 0;
    }

    E get(E key ){
        E temp;
        int a=objectKey.Find(key);
        cout<<a<<endl;
        if(a!=-1){
            objectKey.setToPos(a);
            objectValue.setToPos(a);
            temp=objectValue.getValue();
            objectKey.Erase();
            objectValue.Erase();
            objectKey.pushBack(key);
            objectValue.pushBack(temp);
            objectKey.setToBegin();
            objectValue.setToBegin();
            return temp;
        }
        else{
            return -1;
        }
    }

    void put(E key,E value){
        if(current==0){
                objectKey.setToBegin();
                objectValue.setToBegin();
                objectKey.push(key);
                objectValue.push(value);
                current++;
        }
          else if(current<capacity){
            if(objectKey.Find(key)==-1){
                objectKey.pushBack(key);
                objectValue.pushBack(value);
                current++;
            }
            /*if(objectKey.Find(key)!=-1){
                int a=objectKey.Find(key);
                objectValue.setToPos(a);
                objectValue.push(value);
                objectValue.setToBegin();
                objectKey.setToBegin();
                current++;
            }*/
         }
         else if(current>=capacity){

                objectKey.setToBegin();
                objectValue.setToBegin();
                objectKey.Erase();
                objectValue.Erase();
                objectKey.pushBack(key);
                objectValue.pushBack(value);


         }

}
};

int main(){
    int C;
    int number;
    int a,key1,value1;


     ifstream inputFile;
     ofstream OutFile;
     string inSS;

      inputFile.open("Lru_input.txt");
      OutFile.open("Lru_output.txt");


            getline(inputFile,inSS);
            C=stoi(inSS);
            getline(inputFile,inSS);
            number=stoi(inSS);

            LRUCache<int> FinalOb(C);
            int data[number];

            for(int i=0;i<number;i++){
                    getline(inputFile,inSS,' ');
                    a=stoi(inSS);
                   //cout<<a<<' ';
                   if(a==2){
                   getline(inputFile,inSS,' ');
                   key1=stoi(inSS);
                   getline(inputFile,inSS);
                   value1=stoi(inSS);

                   FinalOb.put(key1,value1);
                   }

                  if(a==1){

                    getline(inputFile,inSS);
                    key1=stoi(inSS);

                   int c=FinalOb.get(key1);
                   OutFile<<c<<endl;
                   }

            }
            inputFile.close();
            OutFile.close();




    }





