#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

string RSP = "RSP";

int get(char a, char b) {
	if (a == b)
		return 0;
	int ia = RSP.find(a), ib = RSP.find(b);
	if ((ia + 1) % 3 == ib)
		return 1;
	else
		return -1;
}

int main() {
	int n;
	string a, b;
	cin >> n >> a >> b;

	int ca = 0, cb = 0;
	for (int i = 0; i < a.size() * b.size(); ++i) {
		int t = get(a[i % a.size()], b[i % b.size()]);
		if (t == 1)
			++ca;
		else if (t == -1)
			++cb;
	}

	ca *= n / (a.size() * b.size());
	cb *= n / (a.size() * b.size());

	for (int i = 0; i < n % (a.size() * b.size()); ++i) {
		int t = get(a[i % a.size()], b[i % b.size()]);
		if (t == 1)
			++ca;
		else if (t == -1)
			++cb;
	}

	cout << cb << " " << ca << endl;
	return 0;
}