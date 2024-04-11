#include<bits/stdc++.h>
using namespace std;

int n,m,used[100100],a[100100];
vector<int>r[100100],ans;

void dfs(int x,int fa){
	used[x]=1;a[x]^=1;ans.push_back(x);
	for (int i=0,y;i<(int)r[x].size();i++){
		if (used[y=r[x][i]]) continue;
		dfs(y,x);
		ans.push_back(x);a[x]^=1;
	}
	if (a[x]&&fa){
		ans.push_back(fa);ans.push_back(x);
		a[fa]^=1;a[x]^=1;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		r[x].push_back(y);
		r[y].push_back(x);
	}
	for (int i=1;i<=n;scanf("%d",&a[i++]));
	int st=1;
	for (int i=1;i<=n;i++){
		st=a[i]?i:st;
	}
	dfs(st,0);
	if (a[st]){
		ans.pop_back();
		a[st]^=1;
	}
	for (int i=1;i<=n;i++){
		if (a[i]){
			printf("-1");
			return 0;
		}
	}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
	
}