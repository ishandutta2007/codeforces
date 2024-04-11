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
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, m;
int tbl[101][101];
int ansr[101], ansc[101];

bool checkrow(int r){
	int sum = 0;
	REP(i, m){
		sum += tbl[r][i];
	}
	if(sum >= 0) return 0;
	ansr[r] ^= 1;
	REP(i, m){
		tbl[r][i] = -tbl[r][i];
	}
	return 1;
}
bool checkcol(int c){
	int sum = 0;
	REP(i, n){
		sum += tbl[i][c];
	}
	if(sum >= 0) return 0;
	ansc[c] ^= 1;
	REP(i, n){
		tbl[i][c] = -tbl[i][c];
	}
	return 1;
}

void putans(int *d, int n){
	int sum=0;
	REP(i, n) sum += d[i];
	printf("%d", sum);
	REP(i, n) if(d[i]) printf(" %d", i+1);
	puts("");
}
main(){
	scanf("%d%d", &n, &m);
	REP(i, n)REP(j, m) scanf("%d", &tbl[i][j]);
	int f;
	do{
		f = 0;
		REP(i, n) f |= checkrow(i);
		REP(i, m) f |= checkcol(i);
	}while(f);
	putans(ansr, n);
	putans(ansc, m);
	return 0;
}