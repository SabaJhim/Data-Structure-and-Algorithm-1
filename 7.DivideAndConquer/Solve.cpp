#include<iostream>
#include<fstream>

using namespace std;


class Pair
{
public:
    int x;
    int y;
    Pair(int a=0,int b=0)
    {
        x=a;
        y=b;
    }
};

class Inversion
{
public:
    int p=0;
    int Count=0;
    Pair* PairArray;

    Inversion(int C=0)
    {
        PairArray=new Pair[C*C];
    }

    void Merge(int*a,int l,int m,int r)
    {
        int C_temp=0;
        int n1=m-l+1;
        int n2=r-m;
        int leftArray[n1];
        int rightArray[n2];
        for(int i=0; i<n1; i++)
        {
            leftArray[i]=a[l+i];

        }
        for(int i=0; i<n2; i++)
        {
            rightArray[i]=a[m+1+i];
        }
        int i=0;
        int j=0;
        int k=l;
        while(i<n1&&j<n2)
        {
            if(leftArray[i]<=rightArray[j])
            {
                a[k]=leftArray[i];
                k++;
                i++;
            }
            else if(leftArray[i]>rightArray[j])
            {
                a[k]=rightArray[j];
                C_temp=n1-i;
                Count=Count+C_temp;
                for(int d=0;d<C_temp;d++){
                PairArray[p]=Pair(leftArray[i+d],rightArray[j]);
                p++;
                }
                j++;
                k++;

            }
        }
        while(i<n1)
        {
            a[k]=leftArray[i];
            k++;
            i++;

        }
        while(j<n2)
        {
            a[k]=rightArray[j];
            k++;
            j++;

        }

    }

    void InverseSearch(int* a,int left,int right)

    {
        if(left<right)
        {
            int mid=(left+right)/2;

            InverseSearch(a,left,mid);
            InverseSearch(a,mid+1,right);

            Merge(a,left,mid,right);

        }

    }
};


int main()
{
    ifstream inputFile;
    string inSS;
    string inSS1;
    ofstream outputFile;
    inputFile.open("input.txt");
    outputFile.open("output.txt");
    int a=0;
    int* arr;

    if(inputFile.is_open()){
    while(!inputFile.eof()){
        getline(inputFile,inSS);
        a=stoi(inSS);
        arr=new int[a];

        for(int i=0;i<a;i++){
            getline(inputFile,inSS,' ');
            arr[i]=stoi(inSS);
        }
    }

    }


    Inversion M(a);

    M.InverseSearch(arr,0,a-1);
    int t=M.Count;
    cout<<t<<endl;
    outputFile<<t<<endl;
    cout<<"Inverted pairs are :"<<endl;
    outputFile<<"Inverted pairs are :"<<endl;
    for(int i=0; i<t; i++)
    {
        cout<<"("<<M.PairArray[i].x<<","<<M.PairArray[i].y<<")"<<" ";
        outputFile<<"("<<M.PairArray[i].x<<","<<M.PairArray[i].y<<")"<<" ";
    }
    cout<<endl;
    outputFile<<endl;
}
