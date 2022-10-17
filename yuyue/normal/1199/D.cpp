#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int w[M],n,q;
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
struct node{
	int mi,tag;
}a[M<<3];
void pushup(int x){
	a[x].mi=min(a[lc].mi,a[rc].mi);
}
void B(int x,int l,int r){
	a[x].tag=-1;
	if (l==r){
		a[x].mi=w[l];
		return ;
	}
	B(lc,l,mid);
	B(rc,mid+1,r);
	pushup(x);
}
void pushdown(int x){
	if (a[x].tag==-1) {
//		a[x].tag=-1;
		return ;
	}
	a[lc].tag=max(a[lc].tag,a[x].tag);
	a[rc].tag=max(a[rc].tag,a[x].tag);
	a[lc].mi=max(a[lc].mi,a[x].tag);
	a[rc].mi=max(a[rc].mi,a[x].tag);
	a[x].tag=-1;
}
void U(int x,int l,int r,int p,int d){
	if (l==r){
		a[x].mi=d;
		return ;
	}
	pushdown(x);
	if (p<=mid) U(lc,l,mid,p,d);
	else U(rc,mid+1,r,p,d);
	pushup(x);
}
int Q(int x,int l,int r,int p){
	if (l==r) return a[x].mi;
	pushdown(x);
	if (p<=mid) return Q(lc,l,mid,p);
	return Q(rc,mid+1,r,p);
}
int main(){
	n=read(); 
	F(i,1,n) w[i]=read();
	q=read();
	B(1,1,n);
	while (q--){
		int ty=read();
		if (ty==1){
			int p=read(),x=read();
			U(1,1,n,p,x);
		}
		else {
			int x=read();
			pushdown(1);
			a[1].tag=x;
			a[1].mi=max(a[1].mi,x);
		}
	}
	F(i,1,n-1) cout<<Q(1,1,n,i)<<" ";
	cout<<Q(1,1,n,n)<<"\n";
	return 0;
}