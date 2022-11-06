#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

long long int solve(int N,vector<long long int>&sums,int S,int F,int time){
	//10000 10 100 1000
	return sums[F+time]-sums[S+time];
	
}

int main() { 
	long long int N;cin>>N;
	vector<long long int>as(N);
	vector<long long int>sums(2*N+1);
	for(int i=0;i<N;++i){
		cin>>as[i];
		sums[i+1]=sums[i]+as[i];
	}
	for(int i=0;i<N;++i){
		sums[N+i+1]=sums[N+i]+as[i];
	}
	int S,F;cin>>S>>F;
	S--;F--;

	long long int ans=-1;
	int ans_start_time=-1;
	for(int t=0;t<N;++t){
		long long int nans=solve(N,sums,S,F,N-t);
		if(ans<nans){
			ans=nans;
			ans_start_time=t;
		}

	}
	cout<<ans_start_time+1<<endl;
	return 0;

}