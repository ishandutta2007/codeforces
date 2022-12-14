#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<long long int,int> pli;
const int mod = 1e9+7;


ll bases[60];
vector<pli> e[100001];
bool vis[100001];
ll d[100001];
ll cnt,bcnt;
void ins(ll x){
	for(int i=59;i>=0;i--)
		if(x&(1ll<<i)){
			if(!bases[i]){
				bases[i]=x;
				bcnt++;
				return;
			}
			else{
				x^=bases[i];
			}
		}
}
vector<int> v;
void dfs(int x){
	vis[x]=true;
	v.emplace_back(x);
	cnt++;
	for(auto it:e[x])
		if(vis[it.second]) ins(d[x]^d[it.second]^it.first);
		else{
			d[it.second]=d[x]^it.first;
			dfs(it.second);
		}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		e[u].emplace_back(w,v);
		e[v].emplace_back(w,u);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			memset(bases,0,sizeof bases);
			cnt=bcnt=0;
			v.clear();
			dfs(i);
			for(int j=59;j>=0;j--){
				ll b=(1ll<<j)%mod;
				bool has=false;
				for(int k=0;k<60;k++)
					if((1ll<<j)&bases[k])
						has=true;
				if(has)
					ans=(ans+cnt*(cnt-1)/2%mod*b%mod*((1ll<<(bcnt-1))%mod))%mod;
				else{
					ll ocnt=0;
					for(int it:v)
						if(d[it]&(1ll<<j))
							ocnt++;
					ans=(ans+ocnt*(cnt-ocnt)%mod*b%mod*((1ll<<bcnt)%mod))%mod;
				}
			}
		}
	cout<<ans<<endl;
}