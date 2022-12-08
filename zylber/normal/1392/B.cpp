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
		tint n, k;
		cin >> n >> k;
		vi a(n);
		forn(i, n) {
			cin >> a[i];
		}
		
		tint d = a[0];
		forn(i, n) {
			d = max(d, a[i]);
		}
		
		
		forn(i, n) {
			a[i] = d-a[i];
		}
		d = a[0];
		forn(i, n) {
			d = max(d, a[i]);
		}
		
		forn(i, n) {
			if(i) cout << " ";
			if(k%2) {
				cout << a[i];
			}
			else {
				cout << d-a[i];
			}
		}
		cout << endl;
	}
}