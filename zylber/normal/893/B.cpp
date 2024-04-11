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
	tint n;
	cin >> n;
	tint k = 3, ans = 1;
	while((1LL<<(k-1))<=n) {
		if(n%((1LL<<k)-(1LL<<(k/2)))==0) {
			ans = (1LL<<k)-(1LL<<(k/2));
		}
		k+=2;
	}
	cout << ans << endl;
    return 0;
}