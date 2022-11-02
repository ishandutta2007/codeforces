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
	if(n/2 > k){
		puts("-1");
	}else if(n == 1){
		puts(k == 0 ? "1": "-1");
	}else{
		k -= n/2 - 1;
		printf("%d %d", k, 2*k);
		int t = 1;
		REP(i, (n-2)/2){
			while(t == k || t == 2*k || t+1 == k || t+1 == 2*k) t++;
			printf(" %d %d", t++, t++);
		}
		while(t == k || t == 2*k || t+1 == k || t+1 == 2*k) t++;
		if(n&1) printf(" %d\n", t);
	}
	return 0;
}