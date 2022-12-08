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
	tint n, t;
	cin >> n >> t;
	
	vector<pair<tint, pair<tint, tint>>> p(n);
	forn(i, n) {
		cin >> p[i].first >> p[i].second.first;
		p[i].second.second = i+1;
	}
	sort(p.rbegin(), p.rend());
	
	tint suma = 0, ind = 0;
	set<pair<int, int>> used;
	dforn(i, n+1) {
		while(ind < n && p[ind].first == i) {
			suma += p[ind].second.first;
			used.insert(p[ind].second);
			ind++;
		}
		
		while((int)used.size() > 0 && suma > t) {
			auto it = used.end();
			it--;
			pair<int, int> a = *it;
			suma -= a.first;
			used.erase(it);
		}
		
		if((int)used.size() >= i) {
			cout << i << endl;
			cout << i << endl;
			auto it = used.begin();
			forn(j, i) {
				if(j) cout << " ";
				cout << (*it).second;
				it++;
			}
			cout << endl;
			return 0;
		}
	}
	
	return 0;
}