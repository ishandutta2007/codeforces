#include<bits/stdc++.h>
using namespace std;
const int N=400005,mo=1000000007,inv2=(mo+1)>>1;
int f[N][2],k,n,m,i,j,xb,s00,s10,s01,s11,b[N],i00,i10,i01,i11,cnt,ans;
struct seg{int l,r;}s0[N],s1[N],s[N];
pair<int,int*>a[N];
inline bool cmpl(seg a,seg b){return a.l<b.l || (a.l==b.l && a.r>b.r);}
inline bool cmpr(seg a,seg b){return a.r<b.r;}
int pow(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>k>>n>>m;if(!n && !m)return cout<<pow(2,k),0;
	for(i=1;i<=n;++i)cin>>s[i].l>>s[i].r;
	sort(s+1,s+n+1,cmpl);j=1<<30;
	for(i=n,n=0;i;--i)
		if(s[i].r<j)j=s[i].r,s0[++n]=s[i];
	for(i=1;i<=n;++i){
		a[++xb]=make_pair(s0[i].l-1,&s0[i].l);
		a[++xb]=make_pair(s0[i].r,&s0[i].r);
	}
	for(i=1;i<=m;++i)cin>>s[i].l>>s[i].r;
	sort(s+1,s+m+1,cmpl);j=1<<30;
	for(i=m,m=0;i;--i)
		if(s[i].r<j)j=s[i].r,s1[++m]=s[i];
	for(i=1;i<=m;++i){
		a[++xb]=make_pair(s1[i].l-1,&s1[i].l);
		a[++xb]=make_pair(s1[i].r,&s1[i].r);
	}sort(a+1,a+xb+1);
	for(i=1;i<=xb;++i){
		if(a[i].first>a[i-1].first || i==1)b[++cnt]=a[i].first;
		*a[i].second=cnt;
	}i=1;f[i][0]=f[i][1]=1;i00=i10=i01=i11=i;
	sort(s0+1,s0+n+1,cmpr),sort(s1+1,s1+m+1,cmpr);
	for(i=2;i<=cnt;++i){
		for(;i10<=n && s0[i10].l<i;++i10)s10=(s10+f[s0[i10].l][1])%mo;
		for(;i00<=n && s0[i00].r<=i;++i00)
			s00=(s00+1ll*f[s0[i00].l][1]*pow(inv2,b[s0[i00].r]))%mo,s10=(s10+mo-f[s0[i00].l][1])%mo;
		for(;i11<=m && s1[i11].l<i;++i11)s11=(s11+f[s1[i11].l][0])%mo;
		for(;i01<=m && s1[i01].r<=i;++i01)
			s01=(s01+1ll*f[s1[i01].l][0]*pow(inv2,b[s1[i01].r]))%mo,s11=(s11+mo-f[s1[i01].l][0])%mo;
		f[i][1]=(pow(2,b[i]-b[1])+mo*2ll-s10-1ll*(s00+s01)*pow(2,b[i])%mo)%mo;
		f[i][0]=(pow(2,b[i]-b[1])+mo*2ll-s11-1ll*(s01+s00)*pow(2,b[i])%mo)%mo;
	}
	return cout<<1ll*pow(2,k-b[cnt]+b[1])*f[cnt][1]%mo,0;
}