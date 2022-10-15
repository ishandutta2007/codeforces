#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline ll
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
const int Mod=998244353,inv2=499122177;
const ll N=(1ll<<60)-1;
struct P{
	ll x,y;
	P(ll _x=0,ll _y=0){x=_x;y=_y;}
	friend bool operator < (P a,P b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
}a[110],b[110];
ll n,m;
ll cnt,root,lc[404000],rc[404000],w[404000],L,R,ans;
vector<P>veca[70],vecb[70],vecc;
I add(ll &x,ll y){(x+=y)>=Mod?x-=Mod:0;}
IN Plus(ll x,ll y){(x+=y)>=Mod?x-=Mod:0;return x;}
I modi(ll &k,ll l,ll r,ll x,ll y){
	if(x>r||y<l)return;
	if(!k)k=++cnt,lc[k]=rc[k]=w[k]=0;
	if(x<=l&&r<=y)return w[k]=1,void();
	re mid=(l+r)>>1;
	modi(lc[k],l,mid,x,y),modi(rc[k],mid+1,r,x,y);
}
I revi(ll l,ll r,ll x,ll y,ll dep){
	if(x>r||y<l)return;
	vecb[dep].emplace_back(P(l,r));
	if(x<=l&&r<=y)return;
	re mid=(l+r)>>1;
	revi(l,mid,x,y,dep+1);revi(mid+1,r,x,y,dep+1);
}
I getit(ll k,ll l,ll r,ll dep){
	if(!k)return;
	if(w[k])veca[dep].emplace_back(P(l,r));
	re mid=(l+r)>>1;
	getit(lc[k],l,mid,dep+1);getit(rc[k],mid+1,r,dep+1);
}
I solve(){
	re l,r,w;
	F(i,1,60)for(auto x:veca[i])for(auto y:vecb[i]){
		w=(x.x^y.x);w>>=(60-i);w<<=(60-i);l=w;r=l+(1ll<<(60-i))-1ll;
		vecc.emplace_back(P(l,r));
//		cout<<"!"<<l<<" "<<r<<endl;
	}
}
IN calc(ll x,ll y){
	x%=Mod;y%=Mod;
	return (ll)Plus(y+1,Mod-x)*Plus(x,y)%Mod*inv2%Mod;
}
int main(){
	read(n);
	F(i,1,n)read(a[i].x),read(a[i].y);
	sort(a+1,a+1+n);
	read(m);
	F(i,1,m)read(b[i].x),read(b[i].y);
	sort(b+1,b+1+m);
	F(i,1,n)modi(root,0,N,a[i].x,a[i].y);
	F(i,1,m)revi(0,N,b[i].x,b[i].y,0);
	getit(root,0,N,0);
	solve();
	F(i,1,60)veca[i].clear(),vecb[i].clear();root=cnt=0;
	F(i,1,n)revi(0,N,a[i].x,a[i].y,0);
	F(i,1,m)modi(root,0,N,b[i].x,b[i].y);
	getit(root,0,N,0);
	solve();
	F(i,1,60)veca[i].clear(),vecb[i].clear();
	sort(vecc.begin(),vecc.end());
	if(vecc.begin()==vecc.end())return !printf("0");
	L=vecc[0].x;R=vecc[0].y;
	for(auto d:vecc){
		if(d.x<=R)R=max(R,d.y);
		else add(ans,calc(L,R)),L=d.x,R=d.y;
	}
	add(ans,calc(L,R));
	cout<<ans;
	return 0;
}