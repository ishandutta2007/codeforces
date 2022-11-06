#include <bits/stdc++.h>
using namespace std;

struct good{
	int id;
	long long int before;
	long long int after;
	vector<int>edges;
};


vector<vector<long long int>> dfs(const int now,const vector<good>&goods){
	vector<vector<vector<long long int>>>dps;
	int t=2;
	
	vector<vector<long long int>>dp(2,vector<long long int>(2,1e18));
	dp[0][0]=0;
	dp[1][0]=goods[now].before;
	dp[1][1]=goods[now].after; 

	int m=2;
	for(auto e:goods[now].edges){
		auto adp(move(dfs(e,goods)));
		for(int i=0;i<adp.size()-1;++i){
			dp.push_back(vector<long long int>(2,1e18));
		}
		for(int i=m-1;i>=0;--i){
			for(int j=adp.size()-1;j>=0;--j){
				dp[i+j][1]=min(dp[i+j][1],dp[i][1]+min(adp[j][0],adp[j][1]));
				dp[i+j][0]=min(dp[i+j][0],dp[i][0]+adp[j][0]);
			}
		}
		m+=adp.size()-1;
	}
	
	return dp;
}

int main() {
	int N;cin>>N;
	vector<good>goods;
	long long int B;cin>>B;
	for(int i=0;i<N;++i){
		long long int d,c;cin>>d>>c;
		goods.push_back(good{i,d,d-c,vector<int>()});
		if(i){
			int a;cin>>a;
			a--;
			goods[a].edges.push_back(i);
		}
	}
	int k=0;
	auto ans=dfs(0,goods);
	for(int i=0;i<ans.size();++i){
		for(int j=0;j<2;++j){
			if(ans[i][j]<=B)k=i;
		}
	}
	
	cout<<k<<endl;
	return 0;
}