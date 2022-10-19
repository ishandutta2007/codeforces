#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mp make_pair
#define mk(x,y,z) mp(mp(x,y),z)
#define fi first
#define se second
#define LG 50
#define N 400100
#define M 1e15+100
using namespace std;

ll n,m,Q,dd,cg[N];
P fa[N][60];
PP fz[N];
char str[5];
struct Xd
{
    ll w,u,v,dir;
}xd[N];
struct Que
{
    ll u,v,w,dir;
}que[N];
map<PP,ll>mm;

inline ll zh(ll u,ll v,ll w)
{
    if(mm.count(mk(u,v,w))) return mm[mk(u,v,w)];
    fz[++dd]=mk(u,v,w);
    return mm[mk(u,v,w)]=dd;
}

namespace Smx
{
    ll xx,tt,aa;
    P as[N];
    struct Node
    {
	ll ls,rs,dw;
    }node[N<<1];
    struct Xn
    {
	ll w,u,v,id;
	bool operator < (const Xn &u) const{return w<u.w;}
    }xn[N];
    inline void down(ll now)
    {
	ll L=node[now].ls,R=node[now].rs;
	if(node[now].dw)
	{
	    node[L].dw=node[now].dw;
	    node[R].dw=node[now].dw;
	    node[now].dw=0;
	}
    }
    void build(ll now,ll l,ll r)
    {
	if(l==r) return;
	ll mid=((l+r)>>1);
	node[now].ls=++tt;
	build(tt,l,mid);
	node[now].rs=++tt;
	build(tt,mid+1,r);
    }
    void chg(ll now,ll l,ll r,ll u,ll v,ll w)
    {
	if(now==1&&u>v) swap(u,v);
//	if(now==1) cout<<"chg:"<<u<<" "<<v<<" "<<w<<endl;
	if(u<=l&&r<=v)
	{
	    node[now].dw=w;
	    return;
	}
	down(now);
	ll mid=((l+r)>>1);
	if(u<=mid) chg(node[now].ls,l,mid,u,v,w);
	if(mid<v) chg(node[now].rs,mid+1,r,u,v,w);
    }
    ll ask(ll now,ll l,ll r,ll u)
    {
//	if(now==1) cout<<"ask:"<<u<<endl;
	if(node[now].dw || l==r) return node[now].dw;
	ll mid=((l+r)>>1);
	if(u<=mid) return ask(node[now].ls,l,mid,u);
	return ask(node[now].rs,mid+1,r,u);
    }
    inline void work()
    {
	ll i,j,p,q;
	build(tt=1,0,m);
	for(i=1;i<=n;i++)
	{
	    if(xd[i].dir>=2) xn[++xx]=(Xn){xd[i].w,xd[i].u,xd[i].v,i};
	    else if(xd[i].dir==1) xn[++xx]=(Xn){xd[i].u,xd[i].w,xd[i].w,i},xn[++xx]=(Xn){xd[i].v,xd[i].w,xd[i].w,i};
	    else as[++aa]=mp(xd[i].v,xd[i].w);
	}
	for(i=1;i<=Q;i++) if(que[i].dir==0) as[++aa]=mp(que[i].u,que[i].v);
	sort(xn+1,xn+xx+1);
	sort(as+1,as+aa+1);
//	for(i=xx;i>=1;i--) cout<<xn[i].w<<" "<<xn[i].u<<" "<<xn[i].v<<" "<<xn[i].id<<endl;
//	for(i=1;i<=aa;i++) cout<<" "<<as[i].fi<<" "<<as[i].se<<endl;
	//*
	for(i=m,p=xx,q=aa;i>=0;i--)
	{
	    for(;p>=1&&xn[p].w==i;p--) chg(1,0,m,xn[p].u,xn[p].v,xn[p].id);
	    for(;q>=1&&as[q].fi==i;q--)
	    {
		if(q<aa&&as[q]==as[q+1]) continue;
		ll id=zh(as[q].fi,as[q].se,0),t=ask(1,0,m,as[q].se);
		if(t)
		{
		    if(xd[t].dir>=2)
		    {
			fa[id][0]=mp(zh(xd[t].w,as[q].se,xd[t].dir),xd[t].w-as[q].fi);
			if(as[q].se!=xd[t].v) fa[zh(xd[t].w,as[q].se,xd[t].dir)][0]=mp(zh(xd[t].w,xd[t].v,xd[t].dir),abs(xd[t].v-as[q].se));
		    }
		    else fa[id][0]=mp(zh(xd[t].v,xd[t].w,xd[t].dir),abs(xd[t].v-as[q].fi));
		}
		else
		{
		    fa[zh(m,as[q].se,0)][0]=mp(zh(m,as[q].se,0),0);
		    fa[id][0]=mp(zh(m,as[q].se,0),m-as[q].fi);
		}
	    }
	}
	//*/
//	return;
	
	aa=xx=0;
	for(i=1;i<=tt;i++) node[i].dw=0;
	for(i=1;i<=n;i++)
	{
	    if(xd[i].dir>=2) xn[++xx]=(Xn){xd[i].w,xd[i].u,xd[i].v,i};
	    else if(xd[i].dir==0) xn[++xx]=(Xn){xd[i].u,xd[i].w,xd[i].w,i},xn[++xx]=(Xn){xd[i].v,xd[i].w,xd[i].w,i};
	    else as[++aa]=mp(xd[i].v,xd[i].w);
	}
	for(i=1;i<=Q;i++) if(que[i].dir==1) as[++aa]=mp(que[i].u,que[i].v);
	sort(xn+1,xn+xx+1);
	sort(as+1,as+aa+1);
//	for(i=1;i<=aa;i++) cout<<as[i].fi<<" "<<as[i].se<<endl;
	for(i=0,p=q=1;i<=m;i++)
	{
//	    cout<<xn[p].w<<endl;
	    for(;p<=xx&&xn[p].w==i;p++) chg(1,0,m,xn[p].u,xn[p].v,xn[p].id);
	    for(;q<=aa&&as[q].fi==i;q++)
	    {
		if(q>1&&as[q]==as[q-1]) continue;
		ll id=zh(as[q].fi,as[q].se,1),t=ask(1,0,m,as[q].se);
		if(t)
		{
		    if(xd[t].dir>=2)
		    {
			fa[id][0]=mp(zh(xd[t].w,as[q].se,xd[t].dir),as[q].fi-xd[t].w);
			if(as[q].se!=xd[t].v) fa[zh(xd[t].w,as[q].se,xd[t].dir)][0]=mp(zh(xd[t].w,xd[t].v,xd[t].dir),abs(xd[t].v-as[q].se));
		    }
		    else fa[id][0]=mp(zh(xd[t].v,xd[t].w,xd[t].dir),abs(as[q].fi-xd[t].v));
		}
		else
		{
//		    cout<<" "<<0<<" "<<as[q].se<<endl;
		    fa[zh(0,as[q].se,1)][0]=mp(zh(0,as[q].se,1),0);
		    fa[id][0]=mp(zh(0,as[q].se,1),as[q].fi);
		}
	    }
	}
//	return;

	xx=aa=0;
	for(i=1;i<=tt;i++) node[i].dw=0;
	for(i=1;i<=n;i++)
	{
	    if(xd[i].dir<=1) xn[++xx]=(Xn){xd[i].w,xd[i].u,xd[i].v,i};
	    else if(xd[i].dir==3) xn[++xx]=(Xn){xd[i].u,xd[i].w,xd[i].w,i},xn[++xx]=(Xn){xd[i].v,xd[i].w,xd[i].w,i};
	    else as[++aa]=mp(xd[i].v,xd[i].w);
	}
	for(i=1;i<=Q;i++) if(que[i].dir==2) as[++aa]=mp(que[i].v,que[i].u);
	sort(xn+1,xn+xx+1);
	sort(as+1,as+aa+1);
//	for(i=1;i<=xx;i++) cout<<xn[i].w<<" "<<xn[i].u<<" "<<xn[i].v<<" "<<xn[i].id<<endl;
	for(i=0,p=q=1;i<=m;i++)
	{
	    for(;p<=xx&&xn[p].w==i;p++) chg(1,0,m,xn[p].u,xn[p].v,xn[p].id);
	    for(;q<=aa&&as[q].fi==i;q++)
	    {
		if(q>1&&as[q]==as[q-1]) continue;
		ll id=zh(as[q].se,as[q].fi,2),t=ask(1,0,m,as[q].se);
		if(t)
		{
		    if(xd[t].dir<=1)
		    {
			fa[id][0]=mp(zh(as[q].se,xd[t].w,xd[t].dir),as[q].fi-xd[t].w);
			if(as[q].se!=xd[t].v) fa[zh(as[q].se,xd[t].w,xd[t].dir)][0]=mp(zh(xd[t].v,xd[t].w,xd[t].dir),abs(xd[t].v-as[q].se));
		    }
		    else fa[id][0]=mp(zh(xd[t].w,xd[t].v,xd[t].dir),abs(as[q].fi-xd[t].v));
		}
		else
		{
		    fa[zh(as[q].se,0,2)][0]=mp(zh(as[q].se,0,2),0);
		    fa[id][0]=mp(zh(as[q].se,0,2),as[q].fi);
		}
	    }
	}
//	return;

	aa=xx=0;
	for(i=1;i<=tt;i++) node[i].dw=0;
	for(i=1;i<=n;i++)
	{
	    if(xd[i].dir<=1) xn[++xx]=(Xn){xd[i].w,xd[i].u,xd[i].v,i};
	    else if(xd[i].dir==2) xn[++xx]=(Xn){xd[i].u,xd[i].w,xd[i].w,i},xn[++xx]=(Xn){xd[i].v,xd[i].w,xd[i].w,i};
	    else as[++aa]=mp(xd[i].v,xd[i].w);
	}
	for(i=1;i<=Q;i++) if(que[i].dir==3) as[++aa]=mp(que[i].v,que[i].u);
	sort(as+1,as+aa+1);
	sort(xn+1,xn+xx+1);
//	for(i=xx;i>=1;i--) cout<<xn[i].w<<' '<<xn[i].u<<" "<<xn[i].v<<" "<<xn[i].id<<endl;
	for(i=m,p=xx,q=aa;i>=0;i--)
	{
	    for(;p>=1&&xn[p].w==i;p--) chg(1,0,m,xn[p].u,xn[p].v,xn[p].id);
	    for(;q>=1&&as[q].fi==i;q--)
	    {
		if(q<n&&as[q]==as[q+1]) continue;
		ll id=zh(as[q].se,as[q].fi,3),t=ask(1,0,m,as[q].se);
//		cout<<t<<endl;
		if(t)
		{
		    if(xd[t].dir<=1)
		    {
//			cout<<as[q].se<<' '<<as[q].fi<<"->"<<as[q].se<<" "<<xd[t].w<<endl;
			fa[id][0]=mp(zh(as[q].se,xd[t].w,xd[t].dir),xd[t].w-as[q].fi);
			if(as[q].se!=xd[t].v) fa[zh(as[q].se,xd[t].w,xd[t].dir)][0]=mp(zh(xd[t].v,xd[t].w,xd[t].dir),abs(xd[t].v-as[q].se));
		    }
		    else fa[id][0]=mp(zh(xd[t].w,xd[t].v,xd[t].dir),abs(xd[t].v-as[q].fi));
		}
		else
		{
		    fa[zh(as[q].se,m,3)][0]=mp(zh(as[q].se,m,3),0);
		    fa[id][0]=mp(zh(as[q].se,m,3),m-as[q].fi);
		}
	    }
	}
    }
}

