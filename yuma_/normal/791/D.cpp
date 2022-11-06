#include "bits/stdc++.h"
using namespace std;

struct aa {
	long long int sum;
	long long int asize;
	long long int len;
	vector<long long int>rema_nums;
};

aa getans(const vector<vector<int>>&edges,const int now, const int from, const int K) {
	aa ans{ 0,1,0,vector<long long int>(K) };
	ans.rema_nums[0] = 1;
	for (auto e : edges[now]) {
		if (e == from)continue;
		else {
			auto p(getans(edges, e, now, K));

			aa nextans(ans);
			for (int i = 0; i < K; ++i) {
				for (int j = 0; j < K; ++j) {
					int rema = (i + j) % K;
					if (i + j >= K+1) {
						nextans.sum += 2*ans.rema_nums[j] * p.rema_nums[i];
					}
					else if(i+j){
						nextans.sum += ans.rema_nums[j] * p.rema_nums[i];
					}
				}
				nextans.rema_nums[i] += p.rema_nums[i];
			}
			nextans.sum += p.asize*ans.len;
			nextans.sum += p.len*ans.asize;
			nextans.len += p.len;
			nextans.sum += p.sum;
			nextans.asize += p.asize;

			ans = nextans;
		}
	}
	ans.len += ans.rema_nums[K - 1];
	rotate(ans.rema_nums.begin(), ans.rema_nums.begin() + K-1, ans.rema_nums.end());
	return ans;
}

int main() {
	int N, K; cin >> N >> K;
	vector<vector<int>>edges(N, vector<int>());
	for (int i = 0; i < N - 1; ++i) {
		int a, b; cin >> a >> b; a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);

	}
	 auto ans=getans( edges,0, -1,K);
	 cout << ans.sum << endl;
	return 0;
}