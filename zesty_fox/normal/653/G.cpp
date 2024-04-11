#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
	T x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1000010,MOD=1e9+7;

inline ll qpow(ll x,ll y=MOD-2){
	ll res=1;
	while(y){
		if(y&1) (res*=x)%=MOD;
		(x*=x)%=MOD;y>>=1;
	}
	return res;
}

ll fac[N],faci[N];
void init_fac(int lim){
	fac[0]=1;
	for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i%MOD;
	faci[lim]=qpow(fac[lim]);
	for(int i=lim-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
}

inline ll C(int x,int y){
	if(x<0||y<0||x<y) return 0;
	return fac[x]*faci[y]%MOD*faci[x-y]%MOD;
}

int p[N],pcnt,v[N];
vector<pair<int,short> > prs[N];
void init_pr(int lim){
	for(int i=2;i<=lim;i++){
		if(!v[i]) {v[i]=i,p[++pcnt]=i;}
		for(int j=1;j<=pcnt;j++){
			if(p[j]>v[i]||p[j]>lim/i) break;
			v[p[j]*i]=p[j];
		}
	}
	for(int i=1;i<=pcnt;i++){
		//~ for(int j=p[i];j<=lim;j+=p[i]) prs[j].pb(i);
		ll pw=p[i];
		for(int j=1;pw<=lim;j++,pw*=p[i])
			for(ll k=pw;k<=lim;k+=pw)
				if(j==1) prs[k].pb(mp(i,j));
				else prs[k].back().se++;
	}
}

int n,a[N];
vi cs[N];
ll sum[N],sumc[N],ans;
int main(){
	n=rdi();init_fac(n);init_pr(1000000);
	for(int i=1;i<=n;i++){
		a[i]=rdi();
		//~ for(auto tmp:prs[a[i]]){
			//~ int x=a[i],cnt=0;
			//~ while(x%p[tmp]==0) x/=p[tmp],cnt++;
			//~ cs[tmp].pb(cnt);
		//~ }
		for(auto tmp:prs[a[i]]) cs[tmp.fi].pb(tmp.se);
	}
	sumc[n]=C(n-1,n);
	for(int i=n-1;i>=0;i--) sumc[i]=(sumc[i+1]+C(n-1,i))%MOD;
	for(int id=1;id<=pcnt;id++){
		if(cs[id].empty()) continue;
		sort(cs[id].begin(),cs[id].end());
		int siz=cs[id].size(),delta=n-siz+1;
		for(int i=n;i>=delta;i--) sum[i]=sum[i+1]+cs[id][i-delta];
		for(int i=delta;i<=n;i++){
			ans+=(-cs[id][i-delta])*C(n-1,i-1)*(n-i);
			ans+=C(n-1,i-1)*sum[i+1];
			ans+=(-cs[id][i-delta])*sumc[i+1];
			ans+=C(n-1,i)*cs[id][i-delta]%MOD*(i-1);
			ans%=MOD;
		}
		ans+=sum[delta]*(sumc[0]-sumc[delta-1])%MOD;
		ans%=MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}