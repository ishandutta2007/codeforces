#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
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

const double EPS = 1e-9;
ll gcd(ll a,ll b){
	return b>0?gcd(b,a%b):a;
}
int a, b;
main(){
	vector< vector<pii> > ok(1001);
	REP(i, 1000)REP(j,1000){
		int t = (int)(sqrt(i*i+j*j)+EPS);
		if(i && j && t <= 1000 && t*t == i*i+j*j){
			ok[t].push_back(pii(i, j));
		}
	}
//	REP(i, 1001) if(ok[i]) cout << i << " ";
	scanf("%d%d", &a, &b);
	int ans;
	if(a > b) swap(a, b);
	int p = a/gcd(a, b);
	int q = b/gcd(a, b);
	FOR(it, ok[gcd(a, b)]){
		int x = it->first;
		int y = it->second;
		if(x*q == y*p) swap(x, y);
		if(x*q == y*p) continue;
		puts("YES");
		puts("0 0");
		printf("%d %d\n", -y*q, x*q);
		printf("%d %d\n", x*p, y*p);
		goto END;
	}
	puts("NO");
END:
	return 0;
}