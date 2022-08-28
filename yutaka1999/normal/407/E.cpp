#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define SIZE 200005
#define BT 256*1024*2
#define MD 1000000000

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;
typedef pair <int,int> PI;

struct segtree
{
	ll seg[BT],add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-1,add[i]=0;//initially -1!!
	}
	void pass(int k)
	{
		for(int t=k*2+1;t<=k*2+2;t++)
		{
			seg[t]+=add[k];
			add[t]+=add[k];
		}
		add[k]=0;
	}
	void update(int a,int b,int k,int l,int r,ll v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]+=v;
			add[k]+=v;
		}
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
	int right()//0E
	{
		if(seg[0]<0) return -1;
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			pass(k);
			int m=(l+r)/2;
			if(seg[k*2+2]>=0)
			{
				l=m;
				k=k*2+2;
			}
			else
			{
				r=m;
				k=k*2+1;
			}
		}
		return l;
	}
};
segtree seg;
ll A[SIZE];
P mx[SIZE],mn[SIZE];

PI solve(vector <ll> vec,int k)
{
	int n=vec.size();
	seg.init(n+2);
	map <ll,int> mp;
	int sx=0,sn=0;
	PI ret=P(-1,-1);
	for(int i=n-1;i>=0;i--)
	{
		seg.update(i,i+1,k);//because initially all -1
		int last=i;
		while(sx>0&&mx[sx-1].first<vec[i])
		{
			sx--;
			seg.update(last+1,mx[sx].second+1,mx[sx].first);
			last=mx[sx].second;
		}
		seg.update(i,last+1,-vec[i]);
		mx[sx++]=P(vec[i],last);
		last=i;
		while(sn>0&&mn[sn-1].first>vec[i])
		{
			sn--;
			seg.update(last+1,mn[sn].second+1,-mn[sn].first);
			last=mn[sn].second;
		}
		seg.update(i,last+1,vec[i]);
		mn[sn++]=P(vec[i],last);
		int to=n-1;
		if(mp.count(vec[i])) to=mp[vec[i]]-1;
		seg.update(i,to+1,1);
		seg.update(to+1,n+1,-k-BT);
		mp[vec[i]]=i;
		int right=seg.right();
		int L=right-i+1;
		ret=max(ret,PI(L,-i));
	}
	return ret;
}
int main()
{
	int n,k,d;
	scanf("%d %d %d",&n,&k,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		A[i]+=MD;
	}
	PI ret=P(-1,-1);
	if(d==0)
	{
		for(int i=0;i<n;)
		{
			int f=i;
			for(;i<n&&A[i]==A[f];i++);
			int L=i-f;
			ret=max(ret,PI(L,-f));
		}
	}
	else
	{
		for(int i=0;i<n;)
		{
			vector <ll> vec;
			int f=i;
			for(;i<n&&A[i]%d==A[f]%d;i++) vec.push_back(A[i]/d);
			PI gt=solve(vec,k);
			gt.second-=f;
			ret=max(ret,gt);
		}
	}
	int L=-ret.second,R=L+ret.first-1;
	printf("%d %d\n",L+1,R+1);
	return 0;
}