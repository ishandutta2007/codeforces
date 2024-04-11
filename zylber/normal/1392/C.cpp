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
using namespace std;
typedef long long tint;
typedef pair<tint, tint> pii;
typedef vector<tint> vi;
typedef vector<vi> vvi;

int main()
{
	int C;
	cin >> C;
	forn(tc, C) {
		tint n;
		cin >> n;
		vi a(n);
		forn(i, n) {
			cin >> a[i];
		}
		tint ans = 0;
		forn(i, n-1) if(a[i] > a[i+1]) ans += a[i]-a[i+1];
		cout << ans << endl;
	}
}