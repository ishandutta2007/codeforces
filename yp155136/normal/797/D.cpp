#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX_N = 1e5 + 6;
const int INF = 1e9 +7;

vector<int> gao;
vector<int> edg[MAX_N];
int v[MAX_N];
int deg[MAX_N];
int ans=0;

void dfs(int id,int L,int R) {
	if (L<=v[id] && v[id]<=R) gao.push_back(v[id]);
	for (int i=0;2>i;i++) {
		if (edg[id][i]==-1) continue;
		if (i==1) dfs(edg[id][i],max(L,v[id]),R);
		if (i==0) dfs(edg[id][i],L,min(v[id]-1,R));
	}
}

int main () {
	int n;
	scanf("%d",&n);
	vector<int> _;
	map<int,int> mp;
	for (int i=1;n>=i;i++) {
		int l,r;
		scanf("%d %d %d",&v[i],&l,&r);
		mp[v[i]]++;
		_.push_back(v[i]);
		if (l!=-1) edg[i].push_back(l),deg[l]++;
		else edg[i].push_back(-1);
		if (r!=-1) edg[i].push_back(r),deg[r]++;
		else edg[i].push_back(-1);
	}
	for (int i=1;n>=i;i++) {
		if (deg[i]==0) dfs(i,-1,INF);
	}
	sort(gao.begin(),gao.end());
	gao.resize(unique(gao.begin(),gao.end()) - gao.begin());
	int tot=n;
	for (int i:gao) {
		tot-=mp[i];
	}
	printf("%d\n",tot);
}