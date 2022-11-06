#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;

typedef long long int64;

template< class T >
struct BinaryIndexedTree
{
	vector< T > data;

	BinaryIndexedTree()
	{
		data.assign(0, 0);
	}
	BinaryIndexedTree(int sz)
	{
		data.assign(++sz, 0);
	}

	T sum(int k)
	{
		T ret = 0;
		for (++k; k < data.size(); k += k & -k) ret += data[k];
		return (ret);
	}

	void add(int k, T x)
	{
		k = min(k, (int)data.size() - 2);
		for (++k; k > 0; k -= k & -k) data[k] += x;
	}
};

struct SegmentTree
{
	int sz;
	vector< vector< int > > nums;
	vector< BinaryIndexedTree< int64 > > seg;

	SegmentTree(vector< vector< int > > sg)
	{
		sz = 1;
		while (sz < sg.size()) sz <<= 1;
		nums.resize(2 * sz - 1);
		for (int i = 0; i < sg.size(); i++) nums[sz + i - 1] = sg[i];
		for (int i = sz - 2; i >= 0; i--) {
			nums[i].resize(nums[2 * i + 1].size() + nums[2 * i + 2].size());
			merge(nums[2 * i + 1].begin(), (nums[2 * i + 1].end()),
				nums[2 * i + 2].begin(),nums[2 * i + 2].end(),nums[i].begin());
		}
		for (int i = 0; i < 2 * sz - 1; i++) seg.push_back(BinaryIndexedTree< int64 >(nums[i].size()));
	}

	void update(int x, int y, int64 z)
	{
		x += sz - 1;
		seg[x].add(lower_bound(begin(nums[x]), end(nums[x]), y) - begin(nums[x]), z);
		while (x > 0) {
			x = (x - 1) >> 1;
			seg[x].add(lower_bound(begin(nums[x]), end(nums[x]), y) - begin(nums[x]), z);
		}
	}

	int64 query(int a, int b, int k, int l, int r)
	{
		if (a >= r || b <= l) return (0);
		if (a <= l && r <= b) return (seg[k].sum(lower_bound(begin(nums[k]), end(nums[k]), a) - begin(nums[k])));
		return (query(a, b, 2 * k + 1, l, (l + r) >> 1) + query(a, b, 2 * k + 2, (l + r) >> 1, r));
	}

	int64 query(int a, int b)
	{
		return (query(a, b, 0, 0, sz));
	}
};

#define Seg_Max_N (1<<17) 

using Value = pair<vector< int >, BinaryIndexedTree< int64 > >;
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n,const vector<vector<int>>&v) :dat(2 * Seg_Max_N) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = N-1; i < N-1+v.size(); i++) {
			dat[i].first=v[i-(N-1)];
			dat[i].second=BinaryIndexedTree<int64>(dat[i].first.size());
		}
		for (int i = N - 2; i >= 0; --i) {
			int l=i*2+1,r=i*2+2;
			dat[i].first.resize(dat[l].first.size()+dat[r].first.size());
			merge(dat[l].first.begin(),dat[l].first.end(),
				dat[r].first.begin(),dat[r].first.end(),
				dat[i].first.begin());
			dat[i].second=BinaryIndexedTree<int64>(dat[i].first.size());
		}
	}
	// update k th element
	void update(int k, int a,int64 b) {
		k += N - 1;
		dat[k].second.add(
			lower_bound(dat[k].first.begin(),dat[k].first.end(),a)-dat[k].first.begin(),
			b);

		while (k > 0) {
			k = (k - 1) / 2;
			dat[k].second.add(
				lower_bound(dat[k].first.begin(), dat[k].first.end(), a) - dat[k].first.begin(),
				b);
		}
	}
	// min [a, b)
	int64  query(int a, int b,int X) { return query(a, b,X, 0, 0, N); }
	int64  query(int a, int b,int X, int k, int l, int r) {
		if (r <= a or b <= l) return 0;
		if (a <= l and r <= b) {
			auto it=lower_bound(dat[k].first.begin(),dat[k].first.end(),X);
			return dat[k].second.sum(it-dat[k].first.begin());
		}
		const int m = (l + r) / 2;
		const int64 al(query(a, b,X, k * 2 + 1, l, m));
		const int64 ar(query(a, b,X, k * 2 + 2, m, r));
		return al+ar;
	}
};

int N, M;
int A[100000];
set< int > st[100001];
int T[100000], X[100000], Y[100000];
vector< tuple< int, int, int > > qs[100001];
int main()
{


	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		st[A[i]].emplace(i);
	}
	for (int i = 1; i <= N; i++) st[i].emplace(N);


	vector< vector< int > > sg(N + 1);
	auto push = [&](int idx, int a, int b, int c)
	{
		sg[a].push_back(b);
		qs[idx].emplace_back(a, b, c);
	};

	for (int i = 0; i < N; i++) {
		auto it = st[A[i]].lower_bound(i);
		if (it != begin(st[A[i]])) push(100000, *it, *prev(it), *it - *prev(it));
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &T[i], &X[i], &Y[i]);
		--X[i];
		if (T[i] == 1) {
			auto it = st[A[X[i]]].lower_bound(X[i]);
			if (it != begin(st[A[X[i]]])) push(i, *it, *prev(it), *prev(it) - *it);
			push(i, *next(it), *it, *it - *next(it));
			it = st[A[X[i]]].erase(it);
			if (it != begin(st[A[X[i]]])) push(i, *it, *prev(it), *it - *prev(it));

			A[X[i]] = Y[i];
			it = st[A[X[i]]].lower_bound(X[i]);
			if (it != begin(st[A[X[i]]])) push(i, *it, *prev(it), *prev(it) - *it);
			st[A[X[i]]].emplace(X[i]);
			it = st[A[X[i]]].lower_bound(X[i]);
			if (it != begin(st[A[X[i]]])) push(i, *it, *prev(it), *it - *prev(it));
			++it;
			push(i, *it, *prev(it), *it - *prev(it));
		}
	}

	for (int i = 0; i <= N; i++) {
		sort(begin(sg[i]), end(sg[i]));
		sg[i].erase(unique(begin(sg[i]), end(sg[i])), end(sg[i]));
	}

	SegmentTree seg(sg);
	segtree seg2(100000,sg);
	auto dodo = [&](int idx)
	{
		for (auto& p : qs[idx]) {
			int a, b, c;
			tie(a, b, c) = p;
			seg.update(a, b, c);
			seg2.update(a,b,c);
		}
	};
	dodo(100000);

	for (int i = 0; i < M; i++) {
		if (T[i] == 1) dodo(i);
		else {
			long long int ans1 = seg.query(X[i], Y[i]);
			long long int ans2 = seg2.query(X[i], Y[i], X[i]);
			printf("%lld\n", ans2);
		}
	}
	return 0;
}