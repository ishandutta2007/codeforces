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
	int h;
	cin >> h;
	h++;
	vector<int> a(h);
	forn(i, h) cin >> a[i];
	
	int rompe = 0;
	forn(i, h-1) if(a[i] > 1 && a[i+1] > 1) rompe = 1;
	
	if(!rompe) {
		cout << "perfect" << endl;
	} else {
		cout << "ambiguous" << endl;
		cout << 0;
		int printed = 1;
		forn(i, h-1) {
			forn(j, a[i+1]) cout << " " << printed;
			printed += a[i+1];
		}
		cout << endl;
		
		printed = 1;
		cout << 0;
		forn(i, h-1) {
			if(a[i] > 1) cout << " " << printed - 1; else cout << " " << printed;
			forn(j, a[i+1]-1) cout << " " << printed;
			printed += a[i+1];
		}
		cout << endl;
	}
	
	return 0;
}