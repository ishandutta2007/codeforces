#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;

vector<int> _[MAX_N];
vector<int> edg[MAX_N];
int col[MAX_N];
pii p[MAX_N];
int inn[MAX_N];
bool visit[MAX_N];
int d[MAX_N];

void dfs1(int id,int &cur_id,int p) {
	visit[id]=1;
	for (auto i:_[id]) {
		if (!visit[i]) {
			if (col[i] == col[id]) {
				inn[i] = inn[id];
				dfs1(i,cur_id,id);
			}
			else {
				cur_id++;
				inn[i] = cur_id;
				dfs1(i,cur_id,id);
			}
		}
	}
}

void dfs2(int id) {
	visit[id]=1;
	for (auto i:edg[id]) {
		if (!visit[i]) {
			d[i] = d[id]+1;
			dfs2(i);
		}
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			_[i].clear();
			edg[i].clear();
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&col[i]);
		}
		for (int i=1;n>i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			p[i] = make_pair(a,b);
			_[a].push_back(b);
			_[b].push_back(a);
		}
		memset(visit,0,sizeof(visit));
		int cur_id=1;
		inn[1]=1;
		dfs1(1,cur_id,1);
		for (int i=1;n>i;i++) {
			if (inn[p[i].first] != inn[p[i].second]) {
				edg[inn[p[i].first]].push_back(inn[p[i].second]);
				edg[inn[p[i].second]].push_back(inn[p[i].first]);
			}
		}
		memset(visit,0,sizeof(visit));
		memset(d,0,sizeof(d));
		dfs2(1);
		int mx=-1;
		int mx_id=-1;
		for (int i=1;cur_id>=i;i++) {
			if (d[i] > mx) {
				mx = d[i];
				mx_id = i;
			}
		}
		memset(visit,0,sizeof(visit));
		memset(d,0,sizeof(d));
		d[mx_id]=1;
		dfs2(mx_id);
		mx=-1;
		for (int i=1;cur_id>=i;i++) {
			mx = max(mx,d[i]);
		}
		printf("%d\n",mx/2);
	}
}