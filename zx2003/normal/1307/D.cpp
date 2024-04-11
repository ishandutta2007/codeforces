#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k,i,x,y,a[N],d1[N],d2[N],ans;
vector<int>e[N];
void bfs(int x,int*d){
	queue<int>q;d[x]=1;q.push(x);
	for(;!q.empty();){
		int x=q.front();q.pop();
		for(int y:e[x])if(!d[y])d[y]=d[x]+1,q.push(y);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;++i)scanf("%d",a+i);
	for(i=1;i<=m;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	bfs(1,d1);bfs(n,d2);
	sort(a+1,a+k+1,[&](int x,int y){return d1[x]<d1[y];});
	int mx=d2[a[k]];
	for(i=k-1;i;--i)ans=max(ans,d1[a[i]]+mx),mx=max(mx,d2[a[i]]);
	ans=min(ans,d1[n])-1;
	printf("%d\n",ans);
	return 0;
}