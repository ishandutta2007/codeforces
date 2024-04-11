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

bool isprime(int x){
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}

void searchprime(int n, ll &p, ll &q){
	for(int i=n;i;i--){
		if(isprime(i)){
			p=i;
			break;
		}
	}
	for(int i=n+1;;i++){
		if(isprime(i)){
			q=i;
			break;
		}
	}
}

ll gcd(ll a,ll b){
	return b>0?gcd(b,a%b):a;
}
int n, t;
main(){
	scanf("%d", &t);
	REP(i, t){
		scanf("%d", &n);
		ll q, p;
		searchprime(n, p, q);
		ll u = p*q - 2*(p+q) + 2*(n+1);
		ll b = 2*p*q;
		ll g = gcd(u, b);
		printf("%I64d/%I64d\n", u/g, b/g);
	}
	return 0;
}