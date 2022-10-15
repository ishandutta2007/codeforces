#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<iterator>

using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		cout << max(0, n - 2) << endl;
	}
	return 0;
}