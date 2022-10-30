#include<bits/stdc++.h>
#define maxn 400100
#define mod 1000000007
using namespace std;
struct WXHAKIOI{
	int mx[maxn<<2],atg[maxn<<2];
	void upd(int o){
		mx[o]=min(mx[o<<1],mx[o<<1|1])+atg[o];
	}
	void mdy(int o,int l,int r,int ql,int qr,int a){
		if(ql<=l&&r<=qr){
			atg[o]+=a;
			mx[o]+=a;
			return ;
		}
		int mid=l+r>>1;
		if(ql<=mid)mdy(o<<1,l,mid,ql,qr,a);
		if(qr>mid)mdy(o<<1|1,mid+1,r,ql,qr,a);
		upd(o);
	}
	int qry(int o,int l,int r,int ql,int qr,int tg){
		if(ql<=l&&r<=qr){
			if(mx[o]+tg>0)return -1;
			if(l==r)return l;
		}
		int mid=l+r>>1,ans=-1;
		if(qr>mid)ans=qry(o<<1|1,mid+1,r,ql,qr,tg+atg[o]);
		if(ql<=mid&&ans==-1)ans=qry(o<<1,l,mid,ql,qr,tg+atg[o]);
		return ans;
	}
}f[2];
typedef pair<int,int> par;
par a[maxn],b[maxn];
int dp[maxn],M,n,m,lsh[maxn],tp,tag[2][maxn];
vector<int>v[2][maxn];
int getid(int x){
	return lower_bound(lsh+1,lsh+tp+1,x)-lsh;
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	scanf("%d%d%d",&M,&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].first,&a[i].second);
		lsh[++tp]=a[i].first,lsh[++tp]=a[i].second;
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&b[i].first,&b[i].second);
		lsh[++tp]=b[i].first,lsh[++tp]=b[i].second;
	}
	lsh[++tp]=M;
	lsh[++tp]=1;
	sort(lsh+1,lsh+tp+1);
	tp=unique(lsh+1,lsh+tp+1)-lsh-1;
	for(int i=1;i<=n;++i)
		v[0][getid(a[i].first)].push_back(getid(a[i].second));
	for(int i=1;i<=m;++i)
		v[1][getid(b[i].first)].push_back(getid(b[i].second));
	for(int i=1;i<=n;++i)f[0].mdy(1,1,tp,getid(a[i].second),tp,1);
	for(int i=1;i<=m;++i)f[1].mdy(1,1,tp,getid(b[i].second),tp,1);
	tag[0][0]=tag[1][0]=1;
	tag[0][1]=tag[1][1]=mod-1;
	for(int i=0;i<=tp;++i){
		for(int j=0;j<2;++j)
			for(auto p:v[j][i])f[j].mdy(1,1,tp,p,tp,-1);
		for(int j=0;j<2;++j)
			dp[j]=(dp[j]+tag[j][i])%mod;
//		printf("[%d,%d]",dp[0],dp[1]);
		if(i==tp)continue;
		for(int j=0;j<2;++j){
			int pos=f[j].qry(1,1,tp,i+1,tp,0);
//			printf("{%d}",pos);
			if(pos==-1)continue;
			int A=qpow(2,lsh[i+1]-lsh[i]-1);
			int B=(mod-1ll*(dp[0]+dp[1])*A%mod)%mod;
			tag[j][pos+1]=(1ll*tag[j][pos+1]+B+dp[j])%mod;
			tag[j][i+1]=(tag[j][i+1]+1ll*A*(dp[0]+dp[1])-dp[j]+mod)%mod;
		}
	}
	int ans=(dp[0]+dp[1])%mod;
	printf("%d",ans);
}