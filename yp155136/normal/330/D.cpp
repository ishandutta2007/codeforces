#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
#include <cassert>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e3 +6;

string s[MAX_N];
int mp[MAX_N][MAX_N];
int tt[MAX_N][MAX_N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	pii st,ed;
	memset(mp,-1,sizeof(mp));
	for (int i=1;n>=i;i++) {
		cin >> s[i];
		s[i] = " "+s[i];
		for (int j=1;m>=j;j++) {
			if (s[i][j] == 'T') {
				mp[i][j] = -1;
			}
			else if (s[i][j] == 'S') {
				st=make_pair(i,j);
				mp[i][j] = 0;
			}
			else if (s[i][j] == 'E') {
				ed=make_pair(i,j);
				mp[i][j] = 0;
			}
			else {
				mp[i][j] = s[i][j] - '0';
			}
		}
	}
	queue<pii> que;
	que.push(st);
	memset(tt,-1,sizeof(tt));
	tt[st.first][st.second] = 0;
	while (!que.empty()) {
		pii p=que.front();
		que.pop();
		int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
		for (int i=0;4>i;i++) {
			int tx=p.first+dx[i],ty=p.second+dy[i];
			if (mp[tx][ty] != -1 && tt[tx][ty] == -1) {
				tt[tx][ty] = tt[p.first][p.second] + 1;
				que.push(make_pair(tx,ty));
			}
		}
	}
	while (!que.empty()) que.pop();
	int ttt=tt[ed.first][ed.second];
	que.push(ed);
	memset(tt,-1,sizeof(tt));
	tt[ed.first][ed.second] = 0;
	while (!que.empty()) {
		pii p=que.front();
		que.pop();
		int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
		for (int i=0;4>i;i++) {
			int tx=p.first+dx[i],ty=p.second+dy[i];
			if (mp[tx][ty] != -1 && tt[tx][ty] == -1) {
				tt[tx][ty] = tt[p.first][p.second] + 1;
				que.push(make_pair(tx,ty));
			}
		}
	}
	assert(tt[st.first][st.second] == ttt);
	long long int ans=0;
	for (int i=1;n>=i;i++) {
		for (int j=1;m>=j;j++) {
			if (tt[i][j] != -1 && tt[i][j] <= ttt && mp[i][j] != -1) ans += mp[i][j]; 
		}
	}
	cout<<ans<<endl;
}