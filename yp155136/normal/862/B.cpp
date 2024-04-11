#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;
const int MAX_N =1e5 +6;

int color[MAX_N];
vector<int> edg[MAX_N];
bool visit[MAX_N];

void dfs(int id,int col) {
	color[id] = col;
	visit[id] = 1;
	for (int i:edg[id]) {
		if (!visit[i]) dfs(i,1-col);
	}
}

int main () {
	int n;
	scanf("%d",&n);
	for (int i=1;n>i;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	dfs(1,1);
	LL cnt1=0;
	for (int i=1;n>=i;i++) {
		cnt1 += (color[i]==1);
	}
	cout<<cnt1*(n-cnt1)-(n-1)<<endl;
}