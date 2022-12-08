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
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	int parity = 0;
	forn(i, n) forn(j, i) if(a[j] > a[i]) parity ^= 1;
	
	int m;
	cin >> m;
	forn(i, m) {
		int l, r;
		cin >> l >> r;
		parity += (r-l+1)/2;
		parity %= 2;
		if(parity) cout << "odd" << endl; else cout << "even" << endl;
	}
	return 0;
}