#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n;
int a[300001];
void solve(int bit, vector <int> &a, vector <vector <int>> &dump, long long *res){
	vector <int> s[2];
	int c[2]={0, 0};
	for(auto i: a){
		if((i>>bit)&1){//bit 1
			res[1]+=c[0];
			s[1].push_back(i);
			c[1]++;
			
		}
		else{//bit 0
			res[0]+=c[1];
			s[0].push_back(i);
			c[0]++;
		}
	}
	if(!s[0].empty()) dump.push_back(s[0]);
	if(!s[1].empty()) dump.push_back(s[1]);
}
vector <vector <int>> now[2];
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	now[0].push_back(vector<int>());
	for(int i=1; i<=n; i++) now[0].back().push_back(a[i]);
	long long ans=0;
	int x=0;
	for(int i=30, c=0; i>=0; i--, c=1-c){
		now[1-c].clear();
		long long res[2]={0, 0};
		for(auto &v: now[c]) solve(i, v, now[1-c], res);
		if(res[1]<res[0]){
			ans+=res[1];
			x^=1<<i;
		}
		else ans+=res[0];
	}
	cout<<ans<<' '<<x<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--) solve();
}