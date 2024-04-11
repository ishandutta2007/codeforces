#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



int main() {
	int N,K;cin>>N>>K;
	set<int>aset;
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d", &a);
		aset.emplace(a);
	}
	int pre=0;
	for (int i = 0; i < K; ++i) {
		int answer;
		if (aset.empty()) {
			answer=0;
		}
		else {
			auto it=aset.begin();
			answer=*it-pre;
			pre=*it;
			aset.erase(it);
		}
		printf("%d\n",answer);
	}
	return 0;
}