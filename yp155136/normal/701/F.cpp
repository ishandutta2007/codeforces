#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <cassert>
using namespace std;

#define int long long
typedef pair<int,int> pii;
const int MAX_N = 1004;
const int MAX_M = 30004;
const int INF = 1e15+7;
const int MAX_C=2;

int cnt[MAX_N][MAX_N];
int w1[MAX_N][MAX_N];
int id1[MAX_N][MAX_N];
int w2[MAX_N][MAX_N];
int id2[MAX_N][MAX_N];
vector<int> edg[MAX_N];
bool visit[MAX_N];
int depth[MAX_N]; //for finding the bridge
int bfs[MAX_N];
int low[MAX_N];
set<pii> path;
set<pii> path2;
pii Remove;
int ans1_1;
int ans1_2;
int ans2_1;
int ans2_2[MAX_C];
int real_ans1;
int real_ans2[MAX_C];

void dfs(int id,int parent,int cur_depth) {
	depth[id] = cur_depth;
	visit[id]=true;
	low[id] = cur_depth;
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		int tmp=*i;
		if (visit[tmp]==true) {
			if (low[tmp]<low[id]) {
				if (tmp!=parent) {
					low[id]=low[tmp];
				}
				else if (tmp==parent && cnt[tmp][id]>1) {
					low[id]=low[tmp];
				}
			}
			
		}
		else {
			dfs(tmp,id,cur_depth+1);
			if (low[tmp] < low[id]) low[id]=low[tmp];
		}
	}
	if (low[id]==cur_depth) {
		if (path.find(make_pair(id,parent)) != path.end() || path.find(make_pair(parent,id)) != path.end()) {
			if (id!=parent) {
				ans1_1 = min(ans1_1,w1[id][parent]);
				if (ans1_1==w1[id][parent])ans1_2 = id1[id][parent];
			}
		}
	}
}

void dfs2(int id,int parent,int cur_depth) {
	depth[id] = cur_depth;
	visit[id]=true;
	low[id] = cur_depth;
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		int tmp=*i;
		if (Remove==make_pair(id,tmp) || Remove==make_pair(tmp,id)) {
			if (cnt[id][tmp] == 1) continue;
		}
		if (visit[tmp]==true) {
			if (low[id]>low[tmp]) {
				if (tmp!=parent) {
					low[id]=low[tmp];
				}
				else if (tmp==parent && make_pair(tmp,id)!=Remove && make_pair(id,tmp)!=Remove &&cnt[tmp][id]>1) {
					low[id]=low[tmp];
				}
				else if (tmp==parent && cnt[tmp][id] > 2) {
					low[id] = low[tmp];
				}
			}
			
		}
		else {
			dfs2(tmp,id,cur_depth+1);
			if (low[tmp] < low[id]) low[id]=low[tmp];
		}
	}
	if (low[id]==cur_depth) {
		if (path2.find(make_pair(id,parent)) != path2.end() || path2.find(make_pair(parent,id)) != path2.end()) {
			if (id!=parent && make_pair(id,parent)!=Remove && make_pair(parent,id)!=Remove) {
				ans2_1 = min(ans2_1,w1[id][parent]);
				if (ans2_1==w1[id][parent])ans2_2[1] = id1[id][parent];
			}
			else if (id!=parent && cnt[id][parent]>1) {
				ans2_1 = min(ans2_1,w2[id][parent]);
				if (ans2_1==w2[id][parent])ans2_2[1] = id2[id][parent];
			}
		}
	}
}

void BFS(int id) {
	bfs[id] = 1;
	queue<int> que;
	que.push(id);
	while (!que.empty()) {
		int t=que.front();
		que.pop();
		for (auto i =edg[t].begin();i!=edg[t].end();i++) {
			int tmp=*i;
			if (make_pair(tmp,t)==Remove || make_pair(t,tmp)==Remove) {
				if (cnt[tmp][t]==1) continue;
			}
			if (bfs[tmp] > bfs[t]+1) {
				bfs[tmp]=bfs[t] + 1;
				que.push(tmp);
			}
		}
	}
}

