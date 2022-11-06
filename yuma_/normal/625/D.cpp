#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

int memo[2][2][100000];
int N;

string getans(vector<int>nums) {
	vector<int>anss;
	if (nums.size() % 2 == 0) {
		for (int i = 0; i < nums.size() / 2; ++i) {
			if (nums[i] == nums[nums.size() - i - 1]) {
				anss.push_back(nums[i]);
			}
			else if (nums[i] == nums[nums.size() - i - 1] + 10) {
				if (i == nums.size() / 2 - 1)return "";
				anss.push_back(nums[i]);
				nums[nums.size() - i - 2]--;
			}
			else if (nums[i] == nums[nums.size() - i - 1] + 11) {
				anss.push_back(nums[i] - 1);
				nums[nums.size() - i - 2]--;
				nums[i + 1] += 10;
			}
			else if (nums[i] == nums[nums.size() - i - 1] + 1) {
				if (i == nums.size() / 2 - 1)return "";
				anss.push_back(nums[i] - 1);
				nums[i + 1] += 10;
			}
			else {
				return "";
			}
		}
		string from;
		string to;
		for (int i = 0; i < anss.size(); ++i) {
			if (anss[i] < 0)return "";
			if (anss[i] <= 9) {
				from.push_back(anss[i] + '0');
				to.push_back('0');
			}
			else if (anss[i] <= 18) {
				from.push_back('9');
				to.push_back((anss[i] - 9) + '0');
			}
			else {
				return "";
			}
		}
		reverse(to.begin(), to.end());
		from += to;
		if (from[0] == '0')return "";
		return from;
	}
	else {
		for (int i = 0; i < nums.size() / 2; ++i) {
			if (nums[i] == nums[nums.size() - i - 1]) {
				anss.push_back(nums[i]);
			}
			else if (nums[i] == nums[nums.size() - i - 1] + 10) {
				anss.push_back(nums[i]);
				nums[nums.size() - i - 2]--;
			}
			else if (nums[i] == nums[nums.size() - i - 1] + 11) {
				anss.push_back(nums[i] - 1);
				nums[nums.size() - i - 2]--;
				nums[i + 1] += 10;
			}
			else if (nums[i] == nums[nums.size() - i - 1] + 1) {
				anss.push_back(nums[i] - 1);
				nums[i + 1] += 10;
			}
			else {
				return "";
			}
		}
		string from;
		string to;
		for (int i = 0; i < anss.size(); ++i) {
			if (anss[i] < 0)return "";
			if (anss[i] <= 9) {
				from.push_back(anss[i] + '0');
				to.push_back('0');
			}
			else if (anss[i] <= 18) {
				from.push_back('9');
				to.push_back((anss[i] - 9) + '0');
			}
			else {
				return "";
			}
		}
		if (nums[nums.size() / 2] % 2) {
			return "";
		}
		else {
			from.push_back(nums[nums.size() / 2] / 2 + '0');
		}
		reverse(to.begin(), to.end());
		from += to;
		if (from[0] == '0')return "";
		return from;
	}
}

int main() {
	/*long long int N; cin >> N;
	long long int A, B, C; cin >> A >> B >> C;
	if (A <= (B - C)) {
	long long int ans = N / A;
	cout << ans << endl;
	}
	else {
	long long int num = (N - B) / (B - C);
	long long int rest = N - num*(B - C);
	long long int ans(num);
	while (rest >= B) {
	ans++;
	rest -= (B - C);
	}
	ans += rest / A;
	cout << ans << endl;
	}
	return 0;*/
	string st; cin >> st;
	vector<int>nums;
	for (int i = 0; i <st.size(); ++i) {
		nums.push_back(st[i] - '0');
	}
	N = st.size();

	if (nums[0] == 1 && nums.size() >= 2) {
		vector<int>newnums(nums.begin() + 1, nums.end());
		vector<int>anss;
		newnums[0] += 10;
		string ans(getans(newnums));
		if (ans != "") {
			cout << ans << endl;
			return 0;
		}
	}
	string ans(getans(nums));
	if (ans != "") {
		cout << ans << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}