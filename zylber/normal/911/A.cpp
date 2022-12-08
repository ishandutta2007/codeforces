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
	int n;
	cin >> n;
	int m = 1000000010, ans = n;
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	forn(i, n) m = min(m, a[i]);
	int prev = -n;
	forn(i, n) if(a[i] == m) {
		ans = min(ans, i-prev);
		prev = i;
	}
	cout << ans << endl;
	
	return 0;
}