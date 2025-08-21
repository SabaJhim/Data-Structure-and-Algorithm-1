#include<iostream>
#include<cmath>
#include<string.h>


using namespace std;

template <typename E>class MinHeap
{
public:
    int Capacity;
    E* A;
    E* sorted;
    int Count;
    int child=0;
    int parent=0;
    bool found=true;

    MinHeap(int C=10)
    {
        A=new E[C];
        sorted=new E[C];
        Capacity=C;
        Count=0;
    }


    void Insert(E a)
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
                        E temp=A[child];
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
                E* temporary=new E[Capacity];
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
                        E temp=A[child];
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

    E FindMin()
    {
        if(Count==0)
        {
            return NULL;
        }
        return A[1];
    }

    E ExtractMin()
    {
        if(Count==0)
        {
            return NULL;
        }
        else if(Count==1)
        {
            Count--;
            return A[1];
        }

        else
        {
            E temp=A[1];
            A[1]=A[Count];
            Count--;
            int i=1;

            while(2*i<=Count)
            {
                if(A[2*i]<=A[2*i+1])
                {
                    if(A[i]>A[2*i])
                    {
                        E t=A[i];
                        A[i]=A[2*i];
                        A[2*i]=t;

                    }
                    i=2*i;

                }
                else if(A[2*i]>A[2*i+1])
                {
                    if(A[i]>A[2*i+1])
                    {
                        E t=A[i];
                        A[i]=A[2*i+1];
                        A[2*i+1]=t;

                    }
                    i=2*i+1;

                }
            }
            return temp;

        }


    }

    int Search(E key)
    {
        for(int i=1; i<=Count; i++)
        {
            if(A[i]==key)return i;
        }
        return NULL;
    }

    void HeapSort(){
        int initial=Count;
        for(int i=0;i<initial;i++){
            E t=ExtractMin();
            sorted[i]=t;
        }

    }
};


