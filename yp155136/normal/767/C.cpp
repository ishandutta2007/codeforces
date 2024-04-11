#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

#define int long long

const int MAX_N = 1e6 + 6;

vector<int> edg[MAX_N];
vector<int> ans;
bool visit[MAX_N];
int v[MAX_N];
int need;

int dfs(int id) {
	visit[id]=1;
	int val=v[id];
	for (auto i:edg[id]) {
		if (!visit[i] && i!=0) {
			val += dfs(i);
		}
	}
	if (val==need) {
		ans.push_back(id);
		return 0;
	}
	return val;
}

main () {
	int n;
	while (scanf("%I64d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		int root=-1;
		int sum=0;
		for (int i=1;n>=i;i++) {
			int a,b;
			scanf("%I64d %I64d",&a,&b);
			v[i] = b;
			if (a==0) root=i;
			edg[i].push_back(a);
			edg[a].push_back(i);
			sum += b;
		}
		if (sum%3 != 0) {
			puts("-1");
			continue;
		}
		need = sum/3;
		memset(visit,0,sizeof(visit));
		ans.clear();
		dfs(root);
		if (ans.size()<3) {
			puts("-1");
			continue;
		}
		bool flag=0;
		int cnt=0;
		for (int i=0;3>i;i++) {
			if (ans[i]!=root && cnt<2) {
				if (flag) printf(" ");
				printf("%I64d",ans[i]);
				flag=1;
				cnt++;
			}
		}
		puts("");
	}
}