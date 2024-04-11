#include<bits/stdc++.h>
#define ll long long
#define For(i,j,k) for (int i=(j);i<=(k);i++)
using namespace std;
struct node{
	ll s[10];
	int t[10];
	void upd(int *g){
		ll _s[10]={0,0,0,0,0,0,0,0,0,0};
		For(i,0,9)
			_s[g[i]]+=s[i];
		For(i,0,9)
			s[i]=_s[i],t[i]=g[t[i]];
	}
};
node t[265000];
int tr[10][10][10];
int n,q,a[100005];
void pushdown(int k){
	t[k*2].upd(t[k].t);
	t[k*2+1].upd(t[k].t);
	For(i,0,9)
		t[k].t[i]=i;
}
void pushup(int k){
	For(i,0,9)
		t[k].s[i]=t[k*2].s[i]+t[k*2+1].s[i];
}
void build(int k,int l,int r){
	For (i,0,9)
		t[k].t[i]=i;
	if (l==r){
		for (int i=1;i<=a[l];i*=10)
			t[k].s[a[l]/i%10]+=i;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x,int y,int *v){
	if (l==x&&r==y){
		t[k].upd(v);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else change(k*2,l,mid,x,mid,v),
		 change(k*2+1,mid+1,r,mid+1,y,v);
	pushup(k);
}
ll ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		ll ans=0;
		For(i,0,9)
			ans+=t[k].s[i]*i;
		return ans;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	For(i,0,9)
		For(j,0,9)
			For(k,0,9)
				tr[i][j][k]=(k==i?j:k);
	scanf("%d%d",&n,&q);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	while (q--){
		int fl,l,r,x,y;
		scanf("%d%d%d",&fl,&l,&r);
		if (fl==1){
			scanf("%d%d",&x,&y);
			change(1,1,n,l,r,tr[x][y]);
		}
		else
			printf("%lld\n",ask(1,1,n,l,r));
	} 
}