#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
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
int n,m,inv2,tw,ta,s[5050][5050],fac[5050],inv[5050],ans;
IN Pow(int x,int y){
	re res=1;
	while(y){
		if(y&1)res=(ll)res*x%Mod;
		x=(ll)x*x%Mod;
		y>>=1;
	}
	return res;
}
I add(int &x,int y){
	(x+=y)>=Mod?x-=Mod:0;
}
IN Plus(int x,int y){
	(x+=y)>=Mod?x-=Mod:0;return x;
}
int main(){
	read(n);read(m);
	s[0][0]=1;
	F(i,1,m){
		F(j,1,i)s[i][j]=Plus((ll)s[i-1][j]*j%Mod,s[i-1][j-1]);
	}
	fac[0]=1;
	F(i,1,m)fac[i]=(ll)fac[i-1]*i%Mod;
	inv[m]=Pow(fac[m],Mod-2);
	FOR(i,m-1,0)inv[i]=(ll)inv[i+1]*(i+1)%Mod;
	inv2=Pow(2,Mod-2);tw=Pow(2,n);ta=1;
	F(i,0,m)add(ans,(ll)s[m][i]*ta%Mod*tw%Mod),tw=(ll)tw*inv2%Mod,ta=(ll)ta*(n-i)%Mod;
	printf("%d",ans);
	
	
	return 0;
}