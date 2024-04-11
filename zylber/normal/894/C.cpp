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
	vector<tint> s(n);
	forn(i, n) cin >> s[i];
	forn(i, n) if(s[i]%s[0]) {
		cout << -1 << endl;
		return 0;
	}
	
	if(n<=2) cout << n << endl; else cout << 2*n-3 << endl;
	
	if(n>=2) cout << s[1];
	forn(i, n-2) {
		cout << " " << s[0] << " " << s[i+2];
	}
	
	if(n == 2) cout << " ";
	if(n<=2) cout << s[0];
	cout << endl;
	
	return 0;
}