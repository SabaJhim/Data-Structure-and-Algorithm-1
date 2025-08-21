#include<iostream>
#include<string>
#include<fstream>


using namespace std;

template <typename T> class Node
{
public:
    T Key;
    Node* Left;
    Node* Right;
    Node* Parent;

    Node(Node* L=NULL,Node* R=NULL)
    {
        Left=L;
        Right=R;
        Parent=NULL;
    }
    Node(const T& val,Node* L=NULL,Node* R=NULL)
    {
        Key=val;
        Left=L;
        Right=R;
        Parent=NULL;
    }
    Node(const Node& a )
    {
        Key=a.Key;
        Left=new Node;
        Left=a.Left;
        Right=new Node;
        Right=a.Right;
        Parent=new Node;
        Parent=a.Parent;
    }
};

template <typename T> class BST
{
private:
    Node<T>* root=new Node<T>;
    Node<T>* curr=new Node<T>;
    string str="";
    int count=0;
    int flag=0;



public:
    void Insert(T e)
    {
        curr=root;
        if(root->Left==NULL&&root->Right==NULL)
        {
            root->Key=e;
            root->Left=new Node<T>;
            root->Right=new Node<T>;
            (root->Left)->Parent=root;
            (root->Right)->Parent=root;
            count++;
            return;

        }
        else
        {
            while(curr->Left!=NULL&&curr->Right!=NULL)
            {
                if(curr->Key>e)curr=curr->Left;
                else
                {
                    curr=curr->Right;
                }
            }
            curr->Key=e;
            curr->Left=new Node<T>;
            curr->Right=new Node<T>;
            (curr->Left)->Parent=curr;
            (curr->Right)->Parent=curr;
            count++;
            return ;
        }


    }

    bool Find(T e)
    {
        curr=root;
        if(root->Left==NULL&&root->Right==NULL){
            return false;
        }
        if(curr->Key==e)return true;
        else
        {
            while(curr->Left!=NULL&&curr->Right!=NULL)
            {
                if(curr->Key>e) curr=curr->Left;
                else
                {
                    curr=curr->Right;
                }
                if(curr->Key==e&&(curr->Left!=NULL&&curr->Right!=NULL))
                {
                    return true;
                }
            }
        }
        return false;
    }

    void Delete(T e)
    {
        curr=root;
        if(curr->Key==e)
        {
            if((curr->Left)->Left==NULL&&(curr->Right)->Right==NULL&&(curr->Left)->Right==NULL&&(curr->Right)->Left==NULL)
            {
                curr->Left=NULL;
                curr->Right=NULL;
                count--;

            }
            else
            {
                flag=1;
            }
        }
        else
        {
            while(curr->Left!=NULL&&curr->Right!=NULL)
            {
                if(curr->Key>e) curr=curr->Left;
                else
                {
                    curr=curr->Right;
                }
                if(curr->Key==e)
                {
                    if((curr->Left)->Left==NULL&&(curr->Right)->Right==NULL&&(curr->Left)->Right==NULL&&(curr->Right)->Left==NULL)
                    {
                        curr->Left=NULL;
                        curr->Right=NULL;
                        count--;
                        break;
                    }
                    else
                    {
                        flag=1;
                    }

                }

            }
            if(curr->Key!=e){
                flag=1;
            }
        }


    }


    void preOrder(Node<T>* Root,ofstream &outputFile)

    {     if(root->Left==NULL&&root->Right==NULL){
           cout<<"Tree is empty";
           outputFile<<"Tree is empty";
           return;
    }

        if(Root->Left==NULL&&Root->Right==NULL)
        {
            return;
        }
        else
        {
            outputFile<<Root->Key<<" ";
            cout<<Root->Key<<" ";
            preOrder(Root->Left,outputFile);
            preOrder(Root->Right,outputFile);
        }
    }

    void postOrder(Node<T>*Root,ofstream & outputFile)
    {
         if(root->Left==NULL&&root->Right==NULL){
           cout<<"Tree is empty";
           outputFile<<"Tree is empty";
           return;
         }
        if(Root->Left==NULL&Root->Right==NULL)
        {
            return ;
        }
        postOrder(Root->Left,outputFile);
        postOrder(Root->Right,outputFile);
        outputFile<<Root->Key<<" ";
        cout<<Root->Key<<" ";
        if(Root==root)return ;

    }

    void inOrder(Node<T>*Root,ofstream& outputFile)
    {
         if(root->Left==NULL&&root->Right==NULL){
           cout<<"Tree is empty";
           outputFile<<"Tree is empty";
           return;
         }
        if(Root->Left==NULL&&Root->Right==NULL)
        {
            return ;
        }
        inOrder(Root->Left,outputFile);
        outputFile<<Root->Key<<" ";
        cout<<Root->Key<<" ";
        inOrder(Root->Right,outputFile);
    }

    void ToTree(Node<T>* Root)
    {
        if(Root->Left==NULL&&Root->Right==NULL)
        {
            return;
        }
        string a=to_string(Root->Key);
        str=str+a;
        if(!(Root->Left->Left)&&!(Root->Right->Right))
        {
            return;
        }

        str=str+"(";
        ToTree(Root->Left);
        str=str+")";

        if(!(Root->Right->Right)&&!(Root->Right->Left))
        {
            str=str+"()";
           return;
        }

         str=str+"(";
        ToTree(Root->Right);
        str=str+")";


    }

    void print(Node<T>* Root,int c,ofstream& outputFile)
    {

        static string str1;


        if(c==0)
        {   if(root->Left==NULL&&root->Right==NULL){
               outputFile<<"Tree is empty"<<endl;
               cout<<"Tree is empty"<<endl;
               return;
                }
            if(flag!=1)
            {

                ToTree(root);
                outputFile<<str<<endl;
                cout<<str<<endl;
                str="";
            }
        }

        if(flag==1)
        {
            outputFile<<"Invalid operation"<<endl;
            cout<<"Invalid operation"<<endl;
            flag=0;
            return;
        }


    }

    Node<T>* getRoot()
    {
        return root;
    }
    int getCount()
    {
        return count;
    }




};


/*int main(){
    BST<int> obj;
    obj.Insert(6);
    obj.Insert(7);
    obj.Insert(2);
    obj.Insert(1);
    obj.Insert(11);
    obj.Insert(10);
    obj.Insert(12);
    obj.print(obj.getRoot());
    cout<<obj.Find(12)<<endl;
    cout<<obj.Find(11)<<endl;
    cout<<obj.Find(10)<<endl;
    cout<<obj.Find(19)<<endl;
    cout<<obj.Find(7)<<endl;
    cout<<obj.Find(6)<<endl;
    cout<<obj.Find(5)<<endl;
    cout<<obj.Find(2)<<endl;
    cout<<obj.Find(1)<<endl;
    obj.Delete(10);
    obj.print(obj.getRoot());
    obj.Delete(11);
    obj.print(obj.getRoot());
    obj.Delete(12);
    obj.print(obj.getRoot());
    obj.Delete(11);
    obj.print(obj.getRoot());
    obj.Delete(1);
    obj.print(obj.getRoot());
    obj.Delete(7);
    obj.print(obj.getRoot());
    obj.Delete(2);
    obj.print(obj.getRoot());
    obj.Delete(6);
    obj.print(obj.getRoot());
    obj.Insert(18);
     int* a=new int [obj.getCount()];
     a=obj.inOrder(obj.getRoot());
     //cout<<a<<endl;


     }*/






