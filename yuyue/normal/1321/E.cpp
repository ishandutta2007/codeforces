#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10,inf=(-2e9)-100;
struct node{
	int x,y,z;
}c[M];
bool cmp(node A,node B){
	return A.x<B.x;
}
int bac[M*5];
struct it{
	int x,c;
}a[M],b[M];
bool cp(it A,it B){
	return A.x<B.x;
}
int sm[M];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int s[M*30],tg[M*30];
void pu(int x){
	s[x]=max(s[x],max(s[lc],s[rc]));
}
void build(int x,int l,int r){
	s[x]=inf;
	if (l==r) {
		if (bac[l]) s[x]=bac[l];
		return ;
	}
	build(lc,l,mid); build(rc,mid+1,r);
	pu(x);
}
void pd(int x){
	if (tg[x]) {
		s[lc]+=tg[x]; 
		tg[lc]+=tg[x];
		s[rc]+=tg[x]; 
		tg[rc]+=tg[x];
		tg[x]=0;
	}
}
void ins(int x,int l,int r,int p,int d){
	if (l==r) return s[x]+=d,void();
	pd(x);
	if (p<=mid) {
		ins(lc,l,mid,p,d);
		tg[rc]+=d; s[rc]+=d;
	}
	else ins(rc,mid+1,r,p,d);
	pu(x);
}
int n,m,p;
int main(){
	n=read(); m=read(); p=read();
	int o=inf,oo=inf;
	F(i,1,n){
		a[i]=it{read(),read()};
		o=max(o,-a[i].c);
	}
	int mx=0;
	F(i,1,m){
		b[i]=it{read(),read()};
		mx=max(mx,b[i].x);
		oo=max(oo,-b[i].c);
		if (!bac[b[i].x]) bac[b[i].x]=-b[i].c;
		bac[b[i].x]=max(bac[b[i].x],-b[i].c);
	}
	F(i,1,p){
		c[i]=node{read(),read(),read()};
	}
	sort(a+1,a+n+1,cp);
	sm[n+1]=-inf;
	DF(i,n,1) sm[i]=min(sm[i+1],a[i].c);
	sort(b+1,b+m+1,cp);
	build(1,1,mx);
	sort(c+1,c+p+1,cmp);
	int j=1;
	int ans=o+oo;
	F(i,1,p){
		while (j<n && a[j].x<=c[i].x) j++; 
		if (a[j].x<=c[i].x) break;
		int ca=-sm[j];
		if (c[i].y+1<=mx) ins(1,1,mx,c[i].y+1,c[i].z);
		ans=max(ans,ca+s[1]);
	}
	cout<<ans<<"\n";
	return 0;
}