#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct Dscc {
public:

	//fst:belongs , scd:newedges
	pair<vector<vector<int>>, vector<vector<int>>>get(const vector<vector<int>>&edges) {
		nums.resize(edges.size());
		fill(nums.begin(), nums.end(), -1);
		vector<vector<int>>revedges(edges.size());
		for (int i = 0; i < edges.size(); ++i) {
			for (int k=0;k<edges[i].size();++k) {
				int j(edges[i][k]);
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
			for(int k=0;k<edges[i].size();++k){
				int j(edges[i][k]);
				if (unis[i] != unis[j]) {
					newedges[unis[i]].push_back(unis[j]);
				}
			}
		}
		return make_pair(belongs, newedges);
	}
private:
	vector<int>nums;
	vector<int>unis;


	void dfs(const int id, int &num, const vector<vector<int>>&edges) {
		if (nums[id] != -1)return;
		else {
			nums[id] = -2;
			for(int k=0;k<edges[id].size();++k){
				int i(edges[id][k]);
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
			for(int k=0;k<edges[id].size();++k){
				int i(edges[id][k]);
				dfs2(i, num, edges);
			}
		}
		unis[id] = num;
		return;
	}

}dscc;

vector<vector<int>>get_rev(const vector<vector<int>>&edges){
	vector<vector<int>>rev(edges.size());
	for(int i=0;i<rev.size();++i){
		for(int j=0;j<edges[i].size();++j){
			rev[edges[i][j]].push_back(i);
		}
	}
	return rev;
}
vector<int>solve(const vector<vector<int>>&belongs,const vector<vector<int>>&edges){
	auto rev_edges(get_rev(edges));
	int N(belongs.size());
	vector<int>comes(belongs.size());

	
	for(int i=0;i<rev_edges.size();++i){
		for(int j=0;j<rev_edges[i].size();++j){
			comes[rev_edges[i][j]]++;
		}
	}
	queue<int>que;

	vector<int>nums(N);
	for(int i=0;i<N;++i){
		if(comes[i]==0){
			nums[i]=belongs[i].size();
			que.push(i);
		}else{
			nums[i]=1e8;
		}
	}
	
	int min_id=min_element(nums.begin(),nums.end())-nums.begin();

	vector<int>anss;
	queue<int>ans_que;
	ans_que.push(min_id);
	vector<int>used(N);
	used[min_id]=true;

	int t=1;
	while(!ans_que.empty()){
		t--;
		int now(ans_que.front());

		for(int i=0;i<belongs[now].size();++i){
			anss.push_back(belongs[now][i]);
		}
		ans_que.pop();
		for(int i=0;i<edges[now].size();++i){
			int to(edges[now][i]);
			if(!used[to]){
				used[to]=true;
				que.push(to);
			}
		}
	}
	assert(t==0);
	return anss;
			
}
int main() { 
	int N,M,H;cin>>N>>M>>H;
	vector<int>times(N);
	for(int i=0;i<N;++i){
		int a;scanf("%d",&a);
		times[i]=a;
	}
	vector<vector<int>>edges(N);
	for(int i=0;i<M;++i){
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		if((times[a]+1)%H==times[b]){
			edges[a].push_back(b);
		}
		if((times[b]+1)%H==times[a]){
			edges[b].push_back(a);
		}
	}
	auto p=dscc.get(edges);

	auto belongs(p.first);
	auto newedges(p.second);

	for(int i=0;i<newedges.size();++i){
		sort(newedges[i].begin(),newedges[i].end());
		newedges[i].erase(unique(newedges[i].begin(),newedges[i].end()),newedges[i].end());
	}

	auto anss=solve(belongs,newedges);

	
	printf("%d\n",anss.size());
	for(int i=0;i<anss.size();++i){
		printf("%d",anss[i]+1);
		if(i==anss.size()-1)printf("\n");
		else printf(" ");
	}
	return 0;
}