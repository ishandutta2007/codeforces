#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

typedef vector<int> vi;

int main() {
	string s;
	cin >> s;
	for (int i = s.size() - 1; i >= 0; --i) {
		for (int j = 0; j + i <= s.size(); ++j) {
			string cur(s.begin() + j, s.begin() + i + j);
//			cout << i << cur << endl;
			int count = 0;
			for (int l = 0; l + i <= s.size(); ++l) {
				string test(s.begin() + l, s.begin() + i + l);
				if (cur == test)
					++count;
			}
			if (count >= 2) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}