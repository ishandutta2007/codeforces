#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define BT 1024*128*2
#define INF 1000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

struct segtree
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=INF;
	}
	void add(int k,ll x)
	{
		k+=mum-1;
		seg[k]=min(seg[k],x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return INF;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
ll px[SIZE],dist[SIZE];
ll left[SIZE],right[SIZE];
ll tl[SIZE],tr[SIZE];
P pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++) scanf("%lld",&px[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&dist[i]);
		dist[i]*=2LL;
	}
	//p(i+1)-p(i-1)<=d(i) 
	//epositionaddAE
	int sz=0;
	pos[sz++]=P(INF,0);
	for(int i=1;i<=n;i++)
	{
		while(sz>0&&pos[sz-1].first<px[i]) sz--;
		left[i]=px[i]-px[pos[sz-1].second];
		if(left[i]<=dist[i])
		{
			ll to=px[i]+dist[i]-left[i];
			while(sz>0&&pos[sz-1].first<=to) sz--;
			pos[sz++]=P(to,i);
		}
	}
	sz=0;
	pos[sz++]=P(-INF,n+1);
	for(int i=n;i>=1;i--)
	{
		while(sz>0&&pos[sz-1].first>px[i]) sz--;
		right[i]=px[pos[sz-1].second]-px[i];
		if(right[i]<=dist[i])
		{
			ll to=px[i]-dist[i]+right[i];
			while(sz>0&&pos[sz-1].first>=to) sz--;
			pos[sz++]=P(to,i);
		}
	}
	//e[left,to][to,right]left,rightl
	///2!
	vector <ll> vx;
	for(int i=1;i<=n;i++)
	{
		tl[i]=px[i]+dist[i]-left[i];
		tr[i]=px[i]-dist[i]+right[i];
		//printf("%lld %lld\n",tl[i],tr[i]);
		vx.push_back(tr[i]);
		if(left[i]+right[i]<=dist[i])
		{
			puts("0");
			return 0;
		}
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	seg.init(vx.size()+2);
	ll ret=px[n+1]-px[0];
	for(int i=n;i>=1;i--)
	{
		if(px[i]<tl[i])
		{
			ret=min(ret,px[n+1]-px[i]);
			int to=upper_bound(vx.begin(),vx.end(),tl[i])-vx.begin();
			if(to>0) ret=min(ret,seg.get(0,to)-px[i]);
		}
		if(tr[i]<px[i])
		{
			ret=min(ret,px[i]-px[0]);
			int to=lower_bound(vx.begin(),vx.end(),tr[i])-vx.begin();
			seg.add(to,px[i]);
		}
	}
	if(ret%2==0) printf("%lld\n",ret/2);
	else printf("%lld.5\n",ret/2);
	return 0;
}