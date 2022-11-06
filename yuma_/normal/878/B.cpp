#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

vector<pair<int, long long int>>get_p(vector<int>&v) {
	int pre = -1;
	int sum = 0;
	vector<pair<int, long long int>>ps;
	for (auto n : v) {
		if (pre == sum) {
			sum++;
		}
		else {
			if (sum != 0) {
				ps.push_back(make_pair(pre, sum));
				pre = -1;
				sum = 0;
			}
			else {
				pre = n;
				sum = 0;
			}
		}
	}
	if (sum != 0) {
		ps.push_back(make_pair(pre, sum));
		pre = -1;
		sum = 0;
	}
	return ps;
}



deque<pair<int, pair<int, long long int>>> asolve(deque<pair<int,pair<int,long long int>>>aq, int K) {
	deque<pair<int, pair<int,long long  int>>>que;
	for (auto p : aq) {
		int n=p.second.first;
		long long int num=p.second.second;
		int t = que.size();
		if (que.empty()) {
			que.push_back(make_pair(t, make_pair(n, num)));
		}
		else {
			if (que.back().second.first == n) {
				que.back().second.second+=num;
			}
			else {
				que.push_back(make_pair(t, make_pair(n, num)));
			}
		}
		if (que.back().second.second %K==0) {
			que.pop_back();
		}
		else if (que.back().second.second > K) {
			que.back().second.second%=K;
		}
	}
	return que;
}
deque<pair<int, pair<int, int>>> solve1(vector<int>v, int K) {
	deque<pair<int, pair<int, int>>>que;
	for (auto n : v) {
		int t = que.size();
		if (que.empty()) {
			que.push_back(make_pair(t, make_pair(n, 1)));
		}
		else {
			if (que.back().second.first == n) {
				que.back().second.second++;
			}
			else {
				que.push_back(make_pair(t, make_pair(n, 1)));
			}
		}
		if (que.back().second.second == K) {
			que.pop_back();
		}
	}
	return que;
}

deque<pair<int, pair<int, int>>> solve2(deque<pair<int, pair<int, int>>>q, int K) {
	while (true) {
		if (q.size() <= 1) {
			break;
		}
		else {
			auto f(q.front());
			auto b(q.back());
			if (f.second.first == b.second.first) {
				if (f.second.second + b.second.second >= K) {
					q.pop_front();
					q.back().second.second-=(K-f.second.second);
					if (q.back().second.second == 0) {
						q.pop_back();
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
	}
	return q;
}
int main() {
	int N;
	long long int M, K; cin >> N >> K >> M;
	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	auto q1 = solve1(nums, K);

	auto q2 = solve2(q1, K);

	long long int ans=-1;
	if (q2.size() >= 2) {

		long long int one_num = 0, two_num = 0;
		auto it = q1.begin();
		for (int i = 0; i < q1.size(); ++i) {
			one_num += it->second.second;
			it++;
		}
		auto jt = q2.begin();
		for (int i = 0; i < q2.size(); ++i) {
			two_num += jt->second.second;
			jt++;
		}

		ans = one_num + two_num*(M - 1);
	}
	else if (q2.size() == 1) {
		deque<pair<int,pair<int,long long int>>>q3;
		for (auto q : q1) {
			q3.push_back(make_pair(q.first,make_pair(q.second.first,q.second.second)));
		}
		{
			int n(q2.back().first);
			int k=0;
			for (auto& it : q3) {
				if (it.first == n) {
					it.second.second+=q2.back().second.second*(M-1);
				}
			}
		}
		auto q4=asolve(q3,K);

		long long int four_num=0;
		auto lt = q4.begin();
		for (int i = 0; i < q4.size(); ++i) {
			four_num += lt->second.second;
			lt++;
		}
		ans=four_num;
	}
	else if (q2.size() == 0) {
		long long int one_num = 0, two_num = 0;
		auto it = q1.begin();
		for (int i = 0; i < q1.size(); ++i) {
			one_num += it->second.second;
			it++;
		}
		auto jt = q2.begin();
		for (int i = 0; i < q2.size(); ++i) {
			two_num += jt->second.second;
			jt++;
		}
		if (M % 2) {
			ans=one_num;
		}
		else {
			ans=0;
		}
	}

	cout<<ans<<endl;
	return 0;
}