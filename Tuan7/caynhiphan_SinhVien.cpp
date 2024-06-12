#include<iostream>
using namespace std;
struct SinhVien
{
    int maSV;
    string hoTen;
    int namSinh;
};

typedef SinhVien Item;
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
        if(T->Key.namSinh > x.namSinh)//x nho hon key nen cho ben trai
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
        cout<<T->Key.maSV<<"\t"<<T->Key.hoTen<<"\t"<<T->Key.namSinh<<endl;//in ra,tinh toan,...
        NLR(T->Left);
        NLR(T->Right);
    }
}
//duyet cay: trai-node-phai
void LNR(Tree T){
    if (T!=NULL)
    {
        LNR(T->Left);
         cout<<T->Key.maSV<<"\t"<<T->Key.hoTen<<"\t"<<T->Key.namSinh<<endl;
        LNR(T->Right);
    }
}
//duyet cay: Trai-Phai-Node
void LRN(Tree T){
    if (T!=NULL)
    {
        LRN(T->Left);
    LRN(T->Right);
    cout<<T->Key.maSV<<"\t"<<T->Key.hoTen<<"\t"<<T->Key.namSinh<<endl;
    }
}
//ham tinh tong do tuoi
int tongTuoi(Tree T){
    if (T!=NULL)
    {
        return (2024-T->Key.namSinh) + tongTuoi(T->Left) + tongTuoi(T->Right);
    }
    else
    return 0;
}
//ham dem so sinh vien
int demSoLuongSV(Tree T){
    if (T!=NULL)
    {
        return 1 + demSoLuongSV(T->Left) + demSoLuongSV(T->Right);
    }
    else 
    return 0;
}
//tinh do tuoi trung binh
int doTuoiTB(Tree T){
   return tongTuoi(T)/demSoLuongSV(T);
}
int main(){
    Tree T;
    Init(T);
    //Xay dung cay voi 5 sinh vien nhap vao
    Item x;
    for(int i=0;i<5;i++)
    {
        cout<<"Nhap thong tin sinh vien: \n";
        cout<<"Nhap ma sinh vien: \n";
        cin>>x.maSV;
        cin.ignore();
        cout<<"Nhap ho ten: \n";
        getline(cin,x.hoTen);
        cout<<"Nhap nam sinh: ";
        cin>>x.namSinh;
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
    cout<<"Tong tuoi cua sinh vien la: "<<tongTuoi(T);
    cout<<endl;
    cout<<"Tong so Sinh Vien la: "<<demSoLuongSV(T);
    cout<<endl;
    cout<<"Do tuoi trung binh la: "<<doTuoiTB(T);
    return 0;
}
