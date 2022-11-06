#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;


int main() {
	
	vector<int>oks(101,true);
	int N;scanf("%d",&N);
	for (int i = 0; i < N; ++i) {
		int K;cin>>K;
		vector<int>aoks(101);
		for (int j = 0; j < K; ++j) {
			int a;scanf("%d",&a);
			aoks[a]=true;
		}
		for (int j = 0; j < 101; ++j) {
			if(!aoks[j])oks[j]=false;
		}
	}
	vector<int>anss;
	for (int j = 1; j < 101; ++j) {
		if(oks[j])anss.push_back(j);
	}
	for (int i = 0; i < anss.size(); ++i) {
		printf("%d",anss[i]);
		if(i==anss.size()-1)cout<<endl;
		else printf(" ");
	}
	return 0;
}