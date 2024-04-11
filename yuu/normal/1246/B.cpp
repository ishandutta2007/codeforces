#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100001];
int p[100001];
map <vector <int>, int> m;
void solve2(){
	for(int i=2; i<=100000; i++) if(p[i]==0) for(int j=i; j<=100000; j+=i) if(p[j]==0) p[j]=i;
	for(int i=1; i<=n; i++){
		vector <int> type;
		while(a[i]>1){
			int u=p[a[i]];
			int cnt=0;
			while(a[i]%u==0){
				cnt++;
				a[i]/=u;
			}
			if(cnt%2) type.push_back(u);
		}
		m[type]++;
	}
	long long ans=0;
	for(auto &x: m) ans+=(((long long)x.second)*(x.second-1))/2;
	cout<<ans;
}
vector <long long> val;
int cnt[100001];
void solve3(){
	for(int i=1; ; i++){
		long long now=1;
		for(int j=1; j<=k; j++){
			now*=i;
			if(now>10000000000) break;
		}
		if(now>10000000000) break;
		val.push_back(now);
	}
	long long ans=0;
	for(int i=1; i<=n; i++){
		for(auto &x: val) if(x%a[i]==0){
			long long y=x/a[i];
			if(y>100000) break;
			ans+=cnt[y];
		}
		cnt[a[i]]++;
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1; i<=n; i++)	cin>>a[i];
	if(k==2) solve2();
	else solve3();
}