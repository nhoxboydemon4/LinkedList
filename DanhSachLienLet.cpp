#include<stdio.h>
#include<stdlib.h>

typedef struct NhanVien{
    	char tinh[8];
    	char HoTen[40];
    	char chucvu[10];
    	int nam;
    }nv;
typedef struct NODE{
	nv data;
	NODE *next;
	
}node;
typedef struct List{
	NODE *pHead;
	NODE *pTail;
}list;
void tao_list(list &l);
node *khoi_tao_node(nv a);
void them_dau(list &l, node *p);
void them_cuoi(list &l, node *p);
void nhap_nv(list &l, int n);
void in_nv(list l);
int main(){
	int n=2;
	list l;
	nhap_nv(l,n);
	in_nv(l);
}
void tao_list(list &l){
	l.pHead=NULL;
	l.pTail=NULL;
}
node *khoi_tao_node(nv a){
	node *p = (node*)malloc(sizeof(node));
	p->data=a;
	p->next=NULL;
	return p;
}
void them_dau(list &l, node *p){
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else
	{
		p->next=l.pHead;
		l.pHead=p;
	}
}void them_cuoi(list &l, node *p){
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else
	{
		l.pTail->next=p;
		p->next=NULL;
	}
}
void nhap_nv(list &l, int n){
	tao_list(l);
	for(int i = 0; i<n;i++){
		nv a;
		printf("ten nhan vien\n");
		gets(a.HoTen);
		printf("chuc  vu la\n");
		gets(a.chucvu);
		printf("nam sinh\n");
		scanf("%d",&a.nam);
		printf("tinh thanh\n");
		gets(a.tinh);
		node *p = khoi_tao_node(a);
		them_dau(l,p);
		}
}
void in_nv(list l){
	for(node*p = l.pHead; p != NULL; p = p->next){
		printf("ten nhan vien : %s\n ",p->data.HoTen);
		printf("chuc  vu la\n%s",p->data.chucvu);
		printf("nam sinh %d\n",p->data.nam);
		printf("tinh thanh %s\n",p->data.tinh);
	}
}



