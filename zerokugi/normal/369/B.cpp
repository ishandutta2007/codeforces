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

int n, k, l, r, sall, sk;
main(){
	int i,j;
	while(cin >> n >> k >> l >> r >> sall >> sk){
		REP(i, k){
			if(i) cout << " ";
			cout << sk/k + (i<sk%k?1:0);
		}
		REP(i, n-k){
			cout << " " << (sall-sk)/(n-k) + (i<(sall-sk)%(n-k)?1:0);
		}
		
		cout << endl;
	}
	return 0;
}