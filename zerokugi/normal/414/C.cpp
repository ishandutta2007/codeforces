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
ll table[25] = {0};
ll table2[25] = {0};
main(){
	scanf("%d", &n);
	vector< vector<int> > data(n);
	REP(i, (1<<n)){
		int x;
		scanf("%d", &x);
		REP(j, n){
			if((i & ((2<<j)-1)) == 0) data[j].clear();
			if(((i >> j) & 1) == 0) data[j].push_back(x);
			else{
				if((i & ((1<<j)-1)) == 0) sort(data[j].begin(), data[j].end());
				table[j] += data[j].end() - upper_bound(data[j].begin(), data[j].end(), x);
				table2[j] += lower_bound(data[j].begin(), data[j].end(), x) - data[j].begin();
			}
		}
	}
	ll ans = 0;
	REP(j, n) ans += table[j];
//	REP(j, n) printf("table1[%d] = %I64d\n", j, table[j]);
//	REP(j, n) printf("table2[%d] = %I64d\n", j, table2[j]);
	scanf("%d", &m);
	REP(i, m){
		int x;
		scanf("%d", &x);
		REP(j, x){
			ans = ans - table[j] + table2[j];
			swap(table[j], table2[j]);
		}
//		REP(j, n) printf("table1[%d] = %I64d\n", j, table[j]);
//		REP(j, n) printf("table2[%d] = %I64d\n", j, table2[j]);
		printf("%I64d\n", ans);
	}
	return 0;
}