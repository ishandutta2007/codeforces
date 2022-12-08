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
	tint n, u;
	cin >> n >> u;
	vector<double> e(n);
	forn(i, n) cin >> e[i];
	double best = -1;
	int r = 0, l = 0;
	while(r < n) {
		while(l < n && e[l] - e[r] <= u) {
			l++;
		}
		if(l-r > 2) best = max(best, (e[l-1]-e[r+1])/(e[l-1]-e[r]));
		r++;
	}
	
	if(best < 0) {
		cout << best << endl;
	} else {
		printf("%.9f\n", best);
	}
}