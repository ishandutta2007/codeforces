#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

struct Value {
	long long int sum;
	long long int l_max;
	long long int r_max;
	long long int t_max;
};

Value add(const Value&l, const Value&r) {
	long long int n_sum=l.sum+r.sum;
	long long int n_l_max=max(l.l_max,l.sum+r.l_max);
	long long int n_r_max=max(r.r_max,r.sum+l.r_max);
	long long int n_t_max=max(max(l.t_max,r.t_max),l.r_max+r.l_max);

	return Value{ n_sum,n_l_max,n_r_max,n_t_max };
}


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
int main() {
	int N;
	long long int A;
	cin>>N>>A;
	vector<int>ds(N);
	vector<long long int>moneys(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d %lld",&ds[i],&moneys[i]);
		moneys[i]-=A;
		moneys[i]=-moneys[i];
	}
	vector<Value>vs;
	for (int i = 0; i < N; ++i) {
		if (moneys[i] > 0) {
			vs.push_back(Value{ moneys[i],moneys[i],moneys[i],moneys[i] });
		}
		else {
			vs.push_back(Value{ moneys[i],0,0,0 });
		}
	}
	map<long long int,vector<int>>mp;
	for (int i = 0; i < N-1; ++i) {
		mp[ds[i+1]-ds[i]].push_back(i);
	}
	UnionFind uf(N);

	long long int answer=0;
	for(auto v:vs)answer=max(answer,v.sum);
	for (auto m : mp) {

		long long int nanswer=0;

		for (auto p : m.second) {
			Value l_v=vs[uf.root(p)];
			Value r_v=vs[uf.root(p+1)];
			uf.unionSet(p,p+1);
			Value aft_v=add(l_v,r_v);
			vs[uf.root(p)]=aft_v;
			nanswer=max(nanswer,aft_v.t_max);
		}
		nanswer -= (m.first)*m.first;
		answer=max(answer,nanswer);
	}
	cout<<answer<<endl;
	return 0;
}