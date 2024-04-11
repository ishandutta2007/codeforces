#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2007;
int n,m,l[N],s[N],c[N<<1],f[N<<1][N];
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read(),m=n+read();
    for(int i=1;i<=n;i++)l[i]=read();
    for(int i=1;i<=n;i++)s[i]=read();
    for(int i=1;i<=m;i++)c[i]=read();
    memset(f,0xcf,sizeof(f));
    for(int i=0;i<=m;i++)f[i][0]=0;
    for(int i=n;i;i--){
	for(int j=n;j;j--)
	    f[l[i]][j]=max(f[l[i]][j],f[l[i]][j-1]+c[l[i]]-s[i]);
	for(int j=l[i];j<=m;j++)
	    for(int k=0;k<=n>>j-l[i];k++)
		f[j+1][k>>1]=max(f[j+1][k>>1],f[j][k]+(k>>1)*c[j+1]);
    }
    printf("%d\n",f[m+1][0]);
    return 0;
}