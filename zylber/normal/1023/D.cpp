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
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> s(q+1, -1), e(q+1, -1);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	
	forn(i, n) {
		if(s[a[i]] == -1) s[a[i]] = i;
	}
	
	dforn(i, n) {
		if(e[a[i]] == -1) e[a[i]] = i;
	}
	
	vector<pair<int, int>> events;
	forsn(i, 2, q+1) {
		if(s[i] != -1) {
			events.push_back({s[i], i});
			events.push_back({e[i]+1, i});
		}
	}
	events.push_back({0, 1});
	events.push_back({n+1, 1});
	if(s[q] == -1 && s[0] == -1) {
		cout << "NO" << endl;
		return 0;
	}
	if(q > 1 && s[q] == -1) {
		events.push_back({s[0], q});
		events.push_back({s[0]+1, q});
	}
	sort(events.begin(), events.end());
	
	int actt = 0, acti = 0;
	set<int> acts;
	vector<int> ans(n);
	while(actt < n) {
		while(events[acti].first == actt) {
			int a = events[acti].second;
			if(acts.count(a)) {
				acts.erase(a);
			} else {
				acts.insert(a);
			}
			acti++;
		}
		auto it = acts.end();
		it--;
		ans[actt] = *it;
		actt++;
	}
	
	int valid = 1;
	forn(i, n) {
		if(a[i] != 0 && a[i] != ans[i]) valid = 0;
	}
	
	if(valid) {
		cout << "YES" << endl;
		forn(i, n) {
			if(i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}