#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define mp make_pair
#define fi first
#define se second
#define per(i,a,n) for (int i=int(n)-1;i>=(a);i--)
#define pb push_back
using namespace std;
const int md = int(1e9) + 7;
ll mypow(ll a,ll e){
	if(e==0) return 1;
	return e%2==0?mypow(a*a%md,e>>1):mypow(a,e-1)*a%md;
}
// head
int main(){
	int n;
	cin>>n;
	vector<int> x(n);
	rep(i,0,n) scanf("%d",&x[i]);
	sort(x.begin(), x.end());

	ll ans = 0;
	rep(i,0,n-1){
		int a = i+1;
		int b = n - a;
		ll num = mypow(2,n);
		num -= mypow(2,a);
		num -= mypow(2,b);
		num += 1;
		num %= md;
		ans += 1LL * (x[i+1] - x[i]) * num %md;
	}

	ans %= md; if(ans < 0) ans += md;
	cout<<ans<<endl;
	return 0;
}