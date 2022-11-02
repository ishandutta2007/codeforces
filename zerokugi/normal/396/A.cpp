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

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


ll C[15010][510];
ll comb(int n,int k){
	if(k<0||k>n)return 0;
	if(n==0)return 1;
	if(C[n][k]>0)return C[n][k];
	C[n][k]=(comb(n-1,k-1)+comb(n-1,k)) % MOD;
	return C[n][k];
}
main(){
	scanf("%d", &n);
	map<int, int> pl;
	REP(i, n){
		int x;
		cin >> x;
		for(int i=2;i*i<=x;i++){
			while(x%i == 0){
				pl[i] ++;
				x /= i;
			}
		}
		if(x != 1) pl[x] ++;
	}
	
	ll sum = 1;
	
	FOR(it, pl) (sum *= comb(it->second + n - 1, n - 1)) %= MOD;

	cout << sum << endl;
	return 0;
}