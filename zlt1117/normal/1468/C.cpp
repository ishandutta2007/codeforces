#include<bits/stdc++.h>
#define re register
#define ll long long
#define LL inline ll
#define I inline int
#define V inline void
#define FOR(i,a,b) for(re int i=(a),i##i=(b) ; i<=i##i ; ++i)
#define ROF(i,a,b) for(re int i=(a),i##i=(b) ; i>=i##i ; --i)
#define gc getchar()
//#define gc (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<18,stdin),fs==ft))?0:*fs++
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;
const int N=5e5+10,inf=1e9+7;
char *fs,*ft,buf[1<<18];
LL read(){
    ll p=0; char ch=gc; bool w=0;
    while(!isdigit(ch)) w=ch=='-'?1:0,ch=gc;
    while(isdigit(ch)) p=p*10+ch-'0',ch=gc;
    return w?-p:p;
}
int n,cnt,a[N<<2],b[N<<2],c[N<<2],ans[N],as;
V upd(int rt){
	a[rt]=b[rt]=c[rt]=0;
	b[rt]=a[rs]?b[rs]:b[rt],b[rt]=a[ls]?b[ls]:b[rt];
	a[rt]=a[ls]>=a[rs]?a[ls]:a[rs];
	c[rt]=a[ls]>=a[rs]?c[ls]:c[rs];
	return ;
}
V add(int rt,int l,int r,int p,int k){
	if(l==r) return b[rt]=p,a[rt]=k,c[rt]=p,void();
	int mid=(l+r)>>1; 
	if(p<=mid) add(ls,l,mid,p,k);
	else add(rs,mid+1,r,p,k);
	upd(rt);
}
int main(){
	int x,y;
	n=read();
	FOR(i,1,n){
		x=read();
		if(x==1) y=read(),++cnt,add(1,1,n,cnt,y);
		if(x==2) y=b[1],add(1,1,n,y,0),ans[++as]=y;
		if(x==3) y=c[1],add(1,1,n,y,0),ans[++as]=y;
	}
	FOR(i,1,as) printf("%d ",ans[i]);
	return 0;
}