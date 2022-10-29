#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 3e5 + 6;

bool police[MAX_N];
vector<int> edg[MAX_N];
int visit[MAX_N];

int main () {
	int n,k,d;
	while (scanf("%d %d %d",&n,&k,&d) != EOF) {
		memset(police,0,sizeof(police));
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		for (int i=1;k>=i;i++) {
			int a;
			scanf("%d",&a);
			police[a]=1;
		}
		map<pii,int> mp;
		for (int i=1;n>i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
			mp[make_pair(a,b)]=i;
			mp[make_pair(b,a)]=i;
		}
		memset(visit,0,sizeof(visit));
		for (int i=1;n>=i;i++) {
			if (police[i]) {
				visit[i]=i;
			}
		}
		vector<int> ans;
		queue<pii> que;
		for (int i=1;n>=i;i++) {
			if (police[i]) {
				que.push(make_pair(i,0));
			}	
		}
		while (!que.empty()) {
			pii t=que.front();
			que.pop();
			if (t.second > d) continue;
			for (int j:edg[t.first]) {
				if (visit[j] == 0) {
					que.push(make_pair(j,t.second+1));
					visit[j]=visit[t.first];
				}
				else if (visit[j] != visit[t.first]) {
					ans.push_back(mp[make_pair(j,t.first)]);
				}
			}
		}
		sort(ans.begin(),ans.end());
		ans.resize(unique(ans.begin(),ans.end()) - ans.begin());
		printf("%d\n",ans.size());
		bool flag=0;
		for (int i:ans) {
			if (flag) printf(" ");
			printf("%d",i);
			flag=1;
		}
		puts("");
	}
}