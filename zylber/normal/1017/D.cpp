// C++11
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <sys/time.h>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#define GETT(i, j) get(i, j, n, k, board, mask)
typedef long long tint;
using namespace std;

int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	vector<string> s(m);
	vector<tint> w(n);
	forn(i, n) scanf("%l64d", &w[i]);
	
	vector<vector<int>> wu(1 << n, vector<int>(1 << n, 0));
	vector<int> maskv(1<<n, 0);
	forn(i, 1<<n) forn(j, n) {
		if(i&(1<<j)) maskv[i] += w[j];
	}
	
	forn(i, 1<< n) forn(j, 1 << n) {
		wu[i][j] = maskv[(1<<n) - 1 - (i^j)];
	}
	
	vector<int> cant(1<<n, 0);
	forn(i, m) {
		cin >> s[i];
		tint act = 0;
		forn(j, n) act += (s[i][j] == '1')*(1<<j);
		cant[act]++;
	}
	
	vector<vector<int>> tw(1<<n, vector<int>(200, 0));
	forn(i, 1<< n) forn(j, 1 << n)  {
		if(wu[i][j] < 200) tw[i][wu[i][j]] += cant[j];
	}
	
	forn(i, 1<<n) forn(j, 200) {
		if(j) tw[i][j] += tw[i][j-1];
	}
	
	forn(i, q) {
		char t[n];
		int k;
		tint act = 0;
		scanf("%s %d", t, &k);
		forn(j, n) act += (t[j] == '1')*(1<<j);
		printf("%d\n" , tw[act][k]);
	}
}