#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int MAX_N = 2e5 +6;

vector<int> edg[MAX_N];
bool visit[MAX_N];
int p[MAX_N];
LL _[MAX_N];
LL __[MAX_N];
int n;
LL ans[MAX_N];
int cnt[MAX_N];

void dfs1(int id) {
	visit[id]=1;
	LL ret=1;
	LL ret2=1;
	for (auto i:edg[id]) {
		if (!visit[i]) {
			dfs1(i);
			ret *= (_[i] + 1);
			if ((_[i]+1)%mod == 0) cnt[id]++;
			else ret2*=(_[i]+1);
			ret %= mod;
			ret2%=mod;
		}
	}
	_[id]=ret;
	__[id]=ret2;
}

LL pow(LL a,LL n,LL mod) {
	if (a==0) return 0;
	else if (n==0) return 1%mod;
	else if (n==1) return a%mod;
	LL ret=pow(a,n/2,mod);
	ret*=ret;
	ret%=mod;
	if (n&1) ret*=a;
	ret%=mod;
	return ret;
}

void dfs2(int id,LL p) {
//	cout<<"id = "<<id<<" , p = "<<p<<endl;
	ans[id] = _[id]*p%mod;
	visit[id]=1;
	for (auto i:edg[id]) {
		if (!visit[i]) {
			if (cnt[id]==0) dfs2(i,(ans[id]*pow((_[i]+1)%mod,mod-2,mod)+1)%mod);
			else if (cnt[id]==1 && (_[i]+1)%mod == 0) dfs2(i,((__[id]*p+1)%mod));
			else dfs2(i,1);
		}
	}
}

int main () {
	while (scanf("%d",&n) != EOF) {
		memset(visit,0,sizeof(visit));
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		for (int i=2;n>=i;i++) {
			scanf("%d",&p[i]);
			edg[i].push_back(p[i]);
			edg[p[i]].push_back(i);
		}
		memset(cnt,0,sizeof(cnt));
		dfs1(1);
		memset(visit,0,sizeof(visit));
		dfs2(1,1);
//		for (int i=1;n>=i;i++) {
//			cout<<"_["<<i<<"] = "<<_[i]<<endl;
//			cout<<"__["<<i<<"] = "<<__[i]<<endl;
//			cout<<"cnt["<<i<<"] = "<<cnt[i]<<endl;
//		}
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			printf("%I64d",ans[i]);
		}
		puts("");
	}
}