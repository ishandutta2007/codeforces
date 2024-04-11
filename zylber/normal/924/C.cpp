#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

int main()
{
	tint n;
	cin >> n;
	vector<tint> m(n);
	forn(i, n) cin >> m[i];
	vector<tint> a(n);
	a[0] = m[0];
	forn(i, n-1) a[i+1] = max(a[i], m[i+1]);
	dforn(i, n-1) a[i] = max(a[i], a[i+1]-1);
	
	tint ans = 0;
	forn(i, n) ans += a[i] - m[i];
	cout << ans << endl;
}