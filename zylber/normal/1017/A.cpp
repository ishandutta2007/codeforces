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

int main() { ios::sync_with_stdio(false); cin.tie(NULL);
	tint n;
	cin >> n;
	vector<pair<tint,int>> scores;
	forn(i, n) {
		tint a, b, c, d;
		cin >> a >> b >> c >> d;
		scores.push_back({-(a+b+c+d), i});
	}
	
	sort(scores.begin(), scores.end());
	forn(i, n) if(scores[i].second == 0) cout << i+1 << endl;
}