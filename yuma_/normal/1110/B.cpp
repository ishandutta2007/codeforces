#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


int main() {

	int N,M,K;cin>>N>>M>>K;
	vector<int>as(N);
	for(int i=0;i<N;++i)scanf("%d",&as[i]);
	vector<int>sas;
	for(int i=0;i<=N-2;++i)sas.push_back(as[i+1]-as[i]);
	sort(sas.begin(),sas.end());
	int answer=accumulate(sas.begin(),sas.begin()+(N-K),0);
	answer+=K;
	cout<<answer<<endl;
	return 0;
}