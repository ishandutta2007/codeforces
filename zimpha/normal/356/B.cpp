#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;

int main() {
	long long n, m;
	string s1, s2;
	cin >> n >> m;
	cin >> s1 >> s2;

	long long lx = s1.size(), ly = s2.size();
	long long g = __gcd(lx, ly), T = lx * ly / g;
	long long ret = T;
	static int cnt[MAXN][26];
	for (int i = 0; i < ly; ++ i) cnt[i % g][s2[i] - 'a'] ++;
	for (int i = 0; i < lx; ++ i) ret -= cnt[i % g][s1[i] - 'a'];
	cout << ret * (n * lx / T) << endl;
	return 0;
}