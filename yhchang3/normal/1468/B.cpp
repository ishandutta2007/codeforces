#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<long long> sum(n);
	multiset<int> lenset;
	set<int> alive;
	for(int i=0;i<n;i++)
		cin >> a[i], lenset.insert(1), alive.insert(i), sum[i] = a[i] + (i == 0 ? 0 : sum[i - 1]);
	auto qint = [&](const int& l, const int& r) -> int {
		return (sum[r - 1] - (l == 0 ? 0 : sum[l - 1]) - 1)/ (r - l);	
	};
	vector<int> queries(m);
	priority_queue<tuple<int,int,int>> pq;
	for(int i=0;i+1<n;i++)
		pq.emplace(qint(i, i + 1), i, i + 1);
	for(int i=0;i<m;i++)
		cin >> queries[i];
	reverse(queries.begin(), queries.end());
	vector<int> ans;
	for(int tar:queries) {
		while(!pq.empty() && get<0>(pq.top()) >= tar) {
			auto [x, y, z] = pq.top();pq.pop();
			if(!alive.count(y) || !alive.count(z))	continue;
			alive.erase(z);
			lenset.erase(lenset.find(z - y));
			int rb = n;
			if(y != *alive.rbegin())
				rb = *next(alive.find(y));
			lenset.erase(lenset.find(rb - z));
			lenset.insert(rb - y);
			if(rb != n)
				pq.emplace(qint(y, rb), y, rb);
		}
		ans.emplace_back(*lenset.rbegin() - 1);
	}
	for(int i=m-1;i>=0;i--)
		cout << ans[i] << ' ';
	cout << endl;
	
}