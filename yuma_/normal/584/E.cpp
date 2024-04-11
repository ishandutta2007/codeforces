
#include "bits/stdc++.h"
using namespace std;



int main() {
	int n; cin >> n;
	vector<int>places(n);
	vector<int>nums;
	vector<int>places2(n);
	for (int i = 0; i < n; ++i) {
		int a; cin >> a; a--;
		places[a] = i;
		nums.push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		int a; cin >> a; a--;
		places2[a] = i;
	}
	vector<int>needmoves(n);
	for (int i = 0; i < n; ++i) {
		needmoves[i] = places2[i] - places[i];
	}
	vector<int>needmoves2(n);
	for (int i = 0; i < n; ++i) {
		needmoves2[i] = needmoves[nums[i]];
	}
	vector<pair<int, int>>moves;
	int money = 0;
	bool flag = true;
	while (flag) {
		flag = false;

		for (int i = 0; i < n; ++i) {

			if (needmoves2[i] > 0) {
				const int movepo = i + needmoves2[i];
				if (needmoves2[movepo] <= -needmoves2[i]) {
					flag = true;
					money += abs(needmoves2[i]);
					moves.push_back(make_pair(i, movepo));
					needmoves2[i] += needmoves2[movepo];
					needmoves2[movepo] = 0;
				}
			}
			else if (needmoves2[i] < 0) {
				const int movepo = i + needmoves2[i];
				if (needmoves2[movepo] >= -needmoves2[i]) {
					flag = true;
					money += abs(needmoves2[i]);
					moves.push_back(make_pair(i, movepo));
					needmoves2[i] += needmoves2[movepo];
					needmoves2[movepo] = 0;
				}
			}
		}
		if (!flag) {
			if (all_of(needmoves2.begin(), needmoves2.end(), [](const int a) {return a == 0; })) {

			}
			else {
				for (int i = 0; i < n; ++i) {
					if (flag)break;
					if (needmoves2[i] > 0) {
						for (int k = needmoves2[i]-1; k >=1; --k) {
							const int movepo = i + k;
							if (needmoves2[movepo] <= -k) {
								flag = true;
								money += abs(k);
								moves.push_back(make_pair(i, movepo));
								needmoves2[i] -= k;
								needmoves2[movepo]+=k;
								swap(needmoves2[i], needmoves2[movepo]);
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << money << endl;
	cout << moves.size() << endl;
	for (auto i : moves) {
		cout << i.first+1 << " " << i.second+1 << endl;
	}
	return 0;
}