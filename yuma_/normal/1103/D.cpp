#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
long long int gcd(long long int l, long long int r) {
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);
		}
		else {
			return l;
		}
	}
}

map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}
struct layer {
	long long int a;
	long long int cost;
	vector<long long int>v;
};

#include<unordered_map>
class HashVI {  // 
public:
	size_t operator()(const vector<long long int> &x) const {
		const int C = 997;      // 
		size_t t = 0;
		for (int i = 0; i != x.size(); ++i) {
			t = t * C + x[i];
		}
		return t;
	}
};

template<typename T> struct Compress {
	map<T, int>mp;
	map<int, T>revmp;

	Compress(vector<T>vs) {
		setmp(vs);
	}

	Compress() :mp(), revmp() {

	}
	void setmp(vector<T>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int i = 0; i < static_cast<int>(vs.size()); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}

};

int main()
{
	unordered_map<vector<long long int>, vector<pair<long long int, int>>, HashVI>layer_mp;

	long long int K;
	int LAYER_CNT;
	int PRIME_CNT;
	bool flag=false;
	vector<long long int>last_costs;
	{
		int N;
		scanf("%d %lld", &N, &K);
		if(N==12000)flag=true;
		vector<layer>layers(N);
		for (int i = 0; i < N; ++i) {
			long long int a; scanf("%lld", &a);
			layers[i].a = a;
		}
		for (int i = 0; i < N; ++i) {
			scanf("%lld", &layers[i].cost);
		}

		long long int agcd = layers[0].a;
		for (int i = 1; i<N; ++i)agcd = gcd(agcd, layers[i].a);
		if (agcd == 1) {
			cout<<0<<endl;
			return 0;
		}
		auto div_mp = soinnsuu(agcd);
		 PRIME_CNT = div_mp.size();
		for (int i = 0; i < N; ++i) {
			long long int num = layers[i].a;
			layers[i].v.resize(PRIME_CNT);
			int id = 0;
			for (auto m : div_mp) {
				layers[i].v[id] = 1;
				while (num%m.first == 0) {
					num /= m.first;
					layers[i].v[id] *= m.first;
				}
				id++;
			}
		}
		vector<int>used_ids;
		for (int i = 0; i < N; ++i) {
			layer_mp[layers[i].v];
			auto it = layer_mp.find(layers[i].v);

			it->second.push_back(make_pair(layers[i].cost, i));
			sort(it->second.begin(), it->second.end());
			if (it->second.size()>PRIME_CNT)it->second.pop_back();

		}
		for (auto lm : layer_mp) {
			for (auto p : lm.second) {
				used_ids.push_back(p.second);
			}
		}
		LAYER_CNT=used_ids.size();
		Compress<int> cmp(used_ids);
		last_costs.assign(LAYER_CNT,0);
		for (auto& lm : layer_mp) {
			for (auto& p : lm.second) {
				p.second=cmp.mp[p.second];
				last_costs[p.second]=p.first;
			}
		}

	}
	//if (flag)return 0;

	vector<vector<pair<long long int, int>>>min_costs(1 << PRIME_CNT);

	vector<vector<int>>rev_min_costs(LAYER_CNT);
	{
		for (auto lm : layer_mp) {
			for (int i = 0; i < (1 << PRIME_CNT); ++i) {
				long long int num=1;
				for (int j = 0; j < PRIME_CNT; ++j) {
					if (i&(1 << j)) {
						num*=lm.first[j];
					}
				}
				if (num <= K) {
					for (auto p : lm.second) {
						min_costs[i].push_back(p);
					}
				}
			}
		}
		for (int i = 0; i < (1 << PRIME_CNT); ++i) {
			sort(min_costs[i].begin(),min_costs[i].end());
			while (min_costs[i].size() > PRIME_CNT) {
				min_costs[i].pop_back();
			}
			for (auto mc : min_costs[i]) {
				rev_min_costs[mc.second].push_back(i);
			}
		}
	}
	//if(flag)return 0;
	vector<vector<vector<long long int>>>dp(2,
		vector<vector<long long int>>(1<<PRIME_CNT,vector<long long int>(PRIME_CNT+1,1e18)));
	dp[0][0][0]=0;
	for (int i = 0; i < LAYER_CNT; ++i) {
		int cur=i%2;
		int tar=1-cur;
		for (int j = 0; j < (1 << PRIME_CNT); ++j) {
			for (int k = 0; k <= PRIME_CNT; ++k) {
				dp[tar][j][k]=min(dp[tar][j][k],dp[cur][j][k]);
				if (k != PRIME_CNT) {
					for (auto rmc : rev_min_costs[i]) {
						dp[tar][j^rmc][k + 1] = min(dp[tar][j^rmc][k + 1], dp[cur][j][k] + last_costs[i]);
					}
				}
			}
		}
		for (int j = 0; j < (1 << PRIME_CNT); ++j) {
			for (int k = 0; k <= PRIME_CNT; ++k) {
				dp[cur][j][k]=1e18;
			}
		}
	}
	long long int answer=1e18;
	for (int k = 1; k <= PRIME_CNT; ++k) {
		long long int nanswer=dp[LAYER_CNT%2][(1<<PRIME_CNT)-1][k];
		if (nanswer <= 1e16) {
			answer=min(answer,nanswer*k);
		}
	}
	if(answer>=1e17)answer=-1;
	cout<<answer<<endl;
	return 0;
}