#include<iostream>
#include<fstream>
#include "Heap.cpp"
using namespace std;

class Customer
{
public:

    int arrived;
    int dept;

    Customer(int a=0,int d=0)
    {
        arrived=a;
        dept=d;
    }

    bool operator==(Customer ob2){
        if(dept==ob2.dept)return true;
        else{
            return false;
        }
    }
    bool operator>=(Customer ob2){
        if(dept>=ob2.dept)return true;
        else{
            return false;
        }
    }
        bool operator<=(Customer ob2){
        if(dept<=ob2.dept)return true;
        else{
            return false;
        }
    }
        bool operator>(Customer ob2){
        if(dept>ob2.dept)return true;
        else{
            return false;
        }
    }
        bool operator<(Customer ob2){
        if(dept<ob2.dept)return true;
        else{
            return false;
        }
    }
    Customer operator=(Customer ob2){
        arrived=ob2.arrived;
        dept=ob2.dept;
        return *this;
    }

};

int main()
{

    ifstream inFile;
    string inSS;
    inFile.open("input.txt");
    ofstream outFile;
    outFile.open("output.txt");
    int C=0;
    if(inFile.is_open()){
        getline(inFile,inSS);
        C=stoi(inSS);
    }
    Customer temp(0,0);
    MinHeap<Customer> mainArray=MinHeap<Customer>(C);
    int a=0;
    int d=0;
    Customer Max=Customer(0,0);
    int C_arrived=0;
    int C_dept=0;
    Customer* Solution=new Customer[C];





    if(inFile.is_open()){
        while(!inFile.eof()){
            getline(inFile,inSS,' ');
            a=stoi(inSS);
            getline(inFile,inSS);
            d=stoi(inSS);
            temp=Customer(a,d);
            mainArray.Insert(temp);

        }
    }

    /*for(int i=0; i<C; i++)
    {
        cin>>a>>d;
        temp=Customer(a,d);
        mainArray.Insert(temp);

    }*/
    mainArray.HeapSort();


    int n=0;

    for(int i=0; i<C; i++)
    {


        if(mainArray.sorted[i].arrived>=C_dept)
        {
            Solution[n]=mainArray.sorted[i];
            C_dept=mainArray.sorted[i].dept;
            n++;
        }

    }
    cout<<"Solution"<<endl;
    cout<<n<<endl;
    outFile<<n<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<Solution[i].arrived<<" "<<Solution[i].dept<<endl;
        outFile<<Solution[i].arrived<<" "<<Solution[i].dept<<endl;
    }

    return 0;
}
