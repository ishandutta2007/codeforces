#include "bits/stdc++.h"
using namespace std;

int solve(const vector<int>&difs,const int K) {
	queue<pair<int, int>>que;
	que.emplace(0, 0);
	vector<int>memo(2001,1e7);
	int ans = -1;
	while (!que.empty()) {
		auto atop(que.front());
		que.pop();
		const int nowtime = atop.first;
		const int nowplus = atop.second;
		if (nowplus == 0&&nowtime) {
			ans = nowtime;
			break;
		}
		for (int i = 0; i <= 1000; ++i) {
			if (difs[i]) {
				const int nextplus = atop.second + i - K;
				if (nextplus >=-1000 && nextplus<=1000) {
					if (memo[nextplus + 1000] > nowtime + 1) {
						memo[nextplus + 1000] = nowtime + 1;
						que.emplace(nowtime + 1, nextplus);
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int N, K; cin >> N >> K;
	vector<int>difs(1001);
	for (int i = 0; i < K; ++i) {
		int a; scanf("%d", &a);
		difs[a] = true;
	}
	int ans=solve(difs, N);
	cout << ans << endl;
	return 0;
}