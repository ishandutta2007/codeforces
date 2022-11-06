#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

const int My_Inf = 2147483647;
const long long int My_LInf = 9223372036854775807;

int main() {
	int N; cin >> N;
	vector<bool>nuts;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		nuts.push_back(a);
	}
	int num = 0;
	bool a = false;
	unsigned long long int ans = 1;
	for (int i = 0; i < N; ++i) {
		if (a == false) {
			if (nuts[i]) {
				a = true;
			}
		}
		else {
			if (nuts[i]) {
				ans *= (num + 1);
				num = 0;
			}
			else {
				num++;
			}
		}
	}
	if (!a)ans = 0;
	cout << ans << endl;
	return 0;
}