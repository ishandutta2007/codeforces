#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c,d;cin>>a>>b>>c>>d;
		if(a>1ll*b*c){
			cout<<-1<<endl;
			continue;
		}
		int t=min((ll)c,a/(1ll*b*d));
		ll ans=1ll*(t+1)*a-1ll*t*(t+1)/2*d*b;
		cout<<ans<<endl;
	}
}