#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const LL INF = 1e15+6;
const int MAX_N = 5e3+6;

vector<pii> e[MAX_N];
vector<pii> edg[MAX_N];
vector<pii> rev_edg[MAX_N];
LL dp[MAX_N][MAX_N]; //end at i pass j areas's min time
int rudu[MAX_N];
bool visit[MAX_N];

void BFS() {
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int t=que.front();
		que.pop();
		visit[t]=true;
		for (auto i=e[t].begin();i!=e[t].end();i++) {
			pii tmp=*i;
			int j=tmp.first;
			LL k=tmp.second;
			edg[t].push_back(tmp);
			rudu[j]++;
			rev_edg[j].push_back(make_pair(t,k));
			if (!visit[j]) {
				visit[j]=true;
				que.push(j);
			}
		}
	}
}

int main (){
	int n,m;
	LL T;
	while (scanf("%d %d %I64d",&n,&m,&T) != EOF) {
		for (int x=0;n>=x;x++) {
			edg[x].clear();
			rev_edg[x].clear();
			e[x].clear();
			rudu[x]=0;
			for (int y=0;n>=y;y++) {
				dp[x][y] = INF;
			}
			visit[x]=false;
		}
		for (int x=0;m>x;x++) {
			int i,j,k;
			scanf("%d %d %d",&i,&j,&k);
			e[i].push_back(make_pair(j,k));
		}
		BFS();
		queue<int> que;
		que.push(1);
		dp[1][1]=0;
		while (!que.empty()) {
			int t=que.front();
			que.pop();
			for (auto i=edg[t].begin();i!=edg[t].end();i++) {
				pii tmp=*i;
				int j=tmp.first;
				LL k=tmp.second;
				for (int i=1;n>=i;i++) {
					dp[j][i] = min(dp[j][i],dp[t][i-1]+k);
				}
				rudu[j]--;
				if (!rudu[j]) que.push(j);
			}
		}
		int ans=0;
		for (int i=1;n>=i;i++) {
			if (dp[n][i] <= T) {
				ans = max(ans,i);
			}
		}
		printf("%d\n",ans);
		int now=n;
		vector<int> v;
		v.push_back(n);
		for (int q=ans;q>=1;q--) {
			for (auto i=rev_edg[now].begin();i!=rev_edg[now].end();i++) {
				pii tmp=*i;
				int j=tmp.first;
				LL k=tmp.second;
				if (dp[now][q] == dp[j][q-1]+k) {
					v.push_back(j);
					now=j;
					break;
				}
			}
		}
		for (int i=ans-1;i>=0;i--) {
			if (i!=ans-1) printf(" ");
			printf("%d",v[i]);
		}
		puts("");
	}
}