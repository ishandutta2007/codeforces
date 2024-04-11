#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> f[5];
void solve(){
	cin>>n;
	string s;
	for(int i=0; i<5; i++) f[i].clear();
	for(int i=1; i<=n; i++){
		cin>>s;
		int c[5];
		for(int i=0; i<5; i++) c[i]=0;
		for(char &ch: s) c[ch-'a']++;
		for(int i=0; i<5; i++) f[i].push_back(c[i]*2-((int)s.size()));
	}
	int mx=0;
	for(int i=0; i<5; i++){
		sort(f[i].begin(), f[i].end());
		reverse(f[i].begin(), f[i].end());
		int sum=0;
		int ans=0;
		for(int &x: f[i]){
			sum+=x;
			if(sum>0) ans++;
			else break;
		}
		mx=max(mx, ans);
	}
	cout<<mx<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}