#include <iostream>
#include <stdio.h>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2006;

bool mp[MAX_N][MAX_N];
char s[MAX_N];

int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};

int dx2[8] = {1,1,1,0,0,-1,-1,-1};
int dy2[8] = {1,0,-1,1,-1,1,0,-1};

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		getchar();
		memset(mp,0,sizeof(mp));
		for (int i=1;n>=i;i++) {
			scanf("%s",s);
			for (int j=1;m>=j;j++) {
				mp[i][j] = (s[j-1]=='.');
			}
		}
		queue<pii> que;
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				if (!mp[i][j]) {
					for(int k=0;4>k;k++) {
						if (mp[i-dx[k]][j-dy[k]] && mp[i][j-dy[k]] && mp[i-dx[k]][j]) {
							que.push(make_pair(i,j));
							mp[i][j]=1;
							break;
						}
					}
				}
			}
		}
		while (!que.empty()) {
			pii t=que.front();
			que.pop();
			mp[t.first][t.second]=1;
			for (int i=0;8>i;i++) {
				int x=t.first+dx2[i],y=t.second+dy2[i];
				if (!x || !y) continue;
				if (mp[x][y]) continue;
				for (int j=0;4>j;j++) {
					if (mp[x-dx[j]][y-dy[j]] && mp[x][y-dy[j]] && mp[x-dx[j]][y]) {
						que.push(make_pair(x,y));
						mp[x][y]=1;
						break;
					}
				}
			}
		}
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				if (mp[i][j]) printf(".");
				else printf("*");
			}
			puts("");
		}
	}
}