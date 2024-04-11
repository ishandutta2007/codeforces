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
int g[1001][1001];
main(){
	scanf("%d", &n);
	REP(i, n)REP(j, n) scanf("%d", &g[i][j]);
	int sum = 0;
	REP(i, n) sum ^= g[i][i];
	scanf("%d", &m);
	REP(i, m){
		int q;
		scanf("%d", &q);
		if(q == 3) printf("%d", sum);
		else{
			int x;
			scanf("%d", &x);
			sum ^= 1;
		}
	}
	puts("");
	return 0;
}