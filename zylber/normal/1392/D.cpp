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
		int n;
		string a;
		cin >> n >> a;
		int iguale = 1;
		forn(i, n-1) {
			if(a[i] != a[i+1]) iguale = 0;
		}
		
		tint ans = 0;
		if(iguale) {
			ans = 1 + (n-1)/3;
		} else {
			forn(i, n) {
				if(a[i] != a[(i+n-1)%n]) {
					tint l = 0, k = i;
					while(a[k] == a[i]) {
						l++;
						k = (k+1)%n;
					}
					ans += l/3;
				}
			}
		}
		cout << ans << endl;
	}
}