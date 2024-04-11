#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int main() {
	int N;cin>>N;
	vector<long long int>pre_nums(26);
	for (int i = 0; i < N; ++i) {
		string st; cin >> st;
		vector<long long int>now_nums(26);
		if (i == 0) {
			pair<char, long long int>p(0, 0);
			for (auto c : st) {
				if (p.first == c) {
					p.second++;
				}
				else {
					p = make_pair(c, 1);
				}
				now_nums[p.first - 'a'] = max(now_nums[p.first - 'a'], p.second);
			}
		}
		else {
			bool all_same = count(st.begin(), st.end(), st[0]) == st.size();
			if (all_same) {
				for (int i = 0; i < 26; ++i) {
					if (st[0] == i + 'a') {
						now_nums[i] = (1 + pre_nums[i])*st.size() + pre_nums[i];
					}
					else {
						now_nums[i] = pre_nums[i] ? 1 : 0;
					}
				}
			}
			else {
				pair<char, long long int>st_l(st[0], 1), st_r(st.back(), 1);
				for (int i = 1; i < st.size(); ++i) {
					if (st[i] == st_l.first) {
						st_l.second++;
					}
					else {
						break;
					}
				}
				for (int i = st.size() - 2; i >= 0; --i) {
					if (st[i] == st_r.first)st_r.second++;
					else break;
				}
				vector<long long int>st_lens(26);

				{
					pair<char, long long int>p(0, 0);

					for (auto c : st) {
						if (p.first == c) {
							p.second++;
						}
						else {
							p = make_pair(c, 1);
						}
						st_lens[p.first - 'a'] = max(st_lens[p.first - 'a'], p.second);
					}
				}

				for (int i = 0; i < 26; ++i) {
					now_nums[i] = max(now_nums[i], st_lens[i]);
					if(pre_nums[i])now_nums[i]=max(now_nums[i],1ll);
				}
				{
					if (pre_nums[st_l.first - 'a']) {
						now_nums[st_l.first - 'a'] = max(now_nums[st_l.first - 'a'], 1 + st_l.second);
					}
					if (pre_nums[st_r.first - 'a']) {
						now_nums[st_r.first - 'a'] = max(now_nums[st_r.first - 'a'], 1 + st_r.second);
					}
					if (st_l.first == st_r.first) {
						now_nums[st_l.first - 'a'] = max(
							now_nums[st_l.first - 'a'], 1 + st_l.second + st_r.second);
					}
					
				}

			}
		}

		for (int i = 0; i < 26; ++i) {
			now_nums[i]=min(now_nums[i],static_cast<long long int>(1ll<<30));
		}
		pre_nums=now_nums;
	}
	long long int answer=*max_element(pre_nums.begin(), pre_nums.end());
	cout<<answer<<endl;
	return 0;
}