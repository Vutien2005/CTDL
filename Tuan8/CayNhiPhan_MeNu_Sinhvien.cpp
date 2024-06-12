//Cài đặt cây nhị phân
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
struct TNode
{
	Item Key;
	TNode *Left;
	TNode *Right;
};
typedef TNode *Tree;
//Khởi tạo cây
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
		if(T->Key.namsinh > x.namsinh) //x.năm sinh nhỏ thì cho bên trái
		{
			AddNode(T->Left,x); //Thêm vào bên trái
		}
		else // x.năm sinh lớn hơn key thì cho bên phải
		{
			AddNode(T->Right,x);//Thêm vào bên phải
		}
		
	}
}
//Duyệt cây: Nút (gốc) -> trái -> phải
void NLR(Tree T)
{
	if(T!=NULL)
	{
		cout<<T->Key.masv<<"\t"<<T->Key.hoten<<"\t"<<T->Key.namsinh<<endl;// In ra, tính toán,....
		NLR(T->Left);
		NLR(T->Right);
	}
}
//Duyệt cây: Trái -> Nút -> Phải
void LNR(Tree T)
{
	if(T!=NULL)
	{
		LNR(T->Left);
		cout<<T->Key.masv<<"\t"<<T->Key.hoten<<"\t"<<T->Key.namsinh<<endl;
		LNR(T->Right);
	}
}
//Duyệt cây: Trái -> Phải ->Nút
void LRN(Tree T)
{
	if(T!=NULL)
	{
		LRN(T->Left);
		LRN(T->Right);
		cout<<T->Key.masv<<"\t"<<T->Key.hoten<<"\t"<<T->Key.namsinh<<endl;
	}
}
//Đọc dữ liệu từ tệp SinhVien.txt vào cây t
void ReadFileToTree(Tree &T){
	ifstream f1;
	f1.open("SinhVien.txt");
	if(!f1){
		cout<<"Mo tep loi";
		return;
	}
	Item x;
	while (!f1.eof())///Đọc đến khi kết thúc file tệp
	{
		f1>>x.masv;
		f1.ignore();
		getline(f1,x.hoten);
		f1>>x.namsinh;
		AddNode(T,x);
	}
	f1.close();
	cout<<"Da doc xong";
}

