#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 106;

vector<pii> edg[MAX_N];
int dp[MAX_N];
bool used[MAX_N];

void dfs(int id,int w) {
	used[id]=1;
	dp[id] = w;
	for (pii i:edg[id]) {
		if (!used[i.first]) dfs(i.first,w+i.second);
	}
}

int main () {
	int n;
	scanf("%d",&n);
	for (int i=1;n>i;i++) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edg[a].push_back(make_pair(b,c));
		edg[b].push_back(make_pair(a,c));
	}
	dfs(0,0);
	int mx=0;
	for (int i=0;n>i;i++) mx = max(mx,dp[i]);
	cout<<mx<<endl;
}