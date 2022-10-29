#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 3e5 + 6;
const int MAX_M = 506;

vector<int> edg[MAX_N];
int mp[MAX_M][MAX_M];
bool visit[MAX_N];
int deg[MAX_N];
vector<int> _[MAX_N];  //real edge

int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

void dfs(int id) {
	visit[id]=1;
	for (auto i:edg[id]) {
		if (!visit[i]) {
			_[i].push_back(id);
			_[id].push_back(i);
			deg[i]++;
			deg[id]++;
			dfs(i);
		}
	}
}

int main () {
	int n,m,k;
	while (cin >> n >>m >>k) {
		for (int i=0;n*m>=i;i++) {
			edg[i].clear();
			_[i].clear();
		}
		memset(mp,0,sizeof(mp));
		for (int i=0;n>i;i++) {
			for (int j=0;m>j;j++) {
				char c;
				cin >> c;
				if (c=='.') mp[i][j] = 1;
			}
		}
		int start=-1;
		for (int i=0;n>i;i++) {
			for (int j=0;m>j;j++) {
				int x=i,y=j;
				if (mp[x][y] != 1) continue;
				start = x*m+y;
				for (int K=0;4>K;K++) {
					int tx=x+dx[K],ty=y+dy[K];
					if (tx>=0 && ty>=0 & tx<n && ty<m) {
						if (mp[tx][ty] == 1) {
							edg[x*m+y].push_back(tx*m+ty);
							edg[tx*m+ty].push_back(x*m+y);
						}
					}
				}
			}
		}
		memset(deg,0,sizeof(deg));
		memset(visit,0,sizeof(visit));
		dfs(start);
		queue<int> que;
		for (int i=0;n*m>i;i++) {
			if (deg[i] == 1) que.push(i);
		}
		while (k--) {
			int t=que.front();
			que.pop();
			mp[t/m][t%m] = -1;
			for (auto id:_[t]) {
				deg[id]--;
				if (deg[id] == 1) que.push(id);
			}
		}
		for (int i=0;n>i;i++) {
			for (int j=0;m>j;j++) {
				if (mp[i][j] == 1) cout<<'.';
				else if (mp[i][j] == 0) cout<<'#';
				else cout<<'X';
			}
			cout<<endl;
		}
	}
}