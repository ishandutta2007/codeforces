#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 +6;

int a[MAX_N];
vector<int> edg[MAX_N];
vector<int> vv[MAX_N];
bool visit[MAX_N];

void dfs(int id,int iid) {
	visit[id]=1;
	vv[iid].push_back(id);
	for (int i:edg[id]) {
		if (!visit[i]) dfs(i,iid);
	}
}

int main () {
	int n;
	scanf("%d",&n);
	vector<int> v;
	for (int i=1;n>=i;i++) {
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end()) - v.begin());
	for (int i=1;n>=i;i++) {
		a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() +1;
		edg[i].push_back(a[i]);
	}
	int ans=0;
	for (int i=1;n>=i;i++) {
		if (!visit[i]) {
			ans++;
			dfs(i,ans);
		}
	}
	printf("%d\n",ans);
	for (int i=1;ans>=i;i++) {
		printf("%d",vv[i].size());
		sort(vv[i].begin(),vv[i].end());
		for (int j:vv[i]) {
			printf(" %d",j);
		}
		puts("");
	}
}