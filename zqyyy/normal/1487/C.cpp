#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=107;
int n,a[N][N],b[N];
inline void work(){
    n=read();
    if(n%2==0)for(int i=1;i<n;i+=2)a[i][i+1]=0;
    for(int i=1;i<=n;i++)b[i]=0;
    for(int i=1;i<=n;i++)
	for(int j=i+1+(n%2==0 && i%2==1);j<=n;j++)
	    if(b[i])a[i][j]=-b[i],b[i]=0;
	    else a[i][j]=b[i]=(i%2==0 && n%2==0)?-1:1;
    for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++){
	    printf("%d ",a[i][j]);
	}
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}