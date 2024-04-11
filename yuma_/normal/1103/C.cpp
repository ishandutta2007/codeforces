#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int N,M,K;
struct Edge {
	int id;
	int u;
	int v;
};
vector<vector<Edge>>graph;
vector<int>in_tree;
vector<int>pas;
vector<int>depths;
vector<int>leafs;

void dfs(const int now, const int from,vector<int>&used,int de) {
	pas[now]=from;
	depths[now]=de;
	bool flag=false;
	for (auto e : graph[now]) {
		if (!used[e.v]) {
			used[e.v]=true;
			in_tree[e.id]=true;

			dfs(e.v,e.u,used,de+1);
			flag=true;
		}
	}
	if (!flag) {
		leafs.push_back(now);
	}
}

void pu(vector<int>v) {
	cout<<v.size()<<endl;
	for (int i = 0; i < v.size(); ++i) {
		printf("%d",v[i]+1);
		if(i==v.size()-1)printf("\n");
		else printf(" ");
	}
}

vector<int>make_back(int down, int up) {
	int now = down;
	vector<int>anss;
	while (now != up) {
		anss.push_back(now);
		now = pas[now];
	}
	anss.push_back(now);
	return anss;
}

int main()
{
	cin>>N>>M>>K;
	graph.resize(N);
	pas.resize(N);
	in_tree.resize(M);
	depths.resize(N);
	for (int i = 0; i < M; ++i) {
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		graph[a].push_back(Edge{ i,a,b });
		graph[b].push_back(Edge{ i,b,a });
	}

	vector<int>used(N);
	used[0]=true;
	dfs(0,-1,used,0);

	int path_end_id=-1;
	for (int i = 0; i < N; ++i) {
		if (depths[i]+1 >= (N-1)/K+1) {
			path_end_id=i;
		}
	}
	if (path_end_id == -1) {
		cout << "CYCLES" << endl;
		assert(leafs.size()>=K);
		leafs.resize(K);
		for (auto leaf : leafs) {
			vector<int>backs;
			for (auto e : graph[leaf]) {
				if (depths[e.v] + 2 <= depths[leaf]) {
					backs.push_back(e.v);
					
				}
			}
			assert(backs.size()>=2);
			backs.resize(2);

			int id_a=backs[0];
			int id_b=backs[1];
			int id_c=leaf;

			if(depths[id_a]>depths[id_b])swap(id_a,id_b);

			int bc=depths[id_c]-depths[id_b];
			int ac=depths[id_c]-depths[id_a];
			vector<int>anss;
			if (bc % 3 != 2) {
				anss=make_back(id_c,id_b);
			}
			else if (ac % 3 != 2) {
				anss=make_back(id_c,id_a);
			}
			else {
				anss=make_back(id_b,id_a);
				anss.push_back(id_c);
			}
			assert(anss.size()%3!=0);
			pu(anss);
		}
	}
	else {
		cout<<"PATH"<<endl;
		vector<int>anss=make_back(path_end_id,0);
		pu(anss);
	}
	return 0;
}