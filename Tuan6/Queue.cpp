//Cài đặt hàng đợi bằng con trỏ
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
};
struct Queue
{
	Node *Front;//Đầu lấy ra
	Node *Rear;//Đầu thêm vào
	int count;//Lưu số lượng node
};

//Khởi tạo hàng đợi
void Init(Queue &Q)
{
	Q.Front=NULL;
	Q.Rear=NULL;
	Q.count=0;
}
//Kiểm tra hàng đợi Q có trống không? true/false
bool isEmpty(Queue Q)
{
	if(Q.count==0)
		return true;
	else
		return false;
}
//Trả về độ dài của hàng đợi
int len(Queue Q)
{
	return Q.count;
}
//Tạo và trả về 1 node có data là x
Node *Make_Node(Item x)
{
	Node *p;
	
	p = new Node;
	p->Data=x;
	p->Next=NULL;
	
	return p;
}
//Thêm 1 node có data là x vào hàng đợi
void Push(Queue &Q, Item x)
{
	Node *p;
	
	p=Make_Node(x);//Tạo node
	
	if(isEmpty(Q))//Nếu hàng đợi rỗng
	{
		Q.Front=p;
		Q.Rear=p;
	}
	else //Hàng đợi không rỗng
	{
		Q.Rear->Next=p;//Tạo liên kết với nút p
		Q.Rear=Q.Rear->Next;//Thay đổi vị trí nút Rear
	}
	
	Q.count++; //Tăng đếm node của hàng đợi lên 1
}

//Hiển thị hang đợi
void Display(Queue Q)
{
	while(Q.Front!=NULL)
	{
		cout<<Q.Front->Data.masv<<"\t"<<Q.Front->Data.hoten<<"\t"<<Q.Front->Data.namsinh<<endl;
		Q.Front=Q.Front->Next;
	}
}
//Lấy và trả phần tử và Xóa phần tử
Item Pop(Queue &Q)
{
	Item x;
	Node *p;
	
	x = Q.Front->Data; //Lưu data để trả về
	p = Q.Front; //Lưu địa chỉ để giải phóng
	Q.Front = Q.Front->Next;
	Q.count--;
	delete p;
	
	return x;
}
// Lấy trả về node đầu tiên và không xóa node đi
Item Peak(Queue Q){
	return 	Q.Front->Data;
}
//Tìm và trả về năm sinh nhỏ nhất sử dụng hàm pop. Nếu Queue rỗng thì trả về -1
int Minyear(Queue Q){
	Item Data;
	int min;
	if(isEmpty(Q))
	return -1;
	Data = Pop(Q);
	min=Data.namsinh;
	while (Q.Front!= NULL)
	{
		Data=Pop(Q);
		if(min>Data.namsinh){
			min=Data.namsinh;
		}

	}
	return min;
	
}
//Dựa vào hàm MinYear viết 1 hàm trả về sinh viên (Item) có năm sinh nhỏ nhất (già nhất)
	Item Oldest(Queue Q){
		Item Data, DataMin;
		int min;
		DataMin =Pop(Q);
		min=DataMin.namsinh;
		while (Q.Front!=NULL)
		{
			Data=Pop(Q);
			if(min>Data.namsinh){
				min=Data.namsinh;
				DataMin=Data;
			}
		}
		return DataMin;
		
	}
//Menu
void Menu(Queue Q)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra trong\n";
		cout<<"3. Do dai hang doi\n";
		cout<<"4. Push - Them vao hang doi\n";
		cout<<"5. Pop - Lay va Xoa\n";
		cout<<"6. Peak - Lay node dau tien và ko xoa di\n";
		cout<<"7. Nam sinh nho nhat\n";
		cout<<"8.Sinh vien lon tuoi nhat\n";
		cout<<"9. Hien thi hang doi\n";
		cout<<"10. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (1-10)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khoi tao
			{
				Init(Q);
				cout<<"Da khoi tao!";
				break;
			}
			case 2://Kiem tra trong
			{
				if (isEmpty(Q))
					cout<<"Hang doi trong!";
				else
					cout<<"Hang doi khong trong!";
				break;
			}
			case 3: //Hiển thị độ dài hang đợi
			{
				cout<<"Do dai hang doi la "<<len(Q)<<endl;
				break;
			}
			case 4: //Thêm vào hàng đợi
			{
				Item x;
				//Nhập thông tin sinh viên
				cout<<"Nhap thong tin sinh vien\n";
				cout<<"Ma SV:";
				cin>>x.masv;
				cin.ignore();
				cout<<"Ho ten:";
				getline(cin,x.hoten);
				cout<<"Nam sinh:";
				cin>>x.namsinh;
				
				Push(Q,x);
				cout<<"Da them!";
				
				break;
			}
			case 5: //Pop lấy và trả về
			{
				Item x;
				x = Pop(Q);
				//In ra x
				cout<<x.masv<<"\t"<<x.hoten<<"\t"<<x.namsinh<<endl;
				break;
			}
			case 6://Peak trả về node đầu tiên và không xóa đi
			{
				Item Data;
				if(!isEmpty(Q)){
					Data=Peak(Q);
					//in ra giá trị màn hình
					cout<<Data.masv<<"\t"<<Data.hoten<<"\t"<<Data.namsinh<<endl;
				}
				else{
					cout<<"Ngan xep rong";

				}
				break;

			}
			case 7://Nam sinh nho nhat
			{
				int min;
				if(isEmpty(Q)){
					cout<<"Hang doi rong!\n";
				}
				else{
					min=Minyear(Q);
					cout<<"Nam sinh nho nhat la:"<<min<<endl;
				}
			}
			case 8://In sinh viên lớn tuổi nhất
			{
					Item Data;
				
				if(isEmpty(Q))//Nếu ngăn xếp rỗng
				{
					cout<<"Ngan xep rong!\n";
				}
				else
				{
					Data = Oldest(Q);
					//In ra thông tin sinh viên lớn tuổi
					cout<<Data.masv<<"\t"<<Data.hoten<<"\t"<<Data.namsinh<<endl;
				}
				
				break;
			}
			case 9: //Hiển thị hang đợi
			{
				Display(Q);
				break;
			}
			case 10:
			{
				cout<<"Tam biet!";
				break;
			}		
		}
	}while(LuaChon!=9);
}
int main()
{
	Queue Q;
	
	Menu(Q);
	
	return 0;
}