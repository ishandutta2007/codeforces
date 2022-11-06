#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

vector<vector<long long int>>dp(5001,vector<long long int>(5001,-1e18));

void add(deque<pair<int, long long int>>&que,int a,long long int b) {
	while (!que.empty() && que.back().second < b) {
		que.pop_back();
	}
	que.push_back(make_pair(a,b));
}
int main()
{
	int N,K,X;cin>>N>>K>>X;
	vector<long long int>as(N);
	for(int i=0;i<N;++i)scanf("%lld",&as[i]);

	vector<deque<pair<int,long long int>>>ps(X+1);
	for (int i = 0; i < X; ++i) {
		add(ps[i],K,0);
	}
	for (int i = 0; i < N; ++i) {
		vector<long long int>anss(X+1);
		for (int use_cnt = 0; use_cnt < X; ++use_cnt) {
			long long int n_ans = -1e18;
			if (!ps[use_cnt].empty()) {
				n_ans = ps[use_cnt].front().second + as[i];
			}
			anss[use_cnt+1]=n_ans;

		}
		for (int use_cnt = 1; use_cnt <= X; ++use_cnt) {
			add(ps[use_cnt], K + i + 1, anss[use_cnt]);
		}
		for (int use_cnt = 0; use_cnt <= X; ++use_cnt) {
			if (ps[use_cnt].size() && ps[use_cnt].front().first == i + 1) {
				ps[use_cnt].pop_front();
			}
		}
		
	}
	long long int answer=ps[X].size()?ps[X].front().second:-1;
	if(answer<-1e16)answer=-1;
	cout<<answer<<endl;
	
	return 0;
}