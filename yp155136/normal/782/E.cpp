#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 2e5 +6;

vector<int> edg[MAX_N];
bool visit[MAX_N];

vector<int> v;

void dfs(int id) {
	visit[id]=1;
	v.push_back(id);
	for (auto i:edg[id]) {
		if (!visit[i]) {
			dfs(i);
			v.push_back(id);
		}
	}
}

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		for (int i=1;m>=i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
		}
		v.clear();
		v.push_back(0);
		memset(visit,0,sizeof(visit));
		dfs(1);
		int j=1;
		int sz=v.size()-1;
		for (int i=1;k>=i;i++) {
			if (j>sz) {
				puts("1 1");
			}
			else {
				int cnt=(2*n)/k + ((2*n)%k==0?0:1);
				printf("%d",min(cnt,sz-j+1));
				for (;sz>=j && cnt;j++,cnt--) {
					printf(" %d",v[j]);
				}
				puts("");
			}
		}
	}
}