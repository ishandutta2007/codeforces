#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = double;
const ld eps = 1e-9;

#include<unordered_map>

void  dfs(const int now, const int from, vector<int>&depths,vector<int>&to_depths,const int d, const vector<vector<int>>&edges) {
	depths[now]=d;
	if (edges[now].size() == 1&&now!=0) {
		to_depths[now]=0;
	}
	else {
		for (auto e : edges[now]) {
			if (e == from)continue;
			else {
				dfs(e, now, depths,to_depths, d + 1, edges);
				to_depths[now]=max(to_depths[now],to_depths[e]+1);
			}
		}
	}
	
}

int  dfs2(vector<int>&v,const int now, const int from, const vector<int>&depths,const vector<int>&to_depths, const vector<vector<int>>&edges,vector<int>&anss) {

	if (edges[now].size() == 1&&now!=0) {
		v[0]=1;
		anss[now]=0;
		return 0;
	}
	else {
		int deep_v = -1;
		for (auto e : edges[now]) {
			if (to_depths[e] + 1 == to_depths[now]) {
				deep_v = e;
				break;
			}
		}

		int xx=dfs2(v, deep_v, now, depths, to_depths, edges, anss);
		pair<int, int>ans;
		{
			int len = xx;
			int num = v[len];
			ans = make_pair(num, len);

		}
		{
			v[to_depths[now]]+=1;

			int len=to_depths[now];
			int num=v[to_depths[now]];

			ans=max(ans,make_pair(num,len));
		}
	


		for (auto e : edges[now]) {
			if(e==from)continue;
			if(e==deep_v)continue;
			vector<int>av(to_depths[e]+1);
			dfs2(av,e,now,depths,to_depths,edges,anss);

			for (int len = 0; len < av.size(); ++len) {
				int my_len=len+to_depths[now]-to_depths[e]-1;
				v[my_len]+=av[len];

				ans=max(ans,make_pair(v[my_len],my_len));
			}
		}
		anss[now]=to_depths[now]-(ans.second);
		return ans.second;
	}
	
}

int main() {
	int N; cin >> N;
	if (N == 1) {
		cout<<0<<endl;
		return 0;
	}
	vector<vector<int>>edges(N);
	for (int i = 0; i < N-1; ++i) {
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int>depths(N);
	vector<int>to_depths(N);
	vector<int>anss(N);
	{
		int d=0;
		dfs(0, -1, depths, to_depths, d, edges);
	}
	{
		vector<int>v(to_depths[0]+1);
		dfs2(v,0,-1,depths,to_depths,edges,anss);
	}
	for (int i = 0; i < N; ++i) {
		printf("%d\n",anss[i]);
	}

	return 0;
}