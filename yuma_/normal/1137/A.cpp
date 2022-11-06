#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
struct bu{
	int lr_low_cnt;
	int lr_high_cnt;
	int ud_low_cnt;
	int ud_high_cnt;
};
int main() {
	int H,W;cin>>H>>W;
	vector<vector<int>>field(H,vector<int>(W));
	vector<vector<bu>>bus(H,vector<bu>(W));
	for(int i=0;i<H;++i)for(int j=0;j<W;++j)scanf("%d",&field[i][j]);

	for (int y = 0; y < H; ++y) {
		vector<int>v;
		for (int x = 0; x < W; ++x) {
			v.push_back(field[y][x]);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		map<int,int>mp;
		for (int i = 0; i < v.size(); ++i) {
			mp[v[i]]=i;
		}
		for (int x = 0; x < W; ++x) {
			bus[y][x].lr_low_cnt=mp[field[y][x]];
			bus[y][x].lr_high_cnt=mp.size()-mp[field[y][x]]-1;
		}
	}
	for (int x = 0; x < W; ++x) {

		vector<int>v;
		for (int y = 0; y < H; ++y) {
			v.push_back(field[y][x]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		map<int, int>mp;
		for (int i = 0; i < v.size(); ++i) {
			mp[v[i]] = i;
		}
		for (int y = 0; y < H; ++y) {
			bus[y][x].ud_low_cnt = mp[field[y][x]];
			bus[y][x].ud_high_cnt = mp.size() - mp[field[y][x]] - 1;
		}
	}
	vector<vector<int>>anss(H,vector<int>(W));
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			anss[y][x]=max(bus[y][x].lr_high_cnt,bus[y][x].ud_high_cnt);
			anss[y][x]+=max(bus[y][x].lr_low_cnt,bus[y][x].ud_low_cnt);
			anss[y][x]++;

		}
	}
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			printf("%d ",anss[y][x]);
		}
		cout<<endl;
	}
	return 0;
}