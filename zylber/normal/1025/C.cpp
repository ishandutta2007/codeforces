#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(int a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define eps 0.000000000001
typedef long long tint;
using namespace std;
#define MAXN 1000010

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int act = 1, ans = 1;
	s += s;
	forsn(i, 1, 2*n) {
		if(s[i] != s[i-1]) act++; else act = 1;
		ans = max(ans, act);
	}
	cout << min(n, ans) << endl;
	return 0;
}