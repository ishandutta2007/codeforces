#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 200100
using namespace std;

int n,m,Q,bb,cc,sn,st,num[N],tmp[N],ans[N],cnt[N<<1],ct[N];
struct Que
{
    int t,l,r,id;
    bool operator < (const Que &u) const
    {
	if(t/st!=u.t/st) return t/st<u.t/st;
	if(l/sn!=u.l/sn)
	{
	    if((t/st)&1) return l/sn<u.l/sn;
	    return l/sn>u.l/sn;
	}
	if((l/sn)&1) return r<u.r;
	return r>u.r;
    }
}que[N];
struct Cz
{
    int pos,u,v;
}cz[N];
map<int,int>mm;

inline int zh(int u)
{
    if(mm.count(u)) return mm[u];
    return mm[u]=++bb;
}

inline void ad(int u){ct[u]++;}
inline void de(int u){ct[u]--;}
inline void add(int u)
{
//    cerr<<"add:"<<u<<endl;
    de(cnt[u]);
    cnt[u]++;
    ad(cnt[u]);
}

inline void del(int u)
{
    de(cnt[u]);
    cnt[u]--;
    ad(cnt[u]);
}

int main()
{
    int i,j,o,p,q,t;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
	scanf("%d",&num[i]);
	num[i]=zh(num[i]);
	tmp[i]=num[i];
    }
    for(i=1;i<=m;i++)
    {
	scanf("%d%d%d",&o,&p,&q);
	if(o==1) que[++Q]=(Que){cc,p,q,Q};
	else
	{
	    q=zh(q);
	    cz[++cc]=(Cz){p,num[p],q};
	    num[p]=q;
	}
    }
    st=pow(cc,2.0/3.0);
    sn=pow(n,2.0/3.0);
//    cerr<<" "<<st<<" "<<sn<<endl;
    sort(que+1,que+Q+1);
    memcpy(num,tmp,sizeof(num));
    for(i=p=1,q=t=0;i<=Q;i++)
    {
	for(;t<que[i].t;)
	{
	    t++;
	    num[cz[t].pos]=cz[t].v;
	    if(cz[t].pos>=p && cz[t].pos<=q)
	    {
		del(cz[t].u);
		add(cz[t].v);
	    }
	}
	for(;t>que[i].t;)
	{
	    num[cz[t].pos]=cz[t].u;
	    if(cz[t].pos>=p && cz[t].pos<=q)
	    {
		del(cz[t].v);
		add(cz[t].u);
	    }
	    t--;
	}
	for(;q<que[i].r;q++) add(num[q+1]);
	for(;p>que[i].l;p--) add(num[p-1]);
	for(;q>que[i].r;q--) del(num[q]);
	for(;p<que[i].l;p++) del(num[p]);
//	cerr<<"ask:"<<pq.top()<<endl;
	for(j=1;ct[j];j++);
	ans[que[i].id]=j;
    }
    for(i=1;i<=Q;i++) printf("%d\n",ans[i]);
}