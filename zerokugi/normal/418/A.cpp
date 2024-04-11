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

int n, k;
main(){
	scanf("%d%d", &n, &k);
	if(n <= k*2) puts("-1");
	else{
		printf("%d\n", k*n);
		REP(i, n)REP(j, k) printf("%d %d\n", i+1, (i+j+1)%n+1);
	}
	return 0;
}