main () {
	int n,m;
	while (scanf("%I64d %I64d",&n,&m) != EOF) {
		int s,t;
		scanf("%I64d %I64d",&s,&t);
		for (int x=1;m>=x;x++) {
			int i,j,k;
			scanf("%I64d %I64d %I64d",&i,&j,&k);
			if (i==j) continue;
			if (cnt[i][j] == 0) {
				edg[i].push_back(j);
				edg[j].push_back(i);
				cnt[i][j]++;
				w1[i][j] = k;
				id1[i][j] = x;
				cnt[j][i] = cnt[i][j];
				w1[j][i] = w1[i][j];
				id1[j][i] = id1[i][j];
			}
			else if (cnt[i][j] >= 1) {
				cnt[i][j]++;
				cnt[j][i]++;
				int tmp1=w1[i][j];
				int tmp2=id1[i][j];
				w1[i][j] = min(w1[i][j],k);
				if (w1[i][j] == tmp1) {
					w2[i][j] == min(w2[i][j],k);
					if (w2[i][j] == k || w2[i][j]==0) {
						w2[i][j] = k;
						id2[i][j] = x;
					}
				}
				else {
					w1[i][j] = k;
					id1[i][j] = x;
					w2[i][j] = tmp1;
					id2[i][j] = tmp2;
				}
			}
			w1[j][i]=w1[i][j];
			id1[j][i]=id1[i][j];
			w2[j][i]=w2[i][j];
			id2[j][i]=id2[i][j];
		}
		for(int x=1;n>=x;x++) {
			bfs[x] = INF;
		}
		BFS(s);
		if (bfs[t]==INF) {
			puts("0\n0\n");
			continue;
		}
		int id=t;
		int j=0;
		bool change=false;
		while (id!=s) {
			for (auto i=edg[id].begin();i!=edg[id].end();i++) {
				int tmp=*i;
				if (bfs[id] == bfs[tmp] +1) {
					path.insert(make_pair(id,tmp));
					id=tmp;
					break;
				}
			}
		}
		for (int x=1;n>=x;x++) {
			visit[x]=false;
		}
		ans1_1=real_ans1=INF;
		dfs(s,s,1);
		for (auto j=path.begin();j!=path.end();j++) {
			pii tmp=*j;
			Remove=tmp;
			ans2_1=INF;
			for (int x=0;n>=x;x++) {
				visit[x]=false;
				bfs[x]=INF;
			}
			BFS(s);
			if (bfs[t]==INF) {
				assert(ans1_1!=INF);
				continue;
			}
			id=t;
			path2.erase(path2.begin(),path2.end());
			while (id!=s) {
				for (auto i=edg[id].begin();i!=edg[id].end();i++) {
					int tmp=*i;
					if (bfs[id]==bfs[tmp]+1 && Remove!=make_pair(id,tmp)&&Remove!=make_pair(tmp,id)) {
						path2.insert(make_pair(id,tmp));
						id=tmp;
						break;
					}
					else if (bfs[id]==bfs[tmp]+1 && cnt[id][tmp]>1) {
						path2.insert(make_pair(id,tmp));
						id=tmp;
						break;
					}
				}
			}
			assert(path!=path2 || path==path2 && cnt[tmp.first][tmp.second]>1);
			dfs2(s,s,1);
			if (ans2_1 + w1[tmp.first][tmp.second] <= real_ans1) {
				real_ans1=ans2_1 + w1[tmp.first][tmp.second];
				real_ans2[0]=ans2_2[1];
				real_ans2[1]=id1[tmp.first][tmp.second];
			}
		}
		if (ans1_1==INF && real_ans1==INF) {
			puts("-1");
		}
		else if (ans1_1<=real_ans1) {
			printf("%I64d\n1\n%I64d\n",ans1_1,ans1_2);
		}
		else {
			printf("%I64d\n2\n%I64d %I64d\n",real_ans1,real_ans2[0],real_ans2[1]);
		}
	}
}