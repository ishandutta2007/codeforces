#include<bits/stdc++.h>
using namespace std;
 
int d[100010];
int a[100010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	long long int sum = 0;
	for(int i=1;i<=n;i++)
		cin >> a[i], sum += a[i];
	for(int i=1;i<=n;i++)
		cin >> d[i];
	if(k==0){
		long long int ans = 0, tot = 0;
		for(int i=n;i>=1;i--){
			tot += a[i];
			ans = max(ans, tot - d[i]);
		}
		cout << ans << endl;
	}
	else if(k==1){
		long long int ans = max(0, a[n] - d[n]);
		for(int i=2;i<=n;i++){
			ans = max(ans, sum - a[i] - d[1]);
		}
		for(int i=2;i<n;i++){
			ans = max(ans, sum - a[n] - d[i] + ((a[n] - d[n]) > 0 ? a[n] - d[n]:0));
		}
		long long int tot = a[n];
		for(int i=n-1;i>=2;i--){
			tot += a[i];
			ans = max(ans, tot - d[i]);
		}
		sort(d+1, d+n+1);
		ans = max(ans, sum - d[1] - d[2]);
		cout << ans << endl;
	}
	else{
		int m = 1e9;
		for(int i=1;i<n;i++)
			m = min(m, d[i]);
		long long int ans = max(0LL,sum - m);
		ans = max(ans, 0LL+a[n] - d[n]);
		cout << ans << endl;
	}
}