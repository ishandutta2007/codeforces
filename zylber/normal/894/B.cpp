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
	if(e==0) return 1;
	tint ans = modexp(b, e/2);
	ans = (ans*ans)%MOD;
	if(e%2) ans = (ans*b)%MOD;
	return ans;
}

int main()
{
	tint n, m, k;
	cin >> n >> m >> k;
	if(n%2 != m%2 &&  k == -1) {
		cout << 0 << endl;
		return 0;
	}
	
	cout << modexp(modexp(2,n-1),m-1) << endl; 
    return 0;
}