int main()
{
    ll i,j,k,p,q,a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
	scanf("%lld%lld%lld%lld",&a,&b,&p,&q);
	if(a==p)
	{
	    if(b<q) xd[i]=(Xd){a,b,q,3};
	    else xd[i]=(Xd){a,b,q,2};
	}
	else
	{
	    if(a<p) xd[i]=(Xd){b,a,p,0};
	    else xd[i]=(Xd){b,a,p,1};
	}
    }
    cin>>Q;
    for(i=1;i<=Q;i++)
    {
	scanf("%lld%lld%s%lld",&a,&b,str+1,&p);
	if(str[1]=='R') que[i]=(Que){a,b,p,0};
	else if(str[1]=='L') que[i]=(Que){a,b,p,1};
	else if(str[1]=='D') que[i]=(Que){a,b,p,2};
	else que[i]=(Que){a,b,p,3};
    }
    Smx::work();
    //*
    for(i=1;i<=dd;i++)
    {
	if(!fa[i][0].se)
	{
	    cg[i]=fa[i][0].fi;
	    fa[i][0]=fa[fa[i][0].fi][0];
	}
    }
    //*/
//    for(i=1;i<=dd;i++) if(fa[i][0].se<0) cout<<fz[i].fi.fi<<" "<<fz[i].fi.se<<" "<<fz[i].se<<endl;
    for(j=1;j<=LG;j++)
    {
	for(i=1;i<=dd;i++)
	{
	    fa[i][j].fi=fa[fa[i][j-1].fi][j-1].fi;
	    fa[i][j].se=fa[i][j-1].se+fa[fa[i][j-1].fi][j-1].se;
	    if(fa[i][j].se>M) fa[i][j].se=M;
	}
    }
    /*
    if(n==3&&m==2)
    {
	cout<<que[167].u<<" "<<que[167].v<<" "<<que[167].w<<" "<<que[167].dir;
	return 0;
    }
    //*/
    /*
    for(i=0;i<=m;i++)
    {
	for(j=0;j<=m;j++)
	{
	    for(k=0;k<4;k++)
	    {
		if(!mm.count(mk(i,j,k))) continue;
		ll t=fa[zh(i,j,k)][0].fi;
		cerr<<i<<" "<<j<<" "<<k<<"->"<<fz[t].fi.fi<<" "<<fz[t].fi.se<<" "<<fz[t].se<<" dis="<<fa[zh(i,j,k)][0].se<<endl;
	    }
	}
    }
    return 0;
    //*/
