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
string s;
main(){
	cin >> n >> k >> s;
	if(k-1 < n-k){
		REP(i, k-1) puts("LEFT");
		REP(i, n) printf("PRINT %c\n%s", s[i], i==n-1?"":"RIGHT\n");
	}else{
		REP(i, n-k) puts("RIGHT");
		REP(i, n) printf("PRINT %c\n%s", s[n-i-1], i==n-1?"":"LEFT\n");
	}
	
	return 0;
}