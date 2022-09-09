#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const int N=1e6+5;
int n,e[N],i,j,l,S;
ll a[N],k,g,f[13][2099],x,y,z,w[13],ans=1ll<<60;
bool can[2099];
vector<ll>pr;vector<int>v;
unordered_map<ll,vector<int>>mp;
void factor(ll g){
	for(i=2;1ll*i*i<=g;++i)if(g%i==0)for(pr.push_back(i);g%i==0;g/=i);
	if(g>1)pr.push_back(g);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;for(i=1;i<=n;++i)cin>>a[i],g=gcd(g,a[i]);factor(g);
	if(g==1){cout<<0<<endl;return 0;}
	for(i=1;i<=n;++i){
		cin>>e[i];
		x=1,y=a[i];for(;z=gcd(y,g),z>1;y/=z,x*=z);mp[x].push_back(e[i]);
	}
	S=1<<pr.size();for(i=0;i<=pr.size();++i)for(j=0;j<S;++j)f[i][j]=1ll<<60;f[0][0]=0;
	for(auto u:mp){
		memset(can,0,S);tie(x,v)=u;
		for(j=0;j<pr.size();++j)for(w[j]=1;x%pr[j]==0;x/=pr[j])w[j]*=pr[j];
		for(i=0;i<S;++i){
			ll pi=1;
			for(j=0;j<pr.size();++j)if(i>>j&1)pi*=w[j];
			can[i]=pi<=k;
		}
		sort(v.begin(),v.end());v.resize(min(v.size(),pr.size()));
		for(int w:v){
			bool fl=0;
			for(l=pr.size();l;--l)for(i=S;i;--i)for(j=i;j;j=(j-1)&i)if(can[j]){
				ll nw=f[l-1][i^j]+w;
				if(nw<f[l][i])f[l][i]=nw,fl=1;
			}
			if(!fl)break;
		}
	}
	for(i=1;i<=pr.size();++i)ans=min(ans,f[i][S-1]*i);
	if(ans==1ll<<60)ans=-1;cout<<ans<<endl;
	return 0;
}