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
	int H,W;cin>>H>>W;
	vector<string>field(H);
	for (int i = 0; i < H;++i) {
		char chs[1020];
		scanf("%s",chs);
		string st=chs;
		field[i]=st;
	}
	UnionFind uf(H+W);
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			if (field[y][x] == '=') {
				uf.unionSet(y,x+H);
			}
		}
	}
	vector<vector<int>>edges(H+W);
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			int y_id=uf.root(y);
			int x_id=uf.root(x+H);
			if (field[y][x] == '<') {
				edges[y_id].push_back(x_id);
			}
			else if (field[y][x] == '>') {
				edges[x_id].push_back(y_id);
			}
		}
	}
	vector<int>valids(H+W);
	for (int i = 0; i < H + W; ++i) {
		valids[uf.root(i)]=true;
	}
	bool ok=true;
	vector<int>anss(H+W);
	{
		vector<int>comes(H+W);
		for (int i = 0; i < H + W; ++i) {
			for(auto e:edges[i])comes[e]++;
		}
		queue<pair<int,int>>que;
		for (int i = 0; i < H + W; ++i) {
			if (valids[i] && comes[i] == 0) {
				que.emplace(i,1);
			}
		}
		while (!que.empty()) {
			auto p=que.front();
			int now=p.first;
			int num=p.second;
			que.pop();
			anss[now]=num;
			for (auto e : edges[now]) {
				comes[e]--;
				if (comes[e] <= 0) {
					assert(comes[e]==0);
					que.emplace(e,num+1);
				}
			}
		}
		if(count(comes.begin(),comes.end(),0)!=H+W)ok=false;
	}
	if (ok) {
		cout<<"Yes"<<endl;
		vector<int>nums(H+W);
		for (int i = 0; i < H + W; ++i) {
			int id=uf.root(i);
			nums[i]=anss[id];
		}
		for (int i = 0; i < H; ++i) {
			printf("%d ",nums[i]);
		}
		cout<<endl;
		for (int i = 0; i < W; ++i) {
			printf("%d ",nums[H+i]);
		}
		cout<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	return 0;
}