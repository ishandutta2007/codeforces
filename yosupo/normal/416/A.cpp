#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	ll l = -2*1000000000;
	ll r = -l;
	for (int i = 0; i < n; i++) {
		string s;
		ll d;
		string ss;
		cin >> s >> d >> ss;
		if (ss != "Y") {
			if (s == ">=") {
				s = "<";
			} else if (s == ">") {
				s = "<=";
			} else if (s == "<=") {
				s = ">";
			} else if (s == "<") {
				s = ">=";
			}
		}
		if (s == ">=") {
			l = max(l,d);
		}
		if (s == ">") {
			l = max(l,d+1);
		}
		if (s == "<=") {
			r = min(r,d);
		}
		if (s == "<") {
			r = min(r,d-1);
		}
	}
	if (l <= r) {
		cout << l << endl;
	} else {
		cout << "Impossible" << endl;
	}
}