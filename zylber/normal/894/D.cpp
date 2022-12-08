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

tint query(tint h, vector<tint>& dists, vector<tint> &sums) {
	int top = dists.size(), bot = 0;
	while(top-bot>1) {
		tint mid = (top+bot)/2;
		if(dists[mid] <= h) {
			bot = mid;
		} else {
			top = mid;
		}
	}
	return h*top-sums[top-1];
}

int main()
{
	tint n, m;
	scanf("%I64d %I64d", &n, &m);
	vector<tint> l(n+1);
	forn(i, n-1) scanf("%I64d", &(l[i+2]));
	
	vector<vector<tint> > dists(n+1);
	vector<vector<tint> > sums(n+1);
	for(int i = n; i>=1; i--) {
		dists[i].push_back(0);
		if(2*i < n) {
			vector<tint> newdists(dists[2*i].size()+dists[2*i+1].size()), distizq, distder;
			forn(j, dists[2*i].size()) {
				distizq.push_back(dists[2*i][j]+l[2*i]);
			}
			forn(j, dists[2*i+1].size()) {
				distder.push_back(dists[2*i+1][j]+l[2*i+1]);
			}
			merge(distizq.begin(),distizq.end(),distder.begin(), distder.end(),newdists.begin());
			forn(j, newdists.size()) {
				dists[i].push_back(newdists[j]);
			}
		}
		
		if(2*i == n) {
			forn(j, dists[2*i].size()) {
				dists[i].push_back(dists[2*i][j]+l[2*i]);
			}
		}
		
		forn(j, dists[i].size()) {
			if(j) sums[i].push_back(sums[i][j-1]+dists[i][j]); else sums[i].push_back(0);
		}
	}
	
	forn(i, m) {
		tint a, h;
		cin >> a >> h;
		tint ans = 0;
		ans += query(h, dists[a], sums[a]);
		tint prev = a;
		while(a/2 > 0) {
			prev = a;
			h-= l[a];
			a/=2;
			int b = 2*a;
			if(h>=0) ans+=h;
			if(b==prev) b++;
			if(b > n) continue;
			if(h>=l[b]) ans += query(h-l[b], dists[b], sums[b]);
			
		}
		printf("%lli\n",ans);
	}
	
	return 0;
}