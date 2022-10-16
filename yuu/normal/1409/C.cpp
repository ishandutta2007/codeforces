#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, x, y;
void solve(){
	cin>>n>>x>>y;
	int diff=y-x;
	for(int p=1; p<=diff; p++) if(diff%p==0){
		if(diff/p+1>n) continue;
		int first=y%p;
		if(first==0) first+=p;
		first=max(first, y-p*(n-1));
		for(int i=1; i<=n; i++){
			cout<<first<<" \n"[i==n];
			first+=p;
		}
		return;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}