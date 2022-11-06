#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;



int main() {
	int N; cin >> N;

	vector<vector<vector<int>>>chess(4, vector<vector<int>>(N, vector<int>(N)));
	for (int i = 0; i < 4; ++i) {
		for (int h = 0; h < N; ++h) {
			string st; cin >> st;
			for (int x = 0; x < N; ++x) {
				if (st[x] == '0')chess[i][h][x] = 0;
				else chess[i][h][x] = 1;
			}
		}
	}

	vector<pair<int, int>>ps{
		make_pair(0, 1),
		make_pair(0, 2),
		make_pair(0, 3),
		make_pair(1, 2),
		make_pair(1, 3),
		make_pair(2, 3)
};

	int ans=1e9;
	for (int type = 0; type < 6; ++type) {
		int nans=0;
		for (int i = 0; i < 4; ++i) {
			int flip=(i==ps[type].first||i==ps[type].second);

			for (int y = 0; y < N; ++y) {
				for (int x = 0; x < N; ++x) {
					int color=chess[i][y][x];
					int need=(flip+y+x)%2;
					if(need!=color)nans++;
				}
			}
		}
		ans=min(ans,nans);
	}
	cout<<ans<<endl;
	return 0;
}