#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e6 + 6;

vector<int> edg[MAX_N];
vector<int> cc[MAX_N];
vector<int> ci[MAX_N];
bool visit[MAX_N];
int ans[MAX_N];
int p[MAX_N];

void dfs(int id,int no) {
	visit[id]=true;
	cc[no].push_back(p[id]);
	ci[no].push_back(id);
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		int tmp=*i;
		if (visit[tmp]==false) {
			dfs(tmp,no);
		}
	}
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int x=0;n>=x;x++) {
			edg[x].clear();
			cc[x].clear();
			ci[x].clear();
			visit[x]=false;
		}
		for (int x=1;n>=x;x++) {
			scanf("%d",&p[x]);
		}
		for (int x=0;m>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			edg[j].push_back(i);
			edg[i].push_back(j);
		}
		int id=1;
		for (int x=1;n>=x;x++) {
			if (!visit[x]) {
				dfs(x,id++);
			}
		}
		for (int x=1;id>x;x++) {
			sort(cc[x].begin(),cc[x].end());
			sort(ci[x].begin(),ci[x].end());
			int len=cc[x].size();
			int tmp=len-1;
			for (int i=0;len>i;i++) {
				ans[ ci[x][i] ] = cc[x][tmp--];
			}
		}
		for (int x=1;n>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",ans[x]);
		}
		puts("");
	}
}