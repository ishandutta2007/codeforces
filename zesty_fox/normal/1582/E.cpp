#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
const ll inf=1e18;
int n,m,a[N];
ll sum[N],f[N][666];
inline void work(){
    n=read(),m=sqrt(2*n);
    for(int i=1;i<=m;i++)f[0][i]=0;
    f[0][0]=inf;
    for(int i=1;i<=n;i++)a[i]=read();
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
	for(int j=0;j<=m;j++)f[i][j]=f[i-1][j];
	for(int j=1;j<=m && j*(j+1)/2<=i;j++){
	    ll res=sum[i]-sum[i-j];
	    if(f[i-j][j-1]>res)f[i][j]=max(f[i][j],res);
	}
    }
    for(int i=m;i;i--)
	if(f[n][i]){
	    printf("%d\n",i);
	    return;
	}
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}