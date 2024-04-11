#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1024*128*4

using namespace std;
typedef long long int ll;

ll t[100005],a[100005],b[100005];
ll in[100005],pos[100005];
vector <ll> vx;
struct P
{
	ll v,s,n;
	bool operator==(P p)
	{
		return p.v==v&&p.s==s&&p.n==n;
	}
};
P mp(ll v,ll n,ll s)
{
	P ret;
	ret.v=v;ret.s=s;ret.n=n;
	return ret;
}
const P PAR=mp(0,0,0);
struct segtree
{
	ll val[SIZE*2],sum[SIZE*2],num[SIZE*2];
	int n,mum;
	
	void init(int m)
	{
		n=m;mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			sum[i]=0;
			val[i]=0;
			num[i]=0;
		}
	}
	P unite(P l,P r)
	{
		P ret;
		ret.n=l.n+r.n;
		ret.s=l.s+r.s;
		ret.v=l.v+r.v+(r.s*l.n-l.s*r.n);
		return ret;
	}
	void make(int k)
	{
		P l=mp(val[k*2+1],num[k*2+1],sum[k*2+1]);
		P r=mp(val[k*2+2],num[k*2+2],sum[k*2+2]);
		P u=unite(l,r);
		val[k]=u.v;
		sum[k]=u.s;
		num[k]=u.n;
	}
	void updata(int k,int x)
	{
		int bk=k;
		k+=mum-1;
		sum[k]=vx[bk]*x;
		num[k]=x;
		val[k]=0;
		while(k>0)
		{
			k=(k-1)/2;
			make(k);
		}
	}
	void erase(int k)
	{
		updata(k,0);
	}
	void add(int k)
	{
		updata(k,1);
	}
	P ans(int a,int b,int k,int l,int r)
	{
		if(r<=a||b<=l) return PAR;
		if(a<=l&&r<=b) return mp(val[k],num[k],sum[k]);
		P v1=ans(a,b,k*2+1,l,(l+r)/2);
		P v2=ans(a,b,k*2+2,(l+r)/2,r);
		if(v1==PAR&&v2==PAR) return PAR;
		if(v1==PAR) return v2;
		if(v2==PAR) return v1;
		return unite(v1,v2);
	}
	ll ans(int a,int b)
	{
		P p=ans(a,b,0,0,mum);
		return p.v;
	}
};
segtree seg;
int search(ll x) {return lower_bound(vx.begin(),vx.end(),x)-vx.begin();}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&in[i]);
		pos[i]=in[i];
		vx.push_back(in[i]);
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%I64d %I64d %I64d",&t[i],&a[i],&b[i]);
		if(t[i]==1)
		{
			a[i]--;
			pos[a[i]]+=b[i];
			vx.push_back(pos[a[i]]);
		}
		else
		{
			vx.push_back(a[i]);
			vx.push_back(b[i]);
		}
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	seg.init(vx.size()+5);
	for(int i=0;i<n;i++)
	{
		pos[i]=in[i];
		in[i]=search(in[i]);
		seg.add(in[i]);
	}
	for(int i=0;i<q;i++)
	{
		if(t[i]==1)
		{
			seg.erase(search(pos[a[i]]));
			pos[a[i]]+=b[i];
			seg.add(search(pos[a[i]]));
		}
		else
		{
			a[i]=search(a[i]);
			b[i]=search(b[i]);
			printf("%I64d\n",seg.ans(a[i],b[i]+1));
		}
	}
	return 0;
}