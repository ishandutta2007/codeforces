#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_N = 506;
int mp[MAX_N][MAX_N];
int magic[8][MAX_N][MAX_N];
bool used[8][MAX_N][MAX_N];

int a[36];

int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {1,1,1,0,-1,-1,-1,0};

struct P {
	int x,y,dur;
	int level,t;
};

P MP(int _x,int _y,int _dur,int _level,int _t) {
	return P{_x,_y,_dur,_level,_t};
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(mp,0,sizeof(mp));
		memset(magic,-1,sizeof(magic));
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		int x=250,y=250;
		queue<P> que;
		que.push(MP(x,y,1,1,1));
		while (!que.empty()) {
			P p=que.front();
			que.pop();
			mp[p.x][p.y] = 1;
			if (p.t == a[p.level]) {
				used[0][0][0] = true;
				if (p.level==n) continue;
				else {
					int dur=p.dur-1 +8;
					dur%=8;
					if (!used[dur][p.x+dx[dur]][p.y+dx[dur]]) que.push(MP(p.x+dx[dur],p.y+dy[dur],dur,p.level+1,1));
					used[dur][p.x+dx[dur]][p.y+dx[dur]] = true;
					dur = p.dur + 1;
					dur%=8;
					if (!used[dur][p.x+dx[dur]][p.y+dx[dur]]) que.push(MP(p.x+dx[dur],p.y+dy[dur],dur,p.level+1,1));
					used[dur][p.x+dx[dur]][p.y+dx[dur]] = true;
				}
			}
			else {
				if (used[0][0][0]) memset(used,0,sizeof(used));
				que.push(MP(p.x+dx[p.dur],p.y+dy[p.dur],p.dur,p.level,p.t+1));
			}
		}
		int ans=0;
		for (int i=0;MAX_N>i;i++) {
			for (int j=0;MAX_N>j;j++) {
				ans += mp[i][j];
			}
		}
		printf("%d\n",ans);
	}
}