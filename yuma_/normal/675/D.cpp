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
	int N; cin >> N;
	map<int, pair<int,int>>mp;
	set<int>aset;
	{
		int a; cin >> a;
		mp[a] =make_pair(0,-1);
		aset.emplace(a);
	}
	vector<int>nums;
	for (int i = 0; i < N-1; ++i) {
		int a; cin >> a;
		auto it=aset.lower_bound(a);
		if (it == aset.begin()) {
			mp[a] = make_pair(mp[*it].first+1,*it);
		}
		else if (it == aset.end()) {

			mp[a] = make_pair(mp[*prev(it)].first + 1, *prev(it));
		}
		else {
			if (mp[*prev(it)].first < mp[*it].first) {
				mp[a] = make_pair(mp[*it].first + 1, *it);

			}
			else {
				mp[a] = make_pair(mp[*prev(it)].first + 1, *prev(it));

			}
		}
		nums.emplace_back(a);
		aset.emplace(a);
	}
	for (int i = 0; i < nums.size();++i) {
		cout << mp[nums[i]].second;
		if (i != nums.size() - 1)cout << " ";
	}
	cout << endl;
	return 0;
}