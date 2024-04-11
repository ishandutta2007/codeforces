#include<bits/stdc++.h>
#define maxn 200010
#define maxm 2100000
using namespace std;
typedef long long ll;
const ll inf=(ll)3e18;
struct data{ll x,flag,id;int operator<(const data& d)const{return x<d.x;}}d[maxn<<2];
ll dp[maxn<<2][2],c[maxn<<2],s[maxn<<2],v[maxn<<2],nw,ans;
ll _s[maxn<<2],n,np,m,C,tp,pre;
bool is2[maxn<<2];
struct zkw{
	ll zkwm,s[maxm],atg[maxm];
	void init(int len){
		zkwm=1;
		while(zkwm<=len+2)zkwm<<=1;
		for(int i=1;i<=zkwm+zkwm;++i)s[i]=-inf;
	}
	ll query(int l,int r){
		if(l>r||r<=0||l>np)return -inf;
		l=max(l,1),r=min((ll)r,np);
		ll lans=-inf,rans=-inf;
//		for(int i=l;i<=r;++i)lans=max(lans,s[i]);
//		return lans;
		for(l+=zkwm-1-1,r+=zkwm+1-1;l^r^1;l>>=1,r>>=1){
			if(lans!=-inf)lans+=atg[l];
			if(rans!=-inf)rans+=atg[r];
			if(~l&1)lans=max(lans,s[l^1]);
			if(r&1)rans=max(rans,s[r^1]);
		}
		if(lans!=-inf)lans+=atg[l];
		if(rans!=-inf)rans+=atg[r];
		lans=max(lans,rans);
		if(lans!=-inf)for(l>>=1;l;l>>=1)lans+=atg[l];
		return lans;
	}
	void mdy(int l,int r,ll a){
//		for(int i=l;i<=r;++i)s[i]+=a;return ;
		if(l>r||r<=0||l>np)return ;
		l=max(l,1),r=min((ll)r,np);
		int f=0;
		for(l+=zkwm-1-1,r+=zkwm+1-1;l^r^1;l>>=1,r>>=1,f=1){
			if(~l&1)atg[l^1]+=a,s[l^1]+=a;
			if(r&1)atg[r^1]+=a,s[r^1]+=a;
			if(f)s[l]=max(s[l<<1],s[l<<1|1])+atg[l],s[r]=max(s[r<<1],s[r<<1|1])+atg[r];
		}
		s[l]=max(s[l<<1],s[l<<1|1])+atg[l],s[r]=max(s[r<<1],s[r<<1|1])+atg[r];
		for(l>>=1;l;l>>=1)s[l]=max(s[l<<1],s[l<<1|1])+atg[l];
	}
	void _mdy(int l,ll a){
//		s[l]=max(s[l],a);return ;
		l+=zkwm-1;
		atg[l]=0;
		for(int _l=l>>1;_l;_l>>=1)a-=atg[_l];
		if(s[l]<a)s[l]=a; else return ;
		for(l>>=1;l;l>>=1)s[l]=max(s[l<<1],s[l<<1|1])+atg[l];//,printf("_s:{%lld,%lld}\n",s[l],l);
	}
}A[4];

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&C);
	for(ll i=1,L,R;i<=n;++i)
		scanf("%lld%lld",&L,&R),
		d[++tp]=data{L,1ll,0ll},d[++tp]=data{R,-1ll,0ll};
	for(ll i=1,L,R;i<=m;++i)
		scanf("%lld%lld",&L,&R),
		d[++tp]=data{L,1ll,1ll},d[++tp]=data{R,-1ll,1ll};
	sort(d+1,d+tp+1);
	int tg=0,ch=0;
	for(int i=1;i<=tp;++i){
		if(i>1){
			ll x=d[i].x-d[i-1].x;
			if(tg==2)v[i]=x,s[i]=0,is2[i-1]=true;
			else if(tg==1)v[i]=(ch==0?1:0)*x,s[i]=(ch==0?1:-1)*x;
			else v[i]=s[i]=0;
			s[i]+=s[i-1],c[i]=v[i]+c[i-1];
		}
		if(d[i].flag>0)
			tg++,ch=d[i].id;
		else if(d[i].flag<0)
			tg--,ch=1-d[i].id;
		_s[i]=s[i];
	}
	sort(_s+1,_s+tp+1);
	np=unique(_s+1,_s+tp+1)-_s-1;
//	printf("{%lld,%d}",tp,np);
	for(int i=0;i<4;++i)
		A[i].init(np);
	for(int i=0;i<=tp+1;++i)
		dp[i][0]=dp[i][1]=-inf;
	for(int i=1;i<tp;++i){
//		if(i%100==0)printf("[ok,%d]",i);
		if(is2[i]){
			if(s[i]>=C)dp[i][0]=max(dp[i][0],pre-s[i]+C+v[i+1]*2);// Vasya>Petya!,Vasya 
			else if(s[i]<=-C)dp[i][1]=max(dp[i][1],pre+v[i+1]*2);// Petya>Vasya!,Petya 
		}
		if(abs(nw)<=C&&is2[i])pre+=v[i+1]*2;
		else pre+=v[i+1],nw+=s[i+1]-s[i];
		if(!is2[i])continue;
		int X=lower_bound(_s+1,_s+np+1,s[i])-_s;
		dp[i][0]=max(dp[i][0],A[0].query(1,X)+c[i+1]-s[i]+v[i+1]);
		dp[i][1]=max(dp[i][1],A[1].query(lower_bound(_s+1,_s+np+1,s[i]+2*C)-_s,np)+c[i+1]+v[i+1]);
		dp[i][0]=max(dp[i][0],A[2].query(1,upper_bound(_s+1,_s+np+1,s[i]-2*C)-_s-1)-s[i]+v[i+1]+c[i+1]+2*C);
		dp[i][1]=max(dp[i][1],A[3].query(X,np)+c[i+1]+v[i+1]);
		int l=X,r=upper_bound(_s+1,_s+np+1,s[i]+2*C)-_s-1;
		if(A[0].s[1]>=(ll)(-2e18))A[0].mdy(l,r,v[i+1]);
		if(A[1].s[1]>=(ll)(-2e18))A[1].mdy(l,r,v[i+1]);
		l=lower_bound(_s+1,_s+np+1,s[i]-2*C)-_s,r=X;
		if(A[2].s[1]>=(ll)(-2e18))A[2].mdy(l,r,v[i+1]);
		if(A[3].s[1]>=(ll)(-2e18))A[3].mdy(l,r,v[i+1]);
		int x=lower_bound(_s+1,_s+np+1,s[i+1])-_s;
		if(dp[i][0]>=0)
			A[0]._mdy(x,dp[i][0]+s[i+1]-c[i+1]),
			A[1]._mdy(x,dp[i][0]-c[i+1]);
		if(dp[i][1]>=0)
			A[2]._mdy(x,dp[i][1]+s[i+1]-c[i+1]),
			A[3]._mdy(x,dp[i][1]-c[i+1]);
//		printf("[%lld,%lld,%lld]\n",dp[i][0],dp[i][1],d[i].x);
	}
	ans=max(ans,pre);
	ans=max(ans,A[1].query(1,np)+c[tp]);
	ans=max(ans,A[3].query(1,np)+c[tp]);
//	printf("[c+_s=%lld,%lld,%lld]",c[tp]+_s[tp],A[1].s[1]+c[tp]+_s[tp],A[1].s[1]+c[tp]+_s[tp]); 
	printf("%lld",ans);
}