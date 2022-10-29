#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 156;

vector<int> edg[MAX_N];
bool visit[MAX_N];
LL dx[4]={0,0,1,-1};
LL dy[4]={1,-1,0,0};
LL magic[5]={1,0,3,2,4};
pii ans[MAX_N];

void dfs(int id,LL x,LL y,LL delta,LL dir) {
	ans[id]=make_pair(x,y);
	visit[id]=1;
	int j=0;
	for (auto i:edg[id]) {
		if (visit[i]==0) {
			while (j==dir) j++;
			int pp=magic[j];
			dfs(i,x+dx[j]*delta/2,y+dy[j]*delta/2,delta/2,pp);
			j++;
		}
	}
}

int main () {
	srand(time(NULL));
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		LL tmp=1;
		for (int i=1;n-1>=i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			tmp*=a;
			tmp*=b;
			tmp/=rand();
			edg[a].push_back(b);
			edg[b].push_back(a);
		}
		srand(tmp);
		for (int i=1;n>=i;i++) {
			if (edg[i].size()>4) {
				puts("NO");
				return 0;
			}
		}
		memset(visit,0,sizeof(visit));
		puts("YES");
		LL x=1,y=1,delta=1;
		while (x<1e13) {
			x*=(rand()+1);
		}
		while (y<1e13) {
			y*=(rand()+1);
		}
		while (delta<1e13) {
			delta*=(rand()+1);
		}
		dfs(1,x,y,delta,4);
		for (int i=1;n>=i;i++) {
			printf("%I64d %I64d\n",ans[i].first,ans[i].second);
		}
	}
}