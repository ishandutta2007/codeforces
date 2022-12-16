#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=307;
int n,m,a[N][N];
inline void work(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    a[i][j]=read();
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
	    int x=(i>1)+(j>1)+(i<n)+(j<m);
	    if(a[i][j]>x){puts("NO");return;}
	    a[i][j]=x;
	}
    puts("YES");
    for(int i=1;i<=n;i++,puts(""))
	for(int j=1;j<=m;j++)
	    printf("%d ",a[i][j]);
}
int main(){
    int T=read();
    while(T--)work();
    return 0;
}