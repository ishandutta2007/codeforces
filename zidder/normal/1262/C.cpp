#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int t;
void yes() {
	cout << "Yes" << endl;
	if (t == 1)
		exit(0);
}

void no() {
	cout << "No" << endl;
	if (t == 1)
		exit(0);
}

void solve(int test_id) {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<int, int> > op;
	for (size_t i = 0; i < 2 * k - 2; i++)
	{
		if (s[i] == ')')
			for (size_t j = 1 + i; j < n; j++)
			{
				if (s[j] == '(') {
					op.emplace_back(i, j);
					s[j] = ')';
					s[i] = '(';
					break;
				}
			}
		i++;
		if (s[i] == '(')
			for (size_t j = i + 1; j < n; ++j) {
				if (s[j] == ')') {
					op.emplace_back(i, j);
					s[j] = '(';
					s[i] = ')';
					break;
				}
			}
	}
	for (int i = 2 * k - 2; i < n / 2 + k; ++i) {
		if (s[i] != '(')
			for (size_t j = 1 + i; j < n; j++)
			{
				if (s[j] == '(') {
					op.emplace_back(i, j);
					s[j] = ')';
					s[i] = '(';
					break;
				}
			}
	}
	cout << op.size() << endl;
	for (size_t i = 0; i < op.size(); i++)
	{
		cout << op[i].first + 1 << " " << op[i].second + 1 << endl;
	}
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
1
10 5
()((()()))
*/