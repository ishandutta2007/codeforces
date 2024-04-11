#include<bits/stdc++.h>
#define ll long long
#define mo1 1000000007
#define mo2 1000000009
#define pii pair<int,int>
using namespace std;

int n,m,fa[303000],x,y,t1,t2,co[303000],used[606000],vis[303000];
vector<int>r[303000];
map<pii,int>mp;
pii p;

int GF(int x){
	return x==fa[x]? x: fa[x]=GF(fa[x]);
}

void dfs(int x,int now){
	vis[x]=1;
	int y=GF(x);
	if (co[y]) co[x]=co[y];
	else{
		if (!used[now+1]){
			used[now+1]=1;
			co[y]=co[x]=now+1;
		}else if (!used[now-1]){
			used[now-1]=1;
			co[y]=co[x]=now-1;
		}else{
			exit(0*puts("NO"));
		}
	}
	for (int i=0;i<(int)r[x].size();i++){
		y=r[x][i];
		if (co[y]) if (abs(co[y]-co[x])>1) exit(0*puts("NO"));
		if (vis[y]) continue;
		dfs(y,co[x]);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		r[x].push_back(y);
		r[y].push_back(x);
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		sort(r[i].begin(),r[i].end());
		t1=i;t2=i;
		for (int j=0;j<(int)r[i].size();j++){
			t1=(ll)t1*r[i][j]%mo1;
			t2=(ll)t2*r[i][j]%mo2;
		}
		p=(pii){t1,t2};
		if (mp.count(p)){
			fa[GF(i)]=GF(mp[p]);
		}else{
			mp[p]=i;
		}
	}
	
	dfs(1,303000);
	puts("YES");
	for (int i=1;i<=n;i++) printf("%d ",co[i]);
}