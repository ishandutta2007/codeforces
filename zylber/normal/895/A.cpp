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
	vector<tint> a(n);
	forn(i,n) cin >> a[i];
	tint ans = 360;
	forn(i,n) {
		tint sum = 0;
		for(int j = i; j < n; j++) {
			sum += a[j];
			tint dif = abs(360-2*sum);
			ans = min(ans, dif);
		}
	}
	cout << ans << endl;
    return 0;
}