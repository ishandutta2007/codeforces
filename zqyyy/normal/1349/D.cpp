#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7,M=3e5+7,mod=998244353;
inline int qpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=1ll*a*a%mod)
	if(b&1)res=1ll*res*a%mod;
    return res;
}
int n,m,a[N],f[M],g[M];
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),m+=a[i];
    int invm=qpow(m,mod-2),invn=qpow(n-1,mod-2);
    g[0]=n-1;
    for(int i=1;i<m;i++){
	int x=(mod+1-1ll*i*invm%mod+mod-1ll*(m-i)*(n-2)%mod*invm%mod*invn%mod)%mod;
	int y=(1+1ll*i*invm%mod*g[i-1])%mod;
	g[i]=1ll*y*qpow(x,mod-2)%mod;
    }
    for(int i=m-1;~i;i--)f[i]=(f[i+1]+g[i])%mod;
    int res=0;
    for(int i=1;i<=n;i++)res=(res+f[a[i]])%mod;
    res=(res+mod-1ll*f[0]*(n-1)%mod)%mod,res=1ll*res*qpow(n,mod-2)%mod;
    printf("%d\n",res);
    return 0;
}