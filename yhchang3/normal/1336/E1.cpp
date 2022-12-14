#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct Z2Basis{
	ll a[53];
	int sz;
	void add(ll x){
		for(int i=0;i<53;i++)
			if((x>>i)&1){
				if((a[i]>>i)&1)
					x^=a[i];
				else{
					a[i]=x;
					sz++;
					return;
				}
			}
	}
	void norm(){
		for(int i=0;i<53;i++)
			for(int j=0;j<i;j++)
				if((a[i]>>i)&1)
					if((a[j]>>i)&1)
						a[j]^=a[i];
	}
}Z2;
const int mod = 998244353;
int cnt[54];
vector<ll> todo;
void dfs(int idx,ll cur){
	if(idx==todo.size()){
		cnt[__builtin_popcountll(cur)]++;
		return;
	}
	dfs(idx+1,cur);
	dfs(idx+1,cur^todo[idx]);
}

ll C[54][54];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	C[0][0]=1;
	for(int i=1;i<=53;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
	}
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		Z2.add(x);
	}
	Z2.norm();
	if(Z2.sz<=26){	
		for(int i=0;i<53;i++)
			if(Z2.a[i]!=0)
				todo.emplace_back(Z2.a[i]);
		dfs(0,0);
		ll c = 1;
		for(int i=Z2.sz;i<n;i++)
			c = c*2%mod;
		for(int i=0;i<=m;i++)
			cout<<c*cnt[i]%mod<<' ';
		cout<<endl;
	}
	else{
		for(int i=0;i<m;i++)
			if(Z2.a[i]==0){
				ll cur = 1LL<<i;
				for(int j=0;j<m;j++)
					if((Z2.a[j]>>i)&1)
						cur^=1LL<<j;
				todo.emplace_back(cur);
			}
		dfs(0,0);
		ll c = 1;
		for(int i=0;i<m-Z2.sz;i++)
			c = c * ((mod+1)/2) % mod;
		for(int i=0;i<n-Z2.sz;i++)
			c = c * 2 % mod;
		for(int i=0;i<=m;i++){
			ll ans = 0;
			for(int j=0;j<=m;j++){
				ll w = 0;
				for(int k=0;k<=min(i,j);k++){
					if(k&1)	w = (w - C[j][k]*C[m-j][i-k])%mod;
					else	w = (w + C[j][k]*C[m-j][i-k])%mod;
				}
				w = (w%mod+mod)%mod;
				ans = (ans + w *cnt[j]) % mod;
			}
			cout<<ans*c%mod<<' ';
		}
		cout<<endl;
	}
}