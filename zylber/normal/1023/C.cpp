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

char get(string& s, int i) {
	if(i < 0 || i > (int) s.size()) return '.';
	return s[i];
}

int main() {
	tint n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	vector<int> pre(n+1), nex(n+1), act(n+1, 1);
	queue<int> rem;
	forn(i, n+1) {
		pre[i] = i-1;
		nex[i] = i+1;
		if(get(s, i) == '(' && get(s, i+1) == ')') rem.push(i);
	}
	
	while(n > k) {
		int a = rem.front(), b = nex[a];
		rem.pop();
		act[a] = 0; act[b] = 0;
		n -= 2;
		int c = pre[a], d = nex[b];
		if(c >= 0 && c < (int) s.size()) {
			nex[c] = d;
		}
		
		if(d >= 0 && d < (int) s.size()) {
			pre[d] = c;
		}
		
		if(get(s, c) == '(' && get(s, d) == ')') {
			rem.push(c);
		}
	}
	
	forn(i, s.size()) if(act[i]) cout << s[i];
	cout << endl;
	
	return 0;
}