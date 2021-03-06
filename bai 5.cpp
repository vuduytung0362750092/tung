#include <iostream>
#include <cmath>
using namespace std ; 
// ham nhap mang a
void nhap_mang(int a[] ,int n) {
	for (int i=0 ; i<n;i++) {
		cout << "a[" << i << "] = " ;
		cin >> a[i] ;
	}
} 
// ham xuat mang 
void xuat_mang(int a[] ,int n) {
	for (int i=0 ; i<n;i++)  {
		cout << a[i] << " " ;
	}
}
// ham sap xep tang dan 
void sapxeptangdan(int a[] , int n) {
	for (int i= 0 ;i<n;i++) {
		for (int j=i+1 ; j<n;j++) {
			if (a[i] > a[j]) {
				swap(a[i] , a[j]) ;
			}
		}
	}
}
// ham sap xep giam dan 
void sapxepgiamdan(int a[] ,int n) {
	for (int i= 0 ;i<n;i++) {
		for (int j=i+1 ; j<n;j++) {
			if (a[i] < a[j]) {
				swap(a[i] , a[j]) ;
			}
		}
	}
}
// ham chuyen cac phan tu <= 0 cua a sang mang b va sap xep mang b 
void movefirst(int a[] , int b[] , int n) {
	int dem = 0; 
	for (int i=0;i<n;i++) {
		if (a[i] <= 0 ) {
			b[dem] = a[i] ; 
			dem++;
		}
	}
}
// ham chuyen cac phan tu > 0 cua mang a sang mang c 
void movesecond(int a[] ,int c[] , int n) {
	int dem = 0 ;
	for (int i=0;i<n;i++) {
		if (a[i] > 0 ) {
			c[dem] = a[i] ;
			dem++;
		}
	}
}
// ham gop mang b va c thanh 1 mang d thoa man de bai 
void gop_mang(int b[] , int m ,int c[] , int k , int d[]) {
	int count = 0 ;
	for (int i=0;i<m;i++) {
		d[count] = b[i] ;
		count++;
	}
	for (int i=0 ; i<k;i++) {
		d[count] = c[i] ;
		count++; 
	}
}
// ham dem so luong phan tu <=0 cua mang a ;
int demfirst(int a[] , int n) {
	int dem = 0 ;
	for (int i=0;i<n;i++) {
		if (a[i] <= 0 ) {
			dem++ ; 
		}
	}
	return dem ;
}
int main() {
	int a[100] ;
	int b[100] ;
	int c[100] ;
	int d[100] ;
	int n ; 
	do {
		cout << "\nNhap vao so phan tu mang a " ;
		cin >> n ;
		if (n<1 || n > 100) {
			cout << "\nVui long nhap lai : " ;
		}
	}
	while (n<1 || n>100) ;
	nhap_mang(a,n) ;
	cout << "\nMang a la : " ;
	xuat_mang(a,n) ;
	int m = demfirst(a,n) ;
	int k = n-m;
	movefirst(a,b,n) ;
	sapxeptangdan(b,m) ;
	movesecond(a,c,n) ;
	sapxepgiamdan(c,k) ;
	gop_mang(b,m,c,k,d) ;
	cout << "\nMang d la : " ; 
	xuat_mang(d,n) ;
}

