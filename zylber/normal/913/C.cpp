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
	tint n, l;
	cin >> n >> l;
	vector<tint> c(31, 2000000000000000000LL);
	forn(i, n) cin >> c[i];
	
	forn(i, 30) c[i+1] = min(c[i+1], 2*c[i]);
	dforn(i, 30) c[i] = min(c[i], c[i+1]);
	
	tint ans = 2000000000000000000LL, voy = 0;
	while(l > 0) {
		tint p = 0;
		while((1LL<<p) <= l) p++;
		ans = min(ans, voy+c[p]);
		voy += c[p-1];
		l -= (1LL << (p-1));
	}
	ans = min(ans, voy);
	cout << ans << endl;
	return 0;
}