#include<iostream>
using namespace std;
typedef int Item;
struct TNode
{
    Item Key;
    TNode *Left;
    TNode *Right;
};
typedef TNode *Tree;
//Khoi tao cay. chu y cay can duoc khoi tao truoc khi dung
void Init(Tree &T)
{
    T=NULL;
}
bool isEmpty(Tree T)
{
    if(T==NULL)
        return true;
    else 
        return false;
}
//them gia tri x vao cay T
void Addnode(Tree &T,Item x)
{
    if (T==NULL)//neu cay rong
    {
        T= new TNode;
        T->Key=x;
        T->Left=NULL;
        T->Right=NULL;
    }
    else//neu cay khong rong
    {
        if(T->Key > x)//x nho hon key nen cho ben trai
        {
            Addnode(T->Left,x);
        }
        else//x lon hon nen cho ben phai
        {
            Addnode(T->Right,x);
        }
    }  
}
//Duyet cay theo thu tu:Nut->trai->phai
void NLR(Tree T)
{
    if(T!=NULL)
    {
        cout<<T->Key<<"\t";//in ra,tinh toan,...
        NLR(T->Left);
        NLR(T->Right);
    }
}
//duyet cay: trai-node-phai
void LNR(Tree T){
    if (T!=NULL)
    {
        LNR(T->Left);
        cout<<T->Key<<"\t";
        LNR(T->Right);
    }
}
//duyet cay: Trai-Phai-Node
void LRN(Tree T){
    if (T!=NULL)
    {
        LRN(T->Left);
    LRN(T->Right);
    cout<<(T->Key)<<"\t";
    }
}
//ham tinh va tra ve tong gia tri cac key trong cay T
int tongKey(Tree T){
    if (T!=NULL)
    {
        return T->Key + tongKey(T->Left) + tongKey(T->Right);
    }
    else
    return 0;
}
//ham dem so nut trong cay
int demSoLuongNut(Tree T){
    if (T!=NULL)
    {
        return 1 + demSoLuongNut(T->Left) + demSoLuongNut(T->Right);
    }
    else 
    return 0;
}
int main(){
    Tree T;
    Init(T);
    //Xay dung cay co cac gia tri sau:7,36,3,1,6,4,15,40 
    int a[]={7,36,3,1,6,4,15,40};
    for(int i=0;i<8;i++)
    {
        Addnode(T,a[i]);
    }
    //Duyet cay: Nut->trai->phai
    cout<<"Duyet cay: Nut->trai->phai :\n";
    NLR(T);
    cout<<endl;
    cout<<"Duyet cay: Trai->Nut->Phai: \n";
    LNR(T);
    cout<<endl;
    cout<<"Duyet cay: Trai->Phai->Node: \n";
    LRN(T);
    cout<<endl;
    cout<<"Mot so thong tin cua cay: \n";
    cout<<"Tong gia tri key trong cac nut: "<<tongKey(T)<<endl;
    cout<<endl;
    cout<<"Tong so nut la: "<<demSoLuongNut(T);
    return 0;
}
