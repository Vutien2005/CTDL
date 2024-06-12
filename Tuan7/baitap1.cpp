#include<iostream>
using namespace std;
struct Nhanvien
{
    int manv;
    string hoTen;
    float heso;
    float tienluong;
};

typedef Nhanvien Item;
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
        if(T->Key.tienluong > x.tienluong)//x nho hon key nen cho ben trai
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
        cout<<T->Key.manv<<"\t"<<T->Key.hoTen<<"\t"<<T->Key.heso<<"\t"<<T->Key.tienluong<<endl;//in ra,tinh toan,...
        NLR(T->Left);
        NLR(T->Right);
    }
}
//duyet cay: trai-node-phai
void LNR(Tree T){
    if (T!=NULL)
    {
        LNR(T->Left);
         cout<<T->Key.manv<<"\t"<<T->Key.hoTen<<"\t"<<T->Key.heso<<"\t"<<T->Key.tienluong<<endl;
        LNR(T->Right);
    }
}
//duyet cay: Trai-Phai-Node
void LRN(Tree T){
    if (T!=NULL)
    {
        LRN(T->Left);
    LRN(T->Right);
    cout<<T->Key.manv<<"\t"<<T->Key.hoTen<<"\t"<<T->Key.heso<<"\t"<<T->Key.tienluong<<endl;
    }
}
//ham tinh tong luong
int tongLuong(Tree T){
    if (T!=NULL)
    {
        return (T->Key.tienluong) + tongLuong(T->Left) + tongLuong(T->Right);
    }
    else
    return 0;
}
//ham dem so nhan vien
int demSoLuongnv(Tree T){
    if (T!=NULL)
    {
        return 1 + demSoLuongnv(T->Left) + demSoLuongnv(T->Right);
    }
    else 
    return 0;
}
//tinh luong trung binh
int Luongtb(Tree T){
   return Luongtb(T)/demSoLuongnv(T);
}
int main(){
    Tree T;
    Init(T);
    //Xay dung cay voi 5 nhan vien nhap vao
    Item x;
    for(int i=0;i<5;i++)
    {
        cout<<"Nhap thong tin Nhan vien: \n";
        cout<<"Nhap ma nhan vien: \n";
        cin>>x.manv;
        cin.ignore();
        cout<<"Nhap ho ten: \n";
        getline(cin,x.hoTen);
        cout<<"Nhap he so: ";
        cin>>x.heso;
        cout<<"nhap tien luong:";
        cin>>x.tienluong;
        Addnode(T,x);
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
    cout<<"Mot so thong tin sinh vien";
    cout<<"------------------------------\n";
    cout<<"Tong luong nhan vien la: "<<tongLuong(T);
    cout<<endl;
    cout<<"Tong so nhan vien la: "<<demSoLuongnv(T);
    cout<<endl;
    cout<<"Luong tb la: "<<Luongtb(T);
    return 0;
}
