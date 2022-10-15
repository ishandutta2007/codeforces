#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
inline void ckn(ll &x,ll y){if(x>y)x=y;}
const int N=5007;
int n,s,e;
ll x[N],a[N],b[N],c[N],d[N],f[2][N];
int main(){
    n=read(),s=read(),e=read();
    for(int i=1;i<=n;i++)x[i]=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=1;i<=n;i++)c[i]=read();
    for(int i=1;i<=n;i++)d[i]=read();
    memset(f[0],0x3f,sizeof(f[0])),f[0][0]=0;
    for(int i=1,o=1;i<=n;i++,o^=1){
	memset(f[o],0x3f,sizeof(f[o]));
	if(i==s){
	    for(int j=i>e;j<i;j++){
		if(j)ckn(f[o][j],f[!o][j]+c[i]+x[i]);
		ckn(f[o][j+1],f[!o][j]+d[i]-x[i]);
	    }
	}else if(i==e){
	    for(int j=i>s;j<i;j++){
		if(j)ckn(f[o][j],f[!o][j]+a[i]+x[i]);
		ckn(f[o][j+1],f[!o][j]+b[i]-x[i]);
	    }
	}else{
	    for(int j=(i>s)+(i>e);j<i;j++){
		if(j>(i>s))ckn(f[o][j],f[!o][j]+b[i]+c[i]);
		if(j>(i>e))ckn(f[o][j],f[!o][j]+a[i]+d[i]);
		if(j>=2)ckn(f[o][j-1],f[!o][j]+a[i]+c[i]+x[i]*2);
		ckn(f[o][j+1],f[!o][j]+b[i]+d[i]-2*x[i]);
	    }
	}
    }
    printf("%lld\n",f[n&1][1]);
    return 0;
}