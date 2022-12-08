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
	string s;
	cin >> s;
	int ss = s.size(), ans = 0;
	forn(i, ss)
	forn(j, i)
	forn(k, j) {
		if(s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') ans++;
	}
	cout << ans << endl;
    return 0;
}