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
int main() {
	int N;cin>>N;
	vector<long long int>hs(N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld",&hs[i]);
	}
	vector<vector<vector<long long int>>>dps(2,vector<vector<long long int>>(N+3,vector<long long int>(3,1e18)));
	dps[0][0][0]=0;
	for (int i = 0; i < N; ++i) {
		int cur=i%2;
		int tar=1-cur;
		for (int num = 0; num <= N; ++num) {
			for (int status = 0; status < 3; ++status) {
				if(dps[cur][num][status]>=1e17)continue;
				int pp_select=status%2;
				int p_select=status/2;

				if (p_select) {
					dps[tar][num][1]=min(dps[tar][num][1],dps[cur][num][status]+max(0ll,hs[i]-hs[i-1]+1));
				}
				else if (pp_select) {
					long long int p_h=min(hs[i-1],i<2?(1ll<<50):hs[i-2]-1);
					dps[tar][num+1][2]=min(dps[tar][num+1][2],dps[cur][num][status]+max(0ll,p_h-hs[i]+1));

					dps[tar][num][0]=min(dps[tar][num][0],dps[cur][num][status]);
				}
				else {
					dps[tar][num+1][2]=min(dps[tar][num+1][2],dps[cur][num][status]+max(0ll,i==0?0:hs[i-1]-hs[i]+1));
				
					dps[tar][num][0] = min(dps[tar][num][0], dps[cur][num][status]);
				}
			}
		
		}
		for (int num = 0; num <= N; ++num) {

			for (int status = 0; status < 3; ++status) {
				dps[cur][num][status] = 1e17;
			}
		}
	}

	vector<long long int>answers((N+3)/2,1e18);
	for (int i = 0; i < answers.size(); ++i) {
		for (int status = 0; status < 3; ++status) {
			answers[i] = min(answers[i], dps[(N) % 2][i][status]);
		}
	}
	for (int i = 0; i < answers.size() - 1; ++i) {
		answers[answers.size()-i-2]=min(answers[answers.size()-i-2],answers[answers.size()-i-1]);
	}
	for (int i = 1; i < answers.size(); ++i) {
		printf("%lld ",answers[i]);
	}
	cout<<endl;
	return 0;
}