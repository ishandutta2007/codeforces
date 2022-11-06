#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

int out(int x,bool win) {
	int num;
	if (x == -1) {

	}
	else {
		cout<<x+1<<endl;
		fflush(stdout);
	}
	if (win) {
		exit(0);
	}
	cin>>num;
	return num;
}
signed main() {
	int N,M,C;cin>>N>>M>>C;
	vector<int>v(N,-1);
	int pre=-1;
	
	while (true) {
		bool win=false;
		if (is_sorted(v.begin(), v.end()) && count(v.begin(), v.end(), -1) == 0) {
			win=true;
		}
		int num=out(pre,win);
		num--;
		
		pre=-1;
		if (num < C / 2) {
			for (int i = 0; i < N; ++i) {
				if (v[i] == -1) {
					pre=i;
					break;
				}
				else {
					if (v[i] > num) {
						pre=i;
						break;
					}
				}
			}
		}
		else {
			for (int i = N - 1; i >= 0; --i) {
				if (v[i] == -1) {
					pre = i;
					break;
				}
				else {
					if (v[i] < num) {
						pre = i;
						break;
					}
				}
			}
		}
		assert(pre!=-1);
		v[pre]=num;

	}
	return 0;
}