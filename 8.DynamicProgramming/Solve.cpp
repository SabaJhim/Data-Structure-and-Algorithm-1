#include<iostream>
#include<fstream>

using namespace std;

class item{
public:
    int id;
    int value;
    int weight;
    item(int i=0,int v=0,int w=0){
        id=i;
        value=v;
        weight=w;
    }
};

int main(){

    ifstream inputFile;
    string inSS;
    string inSS1;
    ofstream outputFile;
    inputFile.open("input.txt");
    outputFile.open("output.txt");
    int C=0;
    item* a;
    int Solution[C];
    int c=0,d=0;
    int w=0;
    int index=0;

    if(inputFile.is_open()){
        getline(inputFile,inSS);
        C=stoi(inSS);
        a= new item[C+1];

    for(int i=1;i<=C;i++){
            getline(inputFile,inSS,' ');
            c=stoi(inSS);
            getline(inputFile,inSS);
            d=stoi(inSS);
      a[i]=item(i,d,c);

    }
        getline(inputFile,inSS);
        w=stoi(inSS);

}

  int matrix[C+1][w+1];


    for(int i=0;i<=C;i++){
        for(int j=0;j<=w;j++){
            if(i==0){
                matrix[i][j]=0;
            //cout<<i<<" "<<j<<" "<<C<<"G"<<" "<<" "<<matrix[i][j]<<" "<<endl;
            }
            else if(a[i].weight>j){
                matrix[i][j]=matrix[i-1][j];
                //cout<<i<<" "<<j<<" "<<C<<" "<<"H"<<" "<<matrix[i][j]<<" "<<endl;
            }
            else if(a[i].weight<=j){

                if(matrix[i-1][j]>(matrix[i-1][j-(a[i].weight)]+a[i].value)){
                    matrix[i][j]=matrix[i-1][j];
                    //cout<<i<<" "<<j<<" "<<C<<" "<<"I"<<" "<<matrix[i][j]<<" "<<endl;
                }
                    else if(matrix[i-1][j]<=(matrix[i-1][j-(a[i].weight)]+a[i].value)){
                    matrix[i][j]=matrix[i-1][j-(a[i].weight)]+a[i].value;
                   // cout<<i<<" "<<j<<" "<<C<<" "<<"J"<<" "<<matrix[i][j]<<" "<<endl;
                }
            }
        }
    }


    cout<<"Solution"<<" "<<matrix[C][w]<<endl;
    outputFile<<matrix[C][w]<<endl;

   /* for(int p=0;p<=C;p++){
        for(int q=0;q<=w;q++){
            cout<<matrix[p][q]<<" ";
        }
        cout<<endl;
    }*/
    int sum=0;
    int i=C;
    int j=w;



    for(int i=C;i>0;i--){
            if((matrix[i-1][j]<=(matrix[i-1][j-(a[i].weight)]+a[i].value))&&a[i].weight<=j){

                //cout<<a[i].weight<<" "<<a[i].value<<endl;
                if(j>=0){
                Solution[index]=a[i].weight;
                sum=sum+a[i].value;
                index++;
                }
                j=j-a[i].weight;
            }
    }

    for(int il=0;il<index;il++){
        cout<<Solution[il]<<" ";
        outputFile<<Solution[il]<<" ";
    }
    cout<<endl;
    outputFile<<endl;
    return 0;



}
