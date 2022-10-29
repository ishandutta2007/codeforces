#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1006;

int mp[MAX_N][MAX_N];
int w[MAX_N][MAX_N];
char c[MAX_N];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		getchar();
		int sx=-1,sy=-1;
		int tx=-1,ty=-1;
		for (int i=1;n>=i;i++) {
			scanf("%s",c);
			for (int j=1;m>=j;j++) {
				char cc=c[j-1];
				if (cc=='S') {
					mp[i][j] = 2;
					sx = i;
					sy = j;
				}
				if (cc=='T') {
					mp[i][j] = 3;
					tx = i;
					ty = j;
				}
				if (cc=='*') mp[i][j] = 0;
				if (cc=='.') mp[i][j] = 1;
			}
		}
		memset(w,-1,sizeof(w));
		w[sx][sy] = 0;
		queue<pii> que;
		que.push(make_pair(sx,sy));
		while (!que.empty()) {
			pii p=que.front();
			que.pop();
			int x=p.first,y=p.second;
			if (w[x][y] > 3) break;
			int ww=w[x][y];
			for (int i=0;4>i;i++) {
				int tx=x+dx[i],ty=y+dy[i];
				while (mp[tx][ty] != 0) {
					if (w[tx][ty] == -1) {
						que.push(make_pair(tx,ty));
						w[tx][ty] = ww+1;
					}
					else if (w[tx][ty] <= ww) break;
					tx += dx[i];
					ty += dy[i];
				}
			}
		}
		if (w[tx][ty] <= 3 && w[tx][ty] != -1) puts("YES");
		else puts("NO");
	}
}