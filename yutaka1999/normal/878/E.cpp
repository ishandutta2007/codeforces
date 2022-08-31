#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MOD 1000000007
#define BT 1024*128*2

using namespace std;
typedef long long int ll;
typedef pair <int,int>  P;
typedef pair <P,int> PP;

ll residue(ll x)
{
	if(x>=0) return x%MOD;
	x=-x;
	x%=MOD;
	x=-x;
	if(x==0) return 0;
	return x+MOD;
}
struct segtree
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void add(int k,ll x)
	{
		x=residue(x);
		k+=mum-1;
		seg[k]+=x;
		if(seg[k]>=MOD) seg[k]-=MOD;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=seg[k*2+1]+seg[k*2+2];
			if(seg[k]>=MOD) seg[k]-=MOD;
		}
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return (vl+vr)%MOD;
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
vector <P> query[SIZE];
ll ans[SIZE];
int A[SIZE];
PP st[SIZE];
ll tw[SIZE];
ll rt[SIZE];
ll inv;
int n,q;

ll mpow(ll m,ll t)
{
	if(t==0) return 1;
	ll ret=mpow(m,t/2);
	ret=ret*ret%MOD;
	if(t%2==1) ret=ret*m%MOD;
	return ret;
}
void build()
{
	tw[0]=1;
	for(int i=1;i<SIZE;i++) tw[i]=tw[i-1]*2LL%MOD;
	inv=mpow(2LL,MOD-2);
	for(int i=0;i<n;i++)
	{
		rt[i]=residue(A[i]);
		if(i>0) rt[i]+=rt[i-1]*inv%MOD;
		rt[i]%=MOD;
	}
}
ll get_sum(int l,int r)
{
	int L=r-l+1;
	ll ret=rt[r]*tw[L-1]%MOD;
	if(l>0)
	{
		ret-=rt[l-1]*inv%MOD;
		if(ret<0) ret+=MOD;
	}
	//printf("%d %d : %lld\n",l,r,ret);
	return ret;
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);l--,r--;
		ans[i]=residue(A[l]);
		if(l+1<=r) query[r].push_back(P(l+1,i));
	}
	build();
	int sz=0;
	st[sz++]=PP(P(0,0),A[0]);
	seg.init(n+2);
	for(int i=1;i<n;i++)
	{
		int last=i;
		ll sum=A[i];
		bool up=false;
		while(sz>0&&(sum>0||up))
		{
			sz--;
			PP p=st[sz];
			if(p.first.first>0)
			{
				seg.add(p.first.first-1,-p.second);
			}
			last=p.first.first;
			int L=p.first.second-p.first.first+1;
			sum=tw[L]*sum+p.second;
			if(up||L>=30||sum>=MOD)
			{
				up=true;
				if(sum<0) sum+=MOD;
				sum%=MOD;
			}
		}
		st[sz++]=PP(P(last,i),sum);
		//printf("%d %d : %lld\n",last,i,sum);
		if(last>0) seg.add(last-1,sum);
		for(int j=0;j<query[i].size();j++)
		{
			int l=query[i][j].first;
			int id=query[i][j].second;
			ans[id]+=2LL*seg.get(l,i+1)%MOD;
			if(ans[id]>=MOD) ans[id]-=MOD;
			int pos=lower_bound(st,st+sz,PP(P(l+1,-1),-1))-st-1;
			int to=st[pos].first.second;
			//[l,to] 
			ans[id]+=2LL*get_sum(l,to)%MOD;
			if(ans[id]>=MOD) ans[id]-=MOD;
		}
	}
	for(int i=0;i<q;i++)
	{
		ans[i]=residue(ans[i]);
		printf("%lld\n",ans[i]);
	}
	return 0;
}