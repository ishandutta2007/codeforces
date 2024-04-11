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

void solve(int testid) {
	int r, c;
	cin >> r >> c;
	vector<string> s(r);
	for (size_t i = 0; i < r; i++)
		cin >> s[i];
	bool okall = true;
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			okall &= s[i][j] == 'A';
		}
	}
	if (okall) {
		cout << 0 << endl;
		return;
	}
	bool okl = true, okr = true;
	for (size_t i = 0; i < r; i++)
	{
		okl &= s[i][0] == 'A';
		okr &= s[i][c - 1] == 'A';
	}

	bool okt = true, okb = true;
	for (size_t i = 0; i < c; i++)
	{
		okt &= s[0][i] == 'A';
		okb &= s[r - 1][i] == 'A';
	}
	if (okt | okb | okl | okr) {
		cout << 1 << endl;
		return;
	}
	for (size_t i = 0; i < r; i++)
	{
		bool ok = true;
		for (size_t j = 0; j < c; j++)
		{
			if (s[i][j] == 'P') {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << 2 << endl;
			return;
		}
	}

	for (size_t i = 0; i < c; i++)
	{
		bool ok = true;
		for (size_t j = 0; j < r; j++)
		{
			if (s[j][i] == 'P') {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << 2 << endl;
			return;
		}
	}
	if (s[0][0] == 'A' || s[0][c - 1] == 'A' || s[r - 1][0] == 'A' || s[r - 1][c - 1] == 'A') {
		cout << 2 << endl;
		return;
	}
	bool wallr = false;
	for (size_t i = 0; i < r; i++)
	{
		wallr |= s[i][0] == 'A';
		wallr |= s[i][c - 1] == 'A';
	}
	for (size_t i = 0; i < c; i++)
	{
		wallr |= s[0][i] == 'A';
		wallr |= s[r - 1][i] == 'A';
	}
	if (wallr) {
		cout << 3 << endl;
		return;
	}
	bool ex = false;
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			ex |= s[i][j] == 'A';
		}
	}
	if (ex)
		cout << 4 << endl;
	else
		cout << "MORTAL" << endl;
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