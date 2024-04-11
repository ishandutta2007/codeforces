#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define x first
#define y second
int n, m;
pair <int, int> r[2001];
pair <int, int> f[2001];
int val[2001];
multiset <int> s;
vector <pair <int, int>> upd[1000002];
void solve(){
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>r[i].x>>r[i].y;
	for(int i=1; i<=m; i++) cin>>f[i].x>>f[i].y;
	sort(f+1, f+m+1);
	sort(r+1, r+n+1);
	for(int i=m-1; i>=1; i--) f[i].y=max(f[i].y, f[i+1].y);
	m=unique(f+1, f+m+1)-f-1;
	for(int i=1; i<=n; i++){
		val[i]=0;
		for(int j=m; j>=1; j--){
			if(f[j].x>=r[i].x){
				val[i]=f[j].y-r[i].y+1;
				upd[f[j].x-r[i].x+1].push_back({i, (j==m)?0:(f[j+1].y-r[i].y+1)});
			}
			else break;
		}
		if(val[i]<0) val[i]=0;
		s.insert(val[i]);
	}
	int ans=max(0, *s.rbegin());
	for(int i=1; i<=1000001; i++) if(!upd[i].empty()){
		for(auto p: upd[i]){
			s.erase(s.find(val[p.first]));
			val[p.first]=p.second;
			if(val[p.first]<0) val[p.first]=0;
			s.insert(val[p.first]);
		}
		ans=min(ans, i+(*s.rbegin()));
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--) solve();
}