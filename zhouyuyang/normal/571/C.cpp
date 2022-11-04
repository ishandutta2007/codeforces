#include<bits/stdc++.h>
const int N=200005;
using namespace std;
#define pa pair<int,int>
int pos[N*2],ans[N],vis[N];
set<int> s[N];
int n,m;
priority_queue<pa,vector<pa >,greater<pa > > Q;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int cnt; scanf("%d",&cnt);
		for (int j=1;j<=cnt;j++){
			int x; scanf("%d",&x);
			s[i].insert(x);
			pos[m+x]=i;
		}
		Q.push(make_pair(s[i].size(),i));
	}
	while (!Q.empty()){
		int k=Q.top().second; Q.pop();
		if (vis[k]) continue; vis[k]=1;
		if (s[k].empty()) return puts("NO"),0;
		int x=*s[k].begin();
		ans[abs(x)]=(x>0);
		if (pos[m-x]){
			int id=pos[m-x];
			s[id].erase(-x);
			Q.push(make_pair(s[id].size(),id));
		}
	}
	puts("YES");
	for (int i=1;i<=m;i++)
		printf("%d",ans[i]);
}