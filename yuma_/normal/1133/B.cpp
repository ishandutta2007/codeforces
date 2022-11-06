#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


signed main() {
	int N,M;cin>>N>>M;
	vector<int>v(N);
	for(int i=0;i<N;++i)scanf("%d",&v[i]);
	vector<int>vv(M);
	for (int i = 0; i < N; ++i) {
		vv[v[i]%M]++;
	}
	int answer=0;
	for (int i = 0; i <=M/2; ++i) {
		if (i * 2 == M||i==0) {
			answer+=vv[i]/2;
		}
		else {
			answer+=min(vv[i],vv[M-i]);
		}
	}
	cout<<answer*2<<endl;
	return 0;
}