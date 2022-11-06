#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
//for CodeForces
#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;



int main() {
//\n
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)scanf("%d",&v[i]);

	vector<pair<int, int>>ls{ make_pair(0,v[0]),make_pair(-1,-1) };
	vector<pair<int, int>>rs{ make_pair(N-1,v[N-1]),make_pair(-1,-1) };


	for (int i = 1; i < N; ++i) {
		if (v[i] != v[0]) {
			ls[1] = make_pair(i, v[i]);
			break;
		}
	}
	for (int i = N - 2; i >= 0; --i) {
		if (v[i] != v[N-1]) {
			rs[1]=make_pair(i,v[i]);
			break;
		}
	}
	int ans=0;
	if (ls[0].second == rs[0].second) {
		ans=max(ans,rs[1].first-ls[0].first);
		ans=max(ans,rs[0].first-ls[1].first);
	}
	else {
		ans=max(ans,rs[0].first-ls[0].first);
	}
	cout<<ans<<endl;
	return 0;
}