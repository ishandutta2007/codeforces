#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long LL;
const LL mod = 1e9+7;
const int MAX_N = 2e5 + 6;

LL pow2(int n) {
	LL ret=1;
	for (int x=0;n>x;x++) {
		ret*=2;
		ret%=mod;
	}
	return ret;
}

int a[MAX_N];
int visit[MAX_N];
int root[MAX_N];

LL BFS(int id) {
	LL ret=1;
	queue<int> que;
	que.push(id);
	visit[id]=1;
	root[id]=id;
	while (!que.empty()) {
		int t=que.front();
		que.pop();
		int tmp=a[t];
		if (visit[tmp] != 0) {
			if (root[tmp] == root[id]) {
				ret *= (pow2(visit[t] - visit[tmp]+1)+mod -2) * (pow2(visit[tmp]-1)) % mod;
				ret%=mod;
			}
			else {
				ret *= (pow2(visit[t])) % mod;
				ret%=mod;
			}
		}
		else {
			visit[tmp] = visit[t]+1;
			root[tmp]=root[t];
			que.push(tmp);
		}
	}
	return ret%mod;
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(visit,0,sizeof(visit));
		memset(root,0,sizeof(root));
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
		}
		LL ans=1;
		for (int x=1;n>=x;x++) {
			if (visit[x]==0) {
				ans *= BFS(x);
				ans%=mod; 
			}
		}
		printf("%I64d\n",ans);
	}
}