#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
////

int main()
{
	int N;cin>>N;
	string st;cin>>st;
	vector<vector<long long int>>dp(N+1,vector<long long int>(5,1e18));
	dp[0][0]=0;
	vector<long long int>as(N);
	for(int i=0;i<N;++i)cin>>as[i];
	string hard="hard";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 5; ++j) {
			bool flag=false;
			if (j < 4) {
				if (st[i] == hard[j]) {
					flag=true;
				}
			}
			if (flag) {
				
				dp[i+1][j]=min(dp[i][j]+as[i],dp[i+1][j]);
				dp[i+1][j+1]=min(dp[i][j],dp[i+1][j+1]);
			}
			else {
				dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
			}
		}
	}

	long long int answer=1e18;
	for(int i=0;i<4;++i)answer=min(answer,dp[N][i]);
	cout<<answer<<endl;
	return 0;
}