#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int memo[5001][5001];

int solve(vector<int>&v,int l,int r) {
	if(memo[l][r])return memo[l][r];
	if (l + 1 == r) {
		memo[l][r]=1;
	}
	else {
		assert(l+2<=r);
		if (v[l] == v[r - 1]) {
			memo[l][r]=1+solve(v,l+1,r-1);
		}
		else {
			memo[l][r]=1+min(solve(v,l,r-1),solve(v,l+1,r));
		}
	}
	return memo[l][r];

}
#include<random>

int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	{
		vector<int>nv;
		int pre=-1;
		for (int i = 0; i < N; ++i) {
			if(pre!=v[i])nv.push_back(v[i]);

			pre=v[i];
		}
		v=nv;
	}
	int answer=solve(v,0,v.size());
	cout<<answer-1<<endl;
	return 0;
}