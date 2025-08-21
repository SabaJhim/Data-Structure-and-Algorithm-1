#include<iostream>
#include<fstream>
//#include"ArrayImplement.cpp"
#include "listImplement.cpp"

using namespace std;

class Pair
{
public:
    int s,c,id;
    Pair(int i=0,int a=0,int b=0)
    {
        id=i;
        s=a;
        c=b;
    }
    Pair operator=(Pair ob2)
    {
        id=ob2.id;
        s=ob2.s;
        c=ob2.c;

        return *this;
    }
    bool operator==(Pair ob2)
    {
        return (id==ob2.id)&&(s==ob2.s);
    }
    friend ostream& operator<<(ostream& stream,Pair ob);
};

ostream& operator<<(ostream& stream,Pair ob)
{
    stream<<"("<<ob.id<<","<<" "<<ob.s<<" "<<","<<ob.c<<")";
    return stream;
}

Pair* SortId(Pair* ob,int length)
{
    Pair temp;
    for(int i=0; i<length; i++)
    {
        for(int j=i; j<length; j++)
        {
            if(ob[i].id>ob[j].id)
            {
                temp=ob[i];
                ob[i]=ob[j];
                ob[j]=temp;
            }
        }
    }
    return ob;
}

Pair* SortTime(Pair* ob,int length)
{
    Pair temp;
    for(int i=0; i<length; i++)
    {
        for(int j=i; j<length; j++)
        {
            if(ob[i].s>ob[j].s)
            {
                temp=ob[i];
                ob[i]=ob[j];
                ob[j]=temp;
            }
        }
    }
    return ob;
}


int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string inSS;

    int totalCustomer;
    int totalTime;
    int start;
    int req;
    Pair* input;

    inputFile.open("Fifa_input.txt");
    outputFile.open("Fifa_output.txt");
    if(inputFile.is_open())
    {
        getline(inputFile,inSS,' ');
        totalCustomer=stoi(inSS);
        getline(inputFile,inSS);
        totalTime=stoi(inSS);
        input=new Pair[totalCustomer];

        for(int i=0; i<totalCustomer; i++)
        {
            getline(inputFile,inSS,' ');
            start=stoi(inSS);
            getline(inputFile,inSS);
            req=stoi(inSS);
            input[i]=Pair(i+1,start,req);

        }
    }
    SortTime(input,totalCustomer);

    Pair Q[totalCustomer];
    Pair S[totalCustomer];
    Pair Output[totalCustomer];
    //Queue<Pair> ob1(Q,0,8);
    //Stack<Pair> ob2(S,0,8);
    Queue<Pair>ob1(Q,0);
    Stack<Pair>ob2(S,0);
    int Console_One_time=0;
    int Consle_Two_time=0;
    int j=0;


    for(int i=0; i<totalCustomer; i++)
    {
        if(Console_One_time==0)
        {
            Console_One_time=input[i].s+input[i].c;
            Output[j]=Pair(input[i].id,Console_One_time,0);
            j++;

        }


        else if(input[i].s>=Console_One_time)
        {
            if(ob1.Length()>0)
            {
                Pair temp=ob1.dequeue();
                ob1.Enqueue(input[i]);
                Console_One_time=Console_One_time+temp.c;
                Output[j]=Pair(temp.id,Console_One_time,0);
                j++;
            }
            else
            {
                Console_One_time=input[i].s+input[i].c;
                Output[j]=Pair(input[i].id,Console_One_time,0);
                j++;

            }


        }
        else if(ob1.Length()<3)
        {
            ob1.Enqueue(input[i]);
        }

        else if(ob1.Length()==3&&input[i].s<Console_One_time)
        {
            if(Consle_Two_time==0)
            {
                Consle_Two_time=input[i].s+input[i].c;
                Output[j]=Pair(input[i].id,Consle_Two_time,0);
                j++;
            }
            else if(Consle_Two_time<input[i].s)
            {
                if(ob2.Length()>0)
                {
                    Pair temp=ob2.pop();
                    Output[j]=Pair(temp.id,Consle_Two_time+temp.c,0);
                    Consle_Two_time=Consle_Two_time+temp.c;
                    j++;
                    ob2.Push(input[i]);
                }
                else
                {
                    Output[j]=Pair(input[i].id,input[i].s+input[i].c,0);
                    Consle_Two_time=input[i].s+input[i].c;
                    j++;
                }
            }
            else if(Consle_Two_time>=input[i].s)
            {
                ob2.Push(input[i]);
            }

        }

    }

    while(ob1.Length()!=0)
    {

        Pair temp1=ob1.dequeue();
        if(Console_One_time>=totalTime)
        {
            Output[j]=Pair(temp1.id,-1,0);
            j++;
            continue;
        }
        else if(Console_One_time+temp1.c>=totalTime)
        {
            Output[j]=Pair(temp1.id,totalTime,0);
            Console_One_time=Console_One_time+temp1.c;
            j++;
            continue;
        }
        else
        {
            if(temp1.s>=Console_One_time)
            {
                Output[j]=Pair(temp1.id,temp1.s+temp1.c,0);
                Console_One_time=temp1.s+temp1.c;
                j++;
            }
            else
            {
                Output[j]=Pair(temp1.id,Console_One_time+temp1.c,0);
                Console_One_time=Console_One_time+temp1.c;
                j++;


            }
        }
    }

    while(ob2.Length()!=0)
    {
        Pair temp1=ob2.pop();
        if(Consle_Two_time>=totalTime)
        {
            Output[j]=Pair(temp1.id,-1,0);
            j++;
            continue;
        }
        else if(Consle_Two_time+temp1.c>=totalTime)
        {
            Output[j]=Pair(temp1.id,totalTime,0);
            Consle_Two_time=Consle_Two_time+temp1.c;
            j++;
            continue;
        }
        else
        {
            if(Consle_Two_time>=temp1.s)
            {
                Output[j]=Pair(temp1.id,Consle_Two_time+temp1.c,0);
                Consle_Two_time=Consle_Two_time+temp1.c;
                j++;
            }
            else
            {
                Output[j]=Pair(temp1.id,temp1.s+temp1.c,0);
                Consle_Two_time=temp1.s+temp1.c;
            }
        }
    }
    SortId(Output,totalCustomer);


    for(int i=0; i<totalCustomer; i++)
    {
        cout<<Output[i].id<<" "<<'>'<<" ";
        outputFile<<Output[i].id<<'>'<<" ";
        if(Output[i].s==-1)
        {
            cout<<'c'<<endl;
            outputFile<<'c'<<endl;
        }
        else
        {
            cout<<Output[i].s<<endl;
            outputFile<<Output[i].s<<endl;
        }

    }

}




