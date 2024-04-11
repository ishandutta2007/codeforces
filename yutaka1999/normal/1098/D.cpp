#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#define SIZE 500005
#define BT 512*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	ll seg[BT],add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=add[i]=0;
	}
	void update(int a,int b,int k,int l,int r,ll v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]+=v,add[k]+=v;
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=max(seg[k*2+1],seg[k*2+2])+add[k];
		}
	}
	void update(int a,int b,ll v)
	{
		update(a,b,0,0,mum,v);
	}
	int solve(int k,int l,int r,ll d)
	{
		if(seg[k]<=d) return 0;
		if(l+1==r) return 1;
		else
		{
			return solve(k*2+1,l,(l+r)/2,d-add[k])+solve(k*2+2,(l+r)/2,r,d-add[k]);
		}
	}
	int solve()
	{
		return solve(0,0,mum,0);
	}
}seg;
int X[SIZE];
int tp[SIZE];
char str[5];

int main()
{
	int n;
	scanf("%d",&n);
	vector <P> vx;
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		scanf("%lld",&X[i]);
		if(str[0]=='+')
		{
			tp[i]=1;
			vx.push_back(P(X[i],i));
		}
		else tp[i]=-1;
	}
	sort(vx.begin(),vx.end());
	for(int i=0;i<n;i++)
	{
		if(tp[i]>0)
		{
			X[i]=lower_bound(vx.begin(),vx.end(),P(X[i],i))-vx.begin();
		}
	}
	set <P> st;
	set <P>::iterator it;
	seg.init(n+2);
	for(int i=0;i<n;i++)
	{
		if(tp[i]>0)
		{
			seg.update(X[i],X[i]+1,vx[X[i]].first);
			seg.update(X[i]+1,n+1,-2LL*vx[X[i]].first);
			st.insert(P(vx[X[i]].first,X[i]));
		}
		else
		{
			it=st.lower_bound(P(X[i],-1));
			int v=it->second;
			st.erase(it);
			seg.update(v,v+1,-X[i]);
			seg.update(v+1,n+1,2LL*X[i]);
		}
		printf("%d\n",st.size()-seg.solve());
	}
	return 0;
}