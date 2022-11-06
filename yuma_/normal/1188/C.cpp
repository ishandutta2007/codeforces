#include<bits/stdc++.h>
using namespace std;

const long long int mod=998244353;
vector<vector<long long int>>dp;
vector<vector<long long int>>dp2;


long long int solve(const vector<int>&v,int K,int sa){
	
	vector<int>rs(v.size());
	int N=v.size();
	for(int i=0;i<=N;++i){
		for(int j=0;j<=K;++j){
			dp[i][j]=0;
			dp2[i][j]=0;
		}
	}
	int r=0;
	for(int l=0;l<v.size();++l){
		while(true){
			if(r==N||v[l]+sa<=v[r]){
				rs[l]=r;
				break;
			}else{
				r++;
			}
		}
	}
	
	for(int i=0;i<N;++i){
		dp[i][1]=1;
	}
	for(int i=0;i<N;++i){
		for(int j=1;j<=K;++j){
			dp[i][j]+=dp2[i][j];
			dp2[i+1][j]+=dp2[i][j];
			if(j!=K){
				dp2[rs[i]][j+1]+=dp[i][j];
				dp2[rs[i]][j+1]%=mod;
			}
		}
	}
	long long int sum=0;
	for(int i=0;i<N;++i){
		sum+=dp[i][K];
	}
	return sum%mod;
}



int main() {
	int N;cin>>N;
	int K;cin>>K;
	
	dp=vector<vector<long long int>>(N+1,vector<long long int>(K+1));
	dp2=vector<vector<long long int>>(N+1,vector<long long int>(K+1));

	vector<int>v(N);
	for(int i=0;i<N;++i){
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.end());
	vector<long long int>sums(100000/(K-1)+4);
	for(int sa=1;sa<=100000/(K-1)+3;++sa){
		sums[sa]=solve(v,K,sa);
	}
	long long int answer=0;	
	for(int sa=1;sa<100000/(K-1)+3;++sa){
		long long int num=sums[sa]-sums[sa+1];
		//if(sa<10)cout<<sums[sa]<<endl;
		answer+=num*sa;
		answer%=mod;
	}
	cout<<answer<<endl;
	return 0;
}