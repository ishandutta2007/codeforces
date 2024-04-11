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
#include <bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

#define BITS 101

int n, m, k;
vector< bitset<BITS> > bits;



int check(bitset<BITS> b){
	int rev = 0;
//	cout << b << endl;
	REP(i, n){
		bitset<BITS> xo = bits[i] ^ b;
		rev += min(xo.count(), m - xo.count());
//		printf("%d (%d, %d)\n", i, xo.count(), m - xo.count());
	}
//	printf("rev=%d\n", rev);
	return rev;
}

main(){
	scanf("%d%d%d", &n, &m, &k);
	bits = vector< bitset<BITS> >(max(n, m));
	if(n < m){
		swap(n, m);
		REP(i, m)REP(j, n){
			int b;
			scanf("%d", &b);
			bits[j].set(i, b);
		}
	}else{
		REP(i, n)REP(j, m){
			int b;
			scanf("%d", &b);
			bits[i].set(j, b);
		}
	}
	int ans = BITS;
	if(k < n){
		REP(i, n) ans = min(ans, check(bits[i]));
	}else{
		REP(i, 1<<m) ans = min(ans, check(bitset<BITS>((unsigned long)i)));
	}
	
	
	printf("%d\n", (ans > k) ? -1 : ans);
	return 0;
}