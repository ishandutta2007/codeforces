#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e5 + 6;

int rudu[MAX_N];
int dp[MAX_N];
vector<pii> edg[MAX_N]; //to,id
vector<int> edg2;

bool check(int id,int n) {
	memset(rudu,0,sizeof(rudu));
	memset(dp,0,sizeof(dp));
	queue<int> que;
	for (int x=0;id>x;x++) {
		rudu[edg2[x]]++;
	}
	for (int x=1;n>=x;x++) {
		if (rudu[x]==0) {
			dp[x]=1;
			que.push(x);
		}
	}
	while (!que.empty()) {
		int t=que.front();
		que.pop();
		if (dp[t] == n) return true;
		for (auto i=edg[t].begin();i!=edg[t].end();i++) {
			pii tmp=*i;
			if (tmp.second>id) break;
			int j=tmp.first;
			rudu[j]--;
			dp[j] = max(dp[j],dp[t]+1);
			if (rudu[j] == 0) {
				que.push(j);
			}
			if (dp[j] == n) {
				return true;
			}
		}
	}
	return false;
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int x=1;m>=x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			edg[i].push_back(make_pair(j,x));
			edg2.push_back(j);
		}
		int L=0,R=m+1;
		while (R-L != 1) {
			int mid=(L+R)>>1;
			if (check(mid,n)) R=mid;
			else L=mid;
		}
		printf("%d\n",(R==m+1?-1:R));
	}
}