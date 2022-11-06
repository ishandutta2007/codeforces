#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;




int main()
{
	long long int N,K;cin>>N>>K;

	vector<pair<long long int ,int>>as;
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		if (a == 1 &&!as.empty()&& as.back().first == 1) {
			as.back().second++;
		}
		else {
			as.push_back(make_pair(a,1));
		}
	}
	long long int ans=0;
	for (int l = 0; l < as.size(); ++l) {
		long long int pro=1;
		long long int min_sum=0,max_sum=0;
		pro=as[l].first;
		max_sum=as[l].second*as[l].first;
		min_sum=as[l].first;

		if (K == 1) {
			ans+=as[l].second;
		}

		for (int x = l + 1; x < as.size(); ++x) {
			auto p=as[x];
			if (p.first == 1) {
				if (pro%K == 0 && min_sum + 1 <= pro / K&&pro / K <= max_sum + p.second) {

					const long long int need = pro / K - min_sum+1;
					const int l_min=max(1ll,need-p.second);
					const int l_max=min(need-1,max_sum-min_sum+1);

					const int r_min=1;
					const int r_max=p.second;

					ans+=l_max-l_min+1;
				}
				min_sum+=p.second;
				max_sum+=p.second;
			}
			else {
				ld d=ld(pro)*p.first;
				if (d >= 2 * 1e18) {
					break;
				}
				else {
					pro*=p.first;
					min_sum+=p.first;
					max_sum+=p.first;

					if (pro%K == 0 && min_sum <= pro / K&&pro / K <= max_sum) {
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}