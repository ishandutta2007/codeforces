#include<bits/stdc++.h>
#define N 150005
using namespace std;

int n,p,q;

struct node{
	int s,a[5],b[5];
	void fill(int x,int y){
		s=1; a[0]=x; b[0]=y;
	}
}t[525000];

node operator +(const node &a,const node &b){
	node c; c=a;
	for (int i=0;i<b.s;i++){
		int fl=0;
		for (int j=0;j<c.s;j++)
			if (c.a[j]==b.a[i]){
				c.b[j]+=b.b[i];
				fl=1;
				break;
			}
		if (fl) continue;
		if (c.s<p){
			c.a[c.s]=b.a[i];
			c.b[c.s]=b.b[i];
			c.s++;
			continue;
		}
		int k=0;
		for (int j=1;j<c.s;j++)
			if (c.b[j]<c.b[k]) k=j;
		if (b.b[i]<c.b[k])
			for (int j=0;j<c.s;j++)
				c.b[j]-=b.b[i];
		else{
			int tmp=c.b[k];
			c.a[k]=b.a[i];
			c.b[k]=b.b[i];
			for (int j=0;j<c.s;j++)
				c.b[j]-=tmp;
		}
	}
	return c;
}

int a[N];

int tg[525000];

void build(int k,int l,int r){
	if (l==r){
		t[k].fill(a[l],1);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}

void pushdown(int k,int l,int r){
	if (!tg[k]) return;
	int mid=(l+r)/2;
	t[k*2].fill(tg[k],mid-l+1);
	t[k*2+1].fill(tg[k],r-mid);
	tg[k*2]=tg[k*2+1]=tg[k];
	tg[k]=0;
}

void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		t[k].fill(v,r-l+1);
		tg[k]=v;
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else change(k*2,l,mid,x,mid,v),
		 change(k*2+1,mid+1,r,mid+1,y,v);
	t[k]=t[k*2]+t[k*2+1];
}

node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	pushdown(k,l,r);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y); 
}

int main(){
	scanf("%d%d%d",&n,&q,&p);
	p=100/p;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while (q--){
		int tp,l,r,x;
		scanf("%d%d%d",&tp,&l,&r);
		if (tp==1){
			scanf("%d",&x);
			change(1,1,n,l,r,x);
		}
		else{
			node ans=ask(1,1,n,l,r);
			printf("%d",ans.s);
			for (int i=0;i<ans.s;i++)
				printf(" %d",ans.a[i]);
			puts("");
		}
	}
}