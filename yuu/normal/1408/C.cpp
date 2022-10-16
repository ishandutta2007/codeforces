#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, l;
double a[100002];
void solve(){
	cin>>n>>l;
	for(int i=1; i<=n; i++) cin>>a[i];
	double currentTime=0;
	int spl=1, spr=1;
	a[0]=0;
	a[n+1]=l;
	int l=0, r=n+1;
	while(l+1<r){
		// cerr<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<'\n';
		// cerr<<a[r-1]<<'\n';
		
		if((a[l+1]-a[l])*spr<=(a[r]-a[r-1])*spl){
			double pro=(a[l+1]-a[l])/spl;
			spl++;
			l++;
			currentTime+=pro;
			a[r]-=pro*spr;
		}
		else{
			double pro=(a[r]-a[r-1])/spr;
			spr++;
			r--;
			currentTime+=pro;
			a[l]+=pro*spl;
		}
	}
	currentTime+=(a[r]-a[l])/(spl+spr);
	cout<<currentTime<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<setprecision(16)<<fixed;
	int t=1;
	cin>>t;
	while(t--) solve();
}