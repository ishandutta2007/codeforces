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

void calcp(vector<int> &ans, int n) {
	if(n == 0) return;
	
	int s = 1;
	while(2*s <= n) s *=2;
	
	forn(i, n-s+1) {
		ans[s+i] = s-i-1;
		ans[s-i-1] = s+i;
	}
	calcp(ans, 2*(s-1)-n);
}

int main()
{
	int n;
	cin >> n;
	if(n%2) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		vector<int> ans(n+1);
		calcp(ans, n);
		forn(i, n) {
			if(i) cout << " ";
			cout << ans[i+1];
		}
		cout << endl;
	}
	
	int s = 1;
	while(s < n) s *= 2;
	if(n <= 5 || s == n) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		if(n == 6) cout << "3 6 1 5 4 2" << endl;
		if(n > 6) {
			cout << "3 6 1 5 4 7 2";
			int p = 15;
			for(int i = 8; i <= n; i++) {
				if(i == n || i == p) {
					cout << " " << (p+1)/2;
					p = 2*p+1;
				} else {
					cout << " " << i+1;
				}
			}
			cout << endl;
		}
	}
	return 0;
}