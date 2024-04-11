#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld =long double;


int main() {
	int N;cin>>N;
	vector<pair<int,int>>ps(N-1);
	for (int i = 0; i < N - 1; ++i) {
		int a,b;cin>>a>>b;a--;b--;
		if(a>b)swap(a,b);
		ps[i]=make_pair(a,b);
	}
	bool ok=true;
	for (int i = 0; i < N-1; ++i) {
		if(ps[i].second!=N-1)ok=false;
	}
	vector<int>v(N-1);
	for (int i = 0; i < N - 1; ++i) {
		if(ps[i].first==N-1)ok=false;
		else {
			v[ps[i].first]++;
		}
	}
	vector<int>unused;
	for (int i = 0; i < N - 1; ++i) {
		if(!v[i])unused.push_back(i);
	}
	vector<int>nums(1,N-1);
	for (int i = 1; i < N; ++i) {
		int k=v[N-1-i];
		if(k==0)continue;
		int now_num=N-i-1;
		for (int j = 0; j < k-1; ++j) {
			int ax=unused.back();
			if (ax > now_num) {
				ok=false;
				break;
			}
			nums.push_back(unused.back());
			unused.pop_back();
		}
		nums.push_back(now_num);
	}
	if (ok) {
		cout<<"YES"<<endl;
		for (int i = 0; i < N - 1; ++i) {
			int a=nums[i]+1;
			int b=nums[i+1]+1;
			cout<<a<<" "<<b<<endl;
		}
	}
	else {
		cout<<"NO"<<endl;
	}

 	return 0;
}