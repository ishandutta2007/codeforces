#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;
const int MAX_M = 1e5 + 6;

bool visit[MAX_N];
int col[MAX_N];
vector<int> edg[MAX_N];

bool dfs(int id,int color) {
	visit[id]=true;
	col[id]=  color;
	bool ret=true;
	for (auto i:edg[id]) {
		if (!visit[i]) ret&=dfs(i,1-color);
		else if (col[i]+color!=1) ret=false;
	}
	return ret;
}

LL cnt[2];

void dfs2(int id) {
	visit[id]=true;
	cnt[col[id]]++;
	for (auto i:edg[id]) {
		if (!visit[i]) dfs2(i);
	}
}

int main () {
	LL n,m;
	while (scanf("%I64d %I64d",&n,&m) != EOF) {
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		for (int i=1;m>=i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
		}
		memset(visit,0,sizeof(visit));
		memset(col,-1,sizeof(col));
		bool can=true;
		for (int i=1;n>=i;i++) {
			if (!visit[i]) {
				can &= dfs(i,0);
			}
		}
		if (!can) {
			//can't bitcoloring --> must have a cycle who lenght is an odd !!!
			puts("0 1");
			continue;
		}
		if (m==0) {
			printf("%I64d %I64d\n",3LL,n*(n-1)*(n-2)/6);
			continue;
		}
		bool _2=false;
		for(int i=1;n>=i;i++) {
			if (edg[i].size() > 1) {
				_2=true;
				break;
			}
		}
		if (!_2) {
			LL ans=0;
			for (int i=1;n>=i;i++) {
				if (edg[i].size() == 1) {
					ans += (n-2);
				}
			}
			printf("2 %I64d\n",ans/2);
		}
		else {
			LL ans=0;
			memset(visit,0,sizeof(visit));
			for (int i=1;n>=i;i++) {
				if (!visit[i]) {
					cnt[0]=cnt[1]=0;
					dfs2(i);
					ans += ((cnt[0]*(cnt[0]-1))/2 + (cnt[1]*(cnt[1]-1))/2);
				}
			}
			printf("1 %I64d\n",ans);
		}
	}
}