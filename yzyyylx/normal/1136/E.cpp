#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 100100
using namespace std;

ll n,m,tt,num[N],K[N];
char str[5];
struct Node
{
    ll ls,rs,ad,sum;
}node[N<<1];
set<P>se;
set<P>::iterator it;
vector<set<P>::iterator>cle;

inline void up(ll now)
{
    ll L=node[now].ls,R=node[now].rs;
    node[now].sum=node[L].sum+node[R].sum;
}

void build(ll now,ll l,ll r)
{
    if(l==r)
    {
	node[now].sum=num[l];
	return;
    }
    ll mid=((l+r)>>1);
    node[now].ls=++tt;
    build(tt,l,mid);
    node[now].rs=++tt;
    build(tt,mid+1,r);
    up(now);
}

void add(ll now,ll l,ll r,ll u,ll v,ll w)
{
//    cout<<now<<" "<<l<<" "<<r<<' '<<u<<' '<<v<<' '<<w<<endl;for(int i=1;i<=500000000;i++);
    node[now].sum+=(v-u+1)*w;
    if(u==l&&v==r)
    {
	node[now].ad+=w;
	return;
    }
    ll mid=((l+r)>>1);
    if(u<=mid) add(node[now].ls,l,mid,u,min(v,mid),w);
    if(mid<v) add(node[now].rs,mid+1,r,max(u,mid+1),v,w);
}

ll ask(ll now,ll l,ll r,ll u,ll v)
{
    if(u==l&&v==r) return node[now].sum;
    ll mid=((l+r)>>1),res=node[now].ad*(v-u+1);
    if(u<=mid) res+=ask(node[now].ls,l,mid,u,min(v,mid));
    if(mid<v) res+=ask(node[now].rs,mid+1,r,max(u,mid+1),v);
    return res;
}

int main()
{
    ll i,j,p,q,t;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%lld",&num[i]);
    for(i=1;i<n;i++) scanf("%lld",&K[i]);
    build(tt=1,1,n);
    cin>>m;
    for(i=1;i<=n;i=j)
    {
	for(j=i+1;j<=n;j++)
	{
	    num[j]=max(num[j],num[j-1]+K[j-1]);
	    if(num[j]!=num[j-1]+K[j-1]) break;
	}
//	cout<<" "<<i<<" "<<j-1<<endl;
	se.insert(mp(i,j-1));
    }
    while(m--)
    {
//	for(it=se.begin();it!=se.end();it++) cout<<(*it).fi<<" "<<(*it).se<<endl;puts("");
	scanf("%s",str);
	if(str[0]=='s')
	{
	    scanf("%lld%lld",&p,&q);
	    printf("%lld\n",ask(1,1,n,p,q));
	}
	else
	{
	    scanf("%lld%lld",&p,&q);
	    it=se.upper_bound(mp(p,n+1)),it--,cle.push_back(it);
//	    cerr<<" "<<(*it).fi<<' '<<(*it).se<<endl;
	    P tmp=(*it);it++;
//	    puts("ok");
//	    cout<<p<<"   "<<tmp.se<<" "<<q<<endl;
	    add(1,1,n,p,tmp.se,q);
//	    puts("ok");
	    if(p>tmp.fi) se.insert(mp(tmp.fi,p-1));
	    for(;it!=se.end();it++)
	    {
//		cerr<<" "<<(*it).fi<<' '<<(*it).se<<endl;
		t=(*it).fi;
		int a=ask(1,1,n,t-1,t-1),b=ask(1,1,n,t,t);
		if(b>a+K[t-1]) break;
		q=a+K[t-1]-b;
		add(1,1,n,(*it).fi,(*it).se,q);
		cle.push_back(it);
	    }
	    it--,q=(*it).se;
	    for(i=0;i<cle.size();i++) se.erase(cle[i]);cle.clear();
	    se.insert(mp(p,q));
	}
    }
}