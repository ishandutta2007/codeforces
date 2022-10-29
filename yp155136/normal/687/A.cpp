#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_N = 1e5 + 6;

vector<int> edg[MAX_N];
int ans[MAX_N];
bool visit[MAX_N];

void BFS(int id) {
	queue<int> que;
	que.push(id);
	ans[id]=0;
	visit[id]=true;
	while (!que.empty()) {
		int t=que.front();
		que.pop();
		for (auto i=edg[t].begin();i!=edg[t].end();i++) {
			int tmp=*i;
			if (visit[tmp]==true) {
				if (ans[t] == ans[tmp]) ans[tmp]=-1;
			}
			else {
				ans[tmp] = 1-ans[t];
				visit[tmp]=true;
				que.push(tmp);
			}
		}
	}
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		memset(ans,-1,sizeof(ans));
		for (int x=0;n>=x;x++) {
			edg[x].clear();
			visit[x]=false;
		}
		for (int x=0;m>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			edg[i].push_back(j);
			edg[j].push_back(i);
		}
		for (int x=1;n>=x;x++) {
			if (visit[x]==false) {
				BFS(x);
			}
		}
		int _0=0,_1=0;
		bool check=true;
		for (int x=1;n>=x;x++) {
			if (ans[x]==1) _1++;
			else if (ans[x]==0) _0++;
			else check=false;
		}
		if (!check) puts("-1");
		else {
			check=false;
			printf("%d\n",_0);
			for (int x=1;n>=x;x++) {
				if (ans[x]==0) {
					if (!check) check=true;
					else printf(" ");
					printf("%d",x);
				}
			}
			puts("");
			printf("%d\n",_1);
			check=false;
			for (int x=1;n>=x;x++) {
				if (ans[x]==1) {
					if (!check) check=true;
					else printf(" ");
					printf("%d",x);
				}
			}
			puts("");
		}
	}
}