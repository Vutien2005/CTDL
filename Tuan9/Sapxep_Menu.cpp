//Cài đặt thuật toán sắp xếp
#include<iostream>
using namespace std;
//Sắp xếp chèn
void Insertion_sort(int arr [],int n){
	int i ,key,j;//i-chỉ số các phần tử cua mảng duyệt;key-Phần tử cần tìm đến vị trí chèn;j-Vị trí chèn 
	for(int i = 1;i<n;i++){

	key = arr[i];//Phần tử cần tìm vị trí chèn
	j=i-1;
	while(j >=0 && arr[j]>key){
		arr[j+1]=arr[j];
		j--;
	}
		arr[j+1] = key;
}
}
// doi cho 2 phan tu(Swap)
void Swap(int &x,int &y){
	int  temp;
	temp=x;
	x=y;
	y=temp;
}
// SelectionSort
void SelectionSort(int arr[],int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		min=i; //  gia su phan tu nho nhat la i;
		//  tim vitri nho nhat trong khoang [i+1,n];
		for(j=i+1;j<n;j++){ 
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		//  doi  cho  vitri min 
		Swap(arr[min],arr[i]);
	}
}

//In mảng
void Inmang(int arr[],int n){
	for(int i = 0;i<n;i++){
cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
// Sắp xếp nổi bọt
void BubbleShort( int arr[], int n){
	int i , j;
	bool KTDoiCho= false;
	for( int i =0 ; i<n-1 ; i++){
		 KTDoiCho= false;
		for( int i = 0 ; j < n -i - 1; j++){
			if(arr[j]>arr[i+1]){
				Swap(arr[j], arr[j+1]);
					KTDoiCho= true;
				
				
			}
		}
		if(!KTDoiCho)//Nếu không có trường hợp đổi chổ nào thì đã sắp xếp
		break;
	}
}
//Menu
void Menu(int arr[],int n)
{
	int LuaChon;

	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Sap xep chen insertion_sort\n";
		cout<<"2. Sap xep lua chon Selection-Sort\n";
		cout<<"3. Sap xep noi bot Bubble-Sort\n";
		cout<<"8. In mang\n";

		cout<<"9. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (1-9)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Sap xep chèn
			{
				Insertion_sort(arr,n);
				cout<<"Da sap xep!";
				break;
			}
			case 2://Sắp xếp lựa chọn
			{
				SelectionSort(arr,n);
				cout<<"Sap xep lua chon Selection Short\n";
				
				break;
			}
			case 3: // Nổi bọt
			BubbleShort(arr,n);
			cout<<"Dã sap xep noi bot\n";
			
			case 8://In mảng
			{
			Inmang(arr,n);
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
	int arr[] = {7,36,3,1,6,4,15,40};//Khai báo và khởi tạo 8 giá trị cho mảng arr
	Menu(arr,8);
	
	return 0;
}
