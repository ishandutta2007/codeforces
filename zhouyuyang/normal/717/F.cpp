#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int sz;
	ll mn0,mn1,r,tg;
	void add(ll v){
		if (sz&1) r+=v;
		tg+=v; mn0+=v;
	}
}t[525000],ans;
node operator +(const node &k1,const node &k2){
	node k; k.tg=0;
	k.sz=k1.sz+k2.sz;
	if (k2.sz&1) k.r=k2.r-k1.r;
	else k.r=k2.r+k1.r;
	if (k1.sz&1){
		k.mn0=min(k1.mn0,k2.mn1+k1.r);
		k.mn1=min(k1.mn1,k2.mn0-k1.r);
	}
	else{
		k.mn0=min(k1.mn0,k2.mn0-k1.r);
		k.mn1=min(k1.mn1,k2.mn1+k1.r);
	}
	return k;
}
void build(int k,int l,int r){
	if (l==r){
		int x; scanf("%d",&x);
		t[k]=(node){1,x-1,1ll<<60,x-1,0};
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void pushdown(int k){
	if (!t[k].tg) return;
	t[k*2].add(t[k].tg);
	t[k*2+1].add(t[k].tg);
	t[k].tg=0;
}
void add(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		t[k].add(v);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) add(k*2,l,mid,x,y,v);
	else if (x>mid) add(k*2+1,mid+1,r,x,y,v);
	else add(k*2,l,mid,x,mid,v),
		 add(k*2+1,mid+1,r,mid+1,y,v);
	t[k]=t[k*2]+t[k*2+1];
}
void find(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		ans=ans+t[k];
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) find(k*2,l,mid,x,y);
	else if (x>mid) find(k*2+1,mid+1,r,x,y);
	else find(k*2,l,mid,x,mid),
		 find(k*2+1,mid+1,r,mid+1,y);
}
int n,Q;
int main(){
	scanf("%d",&n);
	build(1,1,n);
	scanf("%d",&Q);
	while (Q--){
		int tp,l,r,k;
		scanf("%d%d%d",&tp,&l,&r);
		l++; r++;
		if (tp==1){
			scanf("%d",&k);
			add(1,1,n,l,r,k);
		}
		else{
			ans=(node){0,1ll<60,1ll<<60,0,0};
			find(1,1,n,l,r);
			puts(!ans.r&&ans.mn0>=0&&ans.mn1>=0?"1":"0");
		}
	}
}