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
typedef tint tipo;
using namespace std;

int main()
{
#ifdef ACMTUYO
	freopen("B.in","r",stdin);
#endif
	
	int n;
	cin >> n;
	int e = 0;
	while((1<<e) < n) e++;
	
	vector<vector<int> > questions(2*e, vector<int>());
	forn(i, n) {
		forn(j, e) {
			if(i&(1<<j)){
				questions[2*j+1].push_back(i+1);
			}
			else
			{
				questions[2*j].push_back(i+1);
			}
		}
	}
	
	vector<vector<int> > answers(2*e, vector<int>(n));
	forn(i, 2*e) {
		cout << questions[i].size() << endl;
		forn(j, questions[i].size()) {
			if(j) cout << " ";
			cout << questions[i][j];
		}
		cout << endl;
		fflush(stdout);
	
		forn(j, n) cin >> answers[i][j];
	}
	
	cout << -1 << endl;
	forn(i, n) {
		int ans = 1000000000;
		forn(j, e) {
			if(i&(1<<j)){
				ans = min(ans, answers[2*j][i]);
			}
			else
			{
				ans = min(ans, answers[2*j+1][i]);
			}
		}
		if(i) cout << " ";
		cout << ans;
	}
	cout << endl;
	fflush(stdout);
	
	return 0;
}