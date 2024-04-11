#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
const int Mod=1e9+7;
int n,m,a,b,ans,pre[1010000],suf[1010000],fac[1010000],y;
IN Pow(int x,int y){
	re res=1;
	while(y){
		if(y&1)res=(ll)res*x%Mod;
		x=(ll)x*x%Mod;
		y>>=1;
	}
	return res;
}
IN Plus(int x,int y){
	x+=y;
	if(x>=Mod)x-=Mod;
	return x;
}
int main(){
	read(n);read(m);
	pre[0]=fac[0]=suf[m+3]=1;
	F(i,1,m+2)pre[i]=(ll)pre[i-1]*(n-i)%Mod,fac[i]=(ll)fac[i-1]*i%Mod;
	FOR(i,m+2,1)suf[i]=(ll)suf[i+1]*(n-i)%Mod;
	F(x,1,m+2){
		y=Plus(y,Pow(x,m));
		a=(ll)pre[x-1]*suf[x+1]%Mod;
		b=(ll)fac[x-1]*fac[m+2-x]%Mod;
		a=(ll)a*y%Mod;
		ans=Plus(ans,(m-x)&1?(Mod-(ll)a*Pow(b,Mod-2)%Mod):(ll)a*Pow(b,Mod-2)%Mod);
	}
	cout<<ans;
	return 0;
}