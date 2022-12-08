// C++11
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <sys/time.h>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#define GETT(i, j) get(i, j, n, k, board, mask)
typedef long long tint;
using namespace std;

int main() {
	tint n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<tint> c(4, 0);
	forn(i, n) {
		c[2*(a[i]-'0')+(b[i]-'0')]++;
	}
	
	tint ans = c[0]*c[3] + c[0]*c[2] + c[2] * c[1];
	cout << ans << endl;
}