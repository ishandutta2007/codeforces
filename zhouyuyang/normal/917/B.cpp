#include<bits/stdc++.h>
using namespace std;
int f[105][105][26];
int n,m,tot,head[105];
struct edge{int to,next,v;}e[10005];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
int dfs(int x,int y,int v){
	if (f[x][y][v]!=-1)
		return f[x][y][v];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].v>=v&&!dfs(y,e[i].to,e[i].v))
			return f[x][y][v]=1;
	return f[x][y][v]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(f,-1,sizeof(f));
	for (int i=1;i<=m;i++){
		int x,y; char s[5];
		scanf("%d%d%s",&x,&y,s);
		add(x,y,s[0]-'a');
	}
	for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=n;j++)
			putchar(dfs(i,j,0)?'A':'B');
}