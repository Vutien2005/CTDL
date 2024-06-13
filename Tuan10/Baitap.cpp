//Cài đặt danh sách bằng con trỏ
#include<iostream>
using namespace std;
struct Sach
{
	string Ten_Sach;
	string Ten_Tac_Gia;
	float Gia_Sach;
};
typedef Sach Item;
struct TNode
{
	Item Key;
	TNode *Left;
	TNode *Right;
};
typedef TNode *Tree;
//Khởi tạo danh sách
void Init(Tree &T)
{
	T=NULL;
}
//Kiểm tra cây rỗng
bool isEmpty(Tree T)
{
	if(T==NULL)
		return true;
	else
		return false;
}
//Thêm 1 giá trị x vào cây T
void AddNode(Tree &T, Item x)
{
	if(T==NULL) //Cây rỗng
	{
		T = new TNode;
		T->Key = x;
		T->Left =NULL;
		T->Right =NULL;
	}
	else //Cây không rỗng
	{
		if(T->Key.Gia_Sach > x.Gia_Sach) 
		{
			AddNode(T->Left,x); //Thêm vào bên trái
		}
		else 
		{
			AddNode(T->Right,x);//Thêm vào bên phải
		}
		
	}
}
// Hiển thị danh sách
void HienThiDanhSach(Tree T)
{
	while (T!=NULL)
	{
		cout<<T->Key.Gia_Sach<<"\t"<<T->Key.Ten_Sach<<"\t"<<T->Key.Ten_Tac_Gia<<endl;
		T=T->Left;
	}
	
}
//Menu
void Menu(Tree T)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra cay rong\n";
		cout<<"3. Them 1 gia tri\n";
		cout<<"4. Duyet cay: Nut-Trai-Phai\n";
		cout<<"5. Duyet cay: Trai-Nut-Phai\n";
		cout<<"6. Duyet cay: Trai-Phai-Nut\n";
		cout<<"7.Doc tu tep txt vao cay:\n";
		cout<<"9.In ra mn hinh:\n";
		
		cout<<"Moi chon chuc nang (1-9)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1:// Khởi tạo
			{
				Init(T);
				cout<<"Da khoi tao!";
				break;
			}
			case 2:// Kiểm tra rỗng
			{
				if (isEmpty(T))
					cout<<"Cay rong!";
				else
					cout<<"Cay khong trong!";
				break;
			}
			case 3: // Thêm 1 nút vào cây
			{
				Item x;
				cout<<"Nhap thong tin Sach\n";
				cout<<"Ten sach: ";
				getline(cin,x.Ten_Sach);
				cin.ignore();
				cout<<"Ho ten Tac Gia: ";
				getline(cin,x.Ten_Tac_Gia);
				cin.ignore();
				cout<<"Gia Sach: ";
				cin>>x.Gia_Sach;
				AddNode(T,x);
				cout<<"Da xong!\n";
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
	Tree T;
	Menu(T);
	return 0;
}