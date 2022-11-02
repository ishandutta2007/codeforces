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
#define REP(i,x) for(ll i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

ll n;


main(){
	cin >> n;
	
	if(!n){
		cout << 1 << endl;
		return 0;
	}
	
	ll y = n-1;
	ll x = 1;
	ll py = n;
	ll ans = 1;
	
	for(;x<n;x++){
		while(x*x+y*y > n*n) y--;
		if(py == y) ans ++;
		py = y;
		ans ++;
	}
	cout << ans * 4 << endl;
	return 0;
}