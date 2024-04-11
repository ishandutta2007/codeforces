#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

struct Step {
	char a;
	int x;
	int y;
	void show() {
		printf("%c %d %d\n",a,x,y);
	}
};

Step MP(char _a,int _x,int _y) {
	return Step{_a,_x,_y};
}

typedef pair<int,int> pii;
const int MAX_N = 506;

int mp[MAX_N][MAX_N];
char c[MAX_N];
bool visit[MAX_N][MAX_N];

vector<pii> edg[MAX_N][MAX_N];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<Step> step;

void dfs(int x,int y) {
	visit[x][y]=true;
	for (int i=0;4>i;i++) {
		int tx=x+dx[i],ty=y+dy[i];
		if (mp[tx][ty] && !visit[tx][ty]) {
			edg[x][y].push_back(make_pair(tx,ty));
			dfs(tx,ty);
		}
	}
}

void dfs2(int x,int y,bool check) {
	visit[x][y]=true;
	for (auto iter=edg[x][y].begin();iter!=edg[x][y].end();iter++) {
		pii tmp=*iter;
		dfs2(tmp.first,tmp.second,true);
	}
	if (check) {
		step.push_back(MP('D',x,y));
		step.push_back(MP('R',x,y));
	}
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		memset(mp,0,sizeof(mp));
		step.clear();
		vector<pii> roots;
		for (int i=1;n>=i;i++) {
			scanf("%s",c);
			for (int j=0;m>j;j++) {
				if (c[j] == '.') {
					mp[i][j+1]=1;
					step.push_back(MP('B',i,j+1));
				}
				else mp[i][j+1] = 0;
			}
		}
		memset(visit,0,sizeof(visit));
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				if (mp[i][j] && !visit[i][j]) {
					dfs(i,j);
					roots.push_back(make_pair(i,j));
				}
			}
		}
		memset(visit,0,sizeof(visit));
		for (auto iter=roots.begin();iter!=roots.end();iter++) {
			pii tmp=*iter;
			dfs2(tmp.first,tmp.second,false);
		}
		printf("%d\n",step.size());
		for (auto iter=step.begin();iter!=step.end();iter++) {
			(*iter).show();
		}
	}
}