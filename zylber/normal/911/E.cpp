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
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	forn(i, k) cin >> p[i];
	
	int r = 0;
	set<int> nums;
	nums.insert(n+1);
	forn(i, k) {
		if(!nums.empty() && p[i] > *(nums.begin())) {
			cout << -1 << endl;
			return 0;
		}
		nums.insert(p[i]);
		while(r < n && *(nums.begin()) == r+1) {
			nums.erase(nums.begin());
			r++;
		}
	}
	
	while(!nums.empty()) {
		int s = *(nums.begin());
		for(int i = s-1; i > r; i--) {
			p[k] = i;
			k++;
		}
		r = s;
		nums.erase(nums.begin());
	}
	
	forn(i, n) {
		if(i) cout << " ";
		cout << p[i];
	}
	cout << endl;
}