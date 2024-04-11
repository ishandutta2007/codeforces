#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

struct Dscc {
public:

	//fst:belongs , scd:newedges
	pair<vector<vector<int>>, vector<vector<int>>>get(const vector<vector<int>>&edges) {
		nums.resize(edges.size());
		fill(nums.begin(), nums.end(), -1);
		vector<vector<int>>revedges(edges.size());
		for (int i = 0; i < edges.size(); ++i) {
			for (auto j : edges[i]) {
				revedges[j].push_back(i);
			}
		}
		int num = 0;
		for (int i = 0; i < edges.size(); ++i) {
			dfs(i, num, edges);
		}
		vector<int>big(nums.size());
		for (int i = 0; i < nums.size(); ++i) {
			big[nums[i]] = i;
		}
		reverse(big.begin(), big.end());
		unis.resize(edges.size());
		fill(unis.begin(), unis.end(), -1);
		num = 0;
		for (int i = 0; i < big.size(); ++i) {

			dfs2(big[i], num, revedges);
			num++;
		}
		vector<int>nums;
		for (int i = 0; i < unis.size(); ++i) {
			nums.push_back(unis[i]);
		}
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());


		map<int, int>mp;
		for (int i = 0; i < nums.size(); ++i) {
			mp[nums[i]] = i;
		}
		for (int i = 0; i < unis.size(); ++i) {
			unis[i] = mp[unis[i]];
		}

		vector<vector<int>>belongs(nums.size());
		for (int i = 0; i < unis.size(); ++i) {
			belongs[unis[i]].push_back(i);
		}
		vector<vector<int>>newedges(nums.size());
		for (int i = 0; i < edges.size(); ++i) {
			for (auto j : edges[i]) {
				if (unis[i] != unis[j]) {
					newedges[unis[i]].push_back(unis[j]);
				}
			}
		}
		
		for (int i = 0; i < newedges.size(); ++i) {
			sort(newedges[i].begin(),newedges[i].end());
			newedges[i].erase(unique(newedges[i].begin(), newedges[i].end()), newedges[i].end());

		}
		assert(newedges.size()==belongs.size());
		return make_pair(belongs, newedges);
	}
private:
	vector<int>nums;
	vector<int>unis;


	void dfs(const int id, int &num, const vector<vector<int>>&edges) {
		if (nums[id] != -1)return;
		else {
			nums[id] = -2;
			for (auto i : edges[id]) {
				dfs(i, num, edges);
			}
		}
		nums[id] = num++;
		return;
	}
	void dfs2(const int id, const int &num, const vector<vector<int>>&edges) {
		if (unis[id] != -1)return;
		else {
			unis[id] = -2;
			for (auto i : edges[id])
				dfs2(i, num, edges);
		}
		unis[id] = num;
		return;
	}

}dscc;

using Graph=vector<vector<int>>;
vector<string>oks;

