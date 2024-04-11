#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;

struct aUnionFind {
	vector<pair<int, long long int>> data;
	aUnionFind(int size) : data(size, make_pair(-1, 0)) { }

	//y is w bigger than x
	bool unionSet(const int x, const int y, const long long int w) {
		const int rx(root(x).first), ry(root(y).first);
		if (rx != ry) {
			data[rx].first += data[ry].first; data[ry].first = rx;
			data[ry].second = w ^ data[x].second ^ data[y].second;
			return true;
		}
		else {
			return (root(x).second ^ w) == root(y).second;
		}
	}

	//x is belong to first
	//x is second bigger than first
	pair<int, long long int> root(const int x) {
		if (data[x].first < 0) {
			return make_pair(x, 0);
		}
		else {
			pair<int, long long int>ndata;
			ndata.first = root(data[x].first).first;
			ndata.second = data[x].second xor root(data[x].first).second;
			return data[x] = ndata;
		}
	}
	int size(const int x) {
		return -data[root(x).first].first;
	}
};

map<int, int>mp;
int get_num(int a) {
	static int next_num=0;
	if (mp.find(a) == mp.end()) {
		mp[a]=next_num;
		next_num++;
	}
	return mp[a];
}
int main() {
	int Q;cin>>Q;
	int next_num=0;
	int last=0;
	aUnionFind uf(1000000);
	while (Q--) {
		int t;
		scanf("%d",&t);
		if (t == 2) {
			int l,r;
			scanf("%d %d",&l,&r);
			l=l xor last;
			r=r xor last;
			if(l>r)swap(l,r);
			r++;

			int answer=-1;
			if (mp.find(l) == mp.end() || mp.find(r) == mp.end()) {
			}
			else {
				auto lp=uf.root(mp[l]);
				auto rp=uf.root(mp[r]);
				if (lp.first == rp.first) {
					answer=lp.second xor rp.second;
				}
			}
			last=abs(answer);
			printf("%d\n",answer);
		}
		else {
			int l,r,x;scanf("%d %d %d",&l,&r,&x);
			l=l xor last;
			r=r xor last;
			x=x xor last;
			if(l>r)swap(l,r);
			r++;

			//if (mp.find(l) != mp.end() && mp.find(r) != mp.end()) {
			//	auto lp=uf.root(mp[l]);
			//	auto rp=uf.root(mp[r]);

			//	if (lp.first == rp.first) {
			//		continue;
			//	}
			//}
			uf.unionSet(get_num(r),get_num(l),x);
		}
	}
	return 0;
}