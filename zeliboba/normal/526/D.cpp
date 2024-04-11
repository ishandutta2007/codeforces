#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vector<int> kmp (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

vector<int> zf (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int main() {
    int n,k;
    string s;
    cin >> n >> k >> s;
    vi p = kmp(s);
    vi z = zf(s);
    vi ok(n);
    vi q(n + 1);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int l = i + 1;
        if (l % k == 0 && (l/k) % (l - p[i]) == 0) {
            ok[i] = 1;
            if (i + 1 < n && z[i+1] > 0) {
                q[i] += 1;
                q[i+1+min(z[i+1], l/k)] -= 1;
            }
        }
        sum += q[i];
        if (sum > 0) ok[i] = 1;
    }
    for (int i = 0; i < n; ++i) printf("%d", ok[i]);
    return 0;
}