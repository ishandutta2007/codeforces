#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=5007;
struct Hole{int p,c;}a[N];
int n,m,hd,tl,q[N],x[N];
ll s[N],f[2][N];
int main(){
    n=read(),m=read();ll sum=0;
    for(int i=1;i<=n;i++)x[i]=read();
    for(int i=1;i<=m;i++)a[i].p=read(),a[i].c=read(),sum+=a[i].c;
    if(n>sum)puts("-1"),exit(0);
    sort(x+1,x+n+1),sort(a+1,a+m+1,[](auto x,auto y){return x.p<y.p;});
    for(int i=1;i<=n;i++)f[0][i]=1e18;
    for(int i=1,o=1;i<=m;i++,o^=1){
	q[hd=tl=0]=0;
	for(int j=1;j<=n;j++){
	    f[o][j]=f[o^1][j],s[j]=s[j-1]+abs(x[j]-a[i].p);
	    while(hd<=tl && (q[hd]+a[i].c<j || f[o^1][j]-s[j]<f[o^1][q[hd]]-s[q[hd]]))hd++;
	    q[++tl]=j,f[o][j]=f[o^1][q[hd]]+s[j]-s[q[hd]];
	}
    }
    printf("%lld\n",f[m&1][n]);
    return 0;
}