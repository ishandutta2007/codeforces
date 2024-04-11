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
int d[101];
main(){
	scanf("%d", &n);
	REP(i, n){
		int l, r;
		cin >> l >> r;
		for(;l<r;l++) d[l] = i+1;
	}
	int ans=0;
	REP(i, 101) ans += d[i] == 1;
	printf("%d\n", ans);
	return 0;
}