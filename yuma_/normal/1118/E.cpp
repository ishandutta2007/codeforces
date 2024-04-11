#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



int main() {
	long long int N,M;cin>>N>>M;
	if (M*(M - 1) < N) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		vector<pair<int,int>>anss;
		for (int sa = 1; sa < M; ++sa) {
			for (int l = 0; l < M; ++l) {
				if (anss.size() == N)break;

				int r=l+sa;
				r%=M;
				anss.emplace_back(l,r);
			}
		}
		for (int i = 0; i < N; ++i) {
			printf("%d %d\n",anss[i].first+1,anss[i].second+1);
		}
	}
	return 0;
}