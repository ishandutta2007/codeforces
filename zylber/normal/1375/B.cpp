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
		int n, m;
		cin >> n >> m;
		vvi mn(n, vi(m, 0)), a(n, vi(m, 0));
		forn(i, n) forn(j, m) {
			if(i > 0) mn[i][j]++;
			if(j > 0) mn[i][j]++;
			if(i < n-1) mn[i][j]++;
			if(j < m-1) mn[i][j]++;
		}
		
		forn(i, n) forn(j, m) cin >> a[i][j];
		
		int possible = 1;
		forn(i, n) forn(j, m) {
			if(a[i][j] > mn[i][j]) possible = 0;
		}
		
		if(possible) {
			cout << "YES" << endl;
			forn(i, n) {
				forn(j,m) {
					if(j) cout << " ";
					cout << mn[i][j];
				}
				cout << endl;
			}
		} else {
			cout << "NO" << endl;
		}
	}
}