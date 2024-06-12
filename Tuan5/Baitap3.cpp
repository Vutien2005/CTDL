//Cài đặt ngăn xếp bằng con trỏ
#include<iostream>
#include<fstream>
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
};
struct Stack
{
	Node *Top;
};

//Khởi tạo ngăn xếp
void Init(Stack &S)
{
	S.Top=NULL;
}
//Kiểm tra ngăn xếp S có trống không? true/false
bool isEmpty(Stack S)
{
	if(S.Top==NULL)
		return true;
	else
		return false;
}
//Trả về độ dài của ngăn xếp
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
//Tạo node có data là x
Node *Make_Node(Item x)
{
	Node *p;
	
	p=new Node;//Cấp phát bộ nhớ cho con trỏ p
	
	p->Data=x;
	p->Next=NULL;
	
	return p;
}
//Thêm phần tử có data x vào danh sách
void Push(Stack &S,Item x){
	Node *p;
	p = Make_Node(x);
if(S.Top == NULL)//Nếu S.top rỗng
{
    S.Top=p;
}
else{
p->Next=S.Top;
S.Top = p;
}
}
//In ngăn xếp
void InNganXep(Stack S)
{
	while(S.Top!=NULL)
	{
		cout<<S.Top->Data.masv<<"\t"<<S.Top->Data.hoten<<"\t"<<S.Top->Data.namsinh<<endl;
		S.Top=S.Top->Next;
	}
}
Item Peak(Stack S){
	return S.Top->Data;
}
Item Pop(Stack &S){
	Item Data;
	Node *p;
	Data=S.Top->Data;
	p=S.Top;
	S.Top=S.Top->Next;
	delete p;
	return Data;
}
//Tìm và trả về năm sinh nhỏ nhất sử dụng hàm pop.Nếu không có hoặc stack rỗng thì trả về trừ 1
int MinYear(Stack S){
	Item Data;
	int min;
	if(isEmpty(S)){
		return -1;
	}
	Data=Pop(S);
	min=Data.namsinh;
	while(S.Top!=NULL){
		Data=Pop(S);
		if(min>Data.namsinh){
			min=Data.namsinh;
		}
		return min;
	}
}

//Dua vao ham minyear viet 1 ham tra ve sinh vien (Iteam)co nam sinh nho nhat
Item Oldest(Stack S){
	Item Data, DataMin;
	int min;
	DataMin=Pop(S);
	min=DataMin.namsinh;
	while(S.Top!=NULL){
		Data=Pop(S);
		if(min>Data.namsinh){
			min=Data.namsinh;
			DataMin=Data;
		}
		
	}
	return DataMin;
	
}
//viết hàm tiềm kiếm 1 mã sinh viên trog ngăn xếp
int Search(Stack S,int msv){
	int Timthay=-1;
	int Vitri=0;
	Item Data;
	if(isEmpty(S))
	return Timthay;
	while ((S.Top!=NULL))
	{
		Vitri++;
		Data=Pop(S);
		if(Data.masv==msv){
			Timthay=Vitri;
			break;
		}
	}
	return Timthay;
}
//Ghi du lieu vao ngan xep vao tep stack .txt
void SavestackTofile(Stack S){
	ofstream f1;
	Item Data;
	f1.open("stack.txt");
	if(!f1){
	cout<<"Mo tep loi";
	return;
	}while(S.Top!=NULL)
	{
		Data=Pop(S);
		f1<<Data.masv<<endl;
		f1<<Data.hoten<<endl;
		f1<<Data.namsinh<<endl;

	}
	f1.close();
 }
 //do du lieu tu tep stack,txt ra ngan xep
 void ReadFiletoSatck(Stack &S){
	ifstream f1;
	Item x;
	f1.open("stack.txt");
	if(!f1){
		cout<<"mo tep loi!";
		return ;
	}
	while (!f1.eof())
	{
		f1>>x.masv;
		f1.ignore();
		getline(f1,x.hoten);
		f1>>x.namsinh;
		if(!f1.eof()){
			Push(S,x);
		}
		
	}
	f1.close();
	
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
		cout<<"3. Do dai ngan xep\n";
		cout<<"4. Them phan tu vao ngan xep\n";
		cout<<"5.peak -Lay node dau tien va khong xoa\n";
		cout<<"6.Pop- Lay ve data cua node dau tien va xoa di\n";
		cout<<"7.Nam sinh nho nhat\n";
		cout<<"8.Sinh vien gia nhat\n";
		cout<<"9.Sinh vien lon tuoi nhat\n";
		cout<<"10.Ghi thong tin tu ngan xep vao tep\n";
		cout<<"11.Doc du lieu tu tep vao ngan xep\n";
		cout<<"12.Tim kiem theo ma sinh vien\n";
		cout<<"13. In ngan xep\n";
		cout<<"14. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (1-9)?";
		cin>>LuaChon;
		Item Data;
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
			case 3://Lấy độ dai ngăn xếp
			{
				cout<<"Do dai ngan xep la: "<<len(S)<<endl;
				break;
			}
			case 4: //Thêm phần tử vào ngăn xếp
			{
				Item x;
				cout<<"Nhap thong tin sinh vien\n";
				cout<<"Ma SV:";
				cin>>x.masv;
				cin.ignore();
				cout<<"Ho ten:";
				getline(cin,x.hoten);
				cout<<"Nam sinh:";
				cin>>x.namsinh;
				
				Push(S,x);
								break;
			}
			case 5:{
				Item Data;
				if(!isEmpty(S)){
					Data = Peak(S);
				
					cout<<Data.masv<<"\t"<<S.Top->Data.hoten<<"\t"<<S.Top->Data.namsinh<<endl;
				}
				else{
					cout<<"Ngan xep rong";
				}
			}
			case 6:{
				Item Data;
				if(!isEmpty(S)){
					Data=Pop(S);
					cout<<Data.masv<<"\t"<<Data.hoten<<"\t"<<Data.namsinh<<endl;
				}
				Data=Pop(S);
				cout<<Data.masv<<"\t"<<Data.hoten<<"\t"<<Data.masv<<endl;
			}
			case 7://In ra nam sinh nho nhat
			{
				int min;
				if(isEmpty(S)){
					cout<<"Ngan xep rong";
				}
				else{
				min=MinYear(S);
				cout<<"Nam sinh nho nhat la:"<<min;
				break;
				}
				
			}
			case 9://In sinh viên lớn tuổi nhất
			{
				if(isEmpty(S)){
					cout<<"Ngan xep rong";
				}else{


					Data = Oldest(S);
					cout<<"Nam sinh lon nhat la:"<<Data.hoten;
				}
				

			}
			case 10:{
				SavestackTofile(S);
				cout<<"Da ghi vao tep!";
				break;
			}
			case 11://Doc tu tep ra ngan xep
			{
				ReadFiletoSatck(S);
				cout<<"Da doc xong!";
				break;
			}
			case 12:{
				int msv;
				cout<<"Nhap ma sinh vien can tim:";
				cin>>msv;
				int Vitri=Search(S,msv);
				if(Vitri==-1){
					cout<<"Khong tim thay";
				}
				else{
					cout<<"Yim thay tai vi tri"<<Vitri<<endl;
				}
			}
			case 13://In ngăn xếp
			{
				InNganXep(S);
				break;
			}
			case 14:
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