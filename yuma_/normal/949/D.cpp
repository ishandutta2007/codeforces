#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

int solve(vector<int>&v,int t,int M,int K){
	int sum=0;
	int now=0;

	int ans=0;
	for(int i=0;i<t;++i){
		for(int k=0;(k<K)&&now!=v.size();++k){
			sum+=v[now];
			now++;
		}
		if(sum<M){
			ans++;
		}else{
			sum-=M;
		}
	}
	return ans;
}
int main() { 
	int N,D,B;cin>>N>>D>>B;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];

	int x1=solve(v,(N+1)/2,B,1+D);
	reverse(v.begin(),v.end());
	int x2=solve(v,(N)/2,B,1+D);
	reverse(v.begin(),v.end());

	cout<<max(x1,x2)<<endl;
	return 0;
}