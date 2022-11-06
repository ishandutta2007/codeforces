#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;

int main() {
	int N, M; cin >> N >> M;
	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		int a; scanf("%d", &a);
		nums[i] = a;
	}
	vector<pair<int, int>>ps;
	for (int i = 0; i < M; ++i) {
		int t, a;
		scanf("%d %d", &t, &a);
		ps.push_back(make_pair(t, a));
	}
	vector<int>sorts(N, 0);
	{
		int now = 0;
		for (int i = M - 1; i >= 0; --i) {
			for (now; now < ps[i].second; ++now) {
				sorts[now] = ps[i].first;
			}
		}
	}
	
	vector<int>anss;
	{

		int now = N-1;
		for (now; now >=0; --now) {
			if (sorts[now] == 0) {
				anss.push_back(nums[now]);
				nums.pop_back();
			}
			else {
				break;
			}
		}
		sort(nums.begin(), nums.end());
		deque<int>que;
		for (auto n : nums) {
			que.push_back(n);
		}
		for (now; now >= 0; --now) {
			if (sorts[now] == 1) {
				anss.push_back(que.back());
				que.pop_back();
			}
			else {
				anss.push_back(que.front());
				que.pop_front();
			}
		}
	}
	reverse(anss.begin(), anss.end());
	for (int i = 0; i < anss.size(); ++i) {
		cout << anss[i];
		if (i != anss.size() - 1)cout << " ";
	}
	cout << endl;
	return 0;
}