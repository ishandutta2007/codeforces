#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;
vector<pair<int, bool>>check(int s,vector<int>as) {
	vector<pair<int, bool>>ans;
	while (as.size() > 1) {
		pair<int, vector<int>>max_p;
		for (int i = 0; i < as.size(); ++i) {
			if (max_p.first < as[i]) {
				max_p.first = as[i];
				max_p.second = vector<int>{ i };
			}
			else if (max_p.first == as[i]) {
				max_p.second.push_back(i);
			}
		}
		bool flag = false;
		for (auto mn : max_p.second) {
			if (mn&&as[mn - 1] < as[mn]) {
				as[mn] += as[mn - 1];
				as.erase(as.begin() + mn - 1);
				ans.push_back(make_pair(s + mn, false));
				flag = true;
				break;
			}
			if (mn != as.size() - 1 && as[mn + 1] < as[mn]) {
				as[mn] += as[mn + 1];
				as.erase(as.begin() + mn + 1);
				ans.push_back(make_pair(s + mn, true));
				flag = true;
				break;
			}
		}
		if (!flag)return vector<pair<int, bool>>();
		else {

		}
	}
	return ans;
}
int main() {
	
	int N; cin >> N;
	vector<int>as(N);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	int M; cin >> M;
	vector<int>bs(M);
	for (int i = 0; i < M; ++i) {
		cin >> bs[i];
	}
	bool ok = true;
	int sum = 0;
	int now = 0;
	vector<int>starts;
	starts.push_back(0);
	for (int i = 0; i < N; ++i) {
		if (now == M) {
			ok = false;
			break;
		}
		sum += as[i];
		if (sum == bs[now]) {
			sum = 0;
			now++;
			starts.push_back(i + 1);
		}
		else if (sum > bs[now]) {
			ok = false;
			break;
		}
		else {

		}
	}
	if (ok) {
		if (sum != 0 || now != M)ok = false;
	}
	vector<pair<int, bool>>anss;
	if (ok) {
		for (int i = M-1; i >=0;--i) {
			vector<int>av(as.begin() + starts[i], as.begin() + starts[i + 1]);
			if (av.size() >= 2) {

				auto ans = check(starts[i], av);
				if (!ans.empty()) {
					anss.insert(anss.end(), ans.begin(), ans.end());
				}
				else {
					ok = false;
				}
			}
		}
	}
	


	if (ok) {
		cout << "YES" << endl;
		for (auto ans : anss) {
			cout << ans.first+1 << " " << (ans.second ? 'R' : 'L' )<< endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
}