#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007;
int n,m,Q,a[N][N],b[N][N],c[N][N];
ll ans;
int dfs(int x,int y,int dx,int dy){
	if(x<1 || y<1 || x>n || y>m || !a[x][y])return 0;
	return 1+dfs(x+dx,y+dy,dy,dx);	
}
ll calc(ll A,ll B,ll C,ll D){
	return A*B+C*D-1;	
}
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+(abs(i-j)<=1)+(i==j)-(i==1 && j==1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			a[i][j]=1;
			ans+=b[n-i+1][m-j+1];
		}
	while(Q--){
		int x=read(),y=read();bool f=a[x][y]^1;a[x][y]=1;
		int A=dfs(x,y,-1,0),B=dfs(x,y,0,1),C=dfs(x,y,0,-1),D=dfs(x,y,1,0);
		a[x][y]=f,ans+=a[x][y]?calc(A,B,C,D):-calc(A,B,C,D);
		printf("%lld\n",ans);
	}
	return 0;
}