//    cout<<Q<<endl;
    for(i=1;i<=Q;i++)
    {
//	puts("gg");
	ll p=zh(que[i].u,que[i].v,que[i].dir),q=que[i].w;
	if(cg[p]) p=cg[p];
//	if(i==45) cerr<<que[i].u<<" "<<que[i].v<<" "<<que[i].w<<" "<<que[i].dir<<endl;
//	puts("gg");
	for(j=LG;j>=0;j--)
	{
	    if(fa[p][j].se<=q)
	    {
		q-=fa[p][j].se;
		p=fa[p][j].fi;
	    }
	}
//	if(i==45) cerr<<fa[p][0].se<<endl;
//	if(i==45) cerr<<fz[p].fi.fi<<" "<<fz[p].fi.se<<' '<<fz[p].se<<" "<<q<<endl;
	if(fa[p][0].fi==p)
	{
	    printf("%lld %lld\n",fz[p].fi.fi,fz[p].fi.se);
	    continue;
	}
	ll t=fa[p][0].fi;
	if(fz[p].fi.fi==fz[t].fi.fi)
	{
	    if(fz[p].fi.se<fz[t].fi.se) printf("%lld %lld\n",fz[p].fi.fi,fz[p].fi.se+q);
	    else printf("%lld %lld\n",fz[p].fi.fi,fz[p].fi.se-q);
	}
	else
	{
	    if(fz[p].fi.fi<fz[t].fi.fi) printf("%lld %lld\n",fz[p].fi.fi+q,fz[p].fi.se);
	    else printf("%lld %lld\n",fz[p].fi.fi-q,fz[p].fi.se);
	}
	/*
	if(fz[p].se==0) printf("%lld %lld\n",fz[p].fi.fi+q,fz[p].fi.se);
	else if(fz[p].se==1) printf("%lld %lld\n",fz[p].fi.fi-q,fz[p].fi.se);
	else if(fz[p].se==2) printf("%lld %lld\n",fz[p].fi.fi,fz[p].fi.se-q);
	else printf("%lld %lld\n",fz[p].fi.fi,fz[p].fi.se+q);
	//*/
    }
}