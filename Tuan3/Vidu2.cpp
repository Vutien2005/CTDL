//Cài đặt danh sách liên kết đơn bằng con trỏ
#include<iostream>
using namespace std;
typedef int Item;
struct Node //Định nghĩa 1 nút gồm 2 phần: Data, Next
{
	Item Data;
	Node *Next;
};
typedef Node *List; //Định nghĩa 1 danh sách liên kết

//Khởi tạo danh sách liên kết
//Khi làm việc với danh sách liên kết thì phải khởi tạo
void Int(List &L)
{
	L=NULL;
}
//Kiểm tra danh sách có rỗng không? true/false
bool isEmpty(List L)
{
	if(L==NULL)
		return true;
	else
		return false;	
}
//Trả về độ dài danh sách liên kết
int Len(List L)
{
	int dodai=0;
	while(L!=NULL)
	{
		dodai++;
		L=L->Next;
	}
}
int main()
{
	List L;
	
	Int(L);
	cout<<isEmpty(L);
	return 0;
}