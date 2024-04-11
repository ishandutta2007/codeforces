#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
using namespace std;
#define N 200005
#define ll long long
ll a[N], sum[N], a2[N];
int main()
{
	int n, k;
	cin >> n >> k;
	For(i, 1, n) {
		scanf("%lld", &a[i]);
	}
	ll ans = 0;
	For(i, 1, n-1) {
		if(a2[i]) {
			ans += a2[i] / k;
			if(k - a2[i] % k < a[i]) {
				ans++;
				a[i] -= k - a2[i] % k;
			} else {
				ans++;
				a[i] = 0;
			}
		}
		
		ans += a[i] / k;
		a2[i+1] = a[i] % k;
	}
	if((a[n] + a2[n]) % k == 0) {
		cout << ans + (a[n] + a2[n]) / k << endl;
	} else {
		cout << ans + (a[n] + a2[n]) / k + 1<< endl;
	}
	return 0;
}