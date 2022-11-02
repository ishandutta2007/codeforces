#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long int64;
int64 n, m;
string a, b;

const int MAX_LEN = int(1e6) + 10;
int cnt[MAX_LEN][26];

int main() {
	cin >> n >> m;
	cin >> a >> b;
	int k = __gcd(a.size(), b.size());
	//i%k==j%k
	int64 mul = n / (b.size() / k);
	for (int i = 0; i < b.size(); ++i) {
		++cnt[i % k][b[i] - 'a'];
	}
	int64 ret = 0;
	for (int i = 0; i < a.size(); ++i) {
		ret += cnt[i % k][a[i] - 'a'];
	}
//	cout << ret << endl;
	ret *= mul;
	cout << n * (int) a.size() - ret << endl;
}