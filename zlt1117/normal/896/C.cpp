#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define db double
#define ll long long
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int> 
#define iter set<node>::iterator 
#define int ll
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int maxn=1e5+5;
struct node
{
	int l,r;
	mutable int val;
	node(int x=0,int y=0,int v=0){l=x,r=y,val=v;}
	inline bool operator < (const node &b)const{return l<b.l;}
};
inline bool cmp(const node &a,const node &b)
{
	return a.val<b.val;
}
set<node>s;
int opt,l,r,x,y,n,q,seed,mod,a[maxn];
inline int rd()
{
	int ret=seed;
	seed=(1ll*seed*7+13)%1000000007;
	return ret;
}
inline iter split(int x)
{
	iter it=s.lower_bound(node(x,0,0));
	if(it!=s.end()&&it->l==x)return it;
	it--;
	int l=it->l,r=it->r,val=it->val;
	s.erase(it);
	s.insert(node(l,x-1,val)),s.insert(node(x,r,val));
	return s.find(node(x,r,val));
}
inline void init()
{
	
}
inline void input()
{
	n=gi(),q=gi(),seed=gi(),mod=gi();
	FOR(i,1,n)a[i]=rd()%mod+1,s.insert(node(i,i,a[i]));
}
inline int qpow(int x,int k,int mod)
{
	int ret=1;x%=mod;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,k>>=1;
	}
	return ret;
}
inline void solve()
{
	FOR(i,1,q)
	{
		opt=rd()%4+1;
		l=rd()%n+1;
		r=rd()%n+1;
		if(l>r)swap(l,r);
		if(opt==2)
		{
			x=rd()%mod+1;
			split(l),split(r+1);
			iter it=split(l),it2=split(r+1);
			while(it!=it2)s.erase(it++);
			s.insert(node(l,r,x));
		}
		else if(opt==1)
		{
			x=rd()%mod+1;
			split(l),split(r+1);
			iter it=split(l),it2=split(r+1);
			while(it!=it2)it->val+=x,it++;
		}
		else if(opt==3)
		{
			int xx=rd()%(r-l+1)+1;
			vector<node>vec;
			split(l),split(r+1);
			iter it=split(l),it2=split(r+1);
			while(it!=it2)vec.pb(*it),it++;
			sort(vec.begin(),vec.end(),cmp);
			int now=0;
			for(auto x:vec)
			{
				now+=x.r-x.l+1;
				if(now>=xx){printf("%lld\n",x.val);break;}
			}
		}
		else
		{
			x=rd()%mod+1,y=rd()%mod+1;
			split(l),split(r+1);
			iter it=split(l),it2=split(r+1);
			int ans=0;
			while(it!=it2)ans+=1ll*((*it).r-(*it).l+1)*qpow((*it).val,x,y)%y,ans%=y,it++;
			printf("%lld\n",ans);
		}
	}
}
signed main()
{
	init();
	input();
	solve();
	return 0;
}