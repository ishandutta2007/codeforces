#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<string> s(3);
	cin >> s[0] >> s[1] >> s[2];
	vector<int> c(3);
	for (int k=0;k<3;++k){
		for (int i=0;i<2*n;++i){
			c[k] += s[k][i] == '1';
		}
	}
	auto construct = [&](string a, string b, char c) -> string {
		string res = "";
		int cnt1 = 0, cnt2=0;
		vector<int> ones;
		for (int i=0;i<2*n;++i){
			if (a[i] == c) cnt1++;
			else {
				ones.push_back(cnt1);
			}
			if (b[i] == c) cnt2++;
			else {
				ones.push_back(cnt2);
			}
		}
		int cnt = max(cnt1, cnt2);
		sort(ones.begin(), ones.end());
		int ind = 0;
		for (int i=0;i<cnt;++i){
			while (ind < ones.size() && ones[ind] == i) {
				res += c^1;
				ind++;
			}
			res += c;
		}
		while (ind < ones.size() && ones[ind] == cnt) {
			res += c^1;
			ind++;
		}
		return res;	
	};

	if (c[0] <= n && c[1] <= n) {
		cout << construct(s[0], s[1], '0') << endl;
		return;
	}
	if (c[0] <= n && c[2] <= n) {
		cout << construct(s[0], s[2], '0') << endl;
		return;
	}
	if (c[1] <= n && c[2] <= n) {
		cout << construct(s[2], s[1], '0') << endl;
		return;
	}
	if (c[0] >= n && c[1] >= n) {
		cout << construct(s[0], s[1], '1') << endl;
		return;
	}
	if (c[0] >= n && c[2] >= n) {
		cout << construct(s[0], s[2], '1') << endl;
		return;
	}
	if (c[1] >= n && c[2] >= n) {
		cout << construct(s[2], s[1], '1') << endl;
		return;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}