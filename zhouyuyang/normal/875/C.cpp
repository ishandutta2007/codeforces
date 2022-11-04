#include<bits/stdc++.h>
#define N 100005
#define pa pair<int,int>
using namespace std;
int n,m,x,y,tot,cnt;
int ans[N],head[N],dis[N];
struct edge{int to,next;}e[N];
vector<int> vec[N];
priority_queue<pa > q;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		while (x--){
			scanf("%d",&y);
			vec[i].push_back(y);
		}
	}
	for (int i=2;i<=n;i++){
		int le=min(vec[i-1].size(),vec[i].size());
		bool fl=0;
		for (int j=0;j<le;j++)
			if (vec[i-1][j]!=vec[i][j]){
				add(vec[i-1][j],vec[i][j]);
				fl=1; break;
			}
		if (!fl&&vec[i-1].size()>vec[i].size())
			return puts("No"),0;
	}
	for (int i=1;i<=m;i++)	
		q.push(pa(0,i));
	while (!q.empty()){
		int x=q.top().second; q.pop();
		for (int i=head[x];i;i=e[i].next){
			if (dis[e[i].to]*m+e[i].to>=dis[x]*m+x)
				continue;
			for (;dis[e[i].to]*m+e[i].to<dis[x]*m+x;)
				dis[e[i].to]++;
			if (dis[e[i].to]>1) return puts("No"),0;
			q.push(pa(dis[e[i].to],e[i].to));
		}
	}
	for (int i=1;i<=m;i++)
		if (dis[i]==0) ans[++cnt]=i;
	printf("Yes\n%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d ",ans[i]);
}