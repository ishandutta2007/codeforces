#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
const int MAX_N = 3e3 + 6;

vector<int> edg[MAX_N];
int adj[MAX_N][MAX_N];
LL d[3][MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		memset(adj,0,sizeof(adj));
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		for (int i=0;m>i;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a][b] = 1;
			edg[a].push_back(b);
		}
		LL ans=0;
		for (int i=1;n>=i;i++) {
			memset(d,0,sizeof(d));
			//set i as start
			queue<pii> que;
			que.push(make_pair(0,i));
			d[0][i] = 1;
			while (!que.empty()) {
				pii tmp=que.front();
				que.pop();
				for (auto i:edg[tmp.second]) {
					d[tmp.first+1][i] += d[tmp.first][tmp.second];
					if (tmp.first == 0) que.push(make_pair(tmp.first+1,i));
				}
			}
			for (int j=1;n>=j;j++) {
				if (i==j) continue;
				ans += (d[2][j])*(d[2][j]-1)/2;
			}
		}
		printf("%I64d\n",ans);
	}
}