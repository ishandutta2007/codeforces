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
	vector<pair<tint, char> > points(n);
	forn(i, n) {
		cin >> points[i].first >> points[i].second;
	}
	
	tint ans = 0;
	tint lg = -1;
	forn(i, n) {
		if(points[i].second == 'G') {
			if(lg != -1) ans += points[i].first - lg;
			lg = points[i].first;
		}
	}	
	
	if(lg != -1) {
		points.push_back(make_pair(10000000000LL, 'G'));
		lg = -10000000000LL;
		tint lb = 0, lr = 0, mb = 0, mr = 0;
		forn(i, n+1) {
			if(points[i].second == 'B') {
				if(mb == 0) mb = points[i].first - lg; else mb = max(mb,  points[i].first - lb);
				lb = points[i].first;
			}
			
			if(points[i].second == 'R') {
				if(mr == 0) mr = points[i].first - lg; else mr = max(mr,  points[i].first - lr);
				lr = points[i].first;
			}
			
			if(points[i].second == 'G') {
				tint add = 0;
				if(mb != 0) {
					mb = max(mb, points[i].first - lb);
					add += points[i].first - lg - mb;		
				}
					
				if(mr != 0) {
					mr = max(mr, points[i].first - lr);
					add += points[i].first - lg - mr;
				}
				ans += min(add, points[i].first - lg);
				lg = points[i].first;
				mb = 0;
				mr = 0;
			}
		}
	} else {
		tint lb = -1, lr = -1;
		forn(i, n) {
			if(points[i].second == 'R') {
				if(lr != -1) ans += points[i].first - lr;
				lr = points[i].first;
			}
			if(points[i].second == 'B') {
				if(lb != -1) ans += points[i].first - lb;
				lb = points[i].first;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}