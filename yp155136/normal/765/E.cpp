#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 6;

vector<int> edg[MAX_N];
vector<int> _[MAX_N];
int deg[MAX_N];
int sz[MAX_N];
bool visit[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			edg[i].clear();
			_[i].clear();
		}
		memset(deg,0,sizeof(deg));
		for (int i=1;n>i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
			deg[a]++;
			deg[b]++;
		}
		memset(sz,0,sizeof(sz));
		memset(visit,0,sizeof(visit));
		queue<int> que;
		bool flag=0;
		for (int i=1;n>=i;i++) {
			if (deg[i]>2) flag=1;
			if (deg[i] == 1) {
				que.push(i);
				sz[i] = 1;
			}
		}
		if (!flag) {
			while (n%2==1 && n!=1) {
				n = (n+1)/2;
			}
			printf("%d\n",n-1);
			continue;
		}
		int cnt=0;
		bool okay=true;
		int root=-1;
		while (!que.empty()) {
			int t=que.front();
//			cout<<"t = "<<t<<endl;
			que.pop();
			visit[t]=1;
			sort(_[t].begin(),_[t].end());
			_[t].resize(unique(_[t].begin(),_[t].end()) - _[t].begin());
			cnt++;
			if (cnt==n) {
				root = t;
				break;
			}
			if (_[t].size() > 1) {
				okay = false;
				break;
			}
			if (_[t].size() > 0) {
				sz[t] = _[t][0] + 1;
			}
//			cout<<"hihi\n";
			for (auto i:edg[t]) {
				if (!visit[i]) {
					_[i].push_back(sz[t]);
					deg[i]--;
					if (deg[i] == 1) {
						que.push(i);
					}
				}
			}
		}
		if (!okay) {
			puts("-1");
			continue;
		}
//		cout<<"root = "<<root<<endl;
		if (_[root].size() > 2) puts("-1");
		else {
			int ans= _[root][0]+1;
			if (_[root].size()>1) ans += _[root][1];
//			cout<<"ans = "<<ans<<endl;
			while (ans%2==1 && ans!=1) {
				ans = (ans+1)/2;
			}
			printf("%d\n",ans-1);
		}
	}
}