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

tint modexp(tint b, tint e) {
	if(e == 0) return 1;
	tint ans = modexp(b, e/2);
	ans = (ans*ans)%MOD;
	if(e%2) ans = (ans*b)%MOD;
	return ans;
}

tint inv(tint a) {
	return modexp(a, MOD-2);
}

tint choose(tint n, tint k) {
	tint ans = 1;
	forn(i, k) {
		ans = (ans*(n-i))%MOD;
		ans = (ans*inv(i+1))%MOD;
	}
	return ans;
}

int main()
{
	tint LIMIT = 1000001;
	vector<tint> criba(LIMIT, 1);
	forn(i, LIMIT) {
		if(i >= 2) {
			if(criba[i] == 1) {
				for(int k = i; k < LIMIT; k += i) {
					criba[k] = i;
				}
			}
		}
	}
	
	tint q;
	cin >> q;
	forn(i, q) {
		tint x, y;
		cin >> x >> y;
		tint ans = modexp(2, y-1);
		while(x > 1) {
			tint cp = 0, p = criba[x];
			while(x%p == 0) {
				cp++;
				x/=p;
			}
			ans = (ans*choose(y+cp-1,cp))%MOD;
		}
		cout << ans << endl;
	}
    return 0;
}