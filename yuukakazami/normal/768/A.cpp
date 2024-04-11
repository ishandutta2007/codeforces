#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)

int main(){
	int n; static int a[123456];
	cin>>n;
	rep(i,0,n) cin>>a[i];
	sort(a,a+n);
	int ans = 0;
	rep(i,0,n) ans += (a[i]>a[0]) && (a[i] < a[n-1]);
	cout<<ans<<endl;
	return 0;
}