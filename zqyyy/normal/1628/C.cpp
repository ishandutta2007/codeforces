#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,ans;
int a[N][N],b[N][N];
bool vis[N][N];
inline void solve(){
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)vis[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1+(i%2==0);j<=n;j+=2){
			bool ok=1;
			for(int k=0;k<4;k++)ok&=!vis[i+dx[k]][j+dy[k]];
			if(!ok)continue;
			ans^=a[i][j];
			for(int k=0;k<4;k++)vis[i+dx[k]][j+dy[k]]=1;
		}
}
inline void work(){
	n=read(),ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)a[i][j]=b[n-i+1][j]=read();
	solve();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)a[i][j]=b[i][j];
	solve();
	printf("%d\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}