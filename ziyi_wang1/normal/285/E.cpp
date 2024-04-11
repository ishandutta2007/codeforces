#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define STS system("pause")
I read(int &res){
	res=0;re g=1;register char ch=getchar();
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
int n,m,now,f[1010][1010][4],fac[1010],inv[1010],ans;
IN Pow(int x,int y){
	re res=1;
	while(y){
		if(y&1)res=(ll)res*x%Mod;
		x=(ll)x*x%Mod;
		y>>=1;
	}
	return res;
}
I init(){
	fac[0]=1;
	F(i,1,n)fac[i]=(ll)fac[i-1]*i%Mod;
	inv[n]=Pow(fac[n],Mod-2);
	FOR(i,n-1,0)inv[i]=(ll)inv[i+1]*(i+1)%Mod;
}
I Add(int &x,int y){
	x+=y;if(x>=Mod)x-=Mod;
}
IN Plus(int x,int y){
	x+=y;if(x>=Mod)x-=Mod;return x;
}
IN C(int x,int y){
	return (ll)fac[x]*inv[y]%Mod*inv[x-y]%Mod;
}
int main(){
	read(n);read(m);
	init();
	f[1][1][1]=f[1][0][0]=1;
	F(i,2,n){
		F(j,0,i){
			Add(f[i][j][0],Plus(j?f[i-1][j-1][0]:0,Plus(f[i-1][j][0],f[i-1][j][2])));
			if(i<n)Add(f[i][j][1],Plus(j?f[i-1][j-1][0]:0,j?f[i-1][j-1][2]:0));
			Add(f[i][j][2],Plus(j?f[i-1][j-1][1]:0,Plus(f[i-1][j][1],f[i-1][j][3])));
			if(i<n)Add(f[i][j][3],Plus(j?f[i-1][j-1][1]:0,j?f[i-1][j-1][3]:0));
		}
	}
	ans=0;
	F(i,m,n){
		now=(ll)Plus(f[n][i][0],f[n][i][2])*fac[n-i]%Mod*C(i,m)%Mod;
		if((i-m)&1)Add(ans,Mod-now);
		else Add(ans,now);
	}
	cout<<ans;
	return 0;
}