Graph input(int N,int M,int D) {
	Graph g(N);
	oks.resize(N);
	for (int i = 0; i < M; ++i) {
		int a,b;scanf("%d %d",&a,&b);
		a--;b--;
		g[a].push_back(b);
	}
	for (int i = 0; i < N; ++i) {
		cin>>oks[i];
	}
	return g;
}
long long int gcd(long long int l, long long int r) {
	if(l<=0||r<=0)cerr<<"gcd er";
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);

		}
		else {
			return l;
		}
	}
}
void dfs1(int& loop_sz,int de,const Graph&be_graph, int now, vector<int>&depths) {
	depths[now]=de;
	for (auto e : be_graph[now]) {
		if (depths[e] == -1) {
			dfs1(loop_sz,de+1,be_graph,e,depths);
		}
		else {
			int aloop=abs(depths[now]-depths[e]+1);
			if(loop_sz==-1)loop_sz=aloop;
			else {
				loop_sz=gcd(loop_sz,aloop);
			}
		}
	}
}
pair<int,vector<int>> get_loop(vector<int>&belong, const Graph& g) {
	Graph be_graph(belong.size());
	map<int,int>mp;
	for (int i = 0; i < belong.size(); ++i) {
		mp[belong[i]]=i;
	}
	for (int i = 0; i < belong.size(); ++i) {
		for (auto e : g[belong[i]]) {
			auto it=mp.find(e);
			if (it == mp.end()) {

			}
			else {
				be_graph[i].push_back(it->second);
			}
		}
	}
	vector<int>depths(belong.size(),-1);
	int loop_sz=-1;
	dfs1(loop_sz,0,be_graph,0,depths);
	assert(count(depths.begin(),depths.end(),-1)==0);
	return make_pair(loop_sz,depths);
}
int main() {
	int N,M,D;cin>>N>>M>>D;
	Graph g=input(N,M,D);

	auto p=dscc.get(g);
	auto belongs=p.first;
	auto newedges=p.second;
	vector<int>loop_szs(belongs.size());
	vector<vector<int>>pluss(belongs.size(),vector<int>(D));
	vector<vector<int>>depths(belongs.size());
	for (int i = 0; i < belongs.size(); ++i) {
		auto p=get_loop(belongs[i],g);
		loop_szs[i]=p.first==-1?-1:gcd(D,p.first);
		
		depths[i]=p.second;
	}
	vector<pair<int,int>>tos(N);
	for (int i = 0; i < belongs.size(); ++i) {
		for (int j=0;j<belongs[i].size();++j) {
			tos[belongs[i][j]]=make_pair(i,j);
		}
	}
	vector<vector<int>>can_gets(belongs.size(),vector<int>(D));
	for (int i = 0; i < belongs.size(); ++i) {
		for(int j=0;j<D;++j){
			if (loop_szs[i] == -1) {
				if (oks[belongs[i][0]][j] == '1')can_gets[i][j] = 1;
				else can_gets[i][j] = 0;
			}
			else {
				
				for(int k=0;k<belongs[i].size();++k){
					int cost=D/loop_szs[i];
					int aok=0;
					for (int x = 0; x < cost; ++x) {
						int nd=(j+(x*loop_szs[i])+depths[i][k])%D;
						if(oks[belongs[i][k]][nd]=='1')aok=true;
					}
					can_gets[i][j]+=aok;
				} 
			}
		}
	}

	vector<vector<int>>dps(belongs.size(),vector<int>(D,-1e9));
	for (int i = 0; i < belongs.size(); ++i) {
		auto it= find(belongs[i].begin(), belongs[i].end(), 0);
		if (it != belongs[i].end()) {
			int d = D - depths[i][it - belongs[i].begin()];
			d %= D;
			if (d < 0)d += D;
			dps[i][d] = 0;
		}
	}
	queue<int>que;
	vector<int>comes(belongs.size());
	for (int i = 0; i < belongs.size(); ++i) {
		for (auto ne : newedges[i]) {
			assert(ne!=i);
			comes[ne]++;
		}
	}
	for (int i = 0; i < belongs.size(); ++i) {
		if (comes[i] == 0) {
			que.emplace(i);
		}
	}
	while (!que.empty()) {
		int now=que.front();
		que.pop();
		for (int d = 0; d < D; ++d) {
			dps[now][d]+=can_gets[now][d];
		}

		set<int>used;
		for (int i=0;i<belongs[now].size();++i) {
			int be=belongs[now][i];
			for (auto e : g[be]) {
				if (tos[e].first != now) {
					int de_sa = -depths[tos[e].first][tos[e].second] + depths[now][i]+1;
					if (de_sa < 0) {
						de_sa%=D;

						if(de_sa<0)de_sa+=D;
					}
					for (int d = 0; d < D; ++d) {
						int cost = D / loop_szs[now];
						if(loop_szs[now]==-1)cost=1;
						for (int x = 0; x < cost; ++x) {
							int nd = (d + (x*loop_szs[now])+de_sa) % D;
							dps[tos[e].first][nd]=max(dps[tos[e].first][nd],dps[now][d]);
						}
					}
					used.emplace(tos[e].first);

				}
			}
		}
		if (used.size() != newedges[now].size()) {
			cout<<"out"<<now<<endl;
			cout<<newedges[now].size()<<" "<<used.size()<<endl;
			for(int i=0;i<newedges[now].size();++i)cout<<newedges[now][i]<<" ";
			cout<<endl;
			for(auto i:used)cout<<i<<" ";
			cout<<endl;
		}
		for (auto us : used) {
			comes[us]--;
			assert(comes[us]>=0);
			if (comes[us] == 0) {
				que.emplace(us);
			}
		}
	
		
	}
	
	if (count(comes.begin(), comes.end(), 0) != comes.size()) {
		for (int i = 10200; i < belongs.size(); ++i) {
			cout<<belongs[i].size()<<endl;
		}
		for(int i=0;i<comes.size();++i)if(comes[i])cout<<i<<" "<<comes[i]<<endl;
	}
	int answer=0;
	for (int i = 0; i < belongs.size(); ++i) {
		for (int d = 0; d < D; ++d) {
			answer=max(answer,dps[i][d]);
		}
	}
	cout<<answer<<endl;
	return 0;
}