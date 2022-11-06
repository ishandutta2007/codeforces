#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
void out(vector<vector<int>>&v) {
	if (v.empty()) {
		cout<<"NO"<<endl;
		return ;
	}
	else {
		cout<<"YES"<<endl;
	}
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			cout<<v[i][j]+1;
			if(j==v[i].size()-1)cout<<endl;
			else cout<<" ";
		}
	}
}
vector<vector<int>>sw(vector<vector<int>>&v) {
	if(v.empty())return v;
	vector<vector<int>>ret(v[0].size(),vector<int>(v.size()));
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[0].size(); ++j) {
			int num=v[i][j];
			int y=num/v[0].size();
			int x=num%v[0].size();
			ret[j][i]=x*v.size()+y;
		}
	}
	return ret;
}
int main() {
	int N,M;cin>>N>>M;
	bool flag=false;
	if (N > M) {
		flag=true;
		swap(N,M);
	}
	assert(N<=M);
	vector<vector<int>>ans(N,vector<int>(M));
	if (N == 1) {
		if (M == 1) {
			ans[0][0]=0;
		}
		else if (M == 2 || M == 3) {
			ans=vector<vector<int>>(0);
		}
		else if (M == 4) {
			ans = vector<vector<int>>(1, vector<int>{2, 0, 3, 1});
		}
		else {
			for (int i = 0; i < (M + 1) / 2; ++i) {
				ans[0][2*i]=i;

			}
			for (int i = 0; i < M / 2; ++i) {
				ans[0][2*i+1]=i+(M+1)/2;
			}
		}
	}
	else if (N == 2) {
		if (M == 2 || M == 3) {
			ans.clear();
		}
		else {
			for (int i = 0; i < M; ++i) {
				ans[i%2][i]=i;
			}
			for (int i = 0; i < M; ++i) {
				ans[(i+1)%2][i]=M+(i+M-2)%M;
			}
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				const int x=j;
				const int y=(i+j)%N;
				ans[y][x]=i*M+(j+M-i)%M;
			}
		}
	}

	if (flag) {
		ans=sw(ans);
	}
	out(ans);
	return 0;
}