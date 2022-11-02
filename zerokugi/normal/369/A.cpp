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

int n,m,k;
main(){
	cin >> n >> m >> k;
	vector<int> x(2, 0);
	REP(i, n){
		int a;
		cin >> a;
		x[a-1] ++;
	}
	int ans = 0;
	if(x[0] > m){
		ans += x[0]-m;
		m = 0;
	}else m -= x[0];
	ans += max(x[1] - m - k, 0);
	cout << ans << endl;
	return 0;
}