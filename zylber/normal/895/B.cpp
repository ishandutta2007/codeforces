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
	tint n, x, k;
	cin >> n >> x >> k;
	vector<tint> a(n);
	forn(i,n) cin >> a[i];
	sort(a.begin(),a.end());
	vector<tint> r(n), l(n);
	forn(i,n) {
		r[i] = (a[i]+x-1)/x;
		l[i] = a[i]/x;
	}
	
	int actld = 0, actlu = 0;
	tint ans = 0;
	forn(i, n) {
		while(actld != n && a[actld] < a[i]) actld++;
		actlu = max(actld, actlu);
		while(actld != n && l[actld] < r[i]+k-1) actld++;
		while(actlu != n && l[actlu] < r[i]+k) actlu++;
		ans += actlu-actld;
	}
	cout << ans << endl;
    return 0;
}