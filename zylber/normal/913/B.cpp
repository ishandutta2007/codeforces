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
	int n;
	cin >> n;
	vector<int> isleaf(n, 1);
	vector<vector<int>> childs(n);
	
	isleaf[0] = 0;
	forn(i, n-1) {
		int k;
		cin >> k;
		k--;
		childs[k].push_back(i+1);
		isleaf[k] = 0;
	}
	
	forn(i, n) {
		if(isleaf[i]) continue;
		int cl = 0;	
		forn(j, childs[i].size()) {
			if(isleaf[childs[i][j]]) cl++;
		}
		if(cl < 3) {
			cout << "No" << endl;
			return 0;
		} 
	}
	cout << "Yes" << endl;
	return 0;
}