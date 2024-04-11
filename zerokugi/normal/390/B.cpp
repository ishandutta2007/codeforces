#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)

int n;
ll a[100005], b, ans = 0;
main(){
	scanf("%d", &n);
	REP(i, n) scanf("%I64d", &a[i]);
	REP(i, n){
		scanf("%I64d", &b);
		if(a[i]*2 < b || b == 1) ans --;
		else ans += (b/2) * (b - b/2);
	}
	cout << ans << endl;
	return 0;
}