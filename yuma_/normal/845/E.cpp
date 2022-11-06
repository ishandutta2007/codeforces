#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

template<typename T> struct Compress {
	map<T, int>mp;
	map<int, T>revmp;

	Compress(vector<T>vs) {
		setmp(vs);
	}

	Compress() :mp(), revmp() {

	}
	void setmp(vector<T>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int i = 0; i < static_cast<int>(vs.size()); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
};

int H, W, K;
bool check(int t, vector<pair<int, int>>&fires) {
	vector<vector<int>>pluss;
	Compress<int>xcomp, ycomp;
	{
		vector<int>xs, ys;
		xs.emplace_back(-1e9-1);
		xs.emplace_back(0);
		xs.emplace_back(W - 1);
		xs.emplace_back(W);
		xs.emplace_back(W + 10);
		ys.emplace_back(-1e9-1);
		ys.emplace_back(0);
		ys.emplace_back(H - 1);
		ys.emplace_back(H);
		ys.emplace_back(H + 10);
		for (auto fire : fires) {
			int l = fire.first - t;
			int r = fire.first + t + 1;
			int u = fire.second - t;
			int d = fire.second + t + 1;
			xs.emplace_back(l);
			xs.emplace_back(r);
			ys.emplace_back(u);
			ys.emplace_back(d);
		}
		xcomp.setmp(xs);
		ycomp.setmp(ys);
		pluss = vector<vector<int>>(ycomp.mp.size(), vector<int>(xcomp.mp.size()));
		for (auto fire : fires) {
			int l = fire.first - t;
			int tl(xcomp.mp[l]);
			int r = fire.first + t + 1;
			int tr(xcomp.mp[r]);
			int u = fire.second - t;
			int tu(ycomp.mp[u]);
			int d = fire.second + t + 1;
			int td(ycomp.mp[d]);

			pluss[tu][tl]++;
			pluss[tu][tr]--;
			pluss[td][tl]--;
			pluss[td][tr]++;
		}
	}
	vector<vector<int>>nums(ycomp.mp.size(), vector<int>(xcomp.mp.size()));
	int minx = 1e9 + 1;
	int maxx = -1;
	int miny = 1e9 + 1;
	int maxy = -1;
	
	for(int ay=1;ay<ycomp.mp.size()-1;++ay){
		for (int ax = 1; ax < xcomp.mp.size()-1; ++ax) {
			nums[ay][ax] = nums[ay - 1][ax] + nums[ay][ax - 1] - nums[ay - 1][ax - 1] + pluss[ay][ax];
			assert(nums[ay][ax] >= 0);
			if (nums[ay][ax] == 0) {
				
				int tu = ycomp.revmp[ay];
				int td = ycomp.revmp[ay + 1];
				int tl = xcomp.revmp[ax];
				int tr = xcomp.revmp[ax + 1];
				if (tu >= 0 && td <= H&&tl >= 0 && tr <= W) {
					minx = min(minx, tl);
					maxx = max(maxx, tr);
					miny = min(miny, tu);
					maxy = max(maxy, td);
				}
			}
		} 
	}

	if (minx == 1e9 + 1)return true;
	int dx = maxx - minx;
	int dy = maxy - miny;

	bool ok = (max(dx, dy) <= 2 * t+1);
	return ok;
}

int main() {
	cin >> W>>H >> K;
	vector<pair<int, int>>fires;
	for (int i = 0; i < K; ++i) {
		int x, y; cin >> x >> y;
		x--; y--;
		fires.emplace_back(x,y);
	}
	int amin = 0-1;
	int amax = 1e9;
	while (amin + 1 != amax) {
		int amid((amin + amax+1) / 2);
		if (check(amid, fires))amax = amid;
		else amin = amid;
	}
	cout << amax << endl;

	return 0;
}