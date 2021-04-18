#include <iostream>
#include <stdlib.h>
using namespace std ; 
// khai bao nguyen mau ham 
void nhap(int *p , int n) ; 
void xuat(int *p , int n) ; 
// ham main 
int main() {
	int n =5 ; 
	int *p = NULL ;
	p = (int *)realloc(p,5*4) ; 
	nhap(p,n) ; 
	cout << "============XUAT=============" ; 
	xuat(p,n+7) ; 
	cout << "\n\n" ; 
	////////////////
	cout << "============XUAT===============" ; 
	p = (int *)realloc(p,7*4) ; 
	xuat(p,n+7) ; 
	 
	
}
//////////////////////////////////////////////////////////// ddinh nghia lai cac ham 
// ham nhap dung mang dong
void nhap(int *p , int n) {
	for (int i= 0 ; i<n;i++) {
		cout << "\nNhap vao phan tu thu " << i+1 << " : " ; 
	    cin >> p[i] ; 
	}
}
// ham xuat 
void xuat(int *p , int n) {
	for (int i=0 ; i<n;i++) {
		cout << "\nGia tri cua phan tu thu " << i+1 << " la : " ; 
		cout << p[i] ; 
	}
}
