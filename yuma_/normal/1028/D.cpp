#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

const int mod=1e9+7;

int main()
{
	int N;cin>>N;

	set<int>aset{ 0,1000000000 };
	int max_sell=0;
	int min_buy=1000000000;
	long long int answer=1;

	int cnt=0;
	for (int i = 0; i < N; ++i) {
		char chs[10];
		int t;
		scanf(" %s %d",chs,&t);
		string st(chs);
		if (st == "ADD") {
			cnt++;
			aset.emplace(t);
		}
		else if (st == "ACCEPT") {
			cnt=0;
			if (t == max_sell || min_buy == t) {
				
			}
			else if (t < max_sell || min_buy < t) {
				answer=0;
				break;
			}
			else {
				answer*=2;
			}
			aset.erase(t);
			auto it=aset.lower_bound(t);
			max_sell=*prev(it);
			min_buy=*it;
		}
		answer%=mod;
	}
	int num=0;
	for (auto k : aset) {
		if (max_sell < k&&k < min_buy) {
			num++;
		}
	}
	answer*=(num+1);
	answer%=mod;
	cout<<answer<<endl;
	return 0;

}