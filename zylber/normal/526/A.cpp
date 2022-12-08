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
#ifdef ACMTUYO
	freopen("A.in","r",stdin);
#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int can=0;
	forn(i, n)
	{
		for(int d=1; i+4*d<n; d++)
		{
			int good=1;	
			forn(j, 5)
			{
				if(s[i+j*d]!='*') good=0;
			}
			if(good) can=1;
		}
	}
	
	
	if(can) cout << "yes" << endl; else cout << "no" << endl;
	
	return 0;
}