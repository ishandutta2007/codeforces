#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

long long int solve(long long int N,long long int k){
	if(k%2==1){
		return k/2+1;
	}else{
		long long int t=k/2;
		if(N%2==1){

			t--;
			if(t==0)t=N/2;
		}
		return (N+1)/2+solve(N/2,t);
	}
}

int main() { 
	long long int N,K;cin>>N>>K;
	while(K--){
		long long int q;cin>>q;
		long long int ans=solve(N,q);
		cout<<ans<<endl;
	}
	return 0;
}