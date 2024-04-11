#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n;
int a[101];
int b[101];
int c[101];
int p[102];
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) cin>>b[i];
	for(int i=1; i<=n; i++) cin>>c[i];
	p[1]=p[n+1]=a[1];
	for(int i=2; i<=n; i++) p[i]=0;
	for(int i=2; i<=n; i++){
		if((a[i]!=p[i-1])&&(a[i]!=p[i+1])){
			p[i]=a[i];
		}
		else if((b[i]!=p[i-1])&&(b[i]!=p[i+1])){
			p[i]=b[i];
		}
		else{
			p[i]=c[i];
		}
	}
	for(int i=1; i<=n; i++) cout<<p[i]<<" \n"[i==n];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) solve();
}