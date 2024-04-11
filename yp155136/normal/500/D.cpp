#include <iostream>
#include <stdio.h>
#include <utility>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 1e5 + 6;

vector<pii> edg[MAX_N];
pii ipt[MAX_N];
int depth[MAX_N];
int sz[MAX_N];
LL w[MAX_N];
long double tot;

int dfs(int id,int cur_depth,int weight) {
	depth[id]=cur_depth;
	w[id]=weight;
	sz[id]=1;
	for(auto i=edg[id].begin();i!=edg[id].end();i++) {
		pii tmp=*i;
		if (!depth[tmp.first]) {
			sz[id]+=dfs(tmp.first,cur_depth+1,tmp.second);
		}
	}
	return sz[id];
}

int main () {
	LL n;
	while (scanf("%I64d",&n) != EOF) {
		for (int x=0;n>=x;x++) {
			edg[x].clear();
		}
		memset(sz,0,sizeof(sz));
		memset(depth,0,sizeof(depth));
		for (int x=1;n-1>=x;x++) {
			int i,j,k;
			scanf("%d %d %d",&i,&j,&k);
			ipt[x]=make_pair(i,j);
			edg[i].push_back(make_pair(j,k));
			edg[j].push_back(make_pair(i,k));
		}
		dfs(1,1,0);
		//count tot
		tot=0;
		long double C=n*(n-1)*(n-2)/6;
		for (int i=1;n>=i;i++) {
//			cout<<"w["<<i<<"] = "<<w[i]<<endl;
			if (w[i]) {
				tot += (w[i]*(n-2)*sz[i]*(n-sz[i]) / C);
			}
		}
		int m;
		scanf("%d",&m);
		while (m--) {
			int i,j;
			scanf("%d %d",&i,&j);
			int ti=ipt[i].first,tj=ipt[i].second;
			if (depth[ti] < depth[tj]) swap(ti,tj);
			i=ti;
			tot -= ((w[i]-j)*(n-2)*sz[i]*(n-sz[i])/C);
			w[i]=j;
			cout<<fixed<<setprecision(10)<<tot<<endl;
		}
	}
}