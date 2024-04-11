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
	long long int W;cin>>W;
	vector<long long int>nums(8);
	for(int i=0;i<8;++i)cin>>nums[i];

	long long int sum=0;
	for (int i = 0; i < 8; ++i) {
		sum+=nums[i]*(i+1);
	}
	long long int answer = -1;

	if (sum <= W) {
		answer=sum;
	}
	else {
		long long int rest=W;
		answer=0;
		for (int i = 0; i < 8; ++i) {
			long long int x=840/(i+1);
			long long int tt=min(rest/840-3,nums[i]/x-3);
			if (tt >0) {
				nums[i]-=tt*x;
				rest-=tt*840;
				answer+=tt*840;
			}
		}
		vector<vector<int>>oks(9, vector<int>(10000));
		oks[0][0] = true;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 10000; ++j) {
				if (oks[i][j]) {
					for (int num = 0; num <= min(10000ll, nums[i]); ++num) {
						int x = j + num*(i + 1);
						if (x < 10000) {
							oks[i + 1][x] = true;
						}
						else {
							break;
						}
					}
				}
			}
		}
		long long int nanswer=0;
		for (int i = 0; i < 100000; ++i) {
			if(rest>=i&&oks[8][i])nanswer=i;
		}
		answer+=nanswer;
	}
	cout<<answer<<endl;
//\n
	return 0;
}