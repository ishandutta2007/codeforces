#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

long long int answer=0;
long long int  dfs(vector<vector<int>>&edges,vector<int>&sums,const int now, int k) {

	vector<int>v;
	for (auto e : edges[now]) {
		auto ak=dfs(edges,sums,e,k);
		if(ak==-1)continue;
		v.push_back(ak);
	}

	if (sums[now] == -1) {
		long long int min_num=0;
		if (!v.empty()) {
			min_num = *min_element(v.begin(), v.end());
			answer += accumulate(v.begin(), v.end(), 0ll) - min_num*v.size();
			return min_num;

		}
		else {
			return -1;
		}
	}
	else {
		long long int min_num = 0;
		if (!v.empty()) {
			min_num = *min_element(v.begin(), v.end());
			if (min_num < sums[now]) {
				answer=-1e18;
				return 0;
			}
			else {
				answer += accumulate(v.begin(), v.end(), 0ll) -sums[now]*static_cast<long long int>(v.size());

			}
			return sums[now];
		}
		else {
			return sums[now];
		}
	}
}
int main()
{
	int N;cin>>N;
	vector<vector<int>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int a;
		scanf("%d",&a);
		a--;
		edges[a].push_back(i+1);

	}
	vector<int>sums(N);
	for(int i=0;i<N;++i)scanf("%d",&sums[i]);
	long long int mm=dfs(edges,sums,0,0);
	answer+=mm;
	if (answer < -1e17) {
		answer=-1;
	}
	cout<<answer<<endl;

	return 0;
}