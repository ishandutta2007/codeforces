#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod =998244353;
ll mypow(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ret;
}
ll p[1000010];
ll a[1000010];
ll s[1000010];
ll calcu(int i,int j){
	ll now=s[j-1];
	if(i!=1)now=(now+mod-s[i-2])%mod;
	now=now*mypow(a[i-1],mod-2)%mod;
	now=now*mypow(a[j]*mypow(a[i-1],mod-2)%mod,mod-2)%mod;
	return now;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>p[i],p[i]=p[i]*mypow(100,mod-2)%mod;
	a[0]=s[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]*p[i]%mod;
		s[i]=(s[i-1]+a[i])%mod;
		// cout<<i<<" "<<a[i]<<" "<<s[i]<<endl;
	}
	set<int> st;st.insert(1),st.insert(n+1);
	ll ans=calcu(1,n);
	// cout<<"?"<<ans<<endl;
	for(int i=1;i<=q;i++){
		int tmp;cin>>tmp;
		if(st.count(tmp)){
			st.erase(tmp);
			auto it=st.lower_bound(tmp);
			int x=*(--it),y=*(++it)-1;
			ans=ans+mod-calcu(x,tmp-1)+mod-calcu(tmp,y)+calcu(x,y);
			ans%=mod;
		}
		else{
			auto it=st.lower_bound(tmp);
			int x=*(--it),y=*(++it)-1;
			ans=ans+calcu(x,tmp-1)+calcu(tmp,y)+mod-calcu(x,y);
			ans%=mod;
			st.insert(tmp);
		}
		cout<<ans<<"\n";
	}
}