#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 2e5 + 6;

int p[MAX_N];
bool visit[MAX_N];

void dfs(int id) {
	visit[id]=true;
	if (!visit[p[id]]) dfs(p[id]);
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&p[i]);
		}
		int ans=0;
		int cnt=0;
		for (int i=1;n>=i;i++) {
			int t;
			scanf("%d",&t);
			cnt += t;
		}
		if (cnt%2==0) ans++;
		int cur=0;
		memset(visit,0,sizeof(visit));
		for (int i=1;n>=i;i++) {
			if (!visit[i]) dfs(i),cur++;
		}
		if (cur!=1) ans += cur;
		printf("%d\n",ans);
	}
}