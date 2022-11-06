#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"


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
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int N, M;
int aa(const int x, const int y) {
	if (x >= 0 && x < M&&y >= 0 && y < N) {
		return y*M + x;
	}
	else {
		return -1;
	}
}

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
void dfs(const vector<vector<long long int>>&heights, vector<vector<long long int>>&anss, const int nx, const int ny,int &rest,const long long int h) {
	if (rest == 0)return;
	anss[ny][nx] = h;
	rest--;
	for (int way = 0; way < 4; ++way) {
		const int nextx = nx+dx[way];
		const int nexty = ny+dy[way];
		if (aa(nextx, nexty) != -1&&anss[nexty][nextx]==0&&heights[nexty][nextx]>=h) {
			dfs(heights,anss, nextx, nexty,rest,h);
		}
	}
}
int main() { 
	cin >> N >> M;
	long long K; cin >> K;
	map<long long int, vector<pair<int, int>>,greater<long long int>>mp;
	vector<vector<long long int>>heights(N, vector<long long int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int x; 
			scanf("%d", &x);
			heights[i][j] = x;
			mp[x].push_back(make_pair(j, i));
		}
	}
	UnionFind uf(N*M);
	vector<vector<long long int>>anss;
	for (auto m : mp) {
		long long h = m.first;
		for (auto v : m.second) {
			const int nowx = v.first;
			const int nowy = v.second;
			int nowid = aa(nowx, nowy);
			for (int way = 0; way < 4; ++way) {
				const int nextx = nowx + dx[way];
				const int nexty = nowy + dy[way];
				int nextid = aa(nextx, nexty);
				if (nextid != -1&&heights[nexty][nextx]>=h) {
					uf.unionSet(nowid, nextid);
				}
			}
		}
		long long int w = K / h;
		if (w*h == K) {
			for (auto v : m.second) {
				int nowid = aa(v.first, v.second);
				int asize = uf.size(nowid);
				if (asize >= w) {
					anss.resize(N);
					for (int i = 0; i < N; ++i)anss[i].resize(M);
					int rest(w);
					dfs(heights, anss, v.first, v.second, rest, h);
					assert(!rest);
				}
				if (!anss.empty())break;
			}
		}
		if (!anss.empty())break;
	}
	if (anss.empty()) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				printf("%d", int(anss[i][j]));
				if (j == M - 1)printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}