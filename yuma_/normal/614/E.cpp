#include "bits/stdc++.h"
#include<unordered_map>
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
long long int gcd(vector<long long int>nums) {
	if (nums.size() == 1)return nums[0];
	long long int num = nums[0];
	
	for (int i = 1; i < nums.size(); ++i) {
		num = gcd(num, nums[i]);
	}
	return num;
}
vector<long long int> divisor(long long int n) {
		vector<long long int> res;
		for (long long int i = 1; i * i <= n; ++i) {
			if (n % i == 0) {
				res.push_back(i);
				if (i * i != n) res.push_back(n / i);
			}
		}
		sort(begin(res), end(res));
		return res;
	}

int main() {
	int n; cin >> n;
	vector<int>nums;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		sum += a;
		nums.push_back(a);
	}
	int agcd = gcd(vector<long long int>(nums.begin(),nums.begin()+n));
	vector<long long int>div(divisor(agcd));
	long long int ans = 0;
	bool isodd = true;
	for (auto i : div) {
		vector<int>anums(nums);
		transform(anums.begin(), anums.end(),anums.begin(), [=](const long long int& a) {return a / i; });
		const int asum = sum / i;//e[v
		bool ok = true;
		if (asum % 2) {
			int oddnum = count_if(anums.begin(), anums.end(), [](const long long int a) {return a % 2; });
			if (oddnum !=1) {
				ok = false;
			}
		}
		else {
			int oddnum = count_if(anums.begin(), anums.end(), [](const long long int a) {return a % 2; });
			if (oddnum != 0) {
				ok = false;
			}
		}
		if (ok) {
			if (asum % 2) {
				if (ans < i) {
					ans = i;
					isodd = true;
				}
			}
			else {
				if (ans < i * 2) {
					ans = i * 2;
					isodd = false;
				}
			}
		}
	}
	cout << ans << endl;
	if (ans) {
		if (!isodd)ans /= 2;
		transform(nums.begin(), nums.end(), nums.begin(), [=](const long long int& a) {return a / ans; });
		string st;
		int oddnum = -1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] % 2) {
				oddnum = i;
			}
			for (int j = 0; j < nums[i] / 2; ++j) {
				st.push_back('a' + i);
			}
		}
		string revst(st);
		reverse(revst.begin(), revst.end());
		if (oddnum != -1) {
			st.push_back('a' + oddnum);
		}
		st += revst;
		for (int i = 0; i < ans; ++i) {
			cout << st;
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < nums[i]; ++j) {
				cout << char('a' + i);
			}
		}
		cout << endl;
	}

	return 0;
}