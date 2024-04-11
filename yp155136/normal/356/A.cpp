#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int seg[2400020];
int tag[2400020];
bool Tag[2400020]; //to record all different

void init(int id,int L,int R) {
	if (L==R) {
		seg[id]=L;
		tag[id]=0;
		Tag[id]=false;
		return;
	}
	int mid=(L+R)>>1;
	init(id*2,L,mid);
	init(id*2+1,mid+1,R);
	tag[id]=0;
	Tag[id]=false;
	return;
}

void pull(int id,int L,int R) {
	if (tag[id]==0 || Tag[id]==true) return;
	else if (L==R) {
//		cout<<"seg["<<L<<"] = "<<seg[id]<<endl;
//		cout<<"tag["<<L<<"] = "<<tag[id]<<endl;
		if (seg[id]!=L) ;
		else if (seg[id]==L&&seg[id]!=tag[id]) seg[id]=tag[id],Tag[id]=true;
		tag[id]=0;
		return;
	}
	else {
//		cout<<"tag["<<L<<"~"<<R<<"] = "<<tag[id]<<endl;
		int mid=(L+R)>>1;
		if (tag[id*2]!=0 && Tag[id*2]==false) {
			pull(id*2,L,mid);
		}
		if (Tag[id*2]==false) tag[id*2]=tag[id];
//		cout<<"tag["<<L<<"~"<<mid<<"] = "<<tag[id*2]<<endl;
		if (tag[id*2+1]!=0 && Tag[id*2+1]==false) {
			pull(id*2+1,mid+1,R);
		}
		if (Tag[id*2+1]==false) tag[id*2+1]=tag[id];
//		cout<<"tag["<<mid+1<<"~"<<R<<"] = "<<tag[id*2+1]<<endl;
		tag[id]=0;
		if (Tag[id*2]==true && Tag[id*2+1]==true) Tag[id]=true;
		return;
	}
}

void modify(int id,int L,int R,int l,int r,int val) {
	if (l>R || L>r) return;
	else if (l<=L && R<=r) {
		pull(id,L,R);
		tag[id]=val;
//		cout<<"tag["<<L<<"~"<<R<<"] = "<<tag[id]<<endl;
		return;
	}
	pull(id,L,R);
	int mid=(L+R)>>1;
	modify(id*2,L,mid,l,r,val);
	modify(id*2+1,mid+1,R,l,r,val);
//	pull(id,L,R);
}

int query(int id,int L,int R,int pos) {
	if (L==R) {
		pull(id,L,R);
		return seg[id];
	}
	pull(id,L,R);
	int mid=(L+R)>>1;
	if (pos<=mid) return query(id*2,L,mid,pos);
	else return query(id*2+1,mid+1,R,pos);
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		init(1,1,n);
		for (int x=0;m>x;x++) {
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			modify(1,1,n,a,b,c);
		}
		for (int x=1;n>=x;x++) {
			printf("%d",((query(1,1,n,x))==x?0:query(1,1,n,x)));
			if (x!=n) printf(" ");
		}
		puts("");
	}
}