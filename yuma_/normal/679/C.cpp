#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

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
//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	int N, K; cin >> N >> K;
	vector<vector<int>>field(N+2, vector<int>(N + 2,-1));
	vector<vector<int>>types(N + 2, vector<int>(N + 2,-1));
	for (int i = 0; i < N; ++i) {
		string st; cin >> st;
		for (int j = 0; j < N; ++j) {
			if (st[j] == 'X') {
				field[i + 1][j + 1] = -1;
				types[i + 1][j + 1]= -1;
			}
			else {
				field[i + 1][j + 1] = 0;
			}
		}
	}
	UnionFind uf((N + 2)*(N + 2));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int way = 0; way < 4; ++way) {
				const int ax = j + dx[way];
				const int ay = i + dy[way];
				if (field[i][j] ==0 &&field[i + dy[way]][j + dx[way]]==0) {
					uf.unionSet(i*(N + 2) + j, ay*(N + 2) + ax);
				}
			}
		}
	}
	vector<int>nums((N + 2)*(N + 2));
	for (int i = 0; i <= N+1; ++i) {
		for (int j = 0; j <= N+1; ++j) {
			if (!field[i][j]) {
				types[i][j] = uf.root(i*(N + 2) + j);
				nums[uf.root(i*(N + 2) + j)] = uf.size(i*(N + 2) + j);
			}
		}
	}
	int ans = 0;
	for (int u = 1; u <= 1 + N - K; ++u) {
		vector<int>insides((N + 2)*(N + 2));
		for (int y = u; y < u + K; ++y) {
			for (int x = 1; x < 1 + K; ++x) {
				if (types[y][x] != -1) {
					insides[types[y][x]]++;
				}
			}
		}
		for (int l = 1; l <= 1+N - K; ++l) {
			vector<int>connects;
			{
				int x = l - 1;
				for (int y = u; y < u + K; ++y) {
					if (types[y][x] != -1)connects.emplace_back(types[y][x]);
				}
				x = l + K;
				for (int y = u; y < u + K; ++y) {
					if (types[y][x] != -1)connects.emplace_back(types[y][x]);
				}
			}
			{
				int y = u - 1;
				for (int x = l; x < l + K; ++x) {
					if (types[y][x] != -1)connects.emplace_back(types[y][x]);
				}
				y = u + K;
				for (int x = l; x < l + K; ++x) {
					if (types[y][x] != -1)connects.emplace_back(types[y][x]);
				}
			}
			sort(connects.begin(), connects.end());
			connects.erase(unique(connects.begin(), connects.end()),connects.end());
			int nans = 0;
			for (auto c : connects) {
				nans += nums[c] - insides[c];
			}
			nans += K*K;
			if (ans < nans) {
				ans = nans;
			}
			{
				int x = l;
				for (int y = u; y < u + K; ++y) {
					if (types[y][x] != -1) {
						insides[types[y][x]]--;
					}
				}
				x = l + K;
				for (int y = u; y < u + K; ++y) {
					if (types[y][x] != -1) {
						insides[types[y][x]]++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}