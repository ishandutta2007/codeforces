#include<bits/stdc++.h>
#define N 110005
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],deg[N],ok[N*5];
int n,x,y,tot,ans,cnt;
map<vector<int>,int> mmp;
map<int,int> f[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int dfs(int x,int fa){
	if (f[x][fa]) return f[x][fa];
	vector<int> vec;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa) vec.push_back(dfs(e[i].to,x));
	sort(vec.begin(),vec.end());
	if (!mmp[vec]) mmp[vec]=++cnt;
	return f[x][fa]=mmp[vec];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		deg[x]++; deg[y]++;
	}
	for (int i=1;i<=n;i++)
		if (deg[i]<4) ok[dfs(i,0)]=1;
	for (int i=1;i<=cnt;i++)
		if (ok[i]) ans++;
	printf("%d\n",ans);
}