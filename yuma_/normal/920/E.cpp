#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;


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
	
	int N,M;cin>>N>>M;
	vector<vector<int>>no_edges(N,vector<int>());
	for(int i=0;i<M;++i){
		int a,b;scanf("%d %d",&a,&b);a--;b--;
		no_edges[a].push_back(b);
		no_edges[b].push_back(a);
	}

	auto it=min_element(no_edges.begin(),no_edges.end(),[](const vector<int>&vl,const vector<int>&vr){
		return vl.size()<vr.size();
	});
	UnionFind uf(N);
	int x=it-no_edges.begin();
	{
		vector<int>x_uses(N,true);
		for(int i=0;i<no_edges[x].size();++i){
			x_uses[no_edges[x][i]]=false;
		}
		for(int y=0;y<N;++y){
			if(x_uses[y]){
				uf.unionSet(x,y);

			}else{
				
				vector<int>y_uses(N,true);
				for(int j=0;j<no_edges[y].size();++j){
					y_uses[no_edges[y][j]]=false;
				}
				for(int z=0;z<N;++z){
					if(y_uses[z]){
						uf.unionSet(y,z);
					}
				}
			}
		}
	}
	vector<int>anss;
	set<int>roots;
	for(int i=0;i<N;++i){
		int aroot(uf.root(i));
		if(roots.find(aroot)==roots.end()){
			roots.emplace(aroot);
			anss.push_back(uf.size(i));
		}
	}
	sort(anss.begin(),anss.end());
	cout<<anss.size()<<endl;
	for(int i=0;i<anss.size();++i){
		cout<<anss[i]<<" ";
	}
	cout<<endl;
	return 0;

}