#include<stdio.h>
#include<stdlib.h>
#include<math.h>
const int so =100;

void NhapMaTran(int a[so][so],int x,int y){
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++){
			printf("a[%d][%d]=",i,j);scanf("%d",&a[i][j]);
		}
}
void XuatMaTran(int a[so][so],int x,int y){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++)
			printf("%d ",a[i][j]);
			printf("\n");
		}
}

int TongPhanTu(int a[so][so],int x,int y){
	int sum=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++)
			sum=sum+a[i][j];
		}
	return sum;	
}

int HangTongMax(int a[so][so],int x,int y){
	int sum[x]={};
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++)
			sum[i]=sum[i]+a[i][j];
		}
	int max=sum[0];	
	int vt=0;
	for(int i=0;i<x;i++){
		if(sum[i]>max){
			max=sum[i];
			vt=i;	
		}
	}	
	return vt+1;
}
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void HangDuocSapXep(int a[so][so],int x,int y,int row){
	for(int i=0;i<y-1;i++)
	for(int j=0;j<y-1-i;j++){
		if(a[row][j]>a[row][j+1]) swap(a[row][j],a[row][j+1]);
	}
}
void HoanViMaTran(int a1[so][so],int a2[so][so],int &x,int &y){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++)
			a1[j][i]=a2[i][j];
}
}
void TongMaTran(int a1[so][so],int a2[so][so],int x,int y){
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			a1[i][j]=a1[i][j]+a2[i][j];
}
main(){
	int x=2;
	int y=3;
	int a[100][100];
	int kq[100][100];
	NhapMaTran(a,x,y);
	NhapMaTran(kq,x,y);
	printf("\nMa tran vua nhap la: \n");
	XuatMaTran(a,x,y);
	
	printf("\nTong phan tu trong mang la: %d",TongPhanTu(a,x,y));
	printf("\nHang co tong max la hang %d\n",HangTongMax(a,x,y));
		
	TongMaTran(kq,a,x,y);
	XuatMaTran(kq,x,y);
	HoanViMaTran(kq,a,x,y);
	XuatMaTran(kq,y,x);
	system("pause");
}
