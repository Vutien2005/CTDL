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
typedef Node *List;

//Khởi tạo danh sách
void Init(List &L)
{
	L =NULL;
}
//Kiểm tra danh sách L có trống không? true/false
bool isEmpty(List L)
{
	if(L==NULL)
		return true;
	else
		return false;
}
//Trả về độ dài của danh sách
int len(List L)
{
	int dodai=0;
	while(L!=NULL)
	{
		dodai++;
		L=L->Next;
	}
	return dodai;
}
//Tạo và trả về nút mới gán data = x;
Node *Make_Node(Item x)
{
	Node *p;
	
	p = new Node;
	p->Data=x;
	p->Next=NULL;
	
	return p;
}
//Chèn 1 phần tử x vào đầu tiên trong danh sách
void Insert_First(List &L, Item x)
{
	Node *p;
	
	p = Make_Node(x); //Tạo nút mới
	p->Next = L; //Trỏ p->next vào L
	L = p; // Cho L trở thành đầu danh sách
	
}
//In thông tin danh sách ra màn hình
void InDanhSach(List L)
{
	while(L!=NULL)
	{
		cout<<L->Data.manv<<"\t"<<L->Data.hoten<<"\t"<<L->Data.heso<<L->Data.tienluong<<"\t"<<endl;
		L=L->Next;
	}
}
//Chèn phần tử x vào vi trí k
void Insert_k(List &L, Item x, int k)
{
	int vitri=1;
	Node *p;
	List L1; 
	
	if(L==NULL)
	{
		p = Make_Node(x); //Tạo nút mới
		L =p;
	}
	else
	{
		L1 = L;
		while(L1!=NULL && vitri<k-1)//Di chuyển đến trước vị trí k
		{
			vitri++;
			L1=L1->Next;
		}
		
		p = Make_Node(x); //Tạo nút mới
		
		if(L1->Next==NULL)//Chèn vào vị trí cuối cùng
		{
			L1->Next=p;
		}
		else //Chèn vào vị trí không phải cuối
		{
			if(k>1)
			{
				p->Next = L1->Next;
				L1->Next = p;
			}
			else if (k==1)//Chèn vào vị trí đầu
			{
				p->Next=L;
				L = p;
			}
		}
	}
}
//Viết hàm tìm kiếm 1 mã sinh viên trong danh sách. 
//Trả về vị trí nếu tìm thấy, trả về -1 nếu không tìm thấy
int Search(List L, int Masv)
{
	
}
//Viết hàm xóa nút đầu tiên trong danh sách
void Del_First(List &L)
{
	Node *p;
	
	p = L;
	L = L->Next;
	delete p;
}
//Viết hàm xóa nút cuối cùng trong danh sách
void Del_Last(List &L)
{
	
}
//Menu
void Menu(List L)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra trong\n";
		cout<<"3. Do dai danh sach\n";
		cout<<"4. Chen dau danh sach\n";
		cout<<"5. Chen vao vi tri k trong danh sach\n";
		
		cout<<"8. In danh sach\n";
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
			case 3: //Lấy độ dài danh sách
			{
				cout<<"Do dai danh sach la: "<<len(L)<<endl;
				break;
			}
			case 4: //Chen dau danh sach
			{
				Item x;//Khai báo x là kiểu Item (~Sinhvien)
				//Nhap du lieu cho x
				cout<<"Nhap thong tin nhan vien:\n";
				cout<<"Ma nhan vien:";
				cin>>x.manv;
				cin.ignore();
				cout<<"Ho ten: ";
				getline(cin,x.hoten);
				cout<<"He so luong:";
				cin>>x.heso;
				cout<<"So tien luong:";
				cin>>x.tienluong;
				
				//Gọi hàm chèn vào đầu danh sách
				Insert_First(L,x);
				
				break;
			}
			case 5:
			{
				int k; //VỊ trí muốn chèn
				Item x; //Phần tử chèn
				
				//Nhập vị trí chèn
				cout<<"Nhap vi tri chen: ";
				cin>>k;
				
				//Nhap du lieu cho x
				cout<<"Nhap thong tin nhan vien:\n";
				cout<<"Ma nhan vien:";
				cin>>x.manv;
				cin.ignore();
				cout<<"Ho ten: ";
				getline(cin,x.hoten);
				cout<<"He so la:";
				cin>>x.heso;
				cout<<"So tien luong la:";
				cin>>x.tienluong;
				
				//Chèn x vào vi trí k
				Insert_k(L,x,k);
			}
			case 8://In danh sách ra màn hình
			{
				InDanhSach(L);
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
	List L;
	
	//Init(L);
	//cout<<isEmpty(L)<<endl;
	//cout<<"Do dai:"<<len(L);
	Menu(L);
	
	return 0;
}