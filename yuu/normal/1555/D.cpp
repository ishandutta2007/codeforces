#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int f[3][200001];
int first[3];
int last[3];
int cnt[3];
vector <string> pattern={"abc", "acb", "bac", "bca", "cab", "cba"};
// vector <string> pattern={"acb"};
void solve(){
	
	cin>>n>>m;
	cin>>s;
	for(char &c: s) c-='a';
	s='0'+s;
	for(int c=0; c<3; c++){
		for(int i=1; i<=n; i++){
			f[c][i]=((i>=3)?f[c][i-3]:0)+(s[i]==c);
			// cerr<<f[c][i]<<" \n"[i==n];
		}
	}
	for(int i=1, l, r; i<=m; i++){
		cin>>l>>r;
		if(l==r){
			cout<<"0\n";
			continue;
		}
		if(r==(l+1)){
			cout<<(s[l]==s[r])<<'\n';
			continue;
		}
		int ans=r-l+1;
		for(int j=0; j<3; j++){
			last[j]=r;
			while((last[j]-j)%3) last[j]--;
			first[j]=l-1;
			while((first[j]-j)%3) first[j]--;
			cnt[j]=(last[j]-first[j])/3;
			if(first[j]<0) first[j]=0;
		}
		for(auto &p: pattern){
			int res=0;
			for(int j=0; j<3; j++){
				res+=cnt[j]-(f[p[j]][last[j]]-f[p[j]][first[j]]);
			}
			ans=min(ans, res);
		}
		cout<<ans<<'\n';
	}
}
int main(){
	for(auto &x: pattern) for(auto &y: x) y-='a';
	int t;
	// cin>>t;
	t=1;
	while(t--) solve();
}