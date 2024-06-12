//Cài đặt danh sách bằng con trỏ
#include<iostream>
using namespace std;
struct Nhanvien
{
	int manv;
	string hoten;
	float heso;
	float tienluong;
};
typedef Nhanvien Item;
struct Node
{
	Item Data;
	Node *Next;
};
struct Stack
{
    Node *Top;
};

//Khởi tạo danh sách
void Init(Stack &S)
{
	S.Top =NULL;
}
//Kiểm tra danh sách L có trống không? true/false
bool isEmpty(Stack S)
{
	if(S.Top==NULL)
		return true;
	else
		return false;
}
//Trả về độ dài của danh sách
int len(Stack S)
{
	int dodai=0;
	while(S.Top!=NULL)
	{
		dodai++;
		S.Top=S.Top->Next;
	}
	return dodai;
}
//Tao node có data la x
	Node *Make_Node(Item x){
		Node *p;
		p=new Node;
		p->Data=x;
		p->Next=NULL;
		return p;
	}
//Thêm phần tử có data la x vào đầu danh sách
	void Push(Stack &S, Item x){
		Node *p;
		p=Make_Node(x);
		if(S.Top==NULL){
			S.Top=p;
		}
		else{
		p->Next=S.Top;
		S.Top=p;
		}
		
	}

void InNganXep(Stack S){
while (S.Top!=NULL)
{
	cout<<S.Top->Data.manv<<"\t"<<S.Top->Data.hoten<<"\t"<<S.Top->Data.heso<<"\t"<<S.Top->Data.tienluong<<endl;
	S.Top=S.Top->Next;
}

}
void InDanhSachDauCuoi(Stack S){
	while (S.Top!=NULL)
	{
	cout<<S.Top->Data.manv<<"\t"<<S.Top->Data.hoten<<"\t"<<S.Top->Data.heso<<"\t"<<S.Top->Data.tienluong<<endl;
	S.Top=S.Top->Next;
	} 
}
void InDanhSachCuoiDau(Stack S){
	while (S.Top!=NULL)
	{
	cout<<S.Top->Data.manv<<"\t"<<S.Top->Data.hoten<<"\t"<<S.Top->Data.heso<<"\t"<<S.Top->Data.tienluong<<endl;
	S.Top=S.Top->Next;
	}
	
}
//Xóa node đầu danh sách
void Delete_Fist(Stack &S){
	Node *p;
	p=S.Top;
	S.Top=S.Top->Next;
	delete p;
}

//Menu
void Menu(Stack S)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra trong\n";
		cout<<"3. Do dai danh sach\n";
		cout<<"4.Them phan tu vao ngan xep\n";
		cout<<"5.Chen vao cuoi danh sach\n";
		cout<<"6.Xoa node dau danh sach\n";
		cout<<"7.In danh sach tu dau den cuoi\n";
		cout<<"8.IN dang sách \n";
		cout<<"9. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (1-9)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khoi tao
			{
				Init(S);
				cout<<"Da khoi tao!";
				break;
			}
			case 2://Kiem tra trong
			{
				if (isEmpty(S))
					cout<<"Ngan xep trong!";
				else
					cout<<"Ngan xep khong trong!";
				break;
			}
            case 3:
            {
                cout<<"Do dai ngăn xep la: "<<len(S)<<endl;
				break;
            }
			case 4:{
				Item x;
				cout<<"Nhap thong tin nhan vien:\n";
				cout<<"Ma NV:";
				cin>>x.hoten;
				cin.ignore();
				cout<<"Ho ten:";
				getline(cin,x.hoten);
				cout<<"He so luong:";
				cin>>x.heso;
				cout<<"So tien luong:";
				cin>>x.tienluong;
				Push(S,x);
				break;
			}
			case 5:{
				Item x;
				cout<<"Nhap thong tin nhan vien\n";
				cout<<"Ma nv:";
				cin>>x.manv;
				cin.ignore();
				cout<<"Ho ten:";
				getline(cin,x.hoten);
				cout<<"He so:";
				cin>>x.heso;
				cout<<"Tien luong:";
				cin>>x.tienluong;
				Push(S,x);
				break;

			}
			case 6:{
				Delete_Fist(S);
				cout<<"Da Xoa!!\n";
				break;
			}
			case 7:{
				InDanhSachDauCuoi(S);
				break;
			}
			case 8:{
				InNganXep(S);
				break;
			}
			case 9:
			{
				cout<<"Tam biet!";
				break;
			}		
		}
	}while(LuaChon!=9);
}
int main()
{
	Stack S;
	Menu(S);
	
	return 0;
}