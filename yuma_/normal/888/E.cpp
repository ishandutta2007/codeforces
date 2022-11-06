#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

int N;
long long int M;
vector<long long int>get(vector<long long int>&ns) {
	vector<long long int>ans;
	for (int i = 0; i < (1 << (ns.size())); ++i) {
		bitset<30>bs(i);
		long long int sum = 0;
		for (int j = 0; j < ns.size(); ++j) {
			sum += ns[j]*bs[j];
		}
		ans.push_back(sum%M);
	}
	return ans;
}
int main() { cin >> N >> M;
	vector<long long int>as, bs;
	{
		vector<long long int>ns(N);
		for (int i = 0; i < N; ++i)cin >> ns[i];
		int k = 20;
		if (N <= k) {
			as = ns;
			
		}else{
			as = vector<long long int>(ns.begin(),ns.begin() + k);
			bs = vector<long long int>(ns.begin() + k, ns.end());
		}
	}
	auto aans(get(as));
	auto bans(get(bs));
	sort(bans.begin(), bans.end());
	long long int ans = 0;
	for (auto aa : aans) {
		auto it = lower_bound(bans.begin(), bans.end(), M - aa);
		
		if (it != bans.end()) {
			ans = max(ans, aa + *prev(it));
		}
		else {
			ans = max(ans, (aa + bans.back())%M);
		}
	}
	cout << ans << endl;
	
	return 0;
}