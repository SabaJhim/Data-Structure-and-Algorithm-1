#include<iostream>
#include<cmath>
#include<string.h>
#include<fstream>
#include<sstream>

using namespace std;

class MinHeap
{
public:
    int Capacity;
    int* A;
    int Count;
    int child=0;
    int parent=0;
    bool found=true;

    MinHeap(int C=10)
    {
        A=new int[C];
        Capacity=C;
        Count=0;
        for (int i=1; i<Capacity; i++)
        {
            A[i]=-1;
        }
    }


    void Insert(int a)
    {
        if(Count==0)
        {
            A[1]=a;
            Count++;
        }
        else
        {
            if(Count+1<Capacity)
            {
                Count++;
                child=Count;
                parent=floor(Count/2);
                A[child]=a;

                while(child>1)
                {
                    if(A[child]<A[parent])
                    {
                        int temp=A[child];
                        A[child]=A[parent];
                        A[parent]=temp;

                        child=parent;
                        parent=floor(child/2);
                    }
                    else
                    {
                        break;
                    }
                }


            }
            else if(Count+1>=Capacity)
            {
                Capacity=Capacity*2;
                int* temporary=new int[Capacity];
                for(int i=1; i<=Count; i++)
                {
                    temporary[i]=A[i];
                }
                A=temporary;
                Count++;
                child=Count;
                parent=floor(Count/2);
                A[child]=a;

                while(child>1)
                {
                    if(A[child]<A[parent])
                    {
                        int temp=A[child];
                        A[child]=A[parent];
                        A[parent]=temp;

                        child=parent;
                        parent=floor(child/2);
                    }
                    else
                    {
                        break;
                    }
                }

            }

        }

    }

    int FindMin()
    {
        if(Count==0)
        {
            return -1;
        }
        return A[1];
    }

    int ExtractMin()
    {
        if(Count==0)
        {
            return -1;
        }
        else if(Count==1)
        {
            Count--;
            return A[1];
        }

        else
        {
            int temp=A[1];
            A[1]=A[Count];
            Count--;
            int i=1;

            while(2*i<=Count)
            {
                if(A[2*i]<=A[2*i+1])
                {
                    if(A[i]>A[2*i])
                    {
                        int t=A[i];
                        A[i]=A[2*i];
                        A[2*i]=t;

                    }
                    i=2*i;

                }
                else if(A[2*i]>A[2*i+1])
                {
                    if(A[i]>A[2*i+1])
                    {
                        int t=A[i];
                        A[i]=A[2*i+1];
                        A[2*i+1]=t;

                    }
                    i=2*i+1;

                }
            }
            return temp;

        }


    }

    int Search(int key)
    {
        for(int i=1; i<=Count; i++)
        {
            if(A[i]==key)return i;
        }
        return -1;
    }
    void DecreaseKey(int prevKey,int newKey)
    {
        int pos=Search(prevKey);
        if(pos==-1)
        {
            found=false;
            cout<<"This key is not found"<<endl;
        }
        else

        {
            found=true;

                A[pos]=newKey;
                child=pos;
                parent=floor(pos/2);


                while(child>1)
                {
                    if(A[child]<A[parent])
                    {
                        int temp=A[child];
                        A[child]=A[parent];
                        A[parent]=temp;

                        child=parent;
                        parent=floor(child/2);
                    }
                    else
                    {
                        break;
                    }
                }




 //end brackcet
            }
        }


    /* void DecreaseKey(int prevKey,int newKey)
     {
         int pos=Search(prevKey);
         if(pos==-1)
         {
             found=false;
             cout<<"This key is not found"<<endl;
         }
         else

         {
             found=true;
             if(Count==1)
             {
                 Count--;
             }

             else
             {
                 int temp=A[pos];
                 A[pos]=A[Count];
                 Count--;
                 int i=pos;

                 while(2*i<=Count)
                 {
                     if(A[2*i]<=A[2*i+1])
                     {
                         if(A[i]>A[2*i])
                         {
                             int t=A[i];
                             A[i]=A[2*i];
                             A[2*i]=t;

                         }
                         i=2*i;

                     }
                     else if(A[2*i]>A[2*i+1])
                     {
                         if(A[i]>A[2*i+1])
                         {
                             int t=A[i];
                             A[i]=A[2*i+1];
                             A[2*i+1]=t;

                         }
                         i=2*i+1;

                     }
                 }

             }
             Insert(newKey);

         }


     }*/

    void print(ofstream& outputFile)
    {
        int i=1;
        int level=0;
        while(i<=Count)
        {
            cout<<"level "<<level<<":"<<" ";
            outputFile<<"level "<<level<<":"<<" ";
            while(level<=log2(i)&&log2(i)<level+1)
            {
                if(i>Count)
                {
                    break;
                }
                cout<<A[i]<<" ";
                outputFile<<A[i]<<" ";
                i++;
            }
            level=level+1;
            cout<<endl;
            outputFile<<endl;
        }
    }


};


int main()
{

    ifstream inputFile;
    string inSS;
    string inSS1;
    string inSS2;
    string temp;
    int a;
    MinHeap obj;

    inputFile.open("input.txt");
    ofstream outputFile;
    outputFile.open("output.txt");
    if(inputFile.is_open())
    {
        while(!inputFile.eof())
        {
            getline(inputFile,inSS);
            stringstream temp1(inSS);
            getline(temp1,temp,' ');


            if(temp.compare("INS")==0)
            {
                getline(temp1,inSS1);
            }
            if(temp.compare("DEC")==0)
            {
                getline(temp1,inSS1,' ');
                getline(temp1,inSS2);
            }

            if(temp.compare("INS")==0)
            {
                a=stoi(inSS1);
                obj.Insert(a);
                cout<<"INSERTED "<<a<<endl;
                outputFile<<"INSERTED "<<a<<endl;
            }
            else if(temp.compare("FIN")==0)
            {
                int c=obj.FindMin();
                if(c==-1)
                {
                    cout<<"The heap is empty"<<endl;
                    outputFile<<"The heap is empty"<<endl;
                }
                else
                {
                    cout<<"FindMin returned "<<c<<endl;
                    outputFile<<"FindMin returned "<<c<<endl;
                }
            }
            else if(temp.compare("EXT")==0)
            {
                int c=obj.ExtractMin();
                if(c==-1)
                {
                    cout<<"The heap is empty"<<endl;
                    outputFile<<"The heap is empty"<<endl;
                }
                else
                {
                    cout<<"ExtractMin returned "<<c<<endl;
                    outputFile<<"ExtractMin returned "<<c<<endl;
                }
            }
            else if(temp.compare("DEC")==0)
            {
                a=stoi(inSS1);
                int b=stoi(inSS2);
                obj.DecreaseKey(a,b);
                if(obj.found==false)
                {
                    outputFile<<"The key is not found"<<endl;
                }
                if(obj.found==true)
                {
                    cout<<a<<" Decreased to "<<b<<endl;
                    outputFile<<a<<" Decreased to "<<b<<endl;
                }


            }
            else if(temp.compare("PRI")==0)
            {
                cout<<"Printing the Binary heap"<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - -"<<endl;
                outputFile<<"Printing the Binary heap"<<endl;
                outputFile<<"- - - - - - - - - - - -  - - - -"<<endl;
                obj.print(outputFile);
                cout<<"- - - - - - - - - - - - - - - - - - - -"<<endl;
                outputFile<<"- - - - - - - - - - - - - - - - -"<<endl;


            }

        }
    }
}

