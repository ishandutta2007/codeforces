#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;

string convert(string s) {
	for (char& c : s) {
		if ('A' <= c && c <= 'Z') {
			c = c - 'A' + 'a';
		}
	}
	for (char& c : s) {
		if (c == 'o') {
			c = '0';
		}
	}
	for (char& c : s) {
		if (c == 'l' || c == 'i') {
			c = '1';
		}
	}
	return s;
}

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s; int n; cin >> s >> n;
    s = convert(s);
    for (int i = 0; i < n; i++) {
    	static char buf[100500];
    	scanf("%s", buf);
    	if (s == convert(string(buf))) {
    		puts("No");
    		return 0;
    	}
    }
    puts("Yes");
    return 0;
}