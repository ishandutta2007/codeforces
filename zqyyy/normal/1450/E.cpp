#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=207,M=2007,inf=0x3f3f3f3f;
int n,m,a[N][N],dep[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int y=1;y<=n;y++){
		if(a[x][y]==inf)continue;
		if(dep[y]){
			if(dep[y]%2==dep[x]%2)puts("NO"),exit(0);
			continue;
		}
		dfs(y,x);
	}
}
int main(){
	n=read(),m=read();
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),b=read();
		if(b)a[x][y]=1,a[y][x]=-1;
		else a[x][y]=a[y][x]=1;
	}
	dfs(1,0);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i][j]>a[i][k]+a[k][j])
					a[i][j]=a[i][k]+a[k][j];
	for(int i=1;i<=n;i++)if(a[i][i]<0)puts("NO"),exit(0);
	int x=1,mx=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]>=mx && a[i][j]!=inf)x=i,mx=a[i][j];
	printf("YES\n%d\n",mx);
	for(int i=1;i<=n;i++)printf("%d ",x==i?0:a[x][i]);
	return 0;
}