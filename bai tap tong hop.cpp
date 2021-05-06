#include <iostream>
using namespace std ; 
// khai bao struct 
struct NODE {
	int data ; 
	struct NODE *pLeft ; 
	struct NODE *pRight ; 
};
typedef struct NODE node ; 
// ham khoi tao 
void khoitaocay(node *&t) {
	t=NULL ; 
}
// ham them node vao cay 
void themnodevaocay(node *&t , int x ) {
	if (t==NULL) {
		node *p = new node ; 
		p->data = x ; 
		p->pLeft = NULL ; 
		p->pRight = NULL ; 
		t=p ; 
	}
	else {
		if (t->data < x) {
			themnodevaocay(t->pRight,x) ; 
		}
		else if (t->data > x) {
			themnodevaocay(t->pLeft,x) ; 
		}
	}
} 
// ham duyet theo NLR
void NLR(node *t) {
	if (t!=NULL) {
		cout << t->data << " " ; 
		NLR(t->pLeft) ; 
		NLR(t->pRight) ; 
	}
} 
// ham duyet theo LNR
void LNR(node *t) {
	if (t!=NULL) {
		LNR(t->pLeft) ; 
		cout << t->data << " " ; 
		LNR(t->pRight) ; 
	}
}
// ham duyet theo RNL
void RNL(node *t) {
	if (t!=NULL) {
		RNL(t->pRight) ; 
		cout << t->data << " " ; 
		RNL(t->pLeft)  ; 
	}
}
// ham tim kiem node x 
node *timkiemnode(node *t , int x) {
	if (t==NULL) {
		return NULL ; 
	}
	else {
		if (t->data < x) {
			timkiemnode(t->pRight,x) ; 
		}
		else if (t->data > x) {
			timkiemnode(t->pLeft,x) ; 
		}
		else {
			return t ;
		}
	}
}
// ham di tim node the mang
void timnodethemang(node *&X , node *&Y) { /////y = t->pRight ; 
      if (Y->pLeft!=NULL) {
      	timnodethemang(X,Y->pLeft) ; ///// duyet tiep sang trai 
	  }
	  else {
	  	/// khi Y la NULL tuc laf Y da la node xa nhat ben trai cua cay con phai 
	  	X->data = Y->data ; 
	  	X=Y ; 
	  	Y=Y->pRight ; 
	  } 	
}
// ham xoa node co khoa k bat ki tren cay 
void xoa(node *&t , int x) {
	if (t==NULL) {
		return ; 
	}
	else {
		if (t->data < x) {
			xoa(t->pRight,x) ; 
		}
		else if (t->data > x) {
			xoa(t->pLeft,x) ; 
		}
		else {
			node *X = t ; 
			if (t->pLeft == NULL) {
				t=t->pRight ; 
			}
			else if (t->pRight == NULL) {
				t=t->pLeft ; 
			}
			else {
				timnodethemang(X,t->pRight) ; 
			}
			delete X ; 
		}
	}
}
// ham dem so node trong cay 
int demsonodetrongcay(node *t) {
	if (t==NULL) {
		return 0 ; 
	}
	if (t!=NULL) {
		int a = demsonodetrongcay(t->pLeft) ; 
		int b = demsonodetrongcay(t->pRight) ;
		return a + b + 1 ; 
	}
}
// ham dem so node 2 con 
int demnodehaicon(node *t ) {
	if (t==NULL) {
		return 0 ; 
	}
	else {
		if (t->pLeft !=NULL && t->pRight !=NULL) {
			return 1+demnodehaicon(t->pLeft) + demnodehaicon(t->pRight) ; 
		}
	}
	return demnodehaicon(t->pLeft) + demnodehaicon(t->pRight) ; 
}
// ham dem so node la 
int demsonodela(node *t) {
	if (t==NULL) {
		return 0 ; 
	}
	else {
		if (t->pLeft == NULL && t->pRight == NULL) {
			return 1 + demsonodela(t->pLeft) + demsonodela(t->pRight) ; 
		}
	}
	return demsonodela(t->pLeft) + demsonodela(t->pRight) ; 
}
// ham kiem tra so nguyen to 
bool kiemtra(int n) {
	if (n<2) {
		return false ; 
	}
	if (n==2) {
		return true ; 
	}
	if (n>2) {
		for (int i=2 ;i<n;i++) {
			if (n%i==0) {
				return false ; 
			}
		}
	}
	return true ;  
}
// ham xoa cac so nguyen to 
void xoacacsonguyento(node *&t) {
        if (t==NULL) {
        	return ; 
		}
		else {
		if (kiemtra(t->data) == true) {
			xoa(t,t->data) ; 
		}
		xoacacsonguyento(t->pLeft) ; 
		xoacacsonguyento(t->pRight) ; 
	}
}
// ham menu
void menu(node *&t) {
	while (true) {
		system("cls") ; 
		cout << "\n\n\t\t==============MENU================" ; 
		cout << "\n1.Nhap du lieu " ; 
		cout << "\n2.Duyet theo NLR" ; 
		cout << "\n3.Duyet theo LNR" ; 
		cout << "\n4.Duyet theo RNL" ; 
		cout << "\n5.Tim kiem phan tu " ; 
		cout << "\n6.Xoa node co khoa k bat ki " ; 
		cout << "\n7.Dem so node trong cay " ; 
		cout << "\n8.Dem so node hai con " ; 
		cout << "\n9.Dem so node la " ; 
		cout << "\n10.Xoa tat cac cac node la so nguyen to " ; 
		cout << "\n0.Thoat" ; 
		cout << "\n\n\t\t================END===================" ; 
		int luachon ; 
		cout << "\nNhap vao lua chon cua ban : " ; 
		cin >> luachon ; 
		switch(luachon) {
			case 1 : {
				int x ; 
				cout << "\nNhap vao gia tri can them : " ; 
				cin >> x ; 
				themnodevaocay(t,x) ; 
				break;
			}
			case 2 : {
				NLR(t) ; 
				system("pause") ; 
 				break;
			}
			case 3 : {
				LNR(t) ; 
				system("pause") ; 
				break;
			}
			case 4 : {
				RNL(t) ; 
				
				system("pause") ; 
				break;
			}
			case 5 : {
				int x ; 
				cout << "\nNhap vao gia tri node can tim kiem : " ; 
				cin >> x ;
 				node *p = timkiemnode(t,x) ; 
 				if (p==NULL) {
 					cout << "\nPhan tu " << x << " khong trong cay " ; 
				 }
				else {
					cout << "\nPhan tu " << x << " co thuoc trong cay " ; 
				} 
				system("pause") ; 
				break;
			}
			case 6 : { 
			    int x ; 
			    cout << "\nNhap vao gia tri can xoa : " ; 
			    cin >> x ; 
			    xoa(t,x) ; 
				break;
			}
			case 7 : {
				int x = demsonodetrongcay(t) ;
				cout << "\nSo node trong cay se la : " << x ; 
				system("pause") ; 
				break;
			}
			case 8 : {
				int x = demnodehaicon(t) ; 
				cout << "\nSo node hai con trong cay la : " << x ; 
				system("pause") ; 
				break;
			}
			case 9 : {
				int x = demsonodela(t) ; 
				cout << "\nSo node la trong cay la : " << x ; 
				system("pause") ; 
				break;
			}
			case 10 : {
				xoacacsonguyento(t) ; 
				system("pause") ; 
				break;
			}
			case 0 : {
				return ; 
				break;
			}
			default : {
				cout << "\nVui long nhap lai lua chon cua ban : "  ; 
				system("pause") ; 
				break;
			}
		}
 	}
}
int main() {
	node *t ; 
	khoitaocay(t) ; 
	menu(t) ; 
}
