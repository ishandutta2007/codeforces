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

int n;

int data[1001] = {0};

main(){
	int x;
	while(cin >> n){
		REP(i, n){
			cin >> x;
			data[x] ++;
		}
		REP(i, 1000) data[i+1] += data[i];
		cin >> x;
		int ans = 0;
		REP(i, 1001-x) ans = max(ans, data[i+x] - data[i-1]);
		cout << ans << endl;
	}
	return 0;
}