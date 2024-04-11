#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;

vector<int> ans;
vector<int> edg[MAX_N];
int tag[MAX_N];
int val[MAX_N];
int goal[MAX_N];
bool visit[MAX_N];

void dfs(int id) {
	visit[id]=1;
	for (auto i:edg[id]) {
		if (!visit[i]) {
			for (auto j:edg[i]) {
				if (!visit[j]) {
					val[j] ^= tag[id];
					tag[j] ^= tag[id];
				}
			}
		}
	}
	if (goal[id]^val[id]) {
		ans.push_back(id);
		for (auto i:edg[id]) {
			if (!visit[i]) {
				for (auto j:edg[i]) {
					if (!visit[j]) {
						tag[j] ^= 1;
						val[j] ^= 1;
					}
				}
			}
		}
	}
	for (auto i:edg[id]) {
		if (!visit[i])dfs(i);
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=0;n>=x;x++) {
			edg[x].clear();
		}
		for (int i=1;n>i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&val[i]);
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&goal[i]);
		}
		memset(visit,0,sizeof(visit));
		memset(tag,0,sizeof(tag));
		ans.clear();
		dfs(1);
		printf("%d\n",ans.size());
		for (auto i:ans) {
			printf("%d\n",i);
		}
	}
}