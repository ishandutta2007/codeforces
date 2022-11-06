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

bool check(vector<int>v, long long int h) {
	for (int i = v.size() - 1; i >= 0; i -= 2) {
		h-=v[i];
	}
	return h>=0;
}

int main() {
//\n
	int N;long long H;cin>>N>>H;
	vector<int>v(N);
	int ans=N;
	for (int i = 0; i < N; ++i) {
		cin>>v[i];
		sort(v.begin(),v.begin()+i+1);
		vector<int>x(v.begin(),v.begin()+i+1);
		if (check(x, H)) {

		}
		else {
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}