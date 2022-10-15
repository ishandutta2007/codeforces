#include <cstdio>
#include <cctype>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,m,sx,sy;
bool vis[101][101];
void dfs(int x,int y){
	vis[x][y]=1;printf("%d %d\n",x,y);
	for(re int i=1;i<=m;i++)
		if(!vis[x][i])return dfs(x,i);
	for(re int i=1;i<=n;i++)
		if(!vis[i][y])return dfs(i,y);
}
int main(){
	n=read(),m=read(),sx=read(),sy=read();
	dfs(sx,sy);
	return 0;
}