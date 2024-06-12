//Cài đặt danh sách bằng con trỏ
#include<iostream>
using namespace std;
struct Sinhvien
{
	int masv;
	string hoten;
	int namsinh;
};
typedef Sinhvien Item;
struct Node
{
	Item Data;
	Node *Next;
	Node *Prev;
};
struct DoubleLIst
{
	Node *head;
	Node *tail;
};


//Khởi tạo danh sách
void Init(DoubleLIst &L)
{
	L.head=NULL;
	L.tail=NULL;
}
//Kiểm tra danh sách L có trống không? true/false
bool isEmpty(DoubleLIst L)
{
	if(L.head==NULL)
		return true;
	else
		return false;
}
//Trả về độ dài của danh sách
int len(DoubleLIst L)
{
	int dodai=0;
	/*
	while(L.head!=NULL){
		dodai++;
		L.head=L.head->Next;
	}
	*/
	while (L.tail!=NULL)
	{
		dodai++;
		L.tail=L.tail->Prev;
	}
	return dodai;
}
//Tạo 1 node với data là x 
Node *Make_node(Item x){
	Node *p;
	p=new Node;//Cấp phát ô nhớ con trỏ
	p->Data=x;
	p->Next=NULL;
	p->Prev=NULL;

	return p;
}
//Chèn 1 node data là x ở đầu danh sách
void Insert_Fist(DoubleLIst &L, Item x){
	Node *p;
	p=Make_node(x);
	if(L.head==NULL){
		L.head=p;
		L.tail=p;
	
	}else{
		p->Next=L.head;
		L.head->Prev=p;
		L.head=p;
	}
	
}
// chèn 1 node ở cuối danh sạc
void Insert_Last(DoubleLIst &L, Item x){
	Node *p;
	p=Make_node(x);
	if(L.head==NULL){
		L.head=p;
		L.tail=p;
	}else{
	p->Prev=L.tail;
	L.tail->Next=p;
	L.tail=p;
	}
	
}
//In danh sách từ cuối đến đầu
void InDanhSachDauCuoi(DoubleLIst L){
	while (L.head!=NULL)
	{
	cout<<L.head->Data.masv<<"\t"<<L.head->Data.hoten<<"\t"<<L.head->Data.namsinh<<endl;
	L.head=L.head->Next;
	} 
}
void InDanhSachCuoiDau(DoubleLIst L){
	while (L.tail!=NULL)
	{
	cout<<L.head->Data.masv<<"\t"<<L.head->Data.hoten<<"\t"<<L.head->Data.namsinh<<endl;
	L.tail=L.tail->Next;
	}
	
}
//Xóa node đầu danh sách
void Delete_Fist(DoubleLIst &L){
	Node *p;
	p=L.head;
	L.head=L.head->Next;
	delete p;
}
//Menu
void Menu(DoubleLIst L)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra trong\n";
		cout<<"3. Do dai danh sach\n";
		cout<<"4.Chen vao dau danh sach\n";
		cout<<"5.Chen vao cuoi danh sach\n";
		cout<<"6.Xoa node dau danh sach\n";
		cout<<"7.In danh sach tu dau den cuoi\n";
		cout<<"8.IN danh sach tu cuoi dan dau\n";
		cout<<"9. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (1-9)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khoi tao
			{
				Init(L);
				cout<<"Da khoi tao!";
				break;
			}
			case 2://Kiem tra trong
			{
				if (isEmpty(L))
					cout<<"Danh sach trong!";
				else
					cout<<"Danh sach khong trong!";
				break;
			}
			case 3://Lấy độ dài danh sách liên kết đôi
			{
				cout<<"Do dai danh sach lien ket doi la:"<<len(L)<<endl;
			}
			case 4:
			{
				Item x;
				cout<<"Nhap thong tin sinh vien\n";
				cout<<"Ma sv:";
				cin>>x.masv;
				cin.ignore();
				cout<<"Ho ten:";
				getline(cin,x.hoten);
				cout<<"Nam sinh:";
				cin>>x.namsinh;
				Insert_Fist(L,x);
				break;

			}
			case 5://Chèn cuối danh sách
			{
				Item x;
				cout<<"Nhap thong tin sinh vien\n";
				cout<<"Ma sv:";
				cin>>x.masv;
				cin.ignore();
				cout<<"Ho ten:";
				getline(cin,x.hoten);
				cout<<"Nam sinh:";
				cin>>x.namsinh;
				Insert_Last(L,x);
				break;

			}
			case 6://Xóa node đầu tiên
			{
				Delete_Fist(L);
				cout<<"Da Xoa!!\n";
				break;
			}
			case 7://In danh sach từ đầu đến cuối
			{
				InDanhSachDauCuoi(L);
				break;
			}
			case 8:{
				InDanhSachCuoiDau(L);
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
	DoubleLIst L;
	
	//Init(L);
	//cout<<isEmpty(L)<<endl;
	//cout<<"Do dai:"<<len(L);
	Menu(L);
	
	return 0;
}