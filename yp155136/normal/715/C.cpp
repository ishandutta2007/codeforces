#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
using namespace std;

#define MP make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<LL,LL> pii;
typedef pair<pii,LL> piii;
const int MAX_N = 1e5 + 6;

vector<pii> edg[MAX_N];
pii node[MAX_N];
bool visit[MAX_N];
vector<int> tree;
vector<piii> p;
LL mod;
map<LL,LL> q;
map<pii,int> cnt;
LL pow10[MAX_N];
LL pow_10[MAX_N];

void build() {
	pow_10[0] = pow10[0] = 1;
	for (LL i=1;9>=i;i++) {
		if ((mod*i+1)%10 == 0) {
			pow_10[1] = ((mod*i+1)/10)%mod;
		}
	}
	pow10[1] = 10%mod;
	for (int i=2;MAX_N>i;i++) {
		pow_10[i] = (pow_10[i-1] * pow_10[1]) % mod;
		pow10[i] = (pow10[i-1] * pow10[1]) % mod;
	}
}

int dfs1(int id) {
	tree.push_back(id);
	visit[id]=true;
	int ret=1;
	int mx=0;
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		pii tmp=*i;
		if (!visit[tmp.first]) {
			int temp=dfs1(tmp.first);
			ret += temp;
			mx = max(mx,temp);
		}
	}
	node[id] = MP(ret,mx);
	visit[id]=false;
	return ret;
}

int get_cen(int root) {
	tree.clear();
	dfs1(root);
	int sz=tree.size();
	int mx=sz+2;
	int ret=-1;
	for (auto i=tree.begin();i!=tree.end();i++) {
		int tmp=*i;
		if (max(node[tmp].second,sz-node[tmp].first) < mx) {
			mx = max(node[tmp].second,sz-node[tmp].first);
			ret = tmp;
		}
	}
	return ret;
}

void dfs2(int id,int tp,int tq,int depth,int tid) {
//	cout<<"tp = "<<tp<<" , tq = "<<tq<<endl;
	visit[id]=true;
	q[tq]++;
	p.push_back(MP(MP(tp,depth),tid));
	cnt[MP(tq,tid)]++;
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		pii tmp=*i;
		if (!visit[tmp.first]) {
			int d=tmp.second;
			dfs2(tmp.first,(tp*pow10[1]+d)%mod,(tq+d*pow10[depth])%mod,depth+1,tid);
		}
	}
	visit[id]=false;
}

LL solve(int root) {
//	cout<<"root = "<<root<<endl;
	int cen=get_cen(root);
	visit[cen]=true;
	LL ret=0;
	for (auto i=edg[cen].begin();i!=edg[cen].end();i++) {
		pii tmp=*i;
		if (!visit[tmp.first]) ret += solve(tmp.first);
	}
	p.clear();
	q.clear();
	cnt.clear();
	int tid=1;
//	cout<<"cen = "<<cen<<endl;
	for (auto i=edg[cen].begin();i!=edg[cen].end();i++) {
		pii tmp=*i;
		if (!visit[tmp.first]) {
			dfs2(tmp.first,tmp.second%mod,tmp.second%mod,1,tid++);
		}
	}
	ret += q[0];
	for (auto i=p.begin();i!=p.end();i++) {
		piii tmp=*i;
		LL val=tmp.first.first;
		LL depth=tmp.first.second;
		LL id=tmp.second;
		LL need=((-val + mod) * pow_10[depth])%mod;
//		cout<<"val = "<<val<<" , need = "<<need<<" , depth = "<<depth<<endl;
		ret += q[need] - cnt[MP(need,id)];
		if (val==0)ret++;
	}
	visit[cen]=false;
	return ret;
}

int main () {
	int n;
	while (scanf("%d %I64d",&n,&mod) != EOF) {
		for (int x=0;n>=x;x++) {
			edg[x].clear();
			visit[x]=false;
		}
		for (int x=0;n-1>x;x++) {
			int i,j,k;
			scanf("%d %d %d",&i,&j,&k);
			edg[i].push_back(MP(j,k));
			edg[j].push_back(MP(i,k));
		}
		build();
		printf("%I64d\n",solve(1));
	}
}