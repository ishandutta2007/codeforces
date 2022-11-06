#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;


int main() {
	set<int>oks;
	oks.emplace(0);
	long long int N;cin>>N;
	if (N <= 29) {
		for (int i = 0; i < N; ++i) {
			set<int>nextoks;
			for (auto o : oks) {
				vector<int>nums{ 1,5,10,50 };
				for (int i = 0; i < 4; ++i) {
					nextoks.emplace(o + nums[i]);

				}

			}
			oks = nextoks;
			//cout << i << " : " << nextoks.size() << endl;
		}
		cout<<oks.size()<<endl;
	}
	else {
		cout<<49*N-247<<endl;
	}
	
	
	return 0;
}