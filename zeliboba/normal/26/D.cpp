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
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (n + k < m) {
		cout << 0 << endl;
		return 0;
	}
	if (k >= m) {
		cout << 1 << endl;
		return 0;
	}
	double sub = 1;
	for (int i = 0; i <= k; ++i) {
		sub *= (double)(m - k + i) / (double)(n + i + 1);
	}
	printf("%.4lf\n", 1 - sub);
	return 0;
}