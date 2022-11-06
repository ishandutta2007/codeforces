#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

long long int gcd(long long int l, long long int r) {
	assert(l > 0 && r > 0);
	if (l > r)return gcd(r, l);
	else {
		const long long int num = r%l;
		if (num) {
			return gcd(l, num);
		}
		else {
			return l;
		}
	}
}

int main() {
	int N; cin >> N;
	map<int,int>nums;
	for (int i = 0; i < N*N; ++i) {
		int a; 
		scanf("%d", &a);
		auto it = nums.find(a);
		if (it == nums.end()) {
			nums[a]++;
		}
		else {
			it->second++;
		}
	}
	vector<int>anss;
	for (int i = 0; i < N; ++i) {
		int ans = (*(prev(nums.end()))).first;
		nums[ans]--;
		if (nums[ans] == 0) {
			nums.erase(prev(nums.end()));
		}
		for (auto a : anss) {
			int agcd = gcd(a, ans);
			nums[agcd] -= 2;
			if (nums[agcd] == 0) {
				nums.erase(agcd);
			}
		}
		anss.push_back(ans);
		//if (i == 300)assert(false);
	}
	for (int i = 0; i < anss.size(); ++i) {
		cout << anss[i];
		if (i != anss.size() - 1)cout << " ";
	}
	cout << endl;
	return 0;
}