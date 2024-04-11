#include <stdio.h>
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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

vector<int> pf (string s) {
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

void add(string& s, char x, vi& c) {
  if (c[x-'0'] <= 0) x = x=='0' ? '1' : '0';
  s += x;
  c[x-'0']--;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s, t;
  cin >> s >> t;
  if (s.size() < t.size()) {
    cout << s << endl;
    return 0;
  }
  vi c(2);
  for (int i = 0; i < s.size(); ++i) {
    c[s[i]-'0']++;
  }
  auto p = pf(t);
  int l = t.size() - p.back();
  string res = "";
  for (int i = 0; i < t.size(); ++i) {
    add(res, t[i], c);
  }
  for (int i = t.size(); i < s.size(); ++i) {
    add(res, t[(i - t.size()) % l + p.back()], c);
  }
  cout << res << endl;
  return 0;
}