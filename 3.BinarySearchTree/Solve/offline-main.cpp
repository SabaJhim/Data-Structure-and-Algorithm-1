#include<iostream>
#include<string.h>
#include"Offline-3.cpp"
#include<fstream>

using namespace std;



int main()
{

    ifstream inputFile;
    string inSS;
    string inSS1;
    int a;
    BST<int> obj;

    inputFile.open("input.txt");
    ofstream outputFile;
    outputFile.open("output.txt");
    if(inputFile.is_open())
    {
        while(!inputFile.eof())
        {
            getline(inputFile,inSS,' ');
            getline(inputFile,inSS1);

            if(inSS.compare("I")==0)
            {
                a=stoi(inSS1);
                obj.Insert(a);
                obj.print(obj.getRoot(),0,outputFile);
            }
            else if(inSS.compare("D")==0)
            {
                a=stoi(inSS1);
                obj.Delete(a);
                obj.print(obj.getRoot(),0,outputFile);
            }
            else if(inSS.compare("F")==0)
            {
                a=stoi(inSS1);
                bool b=obj.Find(a);
                if(b==true)
                {
                    cout<<"True"<<endl;
                    outputFile<<"True"<<endl;
                }
                else
                {
                    cout<<"False"<<endl;
                    outputFile<<"False"<<endl;
                }
            }
            else if(inSS.compare("T")==0)
            {
                if(inSS1.compare("In")==0)
                {

                    obj.inOrder(obj.getRoot(),outputFile);
                    outputFile<<endl;
                    cout<<endl;

                }
                else if(inSS1.compare("Pre")==0)
                {
                    obj.preOrder(obj.getRoot(),outputFile);
                    cout<<endl;
                    outputFile<<endl;

                }

                else if(inSS1.compare("Post")==0)
                {

                    obj.postOrder(obj.getRoot(),outputFile);

                    outputFile<<endl;
                    cout<<endl;

                }


            }
        }
    }
}
