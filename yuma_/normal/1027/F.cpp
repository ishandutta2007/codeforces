#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


template<typename T> struct Compress {
	map<T, int>mp;
	//map<int, T>revmp;

	Compress(vector<T>vs) {
		setmp(vs);
	}

	Compress() :mp() {

	}
	void setmp(vector<T>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int i = 0; i < static_cast<int>(vs.size()); ++i) {
			mp[vs[i]] = i;
			//revmp[i] = vs[i];
		}
	}

};

int dfs(const vector<vector<int>>&edges, vector<bool>&used, const int now, const int lim) {
	int cnt = -2;
	used[now] = 1;

	for (int i = 0; i<edges[now].size(); ++i) {
		auto e = edges[now][i];
		if (e > lim) {
			cnt += 2 * (edges[now].size() - i);
			break;
		}
		else if (used[e]) {
			cnt += 1;
		}
		else {
			cnt++;
			cnt += dfs(edges, used, e, lim);
		}
	}
	return cnt;

}

bool solve(const vector<vector<int>>&edges, int lim) {
	vector<bool>used(lim + 1);
	for (int i = 0; i <= lim; ++i) {
		if (!used[i]) {
			int k = dfs(edges, used, i, lim);
			assert(k % 2 == 0);
			if (k >= 2)return false;
		}
	}
	return true;
}

int main() {
	int N; scanf("%d", &N);
	vector<pair<int, int>>ps;
	vector<int>v;
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ps.emplace_back(a, b);
		v.push_back(a);
		v.push_back(b);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	Compress<int>comp;
	comp.setmp(v);
	for (auto&p : ps) {
		p.first = comp.mp[p.first];
		p.second = comp.mp[p.second];
	}
	vector<vector<int>>edges(comp.mp.size());
	for (auto p : ps) {
		edges[p.first].push_back(p.second);
		edges[p.second].push_back(p.first);
	}
	for (auto&es : edges) {
		sort(es.begin(), es.end());
	}

	int amin = -1;
	for (auto p : ps) {
		amin = max(amin, min(p.first, p.second) - 1);
	}
	int amax = edges.size();
	while (amin + 1 != amax) {
		int amid((amin + amax) / 2);
		if (solve(edges, amid)) {
			amax = amid;
		}
		else {
			amin = amid;
		}
	}
	if (amax == edges.size()) {
		printf("-1\n");
	}
	else {
		 printf("%d\n",v[amax]);
	}
	return 0;

}