#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 106;
const int MAX_P = 3005;

LL a[MAX_N];

vector<pii> _[MAX_N];
vector<int> edg[MAX_P];
bool visit[MAX_P];
int match[MAX_P];

bool dfs(int id) {
	for (auto i:edg[id]) {
		if (visit[i]) continue;
		visit[i]=true;
		if (match[i] == -1 || dfs(match[i])) {
			match[i] = id;
			return true;
		}
	}
	return false;
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		int tot=0;
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
			LL tmp=sqrt(a[i]);
			tmp += 5;
			for (int j=2;tmp>=j;j++) {
				while (a[i]%j==0) {
					_[i].push_back(make_pair(j,tot++));
					a[i]/=j;
				}
			}
			if (a[i] != 1) _[i].push_back(make_pair(a[i],tot++));
		}
		for (int i=1;m>=i;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			if (x&1) swap(x,y);
			for (pii j:_[x]) {
				for (pii k: _[y]) {
					if (j.first == k.first && j.first!=1) {
						edg[j.second].push_back(k.second);
					}
				}
			} 
		}
		int ans=0;
		memset(match,-1,sizeof(match));
		for (int i=0;tot>i;i++) {
			memset(visit,0,sizeof(visit));
			if (dfs(i))ans++;
		}
		printf("%d\n",ans);
	}
}