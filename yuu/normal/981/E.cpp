#include <bits/stdc++.h>
using namespace std;
int n, q;
vector <int> s[10001];
vector <int> e[10002];
bool good[10001];
const int base=999727999;
int f[10001];
int main(){
	cin>>n>>q;
	for(int i=1, l, r, x; i<=q; i++){
		cin>>l>>r>>x;
		s[l].push_back(x);
		e[r+1].push_back(x);
	}
	f[0]=1;
	for(int i=1; i<=n; i++){
		for(int x: e[i]){
			for(int j=x; j<=n; j++){
				f[j]-=f[j-x];
				if(f[j]<0) f[j]+=base;
			}
		}
		for(int x: s[i]){
			for(int j=n; j>=x; j--){
				f[j]+=f[j-x];
				if(f[j]>=base) f[j]-=base;
			}
		}
		for(int j=1; j<=n; j++) if(f[j]) good[j]=1;
	}
	vector <int> ans;
	for(int i=1; i<=n; i++) if(good[i]) ans.push_back(i);
	cout<<ans.size()<<'\n';
	for(auto x: ans) cout<<x<<' ';
	cout<<'\n';
}