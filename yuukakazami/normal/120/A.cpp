#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string a;
	int b;
	cin >> a >> b;
	if (a == "front")
		cout << (b == 1 ? 'L' : 'R') << endl;
	else
		cout << (b == 2 ? 'L' : 'R') << endl;
	return 0;
}