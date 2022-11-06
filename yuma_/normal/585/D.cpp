#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
long long int powint(long long int a, long long int b) {
	assert(b >= 0);
	if (b == 0)return 1;
	if (b == 1)return a;
	long long int ans = 1;
	long long int aa = powint(a, b / 2);
	ans *= aa*aa;
	if (b % 2)ans *= a;
	return ans;
}
struct aa {
	int plus1;
	int plus2;
	aa(int a, int b) :plus1(a), plus2(b){

	}
};
bool operator==(const aa&l, const aa&r) {
	return l.plus1 == r.plus1&&l.plus2 == r.plus2;
}
bool operator<(const aa&l, const aa&r) {
	return l.plus1 == r.plus1 ? l.plus2 < r.plus2 : l.plus1 < r.plus1;
}

int asum;
pair<int, int> id;
map<aa, pair<int, int>>getmap0(const int start, const int asize,const vector<vector<int>>&pluss, const map<aa, pair<int, int>>&preset) {
	map<aa, pair<int, int>>amap;
	for (int i = 0; i < powint(3, asize); ++i) {
		vector<int>notselects(asize);
		int num = i;
		for (int j = 0; j < asize; ++j) {
			notselects[j] = num % 3;
			num /= 3;
		}
		int plus1 = 0, plus2 = 0;
		int sum = 0;
		for (int j = 0; j < asize; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (k != notselects[j]) {
					if (k == 0) {
						sum += pluss[start+j][k];
						plus1 -= pluss[start + j][k];
						plus2 -= pluss[start + j][k];
					}
					else if (k == 1) {
						plus1 += pluss[start + j][k];
					}
					else {
						plus2 += pluss[start + j][k];
					}
				}
			}
		}
		if (preset.empty()) {
			auto it = amap.find(aa(plus1, plus2));
			if (it != amap.end()) {
				if (it->second.second < sum) {
					it->second.second = sum;
					it->second.first = i;
				}
			}
			else {
				amap[aa(plus1, plus2)] = make_pair(i, sum);
			}
		}
		else {
			auto preit = preset.find(aa{ -plus1,-plus2 });
			if (preit != preset.end()) {
				if (asum < preit->second.second + sum) {
					asum = preit->second.second + sum;
					id = make_pair(preit->second.first, i);
				}
			}
		}
	}
	return amap;
}

map<int, string>mp;
int main() {
	mp[0] = "MW";
	mp[1] = "LW";
	mp[2] = "LM";
	int N; cin >> N;
	vector < vector<int>>pluss(N, vector<int>(3));
	for (int i = 0; i < N; ++i) {
		cin >> pluss[i][0] >> pluss[i][1] >> pluss[i][2];
	}
	if (N <= 13) {
		const int asize = N;
		map<aa,pair<int,int>>preset(getmap0(0,N,pluss, map<aa, pair<int, int>>()));
		auto ansit = preset.find(aa{ 0,0});
		if (ansit == preset.end()) {
			cout << "Impossible" << endl;
			return 0;
		}
		else {
			int id = (*ansit).second.first;
			int num = id;
			for (int j = 0; j < asize; ++j) {
				cout << mp[num % 3]<<endl;
				num /= 3;
			}
		}
	}
	else {
		const int presize = 12;
		map<aa, pair<int, int>>preset(getmap0(0, presize, pluss,map<aa,pair<int,int>>()));
		asum = -1e9;
		id =make_pair(-1,-1);
		getmap0(presize, N - presize, pluss,preset);
		
		if (id==make_pair(-1,-1)) {
			cout << "Impossible" << endl;
		}
		else {
			int prenum = id.first;
			int nextnum = id.second;
			for (int j = 0; j < presize; ++j) {
				cout << mp[prenum % 3] << endl;
				prenum /= 3;
			}
			for (int j = 0; j < N - presize; ++j) {
				cout << mp[nextnum % 3] << endl;
				nextnum /= 3;
			}
		}
		return 0;
	}
	return 0;
}