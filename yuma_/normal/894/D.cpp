#include "bits/stdc++.h"
using namespace std;

long long int solve(int now, long long int rest,const vector<vector<int>>&qs,const vector<vector<long long int>>&sums) {
	auto it=upper_bound(qs[now].begin(),qs[now].end(),rest);
	long long int ans=0;
	ans=rest*(it-qs[now].begin())-sums[now][it-qs[now].begin()];
	return ans;
}

int main() { 
	int N,M;cin>>N>>M;
	vector<int>ls(N);
	for (int i = 0; i < N - 1; ++i) {
		int x;
		scanf("%d",&x);ls[i+1]=x;
	}
	vector<vector<int>>qs(N);
	for (int i = N - 1; i >= 0; --i) {
		if (i * 2+1>=N) {
			qs[i] = vector<int>{ 0 };
		}
		else if (i * 2 + 1 == N - 1) {
			qs[i] = vector<int>{ 0,ls[N - 1] };
		}else{
			vector<int>lv(qs[i*2+1]);
			for_each(lv.begin(), lv.end(), [&](int &a) { a += ls[i * 2 + 1];});
			vector<int>rv(qs[i*2+2]);
			for_each(rv.begin(), rv.end(), [&](int &a) {a += ls[i * 2 + 2]; });

			vector<int>nextv{ 0 };
			auto it=lv.begin();
			auto jt=rv.begin();
			while (it!=lv.end()||jt!=rv.end()) {
				if (it == lv.end()) {
					nextv.emplace_back(*jt);
					jt++;
				}
				else if (jt == rv.end()) {
					nextv.emplace_back(*it);
					it++;
				}else{
					if (*jt < *it) {
						nextv.emplace_back(*jt);
						jt++;
					}else{
						nextv.emplace_back(*it);
						it++;
					}
				}
			}
			qs[i]=nextv;
		}
	}
	vector<vector<long long int>>sums(N);
	for (int j=0;j<N;++j) {
		auto&sum=sums[j];
		sum.insert(sum.begin(),0);
		for (int i = 0; i < qs[j].size(); ++i) {
			sum.push_back(sum.back()+qs[j][i]);
		}
	}
	while (M--) {
		int a,b;cin>>a>>b;
		a--;
		long long int ans=0;
		int now(a);
		int rest(b);

		ans += solve(now, rest, qs, sums);
		while (now) {
			const int next=now%2?now+1:now-1;
			rest -= ls[now];
			if(rest>0)ans+=rest;
			if (next < N) {
				ans += solve(next, rest - ls[next], qs, sums);
			}else{
				ans+=0;
			}
			now=(now-1)/2;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}