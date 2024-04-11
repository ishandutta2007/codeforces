#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

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
struct Edge {
	int u;
	int v;
	int cost;
};

long long int check(long long int n) {
	long long int amin=0;
	long long int amax=2e9;
	while (amin + 1 != amax) {
		long long int amid=(amin+amax)/2;
		if (amid*amid <= n) {
			amin=amid;
		}
		else {
			amax=amid;
		}
	}
	if (amin*amin == n) {
		return amin;
	}
	else {
		return -1;
	}
}

int main() {
	int N;cin>>N;
	vector<long long int>even_xs;
	for (int i = 0; i < N / 2; ++i) {
		long long int a;cin>>a;
		even_xs.push_back(a);
	}
	vector<long long int>anss;
	long long int now=0;

	bool ok=true;
	for (int i = 0; i < N / 2; ++i) {
		long long int next = now + 1;
		while (true) {
			long long int num=next*next-now*now;
			long long int ne_ne_sq=next*next+even_xs[i];
			bool ok=check(ne_ne_sq)!=-1;
			if (ok) {
				anss.push_back(num);
				anss.push_back(even_xs[i]);
				now=check(ne_ne_sq);
				break;
			}
			else {

			}
			next++;
			if(next>=4e6)break;
		}
		if (next >= 4e6) {
			ok = false;
			break;
		}
		else {
		}
	}
	if (!ok) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
		for (int i = 0; i < N; ++i) {
			cout << anss[i];
			if (i == N - 1)cout << endl;
			else cout << " ";
		}
	}
	
	return 0;
}