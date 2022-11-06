#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

int main() {
	int N,K;cin>>N>>K;
	vector<int>v(N);
	for (int i = 0; i < N; ++i) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int ans=0;
	int sum=0;
	int num=0;
	for (int i = 3e5; i >= 0; --i) {
		while (!v.empty()&&v.back() == i) {
			num++;
			v.pop_back();
		}
		if (num == N) {
			if (sum)ans++;
			sum = 0;
			break;
		}
		else {
			if (sum + num > K) {
				ans++;
				sum=num;
			}
			else {
				sum+=num;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}