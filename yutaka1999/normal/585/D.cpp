#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <functional>
#include <cmath>
#include <map>
#include <string>
#define SIZE 30
#define INF 100000000000000LL

using namespace std;
typedef long long int ll;

struct P
{
	ll a,b,c,d;
	P(ll a=0,ll b=0,ll c=0,ll d=0):a(a),b(b),c(c),d(d){}
	bool operator<(const P&l) const
	{
		if(a!=l.a) return a<l.a;
		if(b!=l.b) return b<l.b;
		if(c!=l.c) return c<l.c;
		return d<l.d;
	}
	bool operator==(const P&l) const
	{
		return a==l.a&&b==l.b&&c==l.c&&d==l.d;
	}
};
vector <P> fr;
ll L[SIZE],M[SIZE],W[SIZE],mx;
vector <int> ans;
int sz;
int op[SIZE];
P pd,pl;

void dfs1(int t,int pos,P p)
{
	if(pos==t)
	{
		P q;
		q.a=0;
		q.b=p.a-p.b;
		q.c=p.a-p.c;
		q.d=p.a;
		fr.push_back(q);
		return;
	}
	dfs1(t,pos+1,P(p.a,p.b+M[pos],p.c+W[pos]));
	dfs1(t,pos+1,P(p.a+L[pos],p.b,p.c+W[pos]));
	dfs1(t,pos+1,P(p.a+L[pos],p.b+M[pos],p.c));
}
void dfs2(int t,int pos,P p)
{
	if(pos==t)
	{
		P q;
		q.a=0;
		q.b=p.b-p.a;
		q.c=p.c-p.a;
		q.d=INF;
		int s=lower_bound(fr.begin(),fr.end(),q)-fr.begin()-1;
		if(s>=0)
		{
			P r=fr[s];
			q.d=r.d;
			if(q==r&&mx<p.a+r.d)
			{
				mx=p.a+r.d;
				pd=r;
				pl=p;
			}
		}
		return;
	}
	dfs2(t,pos+1,P(p.a,p.b+M[pos],p.c+W[pos]));
	dfs2(t,pos+1,P(p.a+L[pos],p.b,p.c+W[pos]));
	dfs2(t,pos+1,P(p.a+L[pos],p.b+M[pos],p.c));
}
bool ans1(int t,int pos,P p)
{
	if(pos==t)
	{
		P q;
		q.a=0;
		q.b=p.a-p.b;
		q.c=p.a-p.c;
		q.d=p.a;
		if(q==pd)
		{
			for(int i=0;i<sz;i++) ans.push_back(op[i]);
			return true;
		}
		return false;
	}
	op[sz++]=0;
	if(ans1(t,pos+1,P(p.a,p.b+M[pos],p.c+W[pos]))) return true;
	op[sz-1]=1;
	if(ans1(t,pos+1,P(p.a+L[pos],p.b,p.c+W[pos]))) return true;
	op[sz-1]=2;
	if(ans1(t,pos+1,P(p.a+L[pos],p.b+M[pos],p.c))) return true;
	sz--;
	return false;
}
bool ans2(int t,int pos,P p)
{
	if(pos==t)
	{
		if(p==pl)
		{
			for(int i=0;i<sz;i++)
			{
				ans.push_back(op[i]);
			}
			return true;
		}
		return false;
	}
	op[sz++]=0;
	if(ans2(t,pos+1,P(p.a,p.b+M[pos],p.c+W[pos]))) return true;
	op[sz-1]=1;
	if(ans2(t,pos+1,P(p.a+L[pos],p.b,p.c+W[pos]))) return true;
	op[sz-1]=2;
	if(ans2(t,pos+1,P(p.a+L[pos],p.b+M[pos],p.c))) return true;
	sz--;
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%I64d %I64d %I64d",&L[i],&M[i],&W[i]);
	dfs1(n/2,0,P(0,0,0));
	sort(fr.begin(),fr.end());
	mx=-INF;
	dfs2(n,n/2,P(0,0,0));
	if(mx!=-INF)
	{
		sz=0;
		ans1(n/2,0,P(0,0,0));
		sz=0;
		ans2(n,n/2,P(0,0,0));
		for(int i=0;i<n;i++)
		{
			if(ans[i]==0) puts("MW");
			else if(ans[i]==1) puts("LW");
			else puts("LM");
		}
	}
	else
	{
		puts("Impossible");
	}
	return 0;
}