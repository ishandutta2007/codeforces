#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define y1 __y1__
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=50007;
const ld eps=1e-17;
struct Line{ld k,b;}a[N];
int n,m,tot,v[N];
pair<ld,int>c[N<<1];
struct b1t{
	int c[N<<1];
	inline void clear(){for(int i=1;i<=tot;i++)c[i]=0;}
	inline void add(int p,int x){for(;p<=tot;p+=p&-p)c[p]+=x;}
	inline int ask(int p){int res=0;for(;p;p^=p&-p)res+=c[p];return res;}
	inline int query(int l,int r){return ask(r)-ask(l-1);}
}T;
inline void work(ld mid){
	tot=0;
	for(int i=1;i<=n;i++){
		ld k=a[i].k,b=a[i].b,d=4*k*k*b*b-4*(k*k+1)*(b*b-mid*mid);
		if(d<eps)continue;d=sqrtl(d);
		ld x1=(-2*k*b-d)/(2*(k*k+1)),x2=(-2*k*b+d)/(2*(k*k+1)),y1=k*x1+b,y2=k*x2+b;
		c[++tot]={atan2l(y1,x1),i},c[++tot]={atan2l(y2,x2),i},v[i]=0;
	}
	sort(c+1,c+tot+1);
	for(int i=tot;i;i--)if(!v[c[i].se])v[c[i].se]=i;
}
inline bool chk(ld mid){
	work(mid),T.clear();
	ll res=0;
	for(int i=1;i<=tot;i++)
		if(v[c[i].se]!=i)res+=T.query(i,v[c[i].se]),T.add(v[c[i].se],1);
	return res>=m;
}
inline ld dist(int i,int j){
	ld x=(a[j].b-a[i].b)/(a[i].k-a[j].k),y=a[i].k*x+a[i].b;
	return sqrtl(x*x+y*y);
}
inline ld calc(ld mid){
	work(mid);set<pair<int,int> >s;
	ld res=0;int cnt=0;
	for(int i=1;i<=tot;i++)
		if(v[c[i].se]!=i){
			auto it=s.upper_bound({i+1,0});
			while(it!=s.end() && (it->fi)<v[c[i].se])res+=dist(c[i].se,it->se),++it,cnt++;
			s.insert({v[c[i].se],c[i].se});
		}
	return res+mid*(m-cnt);
}
ld p,q;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),p=read()/1000.,q=read()/1000.,m=read();
	for(int i=1;i<=n;i++)a[i].k=read()/1000.,a[i].b=read()/1000.-q+a[i].k*p;
	ld l=0,r=1e10;
	for(int i=1;i<=100;i++){
		ld mid=(l+r)/2;
		if(chk(mid))r=mid;
		else l=mid;
	}
	printf("%.9Lf\n",calc(l));
	return 0;
}