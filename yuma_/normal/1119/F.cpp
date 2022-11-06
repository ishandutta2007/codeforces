#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
//for CodeForces
#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;
using ll=long long ;
struct Edge {
	int src;
	int dst;
	ll cost;
};
using Graph=vector<vector<Edge>>;
Graph graph;
vector<vector<ll>>dp(0,vector<ll>(2));
int N;
vector<int>used;
vector<multiset<ll>>smalls,bigs;
vector<ll>sums;
vector<int>is_active;

ll anum=0;
ll tttt=0;
void dfs(int now,int T,int W) {
	ll sum=0;
	vector<ll>profit;
	vector<Edge>lists;
	for (auto e : graph[now]) {
		anum++;
		tttt++;
		if (is_active[e.dst]) {
			lists.emplace_back(e);
		}
		if (!used[e.dst]) {
			used[e.dst]=true;
			dfs(e.dst,T,e.cost);
			sum+=dp[e.dst][0];
			profit.emplace_back(dp[e.dst][1]-dp[e.dst][0]);
		}
	}
	graph[now]=lists;
	sort(profit.begin(), profit.end());
	dp[now][0]=0,dp[now][1]=0;
	for (int x = 0; x < 2; x++) {
		if (x > T) {
			continue;
		}
		ll take = sums[now] + sum;
		if (x == 1) take += W;
		auto it=bigs[now].begin();
		int wh = bigs[now].size() + x;
		for (int p = 0; p <= min((int)profit.size(), T- x); p++) {
			while (wh + p > T) {
				//anum++;
				take -= *it;
				it++;
				wh--;
			}
			dp[now][x] = max(dp[now][x], take);
			if (p == min((int)profit.size(), T- x)) break;
			take += profit[profit.size() - p - 1];
		}
	}
	//cout<<"t: "<<T<<" "<<"id: "<<now<<endl;
	//cout<<dp[now][0]<<" "<<dp[now][1]<<endl;
}
int main() {
//\ncin>>N;
	cin>>N;
	graph.resize(N);
	dp.resize(N);
	for(int i=0;i<N;++i)dp[i].resize(2);
	smalls.resize(N);
	bigs.resize(N);
	used.resize(N);
	sums.resize(N);
	fill(used.begin(),used.end(),true);
	ll total=0;
	ll tt=-1;
	int cnum=0;
	for (int i = 0; i < N - 1; ++i) {
		int s,t;
		ll c;
		scanf("%d %d %lld",&s,&t,&c);
		if(!i)tt=c;
		total+=c;
		s--;t--;
		graph[s].push_back(Edge{ s,t,c });
		graph[t].push_back(Edge{ t,s,c });
	}
	Graph test=graph;
	vector<pair<int,int>>degs;
	for (int i = 0; i < N; ++i) {
		degs.emplace_back(make_pair(int(graph[i].size()),i));
	}
	sort(degs.begin(),degs.end());
	auto it=degs.begin();

	is_active=vector<int>(N,true);

	ll ans=0;

	vector<int>active_ids(N);
	vector<int>pos(N);
	iota(active_ids.begin(),active_ids.end(),0);
	pos=active_ids;
	int a_sum=0;
	for (int t = 0; t < N; ++t) {
		while (it != degs.end() && it->first <= t) {
			int id=it->second;
			is_active[id]=false;
			for (auto e : test[id]) {
				if (is_active[e.dst]) {
					smalls[e.dst].insert(e.cost);
				}
				else {
					ans+=e.cost;
				}
			}
			{
				int apos=pos[id];
				pos[active_ids.back()] = apos;

				pos[id]=-1;
				swap(active_ids[apos],active_ids.back());
				active_ids.pop_back();
			}
			it++;
		}
		//cout<<"active_ids"<<endl<<endl;
		//for(auto a_id:active_ids)cout<<a_id<<endl;
		//cout<<endl;
		a_sum+=active_ids.size();
		for (auto a_id : active_ids) {
			used[a_id]=false;
			while (!smalls[a_id].empty() && bigs[a_id].size() < t) {
				auto s_it=prev(smalls[a_id].end());
				ll acost=*s_it;
				sums[a_id]+=acost;
				bigs[a_id].insert(acost);
				smalls[a_id].erase(s_it);
			}
			while(!smalls[a_id].empty() && !bigs[a_id].empty()) {
				cnum++;
				auto  s_it=prev(smalls[a_id].end());
				ll s_num=*s_it;

				auto  b_it=bigs[a_id].begin();
				ll b_num=*b_it;
				if (*s_it > *b_it) {
					sums[a_id]+=s_num-b_num;
					smalls[a_id].erase(s_it);
					bigs[a_id].erase(b_it);
					smalls[a_id].insert(b_num);
					bigs[a_id].insert(s_num);
				}
				else {
					break;
				}
			}
		}

		ll nans=ans;
		for (auto a_id : active_ids) {
			if (!used[a_id]) {
				used[a_id] = true;
				dfs(a_id, t,0);
				nans+=max(dp[a_id][1],dp[a_id][0]);
			}
		}
		 {
			printf("%lld ", total - nans);

		}
	}
	cout<<endl;
	return 0;
}