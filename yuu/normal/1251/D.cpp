#include <bits/stdc++.h>
using namespace std;
int n;
long long s;
int l[200001];
int r[200001];
int p[200001];
bool check(long long x){
	long long cost=x*((n+1)/2);
	int cnt=n/2;
	for(int i=1; i<=n; i++) if(l[p[i]]>x){
		cost+=l[p[i]]-x;
	}
	else if(r[p[i]]<x){
		cost+=l[p[i]];
		cnt--;
	}
	for(int i=1; i<=n; i++) if(l[p[i]]>x){
	}
	else if(r[p[i]]<x){
	}
	else{
		if(cnt){
			cost+=l[p[i]];	
			cnt--;
		}
	}
	return cost<=s;
}
void solve(){
	cin>>n>>s;
	for(int i=1; i<=n; i++) cin>>l[i]>>r[i];
	for(int i=1; i<=n; i++) p[i]=i;
	sort(p+1, p+n+1, [](int a, int b){
		return r[a]<r[b];
	});
	int high=r[p[(n+1)/2]];
	sort(p+1, p+n+1, [](int a, int b){
		return l[a]<l[b];
	});
	int low=l[p[(n+1)/2]];
	int ans=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(check(mid)){
			ans=mid;
			low=mid+1;
		}
		else high=mid-1;
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}