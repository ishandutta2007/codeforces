#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ll=long long ;
#define Whats(x) cout<<#x<<" is "<<(x)<<endl

int dfs(int now,const vector<int>&types, const vector<vector<int>>&chs, int X) {
	if (chs[now].empty()) {
		return 1;
	}
	else {
		int need=0;
		if (types[now] == 0) {
			for (auto ch : chs[now]) {
				need+=dfs(ch,types,chs,X);
			}
		}
		else {
			need=1e9;
			for (auto ch : chs[now]) {
				need=min(need,dfs(ch,types,chs,X));
			}
		}
		return need;
	}
}
int main() {
	int N;cin>>N;
	vector<int>types(N);
	for(int i=0;i<N;++i)scanf("%d",&types[i]);
	vector<vector<int>>chs(N);
	for (int i = 0; i < N - 1; ++i) {
		int pa;scanf("%d",&pa);
		pa--;
		chs[pa].push_back(i+1);
	}

	int leaf_cnt = count_if(chs.begin(), chs.end(), [](const vector<int>&v) {return v.empty(); });
	int amin=1;
	int amax=leaf_cnt+1;
	while (amin + 1 != amax) {
		int amid((amin+amax)/2);
		{
			int need=dfs(0,types,chs,amid);
			if (leaf_cnt - amid + 1 >= need) {
				amin=amid;
			}
			else {
				amax=amid;
			}
		}
	}
	cout<<amin<<endl;
	return 0;
}