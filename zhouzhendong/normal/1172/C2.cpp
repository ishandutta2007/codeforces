#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"---------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
						For(_x,L,R)cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=200005,M=3005,mod=998244353;
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
int n,m;
int a[N],b[N];
int s=0,sp=0,sm=0;
int dp[M][M];
int Fac[M],Inv[M];
int C(int n,int m){
	if (m<0||m>n)
		return 0;
	return (LL)Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int main(){
	n=read(),m=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,n){
		b[i]=read(),s+=b[i];
		if (a[i])
			sp+=b[i];
		else
			sm+=b[i];
	}
	for (int i=Fac[0]=1;i<=m;i++)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	Inv[m]=Pow(Fac[m],mod-2);
	Fod(i,m,1)
		Inv[i-1]=(LL)Inv[i]*i%mod;
	dp[0][0]=1;
	For(i,0,m-1)
		For(j,0,i){
			int v=dp[i][j];
			if (!v)
				continue;
			int inv=Pow(s-j+(i-j),mod-2);
			Add(dp[i+1][j],(LL)v*(sp+(i-j))%mod*inv%mod);
			Add(dp[i+1][j+1],(LL)v*(sm-j)%mod*inv%mod);
		}
	int vm=0,vp=0;
	For(i,0,m){
		int v=dp[m][i];
		if (!v)
			continue;
		int sum=0,fm=1,tmp=1;
		For(j,0,i-1)
			fm=(LL)fm*(sm-j)%mod;
		For(j,0,i-2)
			tmp=(LL)tmp*(sm-1-j)%mod;
		Fod(j,min(i,1),0){
			Add(sum,(LL)(1-j)*C(i,j)%mod*tmp%mod);
			tmp=(LL)tmp*(sm-1-(i-j))%mod;
		}
		Add(vm,(LL)sum*Pow(fm,mod-2)%mod*v%mod);
	}
	For(i,0,m){
		int v=dp[m][m-i];
		if (!v)
			continue;
		int sum=0,fm=1,tmp=1;
		For(j,0,i-1)
			fm=(LL)fm*(sp+j)%mod;
		For(j,0,i-1)
			tmp=(LL)tmp*(1+j)%mod;
		Fod(j,i,0){
			Add(sum,(LL)C(i,j)%mod*tmp%mod);
			tmp=(LL)tmp*Pow(j,mod-2)%mod*(sp+(i-j))%mod;
		}
		Add(vp,(LL)sum*Pow(fm,mod-2)%mod*v%mod);
	}
	For(i,1,n)
		if (a[i])
			printf("%lld\n",(LL)vp*b[i]%mod);
		else
			printf("%lld\n",(LL)vm*b[i]%mod);
	return 0;
}