//CaI DAT DANH SACH LIEN KET BANG CON TRO;
#include<iostream>
using namespace std;
typedef int Item;
struct Node//dinh nghia mot nut
{
    Item data;
    Node *next;
};
typedef Node *List;//Dinh nghia mot danh sach(con tro co the gom nhieu nut)
void Int(List &L)   //khoi tao danh sach
{
    L=NULL;
}
bool isEmpty(List L)//kiem tra danh sach rong hay khong
{
    if(L==NULL){
        return true;
    }else return false;
}
int Len(List L)
{
    int dodai=0;
    while(L!=NULL)
    {
        dodai++;
        L=L->next;
    }
}
int main()
{   
    List L;

    Int(L);
    cout<<isEmpty(L)<<endl;
    cout<<Len(L)<<endl;
    return 0;
}