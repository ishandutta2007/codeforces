#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
namespace fastIO{
    char ss[1<<17],*A=ss,*B=ss;
    inline char gc(){if(A==B){B=(A=ss)+fread(ss,1,1<<17,stdin);}return*A++;}
    inline void read(int &x){
        x=0; static bool fff=0; static char c=gc();
        for (;!(c<='9'&&c>='0'); c=gc()) c=='-'? fff=1: 0;
        for (; (c<='9'&&c>='0'); c=gc()) x=(x<<3)+(x<<1)+c-'0';
        fff? x=-x: 0;
    }
}using namespace fastIO;

ll jc[2001000],inv[2001000],ans,er[1001000];
ll K(ll x,int y=mod-2){
	ll t=1; for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod; return t;
}
inline ll C(int x,int y){
	return jc[x]* inv[y]%mod *inv[x-y]%mod;
}

int T,x=2000001,k,t;

int main(){
	jc[0]=1; for (int i=1;i<=x;i++) jc[i]=jc[i-1]*i%mod;
	inv[x]=K(jc[x]); for (int i=x;i>0;i--) inv[i-1]=inv[i]*i%mod;
	er[0]=1; for (int i=1;i<=1000001;i++) er[i]=er[i-1]*2%mod;
	for (read(T);T--;printf("%I64d\n",ans)){
		read(x), read(k);
		ans=er[k-1];
		for (register int i=2;i*i<=x;++i) if (x%i==0){
			for (t=0;x%i==0;x/=i) ++t;
			ans=ans*C(t+k-1,k-1)%mod;
		}
		if (x-1) ans=ans*k%mod;
	}
}