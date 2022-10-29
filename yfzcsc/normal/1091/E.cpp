#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
typedef pair<ll,ll> pii;
int n,d[maxn],C[maxn];
pii tr[maxn];
ll T1[maxn],T3[maxn],mx[maxn],T2[maxn],S[maxn];
pii operator+(const pii a,const pii b){
	return pii(a.first+b.first,a.second+b.second);
}
void add(ll x,pii p){
	for(x++;x<=n+1;x+=x&-x)tr[x]=tr[x]+p;
}
pii qry(ll x){
	pii ans(0,0);
	for(x++;x;x-=x&-x)ans=(ans+tr[x]);
	return ans;
}
ll qryk(ll K){
	pii p=qry(K);
	pii q=qry(n);
	return (q.first-p.first)*K+p.second;
}
pii s[maxn<<2];
pii mer(pii a,pii b){
	return pii(max(a.first,b.first),max(a.second,b.second));
}
void build(int o,int l,int r){
	if(l==r){
		s[o].first=T1[l]-l;
		s[o].second=T1[l];
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	s[o]=mer(s[o<<1],s[o<<1|1]);
}
pii qry(int o,int l,int r,int ql,int qr){
	if(max(ql,l)>min(qr,r))return pii(-(ll)1e18,-(ll)1e18);
	if(ql<=l&&r<=qr){
		return s[o];
	}
	int mid=l+r>>1;
	if(qr<=mid)return qry(o<<1,l,mid,ql,qr);
	if(ql>mid)return qry(o<<1|1,mid+1,r,ql,qr);
	return mer(qry(o<<1,l,mid,ql,qr),qry(o<<1|1,mid+1,r,ql,qr));
}
void mdy(int o,int l,int r,int x,pii p){
	if(l==r){
		s[o]=mer(s[o],p);
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)mdy(o<<1,l,mid,x,p);
	else mdy(o<<1|1,mid+1,r,x,p);
	s[o]=mer(s[o<<1],s[o<<1|1]);
}
int main(){
	ll sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&d[i]),sum+=d[i];
	sort(d+1,d+n+1,[](int x,int y){return x>y;});
	
	for(int i=1;i<=n;++i)S[i]=S[i-1]+d[i];
	for(int i=n;i>=1;--i){
		//k<A	
		T1[i]=S[i]-(ll)i*(i-1)-qryk(i);
		//k>A
		T2[i]=S[i]-(ll)i*(i+1)-qryk(i+1);
		add(d[i],pii(1,d[i]));
		//k=A
		T3[i]=qryk(i);
//		printf("[%lld]",T1[i]);
	}
	mx[n+1]=-(ll)1e18;
	for(int i=n;i>=1;--i){
		mx[i]=max(mx[i+1],T2[i]);
	}
	build(1,1,n);
	vector<int>v;
	for(int i=n,pos=1;i>=0;--i){
		while(d[pos]>=i&&pos<=n)pos++;
		int A=pos,B=i,flg=1;
		//k<A
		flg&=qry(1,1,n,1,min(B,A-1)).first<=0;
//		printf("{(%d,%d)%lld}",B,A-1,qry(1,1,n,1,min(B,A-1)).first);
//		printf("[%d,%d]",i,flg);
		flg&=qry(1,1,n,B,A-1).second<=B;
//		printf("[%d,%d]",i,flg);
		//k>A
		flg&=mx[A]<=-B;
//		printf("[%d,%d]",i,flg);
		//k=A
		flg&=B+S[A-1]-(ll)A*(A-1)<=T3[A];
		flg&=(sum+B)%2==0;
//		printf("[%d,%d]",i,flg);
		if(flg){
			v.push_back(i);
//			printf("%d ",i);
		}
	}
	if(!v.size()){
		puts("-1");
		return 0;
	}
	sort(v.begin(),v.end());
	for(auto a:v)printf("%d ",a);
}