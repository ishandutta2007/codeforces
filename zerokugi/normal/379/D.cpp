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


main(){
	ll fib1[51]={0}, fib2[51]={0};
	int s[51], t[51];
	ll g[51][3][3] = {0};
	fib1[1] = 1;s[1] = 1;t[1] = 1;
	fib2[2] = 1;s[2] = 2;t[2] = 2;
	for(int i=3;i<=50;i++){
		fib1[i] = fib1[i-2] + fib1[i-1];
		fib2[i] = fib2[i-2] + fib2[i-1];
		REP(j, 3)REP(k, 3) g[i][j][k] = g[i-1][j][k] + g[i-2][j][k];
		g[i][t[i-2]][s[i-1]] ++;
		s[i] = s[i-2];
		t[i] = t[i-1];
//		cout << g[i][1][1] << " " << g[i][2][2] << endl;
	}
	ll k, x, n, m;
	while(cin >> k >> x >> n >> m){
		ll ans1 = 0, ans2 = 0;
		string s[50];
		REP(i, n/2 + 1){
			REP(j, m/2 + 1){
				REP(s1, 2)REP(s2, 2)REP(t1, 2)REP(t2, 2){
					if(i*2+s1+t1 > n || j*2+s2+t2 > m) continue;
					if(i*fib1[k] + j*fib2[k]
					 + g[k][1][1] * t1*s1 + g[k][2][2] * t2*s2
					 + g[k][1][2] * t1*s2 + g[k][2][1] * t2*s1 == x){
					 	if(s1) cout << "C";
					 	REP(q, i) cout << "AC";
					 	REP(q, n-s1-t1-i*2) cout << "Z";
					 	if(t1) cout << "A";
					 	cout << endl;
					 	if(s2) cout << "C";
					 	REP(q, j) cout << "AC";
					 	REP(q, m-s2-t2-j*2) cout << "Z";
					 	if(t2) cout << "A";
					 	return 0;
					 }
				}
			}
		}
		cout << "Happy new year!" << endl;
	}
	return 0;
}