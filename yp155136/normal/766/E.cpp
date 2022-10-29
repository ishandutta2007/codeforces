#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e5 +6;

int a[MAX_N];
vector<int> edg[MAX_N];
pii bit[MAX_N];
bool visit[MAX_N];

LL cnt;

pii operator+(const pii &p1,const pii &p2) {
	return make_pair(p1.first+p2.first,p1.second+p2.second);
}

pii operator-(const pii &p1,const pii &p2) {
	return make_pair(p1.first-p2.first,p1.second-p2.second);
}

pii rev(pii p) {
	return make_pair(p.second,p.first);
}

pii dfs(int id) {
	visit[id] = 1;
	pii son=make_pair(0,0);
	vector<int> v;
	for (auto i:edg[id]) {
		if (!visit[i]) {
			son = son+dfs(i);
			v.push_back(i);
		}
	}
	if (v.size() == 0) return bit[id];
	else if (v.size() == 1) {
		if (bit[id] == make_pair(0LL,1LL)) {
			//bit is 1
			bit[id]=bit[id]+rev(son);
		}
		else {
			bit[id]=bit[id]+son;
		}
	}
	else {
		bool flag=false;
		if (bit[id] == make_pair(0LL,1LL)) {
			flag=1;
			bit[id] = bit[id] + rev(son);
		}
		else {
			bit[id] = bit[id] + son;
		}
		LL _cnt = 0;
		for (auto i:v) {
			son = son -  bit[i];
			pii tmp=bit[i];
			if (flag) tmp=rev(tmp);
			_cnt += tmp.first*son.second + tmp.second*son.first;
			son = son +  bit[i];
		}
		cnt += (_cnt/2);
		return bit[id];
	}
	return bit[id];
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		for (int i=1;n>i;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			edg[x].push_back(y);
			edg[y].push_back(x);
		}
		LL _=1;
		LL ans=0;
		for (int qq=0;20>qq;qq++) {
			if (qq) _*=2;
			for (int i=1;n>=i;i++) {
				if (a[i]%2) bit[i] = make_pair(0,1);
				else bit[i] = make_pair(1,0);
				a[i]/=2;
			}
			memset(visit,0,sizeof(visit));
			cnt = 0;
			dfs(1);
			ans += cnt*_;
			for (int i=1;n>=i;i++) {
//				cout<<"i = "<<i<<" , bit[i] = "<<bit[i].first<<' '<<bit[i].second<<endl;
				ans += bit[i].second*_;
			}
		}
		printf("%I64d\n",ans);
	}
}