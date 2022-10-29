#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 2e5 + 6;
int a[MAX_N];
int ans[MAX_N];

void BFS(int n) {
	memset(ans,-1,sizeof(ans));
	queue<int> que;
	que.push(1);
	ans[1]=0;
	while (!que.empty()) {
		int t=que.front();
		que.pop();
		if (t+1<=n && ans[t+1]==-1 || t+1<=n && ans[t+1]>ans[t]+1) {
			ans[t+1]=ans[t]+1;
			que.push(t+1);
		}
		if (t-1>=1 && ans[t-1]==-1 || t-1>=1 && ans[t-1]>ans[t]+1) {
			ans[t-1]=ans[t]+1;
			que.push(t-1);
		}
		if (ans[a[t]] ==-1 || ans[a[t]] > ans[t] + 1) {
			ans[a[t]]=ans[t]+1;
			que.push(a[t]);
		}
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>=x;x++) scanf("%d",&a[x]);
		BFS(n);
		for (int x=1;n>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",ans[x]);
		}
		puts("");
	}
}