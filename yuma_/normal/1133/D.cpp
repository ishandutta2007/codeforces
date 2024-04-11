#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
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
signed main() {
	int N;cin>>N;
	vector<int>as(N),bs(N);
	for(int i=0;i<N;++i)cin>>as[i];
	for(int i=0;i<N;++i)cin>>bs[i];

	int answer=0;
	map<pair<int,int>,int>ps;
	for (int i = 0; i < N; ++i) {
		if (as[i] == 0) {
			if (bs[i] == 0) {
				answer++;
			}
		}
		else {
			if (bs[i] == 0) {
				ps[make_pair(0,1)]++;
			}
			else {
				if (as[i] < 0) {
					as[i]=-as[i];
					bs[i]=-bs[i];
				}
				bool flag=false;
				if (bs[i] < 0) {
					flag=true;
					bs[i]=-bs[i];
				}
				int agcd=gcd(as[i],bs[i]);
				as[i]/=agcd;
				bs[i]/=agcd;
				if(flag)bs[i]=-bs[i];
				ps[make_pair(bs[i],as[i])]++;
			}
		}
	}
	int nanswer=0;
	for(auto m:ps)nanswer=max(nanswer,m.second);
	cout<<answer+nanswer<<endl;
	return 0;
}