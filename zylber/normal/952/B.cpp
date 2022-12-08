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
	forn(i, 10) {
		cout << i << endl << flush;
		string s;
		getline(cin, s);
		if(s == "great" || s == "cool" || s == "not bad" || s == "don't think so" || s == "don't touch me") {
			cout << "normal" << endl << flush;
			return 0;
		}
		if(s != "no") {
			cout << "grumpy" << endl << flush;
			return 0;
		}
	}
	return 0;
}