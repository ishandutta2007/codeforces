#include <bits/stdc++.h>
using namespace std;
long long n;
void solve(){
	cin>>n;
	long long ans=1e18;
	for(long long c6=0; c6<6; c6++){
		for(long long c8=0; c8<4; c8++){
			long long res=n-c6*6-c8*8;
			if(res<=0) ans=min(ans, c6*15+c8*20);
			else ans=min(ans, c6*15+c8*20+((res-1)/10+1)*25);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}