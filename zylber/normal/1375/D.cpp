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

bool check(vi& a) {
	forn(i, a.size()-1) {
		if(a[i] > a[i+1]) return false;
	}
	return true;
}

int main()
{
	int C;
	cin >> C;
	forn(tc, C) {
		int n;
		cin >> n;
		vi a(n), ans;
		forn(i, n) cin >> a[i];
		while(!check(a)) {
			vector<int> cnt(n+1, 0);
			forn(i, n) cnt[a[i]]++;
			int mex = 0;
			while(cnt[mex]) mex++;
			if(mex == n) {
				int next = 0;
				while(a[next] == next) next++;
				ans.push_back(next+1);
				a[next] = mex;
			} else {
				ans.push_back(mex+1);
				a[mex] = mex;
			}
		}
		
		cout << ans.size() << endl;
		forn(i, ans.size()) {
			if(i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}