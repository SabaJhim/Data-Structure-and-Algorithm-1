#include<iostream>
#include<fstream>

using namespace std;

template<typename E> class Vector
{
public:
    E* arr;
    int length,Capacity;

    Vector(int c=5)
    {
        Capacity=c;
        arr=new E[Capacity];
        length=0;
    }
    void push(E a)
    {
        if(length<Capacity)
        {
            arr[length]=a;
            length++;
        }
        else
        {
            Capacity=2*Capacity;
            E* temp=new E[Capacity];
            for(int i=0; i<length; i++)
            {
                temp[i]=arr[i];
            }
            arr=temp;
            arr[length]=a;
            length++;
        }
    }
};


template <typename E>class vertex
{
public:
    E key;
    Vector<E>* obj=new Vector<E>(5);

    int visited;
    int l=0;
    vertex(int vis=0)
    {
        visited=vis;
    }


};
template<typename E>class Pair
{
public:
    E u;
    E v;
    Pair(E x=0,E y=0)
    {
        u=x;
        v=y;
    }
};

template <typename E>class Graph{

public:
    int v,e;
    int found=0;
    int curr=0;
    vertex<E>* in;
    //----------------------

    E* BFS_Queue;
    E* DFS_Stack;
    int DFS_Stack_Count=0;
    int BFS_Queue_Count=0;
    int next=0;
    //------------------------------

    Pair<E>* BFS_E_Array;
    int BFS_E_Count=0;
    Pair<E>* DFS_E_Array;
    int DFS_E_Count;
    //-----------------------

   /* E* AllArray;
    int All_count=0;
    int shortest=0;
    E* ShortArray;*/





Graph(int ver,int edge){
        v=ver;
        e=edge;
        in=new vertex<E>[v+1];
        BFS_Queue=new E[v];
        DFS_Stack=new E[v];
        BFS_E_Array=new Pair<E>[e];
        DFS_E_Array=new Pair<E>[e];
        //AllArray=new E[v];
        //ShortArray=new E[v];
        //shortest=v;

    }


    void GraphPush(E root,E adj)
    {
        for(int i=0; i<curr; i++)
        {
            if(in[i].key==root)
            {
                in[i].obj->push(adj);
                if(Check(adj)==-1)
                {
                    in[curr].key=adj;
                    curr++;
                }
                found=1;
                break;
            }

        }
        if(found!=1)
        {
            in[curr].key=root;
            in[curr].obj->push(adj);

            curr++;
            if(Check(adj)==-1)
            {
                in[curr].key=adj;
                curr++;
            }
        }
        found=0;
    }

    void print(ofstream& outFile)
    {
        for(int i=0; i<curr; i++)
        {
            cout<<" "<<in[i].key<<"->";
            outFile<<" "<<in[i].key<<"->";
            for(int j=0; j<in[i].obj->length; j++)
            {
                cout<<in[i].obj->arr[j]<<",";
                outFile<<in[i].obj->arr[j]<<",";
            }
            cout<<endl;
            outFile<<endl;
        }
    }

        void BDFSGraphPush(E root,E adj)
    {
        for(int i=0; i<curr; i++)
        {
            if(in[i].key==root)
            {
                in[i].obj->push(adj);
                found=1;
                break;
            }

        }
        if(found!=1)
        {
            in[curr].key=root;
            in[curr].obj->push(adj);

            curr++;
        }
        found=0;
    }

    int BFS_method(int k)
    {

        if(in[k].visited==0)
        {
            int e=0;
            in[k].visited=1;


            for(int j=0; j<BFS_Queue_Count; j++)
            {
                if(in[k].key==BFS_Queue[j])
                {
                    e=1;
                    break;
                }
            }

            if(e!=1)
            {
                BFS_Queue[BFS_Queue_Count]=in[k].key;
                BFS_Queue_Count++;

            }
            e=0;

            for(int i=0; i<in[k].obj->length; i++)
            {
                int d=0;
                for(int j=0; j<BFS_Queue_Count; j++)
                {
                    if(in[k].obj->arr[i]==BFS_Queue[j])
                    {
                        d=1;
                        break;
                    }
                }
                if(d==0)
                {
                    BFS_E_Array[BFS_E_Count]=Pair<E>(in[k].key,in[k].obj->arr[i]);
                    BFS_E_Count++;
                    BFS_Queue[BFS_Queue_Count]=in[k].obj->arr[i];
                    BFS_Queue_Count++;
                }
                d=0;
            }
        }
        next++;
        if(BFS_Queue_Count>next)
        {
            return BFS_Queue[next];
        }
        else
        {
            return -1;
        }


    }


    int Check(E key)
    {
        for(int i=0; i<v; i++)
        {
            if(in[i].key==key)
            {
                return i ;
                break;
            }

        }
        return -1;
    }


    int BFS(E root)
    {
        int i=Check(root);
        int z=0;

        while(i!=-1)
        {
            z=BFS_method(i);
            if(z!=-1)
            {
                i=Check(z);

            }
            else
            {
                break;
            }

        }
    }

    void  DFS(E root)
    {
        E k;
        E en=6;
        int i=Check(root);
        if(i==-1)
        {
            DFS_Stack[DFS_Stack_Count]=root;
            DFS_Stack_Count++;
            return;
        }
        if(in[i].visited==0)
        {
            in[i].visited=1;
            DFS_Stack[DFS_Stack_Count]=in[i].key;
            DFS_Stack_Count++;
            for(int j=0; j<in[i].obj->length; j++)
            {
                int pos=Check(in[i].obj->arr[j]);
                if(in[pos].visited==0)
                {
                    DFS_E_Array[DFS_E_Count]=Pair<E>(in[i].key,in[pos].key);
                    DFS_E_Count++;
                }
                DFS(in[i].obj->arr[j]);

            }
        }
    }

    /*void AllNodes(E root)
    {
        int s=5;
        int pos=0;
        if(root==s)
        {
            AllArray[All_count]=root;
            All_count++;
            for(int i=0;i<All_count;i++){
                cout<<AllArray[i]<<" ";
            }
            if(shortest>=All_count){
                shortest=All_count;
                for(int i=0;i<shortest;i++){
                    ShortArray[i]=AllArray[i];
                }
            }
            cout<<endl;
            return ;
        }
        else if(pos==-1)

        {
            return ;
        }

        else
        {
            pos=Check(root);
            if(in[pos].visited==0&&pos!=-1)
            {   in[pos].visited=1;
                AllArray[All_count]=in[pos].key;
                All_count++;

                for(int j=0; j<in[pos].obj->length; j++)
                {
                    int c;
                    c=Check(in[pos].obj->arr[j]);
                    if(in[c].visited==0){
                    AllNodes(in[pos].obj->arr[j]);
                    c=Check(in[pos].obj->arr[j]);
                    in[c].visited=0;
                    All_count--;
                    }

                }
            }
        }

    }*/

    void Clear()
    {
        for(int i=0; i<v; i++)
        {
            in[i].visited=0;
        }
    }


};


