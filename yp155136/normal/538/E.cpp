#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 2e5 + 6;
const int INF = 1e9 + 7;

vector<int> edg[MAX_N];
int leaf_cnt;
int dpmx[MAX_N],dpmn[MAX_N];

void dfs(int id) {
	if (edg[id].size() == 0) {
		dpmx[id] = dpmn[id] = 1;
		leaf_cnt++;
		return;
	}
	dpmx[id] = INF;
	for (auto i:edg[id]) {
		dfs(i);
		dpmx[id] = min(dpmx[id],dpmn[i]);
		dpmn[id] += dpmx[i];
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		for (int i=1;n>i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(b);
		}
		leaf_cnt=0;
		dfs(1);
		printf("%d %d\n",leaf_cnt-dpmx[1]+1,dpmn[1]);
	}
}