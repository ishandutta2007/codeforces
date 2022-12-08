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
	double r;
	cin >> n >> r;
	vector<double> x(n);
	forn(i, n) cin >> x[i];
	vector<double> y(n, 0);
	
	forn(i, n) {
		y[i] = r;
		forn(j, i) {
			if(abs(x[i]-x[j])-EPS < 2.0*r) {
				y[i] = max(y[i], y[j]+sqrt(4.0*r*r-abs(x[i]-x[j])*abs(x[i]-x[j])));
			}
		}
	}
	
	forn(i, n) {
		if(i) printf(" ");
		printf("%.9f", y[i]);
	}
	printf("\n");
}