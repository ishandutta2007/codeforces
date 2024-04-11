#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
using namespace std;
//using namespace std;
//
//int N;
//int bit[1000010];
//void add(int a,int w) {
//	for	(int x = a; x <= N; x += x &-x)
//		bit[x] += w;
//
//}
//int sum(int a) {
//	int	ret = 0;
//	for	(int x = a; x > 0; x-= x &-x)
//		ret += bit[x];
//	return ret;
//}
//
//int main() {
//	cin >> N;
//	vector<int>lengths;
//	for (int i = 0; i < N; ++i) {
//		int l; cin >> l;
//		lengths.push_back(l);
//	}
//	vector<pair<int, vector<int>>>Nodes(N);
//	Nodes[0].first = lengths[0];
//	for (int i = 1; i < N; ++i) {
//		int p; cin >> p;
//		p--;
//		Nodes[i].first = Nodes[p].first + lengths[i];
//		Nodes[p].second.push_back(i);
//	}
//	vector<int>heights;
//	for (int i = 0; i < N; ++i) {
//		heights.emplace_back(Nodes[i].first);
//	}
//	sort(heights.begin(), heights.end());
//	heights.erase( unique(heights.begin(), heights.end()),heights.end());
//	for (int i = 0; i < N; ++i) {
//		auto it = find(heights.begin(), heights.end(), Nodes[i].first);
//		Nodes[i].first = abs(distance(it, heights.begin()));
//	}
//
//	map<int, int>compress;
//	for (auto it = heights.begin(); it != heights.end();++it) {
//		compress[*it] = abs(distance(it , heights.begin()));
//	}
//	vector<int>m_h(N);
//	for (int i = N - 1; i >= 0; i--) {
//		int nmh = Nodes[i].first;
//		for (auto it : Nodes[i].second) {
//			nmh = max(nmh, m_h[it]);
//		}
//		m_h[i] = nmh;
//	}
//	for (int i = 0; i < 1000010; ++i) {
//		bit[i] = 0;
//	}
//	int q; cin >> q;
//	for (int i = 0; i < q; ++i) {
//		int h; cin >> h;
//		int ans = 0;
//		if (compress.count(h)) {
//			int ch = compress[h];
//			vector<int> nodeid (1,0);
//			while(!nodeid.empty()) {
//				int nid = nodeid.back();
//				nodeid.pop_back();
//				if (Nodes[nid].first > ch) {
//					ans++;
//				}
//				else {
//					for (auto it : Nodes[nid].second) {
//						if (m_h[it] > ch) {
//							nodeid.emplace_back(it);
//						}
//					}
//				}
//			}
//			cout << ans << endl;
//		}
//		else {
//			cout << -1 << endl;
//		}
//	}
//
//
//
//	return 0;
//}


long long int dp[31][31][51];

long long int getans(int n, int m, int k) {
	if (n > m) {
		return getans(m, n, k);
	}
	else {
		if (dp[n][m][k] == -1) {
			if (k == 0)return 0;
			if (n*m == k)return 0;
			if (n*m < k)return 1e20;
			long long int ans = 1e20;
			for (int j = 0; j <= k; ++j) {
				for (int i = 1; i < n; ++i) {
					ans = min(ans, getans(i, m, j) + getans(n - i, m, k - j)+m*m);
				}
				for (int i = 1; i < m; ++i) {
					ans = min(ans, getans(n, i, j) + getans(n, m-i, k - j)+n*n);
				}
			}
			return dp[n][m][k] = ans;
		}
		else {
			return dp[n][m][k];
		}
	}
}

int main()
{
	int p;
	cin >> p;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < p; ++i) {
		int n, m, k;
		cin >> n>>m>>k;
		long long int ans = getans(n, m, k);
		cout << ans << endl;
	}
	
	
	return 0;
}