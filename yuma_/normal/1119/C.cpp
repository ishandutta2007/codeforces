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

bool check(vector<int>v, long long int h) {
	for (int i = v.size() - 1; i >= 0; i -= 2) {
		h-=v[i];
	}
	return h>=0;
}

int main() {
//\n
	int H,W;cin>>H>>W;
	vector<vector<vector<int>>>vs(2,vector<vector<int>>(H,vector<int>(W)));
	for (int i = 0; i < 2; ++i) {
		for (int y = 0; y < H; ++y) {
			for (int x = 0; x < W; ++x) {
				scanf("%d",&vs[i][y][x]);
			}
		}
	}
	vector<vector<int>>hs(2,vector<int>(H)),ws(2,vector<int>(W));
	for (int i = 0; i < 2; ++i) {
		for (int y = 0; y < H; ++y) {
			for (int x = 0; x < W; ++x) {

				hs[i][y] += vs[i][y][x];
				ws[i][x]+=vs[i][y][x];
			}
		}
	}
	bool ok=true;
	for (int y = 0; y < H; ++y) {
		int dif=abs(hs[0][y]-hs[1][y]);
		if(dif%2)ok=false;
	}
	for (int x = 0; x < W; ++x) {
		int dif=abs(ws[0][x]-ws[1][x]);
		if(dif%2)ok=false;
	}
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}