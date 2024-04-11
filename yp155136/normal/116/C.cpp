#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 2e3 +6;

vector<int> edg[MAX_N];
bool visit[MAX_N];
int deg[MAX_N];
int sz[MAX_N];

void dfs(int id,int val) {
	sz[id]=val;
	for (auto i:edg[id]) {
		dfs(i,val+1);
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(deg,0,sizeof(deg));
		for (int i=1;n>=i;i++) {
			int a;
			scanf("%d",&a);
			if (a!=-1) edg[a].push_back(i),deg[i]++;
		}
		memset(visit,0,sizeof(visit));
		for(int i=1;n>=i;i++) {
			if (deg[i]==0) dfs(i,1);
		}
		int mx=-1;
		for (int i=1;n>=i;i++) {
			mx = max(mx,sz[i]);
		}
		printf("%d\n",mx);
	}
}