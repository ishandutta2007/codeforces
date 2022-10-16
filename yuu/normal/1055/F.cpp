#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long f[1000001];
int l[1000001];
int r[1000001];
int m[1000001];
vector <int> g[1000001];
void dfs(int u){
	for(int v: g[u]){
		f[v]^=f[u];
		dfs(v);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=2, p; i<=n; i++){
		cin>>p>>f[i];
		g[p].push_back(i);
	}
	dfs(1);
	for(int i=1; i<=n; i++) g[i].clear();
	for(int i=1; i<=n; i++) l[i]=1;
	for(int i=1; i<=n; i++) r[i]=n+1;
	sort(f+1, f+n+1);
	long long ans=0;
	long long imp=0;
	for(int low=61; low>=0; low--){
		long long res=0;
		for(int i=1; i<=n; i++) if(l[i]<r[i]){
			long long key=(f[i]^ans)&imp;
			key^=1LL<<low;
			m[i]=lower_bound(f+l[i], f+r[i], key)-f;
			if((f[i]>>low)&1){
				res+=r[i]-m[i];
			}
			else{
				res+=m[i]-l[i];
			}
		}
		if(res<k){
			ans^=1LL<<low;
			k-=res;
			for(int i=1; i<=n; i++) if(l[i]<r[i]){
				if((f[i]>>low)&1){
					r[i]=m[i];
				}
				else{
					l[i]=m[i];
				}
			}
		}
		else{
			for(int i=1; i<=n; i++) if(l[i]<r[i]){
				if((f[i]>>low)&1){
					l[i]=m[i];
				}
				else{
					r[i]=m[i];
				}
			}
		}
		imp^=1LL<<low;
	}
	cout<<ans<<'\n';
}