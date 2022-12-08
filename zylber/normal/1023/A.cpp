#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(int a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define eps 0.000000000001
typedef long long tint;
using namespace std;
#define MAXN 1000010

int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	string goal = "";
	if(m+1 < n) {
		cout << "NO" << endl;
		return 0;
	}
	
	int i = 0;
	while(s[i] != '*' && i < n) {
		goal += s[i];
		i++;
	}
	if(s[i] == '*') forn(j, m-n+1) {
		goal += t[i+j];
	}
	
	i++;
	while(i < n) {
		goal += s[i];
		i++;
	}
	
	if(goal == t) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}