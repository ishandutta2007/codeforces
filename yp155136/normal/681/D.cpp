#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 +6;

vector<int> edg[MAX_N];
int rudu[MAX_N];
int a[MAX_N];
bool used[MAX_N];
vector<int> ans;

bool dfs(int id,int p) {
	bool ret;
	if (a[id] == a[p] || a[id] == id) {
		//this is can
		ret=true;
	}
	else {
		ret=false;
	}
	for (int i:edg[id]) {
		ret &= dfs(i,id);
	}
	return ret;
}

void dfs_ans(int id) {
	for (int i:edg[id]) {
		dfs_ans(i);
	}
	if (!used[a[id]] && id == a[id]) {
		ans.push_back(a[id]);
		used[a[id]]=1;
	}
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		memset(rudu,0,sizeof(rudu));
		for (int i=1;m>=i;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			edg[x].push_back(y);
			rudu[y]++;
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		bool can=true;
		for (int i=1;n>=i;i++) {
			if (rudu[i] == 0) {
				can &= dfs(i,i);
			}
		}
		if (!can) puts("-1");
		else {
			memset(used,0,sizeof(used));
			ans.clear();
			for (int i=1;n>=i;i++) {
				if (rudu[i] == 0) {
					dfs_ans(i);
				} 
			}
			printf("%d\n",ans.size());
			for (int i:ans) {
				printf("%d\n",i);
			}
		}
	}
}