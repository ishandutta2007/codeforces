#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, k;
string s;
char c[300001];
void solve(){
	cin>>n>>k;
	cin>>s;
	for(int i=0; i<k; i++) c[i]='?';
	for(int i=0; i<n; i++) if(c[i%k]=='?') c[i%k]=s[i];
	else if(s[i]=='?') continue;
	else if(s[i]!=c[i%k]){
		cout<<"NO\n";
		return;
	}
	int a=0, b=0;
	for(int i=0; i<k; i++) if(c[i]=='0') a++; else if(c[i]=='1') b++;
	if(max(a, b)<=k/2) cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) solve();
}