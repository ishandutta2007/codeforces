#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 106;
const int MAX_M = 106;
const int MAX_C = 106;

vector<int> edg[MAX_C][MAX_N];
bool visit[MAX_N];

void dfs(int id,int col) {
	visit[id]=1;
	for (auto i:edg[col][id]) {
		if (!visit[i]) dfs(i,col);
	}
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int i=0;MAX_C>i;i++) {
			for (int j=0;MAX_N>j;j++) {
				edg[i][j].clear();
			}
		}
		for (int i=1;m>=i;i++) {
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			edg[c][a].push_back(b);
			edg[c][b].push_back(a);
		}
		int q;
		scanf("%d",&q);
		while (q--) {
			int a,b;
			scanf("%d %d",&a,&b);
			int cnt=0;
			for (int i=0;MAX_C>i;i++) {
				memset(visit,0,sizeof(visit));
				dfs(a,i);
				cnt += visit[b];
			}
			printf("%d\n",cnt);
		}
	}
}