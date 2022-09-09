#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll mi[99],xx;int xxb;
inline ll calc(ll x){return *lower_bound(mi,mi+xxb,x)-x;}
struct node{
	int lb,rb,md;
	ll tag1,tag2,mn;
	inline void set(ll x,ll y=-1){
		tag1=x;tag2=0;
		if(y==-1)mn=calc(tag1);else mn=y;
	}
	inline void add(ll x){if(tag1!=-1)tag1+=x;else tag2+=x;mn-=x;if(mn<0)mn=calc(tag1);}
}T[N<<2];
int n,q,t[N],o,l,r,x,i;
inline void upd(int x){T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);}
inline void down(int x){
	if(T[x].tag1!=-1)T[x<<1].set(T[x].tag1,T[x].mn),T[x<<1|1].set(T[x].tag1,T[x].mn),T[x].tag1=-1;
	if(T[x].tag2)T[x<<1].add(T[x].tag2),T[x<<1|1].add(T[x].tag2),T[x].tag2=0;
}
void build(int i,int l,int r){
	T[i].lb=l;T[i].rb=r;T[i].md=l+r>>1;T[i].tag1=-1;
	if(l==r)return T[i].set(t[l]);
	build(i<<1,l,T[i].md);build(i<<1|1,T[i].md+1,r);upd(i);
}
void mdy1(int i){
	if(l<=T[i].lb && T[i].rb<=r)return T[i].set(x,xx);
	down(i);if(l<=T[i].md)mdy1(i<<1);if(T[i].md<r)mdy1(i<<1|1);upd(i);
}
void mdy2(int i){
	if(l<=T[i].lb && T[i].rb<=r){
		if(T[i].mn>x || T[i].tag1!=-1)T[i].add(x);else{
			down(i);
			if(T[i<<1].mn>x)T[i<<1].add(x);else mdy2(i<<1);
			if(T[i<<1|1].mn>x)T[i<<1|1].add(x);else mdy2(i<<1|1);
			upd(i);
		}
		return;
	}
	down(i);if(l<=T[i].md)mdy2(i<<1);if(T[i].md<r)mdy2(i<<1|1);upd(i);
}
ll ask(int i){
	if(T[i].tag1!=-1)return T[i].tag1;
	down(i);return l<=T[i].md?ask(i<<1):ask(i<<1|1);
}
int main(){
	for(i=*mi=1;mi[i-1]<1e14;mi[i]=mi[i-1]*42,++i);xxb=i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%d",t+i);build(1,1,n);
	for(;q--;){
		scanf("%d%d",&o,&l);if(o>1)scanf("%d%d",&r,&x);
		if(o==1)printf("%lld\n",ask(1));
		if(o==2)xx=calc(x),mdy1(1);
		if(o==3)for(;mdy2(1),T[1].mn==0;);
	}
	return 0;
}