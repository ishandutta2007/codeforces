#include<bits/stdc++.h>
using namespace std;
const int maxm=2e6+10;
const int M=2e6+1;
const int mod=1e9+7;
const int maxn=2e5+10;
typedef pair<int,int> pii;
int vis[maxm],pri[maxm/5],psz,nxt[maxm];
int a[maxn],n,flg=0,b[maxn];
map<int,pii>st;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
void ins(int x){
	while(x>1){
		int y=nxt[x],z=0;
		while(x%y==0)x/=y,z++;
		if(z>st[y].first)st[y]=pii(z,1);
		else if(z==st[y].first)st[y].second++;
	}
}
int chk(int x){
	if(x==1)return 1;
	int ret=0;
	int c=1;
	while(x>1){
		int y=nxt[x],z=0;
		while(x%y==0)x/=y,z++;
		if(!((st[y].second>1&&st[y].first==z)||(st[y].first>z)))c=0;
	}
	return c;
}
int main(){
//	freopen("d.in","r",stdin);
	for(int i=2;i<=M;++i){
		if(!vis[i]){
			pri[++psz]=i;
			nxt[i]=i;
		}
		for(int j=1;j<=psz&&pri[j]*i<=M;++j){
			vis[i*pri[j]]=1;
			nxt[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i)if(a[i]>1){
		if(st[a[i]].first>=1){
			ins(a[i]-1),b[i]=0;
		} else ins(a[i]),b[i]=1;
	}
	int ans=1;
	for(auto c:st)ans=1ll*ans*qpow(c.first,c.second.first)%mod;
	for(int i=1;i<=n;++i)if(a[i]>1){
		if(b[i]==0){
			flg|=chk(a[i]-1);
		} else flg|=chk(a[i]);
	}
	printf("%d",(ans+flg)%mod);
}