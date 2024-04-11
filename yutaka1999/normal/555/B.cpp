#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#define SIZE 400005

using namespace std;
typedef long long int ll;

struct P
{
	ll f,s,t;
	P(ll f=0,ll s=0,ll t=0):f(f),s(s),t(t){}
	bool operator<(const P&l) const
	{
		if(f!=l.f) return f<l.f;
		if(s!=l.s) return s<l.s;
		return t<l.t;
	}
};
ll left[SIZE],right[SIZE];
ll A[SIZE];
int tg[SIZE];
P pos[SIZE*2];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%I64d %I64d",&left[i],&right[i]);
	int sz=0;
	for(int i=0;i<n-1;i++)
	{
		ll l=left[i+1]-right[i];
		ll r=right[i+1]-left[i];
		pos[sz++]=P(l,-r,i);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%I64d",&A[i]);
		pos[sz++]=P(A[i],i,i);
	}
	sort(pos,pos+sz);
	set <P> st;
	set <P>::iterator it;
	for(int i=0;i<sz;i++)
	{
		P p=pos[i];
		if(p.s<0)//bridge
		{
			st.insert(P(-p.s,p.t,-1));
		}
		else
		{
			it=st.begin();
			if(it!=st.end())
			{
				if(it->f<p.f)
				{
					puts("No");
					return 0;
				}
				tg[it->s]=p.s;
				st.erase(it);
			}
		}
	}
	if(!st.empty())
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=0;i<n-1;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",tg[i]+1);
	}puts("");
	return 0;
}