int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string inSS;
    string inSS1;
    int ver,edge;
    int u,v;
    int root;
    Graph<int>*ob;



    inputFile.open("input.txt");
    outputFile.open("output.txt");


    if(inputFile.is_open())
    {
        getline(inputFile,inSS,' ');
        ver=stoi(inSS);
        getline(inputFile,inSS);
        edge=stoi(inSS);
        ob=new Graph<int>(ver,edge);
        for(int i=0; i<edge; i++)
        {
            getline(inputFile,inSS,' ');
            u=stoi(inSS);
            getline(inputFile,inSS);
            v=stoi(inSS);
            ob->GraphPush(u,v);
        }
        getline(inputFile,inSS);
        root=stoi(inSS);

    }
    Graph<int>* BFS_Tree=new Graph<int>(ver,edge);
    Graph<int>* DFS_Tree=new Graph<int>(ver,edge);
    //ob->print();

    //BFS->Printing:

     ob->BFS(root);

    cout<<"BFS Predecessor SubGraph G(V,E):"<<endl;
    cout<<"---------------------------------"<<endl;
    outputFile<<"BFS Predecessor SubGraph G(V,E):"<<endl;
    cout<<"---------------------------------"<<endl;



    cout<<"Set of V: ";
    outputFile<<"Set of V: ";
    for(int i=0; i<ob->BFS_Queue_Count; i++)
    {
        cout<<ob->BFS_Queue[i]<<" ";
        outputFile<<ob->BFS_Queue[i]<<" ";
    }

    cout<<endl;
    outputFile<<endl;

    cout<<"Set of E: ";
    outputFile<<"Set of E: ";
    for(int i=0; i<ob->BFS_E_Count; i++)
    {
        BFS_Tree->BDFSGraphPush(ob->BFS_E_Array[i].u,ob->BFS_E_Array[i].v);
        cout<<"("<<ob->BFS_E_Array[i].u<<","<<ob->BFS_E_Array[i].v<<")"<< "";
        outputFile<<"("<<ob->BFS_E_Array[i].u<<","<<ob->BFS_E_Array[i].v<<")"<< "";
    }
    cout<<endl;
    outputFile<<endl;
    cout<<endl;
    outputFile<<endl;
    cout<<"BFS Tree Printing: "<<endl;
    outputFile<<"BFS Tree Printing: "<<endl;
    BFS_Tree->print(outputFile);
    ob->Clear();
    cout<<endl<<endl;
    outputFile<<endl<<endl;



    //DFS->Tree Printing:
    cout<<"DFS predecessor Subgraph G(V,E):"<<endl;
    cout<<"---------------------------------"<<endl;
    outputFile<<"DFS predecessor Subgraph G(V,E):"<<endl;
    outputFile<<"---------------------------------"<<endl;
    cout<<endl;
    outputFile<<endl;

    ob->DFS(root);

    cout<<"Set of V: ";
    outputFile<<"Set of V: ";

    for(int i=0; i<ob->DFS_Stack_Count; i++)
    {
        cout<<ob->DFS_Stack[i]<<" ";
        outputFile<<ob->DFS_Stack[i]<<" ";
    }
    cout<<endl;
    outputFile<<endl;

    cout<<"Set of E: ";
    outputFile<<"Set of E: ";
    for(int i=0; i<ob->DFS_E_Count; i++)
    {
        DFS_Tree->BDFSGraphPush(ob->DFS_E_Array[i].u,ob->DFS_E_Array[i].v);
        cout<<"("<<ob->DFS_E_Array[i].u<<","<<ob->DFS_E_Array[i].v<<")"<< "";
        outputFile<<"("<<ob->DFS_E_Array[i].u<<","<<ob->DFS_E_Array[i].v<<")"<< " ";

    }
    cout<<endl;
    outputFile<<endl;
    cout<<endl;
    outputFile<<endl;

    cout<<"Printing DFS Tree "<<endl;
     outputFile<<"Printing DFS Tree "<<endl;

      DFS_Tree->print(outputFile);
      ob->Clear();




}



