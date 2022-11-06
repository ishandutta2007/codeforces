#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;


int main() {
	int N; cin >> N;
	vector<int>as(N), finals(N+2);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	vector<pair<int, int>>ps;
	{
		int  now = as[0];
		int num = 1;
		for (int i = 1; i < N; ++i) {
			if (now == as[i]) {
				num++;
			}
			else {
				ps.emplace_back(now, num);
				now = !now;
				num = 1;
			}
		}
		ps.emplace_back(now, num);
	}
	ps[0].second += 1;
	ps.back().second += 1;
	int ans = 0;
	{
		int num = 0;
		int pre = 0;
		for (int i = 0; i < ps.size(); ++i) {
			if (ps[i].second >= 2) {
				for (int j = pre + 1; j <= (i+pre)/2; ++j) {
					finals[num++] = ps[pre].first;
				}
				for (int j = (i + pre) / 2+1; j < i; ++j) {
					finals[num++] = ps[i].first;
				}
				for (int j = 0; j <ps[i].second; ++j) {
					finals[num++ ] = ps[i].first;
				}
				pre = i;
			}
			else {
				ans = max((i - pre+1) / 2, ans);
			}
		}
	}
	/*int from = -1;
	int pre = as[0];
	finals[0] = as[0];
	int ans = 0;
	int aa = 0;
	for (int i = 1; i < N; ++i) {
		if (pre == as[i]||i==N-1) {
			if (from == -1) {
				finals[i] = as[i];
				aa = 0;
				continue;
			}
			if (from == i - 2) {
				finals[i - 1] = as[i];
				finals[i] = as[i];
				from = -1;
				aa = 0;
				continue;
			}
			for (int j = from; j <= from + (i-1 - from) / 2; ++j) {
				finals[j] = as[from];

			}
			for (int j = from + (i-1 - from) / 2+1; j <=i-1; ++j) {
				finals[j] = as[i-1];

			}
			finals[i] = as[i];
			from = -1;
			ans = max((aa) / 2, ans);
			aa = 0;
		}
		else {
			aa++;
			if (from == -1) {
				from = i-1;
			}
		}
		pre = as[i];
	}*/
	cout << ans << endl;
	vector<int>anss(finals.begin() + 1, finals.end() - 1);
	for (int i = 0; i < N; ++i) {
		cout << anss[i];
		if (i != N - 1)cout << " ";
	}
	cout << endl;
	return 0;
}