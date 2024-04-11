#include <bits/stdc++.h>
using namespace std;
const int N=200005;
struct Gragh{
	int cnt,y[N*2],nxt[N*2],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,dp[N];
// 0 can be only destroyed before fa
// 1 can be only destroyed after fa
vector <int> sted[N];
bool spec_cmp(int a,int b){
	return dp[a]<dp[b];
}
void solve(int x,int pre){
	int cnt=1;
	sted[x].clear();
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			solve(g.y[i],x);
			cnt++;
			sted[x].push_back(g.y[i]);
		}
	sort(sted[x].begin(),sted[x].end(),spec_cmp);
	if (sted[x].size()==0){
		dp[x]=1;
		return;
	}
	for (int i=0;i<sted[x].size();i++){
		if (dp[sted[x][i]])
			break;
		cnt--;
	}
	dp[x]=cnt&1;
}
void dfs2(int x){
	int i=0;
	while (i<sted[x].size()&&dp[sted[x][i]]==0)
		dfs2(sted[x][i]),i++;
	printf("%d\n",x);
	while (i<sted[x].size())
		dfs2(sted[x][i]),i++;
}
int main(){
	g.clear();
	scanf("%d",&n);
	for (int i=1,p;i<=n;i++){
		scanf("%d",&p);
		if (p!=0)
			g.add(i,p),g.add(p,i);
	}
	solve(1,0);
	if (dp[1]==1){
		puts("YES");
		dfs2(1);
	}
	else
		puts("NO");
	return 0;
}