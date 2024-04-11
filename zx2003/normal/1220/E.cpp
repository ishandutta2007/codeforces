#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,m,i,w[N],eu[N],ev[N],d[N],s;
vector<int>e[N];
ll tot,ans;
queue<int>q;
void dfs(int x,int fa,ll d){for(int y:e[x])if(y!=fa)dfs(y,x,d+w[y]);ans=max(ans,d);}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",w+i);
	for(i=1;i<=m;++i)scanf("%d%d",eu+i,ev+i),e[eu[i]].push_back(ev[i]),e[ev[i]].push_back(eu[i]);
	scanf("%d",&s);
	for(i=1;i<=n;++i)if(d[i]=e[i].size(),d[i]==1 && i!=s)q.push(i);
	for(;!q.empty();){
		int x=q.front();q.pop();
		for(int y:e[x])if(y!=s && --d[y]==1)q.push(y);
	}
	for(i=1;i<=n;++i)e[i].clear(),tot+=i==s || d[i]>1?w[i]:0;
	for(i=1;i<=m;++i){
		if(d[eu[i]]>1)eu[i]=s;if(d[ev[i]]>1)ev[i]=s;
		if(eu[i]==ev[i])continue;
		e[eu[i]].push_back(ev[i]),e[ev[i]].push_back(eu[i]);
	}
	dfs(s,0,0);ans+=tot;printf("%lld\n",ans);
	return 0;
}