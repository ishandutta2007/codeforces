#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
int H,W;
long long int field[20][20];
vector<vector<long long int>>vs(20);
void dfs(int y, int x,int rest,long long int ak) {
	if (rest == 0) {
		vs[y].push_back(ak);
		return ;
	}
	for(int way=0;way<2;++way){
		int nx=x;
		int ny=y;
		if(way==0)nx++;
		else ny++;
		if (nx < W&&ny < H) {
			dfs(ny,nx,rest-1,ak^field[ny][nx]);
		}
	}
}
int main() {
	long long int K;
	cin>>H>>W>>K;
	vs.resize(H);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin>>field[i][j];
		}
	}
	auto lvs = vs;
	auto rvs=vs;
	{
		int cnt=(H+W)/2;
		dfs(0,0,cnt-1,field[0][0]);
		lvs=vs;
		vs.clear();
		vs.resize(H);
	}
	{
		long long int nfield[20][20];
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				nfield[i][j]=field[H-i-1][W-j-1];
			}
		}
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				field[i][j]=nfield[i][j];
			}
		}
	}
	
	{
		int cnt=(H+W+1)/2;
		dfs(0, 0, cnt-1, field[0][0]);
		rvs = vs;
		reverse(rvs.begin(),rvs.end());
	}
	{
		long long int nfield[20][20];
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				nfield[i][j] = field[H - i - 1][W - j - 1];
			}
		}
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				field[i][j] = nfield[i][j];
			}
		}
	}
	for (int y = 0; y < H; ++y) {
		sort(lvs[y].begin(), lvs[y].end());
		sort(rvs[y].begin(), rvs[y].end());
	}
	long long int answer=0;
	for (int y = 0; y < H; ++y) {
		for (auto lv : lvs[y]) {
			long long int need=lv^K;
			int ax=(H+W)/2-y-1;
			need^=field[y][ax];
			auto lt=lower_bound(rvs[y].begin(),rvs[y].end(),need);
			auto rt=upper_bound(rvs[y].begin(),rvs[y].end(),need);
			answer+=rt-lt;
		}
	}
	cout<<answer<<endl;
	return 0;
}