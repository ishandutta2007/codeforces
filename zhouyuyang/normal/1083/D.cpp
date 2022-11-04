#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
const int N=100005;
const int mo=1000000007;
int n;
struct SEG1{
	int tp,t[N*4];
	//tp:0=max,1=min
	int F(int x,int y){
		return tp?min(x,y):x+y-min(x,y);
	}
	void build(int k,int l,int r,int *a){
		if (l==r){
			t[k]=a[l];
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid,a);
		build(k*2+1,mid+1,r,a);
		t[k]=F(t[k*2],t[k*2+1]);
	}
	int ask(int k,int l,int r,int x,int y){
		if (l==x&&r==y) return t[k];
		int mid=(l+r)/2;
		if (y<=mid) return ask(k*2,l,mid,x,y);
		if (x>mid) return ask(k*2+1,mid+1,r,x,y);
		return F(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
	}
}T2,T3;
struct node{
	int tg1,tg2,nds;
	ll S1,S2,S;
	node operator +(const node &b)const{
		node a=*this,c;
		c.S=a.S+b.S;
		c.S1=a.S1+b.S1;
		c.S2=a.S2+b.S2;
		c.nds=a.nds+b.nds;
		c.tg1=c.tg2=0;
		return c;
	}
	void change(int tp,int v){
		if (tp==0){
			tg1+=v;
			S1+=1ll*nds*v;
			S+=1ll*S2*v;
		}
		if (tp==1){
			tg2+=v;
			S2+=1ll*nds*v;
			S+=1ll*S1*v;
		}
	}
};
struct SEG2{
	node t[N*4];
	void build(int k,int l,int r){
		if (l==r){
			t[k]=(node){0,0,1,l-1,n+1,1ll*(l-1)*(n+1)};
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
		t[k]=t[k*2]+t[k*2+1];
	}
	void pushdown(int k){
		if (t[k].tg1){
			t[k*2].change(0,t[k].tg1);
			t[k*2+1].change(0,t[k].tg1);
			t[k].tg1=0;
		}
		if (t[k].tg2){
			t[k*2].change(1,t[k].tg2);
			t[k*2+1].change(1,t[k].tg2);
			t[k].tg2=0;
		}
	}
	void change(int k,int l,int r,int x,int y,int tp,int v){
		if (l==x&&r==y) return t[k].change(tp,v);
		pushdown(k);
		int mid=(l+r)/2;
		if (y<=mid) change(k*2,l,mid,x,y,tp,v);
		else if (x>mid) change(k*2+1,mid+1,r,x,y,tp,v);
		else{
			change(k*2,l,mid,x,mid,tp,v);
			change(k*2+1,mid+1,r,mid+1,y,tp,v);
		} 
		t[k]=t[k*2]+t[k*2+1];
	}
	ll ask(int k,int l,int r,int x,int y,int tp){
		if (l==x&&r==y) return tp?t[k].S1:t[k].S;
		pushdown(k);
		int mid=(l+r)/2;
		if (y<=mid) return ask(k*2,l,mid,x,y,tp);
		if (x>mid) return ask(k*2+1,mid+1,r,x,y,tp);
		return ask(k*2,l,mid,x,mid,tp)+ask(k*2+1,mid+1,r,mid+1,y,tp);
	}
}T1;
int a[N],pre[N],nxt[N];
map<int,int> mp;
pii q0[N],q1[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		if (mp.find(a[i])==mp.end()) pre[i]=0;
		else pre[i]=mp[a[i]]; 
		mp[a[i]]=i;
	}
	mp.clear();
	Rep(i,n,1){
		if (mp.find(a[i])==mp.end()) nxt[i]=n+1;
		else nxt[i]=mp[a[i]]; 
		mp[a[i]]=i;
	}
	int tp0=1,tp1=1;
	T1.build(1,1,n);
	T2.tp=0; T3.tp=1;
	T2.build(1,1,n,pre);
	T3.build(1,1,n,nxt);;
	q0[tp0]=pii(1e9,0);
	//q0:pre
	q1[tp1]=pii(-1e9,0);
	//q1:nxt
	int l=1,ans=0;
	For(i,1,n){
		q0[++tp0]=pii(0,i);
		for (;;){
			T1.change(1,1,n,q0[tp0-1].se+1,q0[tp0].se,0,q0[tp0].fi-pre[i]);
			if (q0[--tp0].fi>pre[i]) break;
		}
		q0[++tp0]=pii(pre[i],i);
		q1[++tp1]=pii(n+1,i);
		for (;;){
			T1.change(1,1,n,q1[tp1-1].se+1,q1[tp1].se,1,nxt[i]-q1[tp1].fi);
			if (q1[--tp1].fi<nxt[i]) break;
		}
		q1[++tp1]=pii(nxt[i],i);
		for (;T2.ask(1,1,n,l,i)>=l||T3.ask(1,1,n,l,i)<=i;l++);
		ans=(ans+T1.ask(1,1,n,l,i,0))%mo;
		ans=(ans+mo-1ll*(i+1)*T1.ask(1,1,n,l,i,1)%mo)%mo;
	}
	printf("%d\n",ans);
}
//(l-pre-1)*(nxt-r-1)
//(l-pre-1)*nxt
//(l-pre-1)*(r+1)