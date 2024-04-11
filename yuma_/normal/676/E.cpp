#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"

bool check(vector<long long int>nums, const long long int K){
	for (int i = 0; i < nums.size()-1; ++i) {
		if (abs(nums[i])>1e9)return false;
		else {

			nums[i + 1] += nums[i] * K;
			nums[i] = 0;
		}
	}
	return nums == vector<long long int>(nums.size());
}
int main() {
	int N, K; cin >> N >> K;
	int moved = 0;
	int zeromoved = false;
	vector<long long int>nums(N+1);
	for (int i = 0; i <= N; ++i) {
		string st; cin >> st;
		if (st == "?") {

		}
		else {
			moved++;
			if (i == 0)zeromoved = true;
			nums[N-i] = stoi(st);
		}
	}
	if (moved == N+1) {
		bool ok = check(nums, K);
		if (ok)cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}else if (K) {
		bool pfinal = (N) % 2;
		if (pfinal) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		return 0;
	}
	else {
		if (zeromoved) {
			if (nums[N])cout << "No" << endl;
			else cout << "Yes" << endl;
		}
		else {

			bool isp = moved % 2;
			if (isp) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}