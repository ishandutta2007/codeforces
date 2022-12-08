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
		int n;
		cin >> n;
		
		vi a(n);
		forn(i, n) cin >> a[i];
		
		forn(i, n) {
			if(i) cout << " ";
			if(i%2) cout << -abs(a[i]); else cout << abs(a[i]);
		}
		
		cout << endl;
	}
}