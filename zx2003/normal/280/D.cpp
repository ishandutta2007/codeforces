#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int st[3000],w,n,a[N],m,o,l,r,k,ans;
struct tup{
	int v,l,r;
	inline tup():v(0),l(0),r(0){}
	inline tup(int i):v(a[i]),l(i),r(i){}
	inline tup(int _v,int _l,int _r):v(_v),l(_l),r(_r){}
	bool operator<(const tup&rhs)const{return v<rhs.v;}
	inline tup operator+(const tup&rhs)const{return (tup){v+rhs.v,l,rhs.r};}
}z;
struct pai{
	tup mn,mx;
	inline pai():mn(0,0,0),mx(0,0,0){}
	inline pai(const tup&z):mn(z),mx(z){}
	inline pai(const tup&a,const tup&b):mn(a),mx(b){}
	inline void rev(){swap(mn,mx);mn.v*=-1;mx.v*=-1;}
	inline pai operator+(const pai&rhs)const{
		return pai(mn+rhs.mn,mx+rhs.mx);
	}
	inline pai operator*(const pai&rhs)const{
		return pai(min(mn,rhs.mn),max(mx,rhs.mx));
	}
};
struct node{
	pai pr,sf,ans;
	int l,r,m,t,su;
	inline void rev(){t^=1;pr.rev();sf.rev();ans.rev();su*=-1;}
	inline void operator+=(const node&rhs){
		ans=ans*rhs.ans*(sf+rhs.pr);
		pr=pr*(pai(tup(su,l,r))+rhs.pr);
		sf=rhs.sf*(sf+pai(tup(rhs.su,rhs.l,rhs.r)));
		su+=rhs.su;r=rhs.r;m=(l+r)>>1;
	}
}t[N<<2],ot[N<<2];
inline void maintain(int i){t[i]=t[i<<1];t[i].t=0;t[i]+=t[i<<1|1];}
inline void pushdown(int i){if(t[i].t)st[++w]=i<<1,st[++w]=i<<1|1,t[i<<1].rev(),t[i<<1|1].rev(),t[i].t=0;}
void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;t[i].m=(l+r)>>1;
	if(l==r){
		t[i].pr=t[i].sf=t[i].ans=(pai){tup(l),tup(l)};t[i].su=a[l];
		return;
	}
	build(i<<1,l,t[i].m);build(i<<1|1,t[i].m+1,r);maintain(i);
}
void mdy(int i,int k){
	if(t[i].l==k && t[i].r==k){
		t[i].pr=t[i].sf=t[i].ans=(pai){tup(k),tup(k)};t[i].su=a[k];
		ot[i]=t[i];return;
	}
	pushdown(i);mdy(i<<1|(t[i].m<k),k);maintain(i);ot[i]=t[i];
}
void rev(int i,int l,int r){
	st[++w]=i;
	if(l<=t[i].l && t[i].r<=r)return t[i].rev();
	pushdown(i);if(l<=t[i].m)rev(i<<1,l,r);if(r>t[i].m)rev(i<<1|1,l,r);
	maintain(i);
}
void query(int i,int l,int r){
	if(l<=t[i].l && t[i].r<=r){if(l==t[i].l)t[0]=t[i];else t[0]+=t[i];return;}
	pushdown(i);if(l<=t[i].m)query(i<<1,l,r);if(r>t[i].m)query(i<<1|1,l,r);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(int i=1;i<=n;++i)cin>>a[i];build(1,1,n);memcpy(ot,t,sizeof t);
	for(cin>>m;m--;){
		cin>>o>>l>>r;if(o==0){a[l]=r;mdy(1,l);continue;}
		w=ans=0;cin>>k;
		for(;k-- && (query(1,l,r),z=t[0].ans.mx,z.v>0);)
			ans+=z.v,rev(1,z.l,z.r);
		cout<<ans<<'\n';
		sort(st+1,st+w+1);w=unique(st+1,st+w+1)-st-1;for(;w;t[st[w]]=ot[st[w]],--w);
	}
	return 0;
}