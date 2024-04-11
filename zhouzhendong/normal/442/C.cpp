#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
					For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
const int N=500005*2;
int n;
int v[N];
int t[N<<2];
void ckmax(int &a,int b){
	if (v[a]<v[b])
		a=b;
	else if (v[a]==v[b]&&a>b)
		a=b;
}
void build(int rt,int L,int R){
	if (L==R)
		return (void)(t[rt]=L);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	ckmax(t[rt]=t[ls],t[rs]);
}
int Query(int rt,int L,int R,int xL,int xR){
	if (R<xL||L>xR)
		return 0;
	if (xL<=L&&R<=xR)
		return t[rt];
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	int x=Query(ls,L,mid,xL,xR);
	ckmax(x,Query(rs,mid+1,R,xL,xR));
	return x;
}
LL ans=0;
int a[N*2];
int lp,rp;
void Solve(int L,int R){
	if (L==R){
		if (L==1)
			a[--lp]=v[L];
		if (R==n)
			a[++rp]=v[R];
	}
	if (L>=R)
		return;
	int mid=Query(1,1,n,L,R);
	if (L<mid&&L>1)
		ans+=v[mid];
	if (R>mid&&R<n)
		ans+=v[mid];
	if (L==1&&R==n)
		a[++rp]=v[mid];
	else if (L==1)
		a[--lp]=v[mid];
	else if (R==n)
		a[++rp]=v[mid];
//	printf("L = %d, R = %d, mid = %d, ans = %lld\n",L,R,mid,ans);
	Solve(L,mid-1);
	Solve(mid+1,R);
}
int main(){
	n=read();
	lp=n+1,rp=n;
	For(i,1,n)
		v[i]=read();
	build(1,1,n);
	Solve(1,n);
//	outval(lp);outval(rp);outarr(a,lp,rp);outval(ans);
	int m=n+1,l=n,r=n+2;
	while (1){
		int vl=0,vm=0,vr=0;
		if (l>lp)
			vl=min(a[l-1],a[m]);
		if (r<rp)
			vr=min(a[r+1],a[m]);
		if (l>=lp&&r<=rp)
			vm=min(a[l],a[r]);
		int mx=max(vl,max(vr,vm));
		if (!mx)
			break;
		ans+=mx;
		if (vl==mx){
			l--;
		}
		else if (vm==mx){
			if (l>=lp&&a[l]>a[r])
				m=l,l--;
			else
				m=r,r++;
		}
		else if (vr==mx){
			r++;
		}
	}
	cout<<ans<<endl;
	return 0;
}