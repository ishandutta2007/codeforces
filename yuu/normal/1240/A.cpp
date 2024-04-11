#include <bits/stdc++.h>
using namespace std;
int n;
int p[200001];
int x, y, a, b;
long long k;
bool check(int lim){
	int ca=0, cb=0, cab=0;
	for(int i=1; i<=lim; i++){
		if(i%a==0){
			if(i%b==0) cab++;
			else ca++;
		}
		else if(i%b==0) cb++;
	}
	long long now=k;
	for(int i=1; i<=lim; i++){
		if(cab){
			now-=p[i]*(x+y);
			cab--;
		}
		else if(cb){
			now-=p[i]*y;
			cb--;
		}
		else if(ca){
			now-=p[i]*x;
			ca--;
		}
		else break;
	}
	return now<=0;
}
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>p[i];
		p[i]/=100;
	}
	sort(p+1, p+n+1);
	reverse(p+1, p+n+1);
	
	cin>>x>>a>>y>>b;
	if(x>y){
		swap(x, y);
		swap(a, b);
	}
	cin>>k;
	int low=1, high=n, mid, res=n+1;
	while(low<=high){
		mid=(low+high)/2;
		if(check(mid)){
			res=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	if(res==n+1) res=-1;
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin>>q;
	while(q--) solve();
}