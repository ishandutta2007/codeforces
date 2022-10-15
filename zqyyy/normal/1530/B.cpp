#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=22;
int n,m,a[N][N];
inline void work(){
	n=read(),m=read();
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++){
			if(i==1){
				if(j==1)a[i][j]=1;
				else a[i][j]=!a[i][j-1];
			}else if(j==1){
				a[i][j]=!a[i-1][j];
			}else if(i==n){
				a[i][j]=(!a[i][j-1]) & (!a[i-1][j]) & (!a[i-1][j-1]) & (!a[i-1][j+1]);
			}else if(j==m)a[i][j]=(!a[i-1][j]) & (!a[i-1][j-1]);
			else a[i][j]=0;
			printf("%d",a[i][j]);
		}
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}