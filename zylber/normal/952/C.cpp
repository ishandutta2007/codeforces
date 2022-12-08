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
	vector<int> a(n);
	
	forn(i, n) cin >> a[i];
	forn(i, n-1) if(abs(a[i] - a[i+1]) > 1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}