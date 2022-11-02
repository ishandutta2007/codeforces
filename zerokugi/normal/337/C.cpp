#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define MOD 1000000009
typedef long long lli;
lli mod_pow(lli a,lli b,lli M){
	if(b==0)return 1;
	lli res=mod_pow((a*a)%M,b/2,M);
	if(b&1)res=(res*a)%M;
	return res;
}
lli n,m,k;
main(){
	int i,j;
	while(cin >> n >> m >> k){
		if(n <= (n-m)*k){
			cout << m << endl;
			continue;
		}
		
		int x = m - (n-m)*(k-1);
		lli ans = (n-m)*(k-1) + x % k;
		x /= k;
		lli sum = 0;
		sum = (k * (mod_pow(2, x+1, MOD)-2+MOD) + ans) % MOD;
		cout << (int)sum << endl;
	}
	return 0;
}