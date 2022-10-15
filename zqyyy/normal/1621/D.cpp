#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=257;
int n,c[N<<1][N<<1];
inline void work(){
    n=read();
    for(int i=1;i<=n+n;i++)
	for(int j=1;j<=n+n;j++)c[i][j]=read();
    ll ans=min({c[1][n+1],c[1][n+n],c[n][n+1],c[n][n+n],c[n+1][1],c[n+n][1],c[n+1][n],c[n+n][n]});
    for(int i=n+1;i<=n+n;i++)for(int j=n+1;j<=n+n;j++)ans+=c[i][j];
    printf("%lld\n",ans);
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}