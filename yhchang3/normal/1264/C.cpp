#include<bits/stdc++.h>
using namespace std;
const int maxn = 200010;

const int mod =  998244353;

long long int power(long long int x,int b){
	long long int res = 1;
	while(b){
		if(b&1)	res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}

long long int SS[maxn],S[maxn],inv[maxn],P[maxn];
long long int f(int l,int r){
	long long int res = SS[r-1]-SS[l-1]-(l-1)*(S[r-1]-S[l-1]);
	res=res%mod*inv[r-1]%mod;
	return	(res+mod)%mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	set<int> st;
	st.insert(1);st.insert(n+1);
	long long int inv100=power(100,mod-2);
	P[0]=inv[0]=1;
	for(int i=1;i<=n;i++){
		long long int p;
		cin>>p;
		p=inv100*p%mod;
		P[i]=P[i-1]*p%mod;
		inv[i]=power(P[i],mod-2);
		S[i]=((S[i-1]+P[i-1]*(1-p))%mod+mod)%mod;
		SS[i]=((SS[i-1]+P[i-1]*(1-p)%mod*i%mod)%mod+mod)%mod;
	}
	long long int ans=f(1,n+1)+n;
	while(q--){
		int u;
		cin>>u;
		auto it=st.find(u);
		if(it==st.end()){
			st.insert(u);
			it=st.find(u);
			--it;
			int l=*it;
			it++;it++;
			int r=*it;
			ans=ans-f(l,r)+f(l,u)+f(u,r);
			ans=(ans%mod+mod)%mod;
			cout<<ans<<'\n';
		}
		else{
			--it;
			int l=*it;
			it++;it++;
			int r=*it;
			st.erase(u);
			ans=ans+f(l,r)-f(l,u)-f(u,r);
			ans=(ans%mod+mod)%mod;
			cout<<ans<<'\n';
		}
	}
}