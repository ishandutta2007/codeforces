#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


void D() {
	vector<int> a;
	string s;
	cin >> s;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a') {
			if (a.size() == 0)
				a.push_back(1);
			else
				a.back()++;
		}
		if (s[i] == 'b') {
			if (a.size() != 0 && a.back() != 0)
				a.push_back(0);
		}
	}
	if (a.size() == 0) {
		cout << 0;
		return;
	}
	long long p = 1;
	for (size_t i = 0; i < a.size(); i++)
	{
		p *= a[i] + 1;
		p %= 1000000007;
	}
	if (p == 0) {
		cout << 1000000006;
	}
	cout << p - 1;
	return;
}
int main() {
	D();
	return 0;
}