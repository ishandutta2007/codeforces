#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX_N = 2e5 + 6;

int s[MAX_N];  //means that how many universities are in the subtree
vector<int> edg[MAX_N];
bool visit[MAX_N];
bool uni[MAX_N];

int dfs(int id) {
	visit[id]=true;
	int ret = uni[id];
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		int tmp=*i;
		if (visit[tmp]==false) {
			ret += dfs(tmp);
		}
	}
	return s[id] = ret;
}

int main () {
	int n;
	int k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int x=0;2*k>x;x++) {
			int i;
			scanf("%d",&i);
			uni[i]=true;
		}
		for (int x=0;n-1>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			edg[i].push_back(j);
			edg[j].push_back(i);
		}
		dfs(1);
		long long ans=0;
		for (int x=2;n>=x;x++) {
			ans += min(s[x],2*k-s[x]);
		}
		printf("%I64d\n",ans);
	}
}