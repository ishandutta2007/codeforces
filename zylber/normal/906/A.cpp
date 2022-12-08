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

bool unique(vector<int>& estado) {
	int s = 0;
	forn(i, 26) s += estado[i];
	return s == 1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> estado(26, 1);	
	int ans = 0;
	forn(i, n-1) {
		char c;
		cin >> c;
		if(c == '!') {
			if(unique(estado)) ans++;
			string w;
			cin >> w;
			vector<int> mask(26, 0);
			forn(i, w.size()) {
				mask[w[i]-'a'] = 1;
			}
			
			forn(i, 26) {
				estado[i] &= mask[i];
			}
		}
		
		if(c == '.') {
			string w;
			cin >> w;
			forn(i, w.size()) estado[w[i]-'a'] = 0;
		}
		
		if(c == '?') {
			if(unique(estado)) ans++;
			char d;
			cin >> d;
			estado[d-'a'] = 0;
		}
	}
	
	cout << ans << endl;
	return 0;
}