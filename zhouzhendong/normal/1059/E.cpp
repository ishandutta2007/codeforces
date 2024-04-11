#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int n,L;
int fa[N][20],depth[N],md[N];
LL S,w[N];
vector <int> e[N];
LL sum[N][20];
int tot=0;
void dfs(int x,int pre,int d){
	depth[x]=d;
	fa[x][0]=pre;
	sum[x][0]=w[fa[x][0]];
	for (int i=1;i<20;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		sum[x][i]=sum[x][i-1];
		if (fa[x][i-1])
			sum[x][i]+=sum[fa[x][i-1]][i-1];
	}
	md[x]=1e9;
	for (auto y : e[x]){
		dfs(y,x,d+1);
		md[x]=min(md[x],md[y]);
	}
	if (md[x]>depth[x]){
		tot++;
		LL s=w[x];
		int y=x;
		for (int i=19;i>=0;i--){
			if (!fa[y][i])
				continue;
			if (s+sum[y][i]<=S)
				s+=sum[y][i],y=fa[y][i];
		}
		md[x]=max(depth[y],depth[x]-L+1);
	}
}
int main(){
	n=read(),L=read(),S=read();
	for (int i=1;i<=n;i++)
		w[i]=read();
	for (int i=1;i<=n;i++)
		if (w[i]>S)
			return puts("-1"),0;
	for (int i=1;i<=n;i++)
		e[i].clear();
	for (int i=2;i<=n;i++)
		e[read()].push_back(i);
	dfs(1,0,0);
//	for (int i=1;i<=n;i++,puts(""))
//		for (int j=0;j<3;j++)
//			cout << fa[i][j] << " ";
//	for (int i=1;i<=n;i++,puts(""))
//		for (int j=0;j<3;j++)
//			cout << sum[i][j] << " ";
	printf("%d",tot);
	return 0;
}