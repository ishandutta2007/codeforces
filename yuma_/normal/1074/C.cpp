#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;

#define Seg_Max_N (1<<18) 

int solve(vector<pair<int, int>>ps) {
	vector<int>xs;
	vector<int>ys;
	for (int i = 0; i < ps.size(); ++i) {
		xs.push_back(ps[i].first);
		ys.push_back(ps[i].second);
	}
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	return 2*(xs.back()-xs.front())+2*(ys.back()-ys.front());
}

int main() {
	int N;scanf("%d",&N);
	vector<pair<int,int>>ps;

	int x_min=1e9,x_max=-1e9,y_min=1e9,y_max=-1e9;
	int x_min_id,x_max_id,y_min_id,y_max_id;
	for (int i = 0; i < N; ++i) {
		int x,y;scanf("%d %d",&x,&y);
		ps.emplace_back(x,y);
		if (x < x_min) {
			x_min_id=i;
			x_min=x;
		}
		if (x > x_max) {
			x_max_id=i;
			x_max=x;
		}
		if (y < y_min) {
			y_min_id=i;
			y_min=y;
		}
		if (y > y_max) {
			y_max_id=i;
			y_max=y;
		}
	}

	int ans_3=0;

	vector<int>ids{ x_min_id,x_max_id,y_min_id,y_max_id };
	for (int k = 0; k < 4; ++k) {
		for (int kk = k + 1; kk < 4; ++kk) {
			int p0_id=ids[k];
			int p2_id=ids[kk];
			for (int i = 0; i < N; ++i) {
				int p1_id = i;
				vector<pair<int, int>>vv{ ps[p0_id],ps[p1_id],ps[p2_id] };
				int nans = solve(vv);
				ans_3 = max(nans, ans_3);
			}
		}
	}
	int ans_4=2*((x_max-x_min)+(y_max-y_min));

	printf("%d",ans_3);
	for (int k = 4; k <= N; ++k) {
		printf(" %d",ans_4);
	}
	cout<<endl;
	return 0;
}