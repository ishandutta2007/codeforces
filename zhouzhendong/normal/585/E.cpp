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
const int N=1e7+5,mod=1e9+7;
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
int n;
int a[N],b[N];
int c[N],d[N];
int u[N];
int main(){
	n=read();
	For(i,1,n)
		a[read()]++;
	n=1e7;
//	outarr(a,1,n);
	For(i,1,n)
		for (int j=i;j<=n;j+=i)
			b[i]+=a[j];
//	outarr(b,1,n);
	For(i,1,n)
		c[i]=Del(Pow(2,b[i])-1);
//	outarr(c,1,n);
	Fod(i,n,1)
		for (int j=i+i;j<=n;j+=i)
			Del(c[i],c[j]);
//	outarr(c,1,n);
	u[1]=1;
	For(i,1,n)
		for (int j=i+i;j<=n;j+=i)
			u[j]-=u[i];
//	outarr(u,1,n);
	For(i,1,n)
		for (int j=i,k=1;j<=n;j+=i,k++)
			d[j]+=b[i]*u[i];
//	outarr(d,1,n);
	int ans=0;
	For(i,2,n)
		Add(ans,(LL)c[i]*d[i]%mod);
	cout<<ans<<endl;
	return 0;
}