#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1000005,mod=1e9+7;
int n,m,a,b;
int Fac[N],Inv[N];
int C(int n,int m){
	if (m>n||m<0)
		return 0;
	return (LL)Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int Pow(int x,int y){
	if (y<0)
		return Pow(x,y+mod-1);
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void init(int n){
	for (int i=Fac[0]=1;i<=n;i++)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	Inv[n]=Pow(Fac[n],mod-2);
	for (int i=n;i>=1;i--)
		Inv[i-1]=(LL)Inv[i]*i%mod;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
int main(){
	n=read(),m=read(),a=read(),b=read();
	init(max(n,m));
	int ans=0;
	for (int i=0;i<=n-2;i++)
		Add(ans,(LL)C(n-2,i)*C(m-1,i)%mod*Fac[i]%mod
					*Pow(m,n-2-i)%mod*Pow(n,n-3-i)%mod*(i+2)%mod);
	cout<<ans<<endl;
	return 0;
}