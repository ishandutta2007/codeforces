#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	ld ax, ay, bx, by, tx, ty; cin >> ax >> ay >> bx >> by >> tx >> ty;
	int N; cin >> N;
	vector<pair<ld, ld>>ps;
	vector<pair<ld,int>>adis, bdis;
	ld sum=0;
	for (int i = 0; i < N; ++i) {
		ld x, y; cin >> x >> y;
		ps.emplace_back(x, y);
		sum += sqrt((tx - x)*(tx - x) + (ty - y)*(ty - y))*2;
		adis.emplace_back(sqrt((ax - x)*(ax - x) + (ay - y)*(ay - y)) - sqrt((tx - x)*(tx - x) + (ty - y)*(ty - y)),i);
		bdis.emplace_back(sqrt((bx - x)*(bx - x) + (by - y)*(by - y)) - sqrt((tx - x)*(tx - x) + (ty - y)*(ty - y)),i);
	}
	sort(adis.begin(), adis.end());
	sort(bdis.begin(), bdis.end());
	if (N == 1) {
		ld ans = min(adis[0].first, bdis[0].first)+sum; cout << fixed << setprecision(22) << ans << endl;
	}
	else {
		ld ans;
		ans = min(bdis[0].first + sum, adis[0].first + sum);
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (adis[i].second == bdis[j].second)continue;
				ans = min(ans, adis[i].first + bdis[j].first + sum);
			}
		}
		cout<<fixed<<setprecision(22) << ans << endl;
	}
	
	
	return 0;
}