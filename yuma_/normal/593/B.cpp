#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;

long long int gcd(long long int l, long long int r) {
	assert(l > 0 && r > 0);
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);

		}
		else {
			return l;
		}
	}
}

int main() {
	long long int n; cin >> n;
	vector<pair<int,int>>ans;
	long long int X, Y; cin >> X >> Y;
	vector<pair<long long int,long long int> >ls;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		ls.push_back({ X*x + y,Y*x + y });	
	}
	sort(ls.begin(), ls.end(), [](const pair<long long int,long long int> &l, const pair<long long int, long long int>&r) {
		return l.first == r.first ? l.second < r.second : l.first < r.first; });
	bool ok = true;
	for (int i = 0; i < n - 1; ++i) {
		if (ls[i].first < ls[i + 1].first) {
			if (ls[i].second > ls[i + 1].second) {
				ok = false;
				break;
			}
		}
	}
	if (!ok) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}