#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int f[1000001];
map <int, int> cnt;
int ft[1000001];
void update(int u, int x){
	for(; u<=n; u+=u&-u) ft[u]+=x;
}
int get(int u){
	int res=0;
	for(; u>0; u-=u&-u) res+=ft[u];
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		cnt[a[i]]++;
		f[i]=cnt[a[i]];
	}
	cnt.clear();
	long long ans=0;
	for(int i=n; i>=1; i--){
		ans+=get(f[i]-1);
		update(++cnt[a[i]], 1);
	}
	cout<<ans<<'\n';
}