//Tính và trả về tổng tuổi
int TongKey(Tree T){
	if(T!=NULL){
		return T->Key.namsinh + TongKey(T->Left) + TongKey(T->Right);
	}
	else{
		return 0;
	}
}
//Đếm và trả về số lượng nút
int DemSoNut(Tree T){
	if(T!=NULL)// Cây không rỗng 
	{
		return 1+ DemSoNut(T->Left) + DemSoNut(T->Right);
	}
	else // Cây rỗng
	{
		return 0;
	}
}
// Đếm và trả về số nút lá
int Demla(Tree T){
	if(T!=NULL){
		if(T->Left==NULL && T->Right==NULL){
			return 1;
		}
		else{
			return Demla(T->Left) + Demla(T->Right);
		}
	}
	else// Cây rỗng
	{
		return 0;
	}
}
// Đếm số năm sinh key lẽ
int DemSoKeyLe(Tree T){
if(T!=NULL)// Cây không rỗng
{
		if(T->Key.namsinh%2==1){
			return 1 +  DemSoKeyLe(T->Left) +  DemSoKeyLe(T->Right);
 		}
		else{
			return (DemSoKeyLe(T->Left)  + DemSoKeyLe(T->Right));
		}
	}
	else // Cây rỗng
	{
		return 0;
	}
}
// Tìm năm sinh đường đi đến nút có key là x
// void Search_X(Tree T, Item x){
// 	if(T!=NULL)
// 	{
// 		cout<<T->Key.namsinh<<"\t";
// 		if(T->Key.namsinh==x){
// 			return;
// 		}
// 		else{
// 			if(T->Key.namsinh>x)// x nhỏ hơn key tìm bên trái
// 			{
// 				Search_X(T->Left,x);
// 			}
// 			else // Lơn hơn key thì tìm bên phải
// 			{
// 				Search_X(T->Right,x);
// 			}
// 		}
// 	}
// 	else{
// 		cout<<"Cay rong!!!";
// 	}
// }
// Tìm và trả về có giá trị nhỏ nhất
/*
TNode *TimMin(Tree T){
	while (T->Left!=NULL)
	{
		T = T ->Left;
	}
	return T;
	
}
*/
//Menu
void Menu(Tree T)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao cay\n";
		cout<<"2. Kiem tra cay rong\n";
		cout<<"3. Them 1 node\n";
		cout<<"4. Duyet cay: Nut-Trai-Phai\n";
		cout<<"5. Duyet cay: Trai-Nut-Phai\n";
		cout<<"6. Duyet cay: Trai-Phai-Nut\n";
		cout<<"7.Doc tu tep txt vao cay:\n";
		cout<<"8.Tong cac key la:\n";
		cout<<"9.Dem so cac nut:\n";
		cout<<"10.Trung binh cac nut:\n";
		cout<<"11. Dem so nut la:\n";
		cout<<"12. Dem so key le:\n";
		cout<<"13.Tim duong di den x:\n";
		cout<<"14.Tim gia tri Min:\n";
		cout<<"15.Tim gia tri Max:\n";
		
		cout<<"20. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (1-20)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khoi tao
			{
				Init(T);
				cout<<"Da khoi tao!";
				break;
			}
			case 2://Kiem tra trong
			{
				if (isEmpty(T))
					cout<<"Cay rong!";
				else
					cout<<"Cay khong trong!";
				break;
			}
		        case  3://Thêm 1 nút vào cây
			{
				Item x;
				cout<<"Nhap thong tin sinh vien\n";
				cout<<"Ma SV: ";
				cin>>x.masv;
				cin.ignore();
				cout<<"Ho ten: ";
				getline(cin,x.hoten);
				cout<<"Nam sinh: ";
				cin>>x.namsinh;
				AddNode(T,x);
				cout<<"Da xong!\n";
				break;
			}
			
	
			case 4://duyệt: nút trái phải
			{
				NLR(T);
				break;
			}
			case 5://Duyệt : Trái - Nút - Phải
			{
				LNR(T);
				break;
			}
			case 6://Duyệt: Trai phai nút
			{
				LRN(T);
				break;
			}
			case 7: // Đọc dữ liệu từ tệp Dulieu.txt vào file
			{
				ReadFileToTree(T);
				break;
			}
        
			case 8: // Tổng các key
			{
				cout<<"Tong cac key la:"<<TongKey(T);
				break;
			}
			case 9: //Đếm số nút
			{
				cout<<"Đem so nut là:"<<DemSoNut(T)<<endl;
				break;
			}
			case 10: //Trung bình các key la
			{
				cout<<"Trung binh cac key la:"<<(float)TongKey(T)/DemSoNut(T)<<endl;
				break;
			}
			case 11: // Đếm lá
			{
				cout<<"Cac nut las la:"<<Demla(T)<<endl;
				break;
			}
			case 12: // ĐẾm số key le
			{
				cout<<"So nut co key le la:"<<DemSoKeyLe(T)<<endl;
				break;
			}
			// case 13: // Tìm đường đi đến x
			// {
				
			// 	Item x;
			// 	cout<<"Nhap x: ";
			// 	cin>>x;

			// 	cout<<"Duong di den x la: ";
			// 	Search_X(T,x);
			// 	break;
			// }
			/*case 14: //Tìm giá trị nhỏ nhất
			{
				TNode *T;
				T = TimMin(T);
				if(T!=NULL){
					cout<<"Gia tri nho nhat:"<<T->Left<<endl;
				}
				else{
					return;
				}
				
				break;
			}*/
			case 20:
			{
				cout<<"Tam biet!";
				break;
			}		
		}
	}while(LuaChon!=20);
}
int main()
{
	Tree T;
	
	Menu(T);
	
	return 0;
}