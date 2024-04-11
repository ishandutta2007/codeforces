#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <map>

#define ll long long
#define dbl long double

using namespace std;
int t;


const long long MOD = 998244353;

void solve(int test_id) {
	string s;
	cin >> s;
	vector<int> dels;
	for (size_t i = 2; i < s.size(); i++)
	{
		if (s[i] == 'o'  && s[i - 1] == 'w' && s[i - 2] == 't' || s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'e') {
			if (dels.empty() || dels.back() < i - 2) {
				if (s[i] == 'e' || s[i] == 'o' && i + 1 < s.size() && s[i + 1] != 'n')
					dels.push_back(i - 1);
				else
					dels.push_back(i);
			}
		}
	}
	cout << dels.size() << endl;
	for (int d : dels)
		cout << d + 1 << " ";
	cout << endl;
}

int main() {
	t = 1;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*

*/