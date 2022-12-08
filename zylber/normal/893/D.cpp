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
	tint n, d;
	cin >> n >> d;
	vector<tint> a(n);
	
	forn(i, n) cin >> a[i];
	
	vector<tint> tengo(n+1);
	tengo[0] = 0;
	forn(i, n) {
		tengo[i+1] = tengo[i] + a[i];
		if(tengo[i+1] > d) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	vector<tint> tot(n+1);
	tot[n] = tengo[n];
	dforn(i, n) {
		tot[i] = max(tot[i+1], tengo[i]);
	}
	
	tint dep = 0, hay = 0, deposite = 0;
	forn(i, n) {
		hay += a[i];
		if(a[i] == 0 && hay < 0) {
			tint pongo = d-deposite-tot[i];
			if(hay+pongo<0) {
				cout << -1 << endl;
				return 0;
			}
			hay += pongo;
			deposite += pongo;
			dep++;
		}
	}
	
	cout << dep << endl;
    return 0;
}