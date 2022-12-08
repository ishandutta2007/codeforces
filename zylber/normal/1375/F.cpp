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
typedef vector<pii> vp;
typedef vector<vp> vvp;

tint getd(vi a) {
	sort(a.begin(), a.end());
	return 2*a[2] - a[0] - a[1];
}

tint check(vi a) {
	sort(a.begin(), a.end());
	return a[2] - a[1] == a[1] - a[0];
}

tint lastd(vi a) {
	sort(a.begin(), a.end());
	return a[2] - a[1];
}

int main()
{
		vi a(3);
		forn(i, 3) cin >> a[i];
		
		cout << "First" << endl;
		cout.flush();
		
		tint y = getd(a);
		cout << y << endl;
		cout.flush();
			
		int pila;
		cin >> pila;
		if(pila == 0) return 0;
		a[pila-1] += y;
		
		while(true) {
			tint y = getd(a);
			if(check(a)) {
				y = lastd(a);
			}
			cout << y << endl;
			cout.flush();
			
			int pila;
			cin >> pila;
			if(pila == 0) return 0;
			a[pila-1] += y;
		}
}