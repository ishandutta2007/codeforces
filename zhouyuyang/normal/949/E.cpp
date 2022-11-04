#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a[22],ans,cur;
void dfs(int x){
	if (cur.size()>=ans.size()) return;
	sort(a[x].begin(),a[x].end());
	a[x].resize(unique(a[x].begin(),a[x].end())-a[x].begin());
	if (x==21){
		if (a[x].size()==1&&a[x][0]==0)
			ans=cur;
		return;
	}
	bool ok=0;
	for (int i=0;i<a[x].size();i++)
		ok|=(abs(a[x][i])>>x)&1;
	if (!ok){
		a[x+1]=a[x];
		dfs(x+1);
		return;
	}
	int y=1<<x;
	cur.push_back(y);
	a[x+1].resize(0);
	for (int i=0;i<a[x].size();i++)
		a[x+1].push_back(abs(a[x][i])&y?a[x][i]-y:a[x][i]);
	dfs(x+1);
	cur[cur.size()-1]*=-1;
	a[x+1].clear();
	for (int i=0;i<a[x].size();i++)
		a[x+1].push_back(abs(a[x][i])&y?a[x][i]+y:a[x][i]);
	dfs(x+1);
	cur.pop_back();
}
int main(){
	scanf("%d",&n);
	while (n--){
		int x;
		scanf("%d",&x);
		a[0].push_back(x);
	}
	ans.resize(100);
	dfs(0);
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
}