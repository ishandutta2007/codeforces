#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
/*
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
*/
const int N=300005*4;
int n;
int p[N],q[N],r[N];
int ans[N];
int sum[N],mx[N];
void pushup(int rt){
	int ls=rt<<1,rs=ls|1;
	sum[rt]=sum[ls]+sum[rs];
	mx[rt]=max(mx[rs],mx[ls]+sum[rs]);
}
void update(int rt,int L,int R,int x,int d){
	if (L==R){
		sum[rt]+=d,mx[rt]+=d;
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		update(ls,L,mid,x,d);
	else
		update(rs,mid+1,R,x,d);
	pushup(rt);
}
int main(){
	n=read();
	For(i,1,n)
		p[i]=read(),r[p[i]]=i;
	For(i,1,n)
		q[i]=read();
	int val=n+1;
	For(i,1,n){
		while (mx[1]<=0)
			update(1,1,n,r[--val],1);
		ans[i]=val;
		update(1,1,n,q[i],-1);
	}
	For(i,1,n)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}