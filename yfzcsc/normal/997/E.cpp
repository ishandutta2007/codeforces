#include<bits/stdc++.h>
#define xx first
#define yy second
#define maxn 130000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll inf=1ll<<60;
struct WXHAK{
	ll mn,atg,ans,tim,cnt; 
}s[maxn<<2];
void add(WXHAK& w,ll x){
	w.mn+=x;
	w.atg+=x;
}
void addtim(WXHAK& w,ll t){
	w.tim+=t;
	w.ans+=w.cnt*t;
}
void pd(int o){
	int ls=o<<1,rs=o<<1|1;
	if(s[o].atg){
		add(s[ls],s[o].atg);
		add(s[rs],s[o].atg);
		s[o].atg=0;
	}
	if(s[o].tim){
		if(s[o].mn==s[ls].mn)addtim(s[ls],s[o].tim);
		if(s[o].mn==s[rs].mn)addtim(s[rs],s[o].tim);
		s[o].tim=0;
	}
}
void upd(int o){
	int ls=o<<1,rs=o<<1|1;
	s[o].mn=min(s[ls].mn,s[rs].mn);
	s[o].ans=s[ls].ans+s[rs].ans;
	s[o].cnt=0;
	if(s[ls].mn==s[o].mn)s[o].cnt+=s[ls].cnt;
	if(s[rs].mn==s[o].mn)s[o].cnt+=s[rs].cnt;
}
void mdy(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){
		add(s[o],x);
		return ;
	}
	pd(o);
	int mid=l+r>>1;
	if(ql<=mid)mdy(o<<1,l,mid,ql,qr,x);
	if(qr>mid)mdy(o<<1|1,mid+1,r,ql,qr,x);
	upd(o);
}
ll qry(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return s[o].ans;
	int mid=l+r>>1;
	pd(o);
	if(qr<=mid)return qry(o<<1,l,mid,ql,qr);
	else if(ql>mid)return qry(o<<1|1,mid+1,r,ql,qr);
	return qry(o<<1,l,mid,ql,qr)+qry(o<<1|1,mid+1,r,ql,qr);
}
void build(int o,int l,int r){
	if(l==r){
		s[o].mn=l;
		s[o].cnt=1;
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	upd(o);
}
ll anses[maxn];
int n,a[maxn],Q,stmx[maxn],stmn[maxn],tmx,tmn;
vector<pii>G[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	scanf("%d",&Q);
	for(int i=1,l,r;i<=Q;++i){
		scanf("%d%d",&l,&r);
		G[r].push_back(pii(l,i));
	}
	build(1,1,n);
	for(int i=1;i<=n;++i){
		mdy(1,1,n,1,n,-1);
		while(tmx&&a[stmx[tmx]]<a[i])
			mdy(1,1,n,stmx[tmx-1]+1,stmx[tmx],-a[stmx[tmx]]),tmx--;
		mdy(1,1,n,stmx[tmx]+1,i,a[i]),stmx[++tmx]=i;
		while(tmn&&a[stmn[tmn]]>a[i])
			mdy(1,1,n,stmn[tmn-1]+1,stmn[tmn],a[stmn[tmn]]),tmn--;
		mdy(1,1,n,stmn[tmn]+1,i,-a[i]),stmn[++tmn]=i;
		addtim(s[1],1);
		for(auto p:G[i])anses[p.second]=qry(1,1,n,p.first,i);
	}
	for(int i=1;i<=Q;++i)printf("%lld\n",anses[i]);
}