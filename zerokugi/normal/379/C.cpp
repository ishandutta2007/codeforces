#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n, m;
main(){
	while(cin >> n){
		vector<pii> a(n);
		REP(i, n){
			int x;
			cin >> x;
			a[i] = pii(x, i);
		}
		sort(a.begin(), a.end());
		int minN = 0;
		REP(i, n){
			if(a[i].first <= minN) a[i].first = ++minN;
			else minN = a[i].first;
			swap(a[i].first, a[i].second);
		}
		sort(a.begin(), a.end());
		REP(i, n) cout << (i ? " " : "") << a[i].second;
		cout << endl;
	}
	return 0;
}