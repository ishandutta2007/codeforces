#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 150005
#define BT 1024*256*2
#define EPS 1e-10

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

/*
lA
pi(1-c*x/T)+pj(1-c*(x+ti)/T) >=  pj(1-c*x/T)+pi(1-c*(x+tj)/T)
<=> pi*tj >= pj*ti
<=> pi/ti >= pj/tj
Ap/t l sort Al

--> paradox Api<pj_A
    t/p TCYAKmax,min
    A
*/
struct segtree//max
{
	double seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-1e10;
	}
	void add(int k,double x)
	{
		k+=mum-1;
		seg[k]=max(seg[k],x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	double get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return -1e10;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			double vl=get(a,b,k*2+1,l,(l+r)/2);
			double vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	double get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree mx,mn;
int tm[SIZE];
int pb[SIZE];
PP pos[SIZE];
vector <int> vec[SIZE];
vector <int> vx;
int n,sz;
ll all;

bool comp(const PP&l,const PP&r)//equal Nsort
{
	P p=l.first,q=r.first;
	return (ll) p.first*(ll) q.second>(ll) p.second*(ll) q.first;
}
bool check(double x)
{
	mx.init(vx.size()+2);
	mn.init(vx.size()+2);
	ll sum=0;
	for(int i=0;i<sz;i++)
	{
		ll nxt=0;
		for(int j=0;j<vec[i].size();j++)
		{
			int v=vec[i][j];
			double f=vx[pb[v]]*(double) (1.0-x*(double) (sum+tm[v])/(double) all);
			//printf("%f : %d %f\n",x,v,f);
			if(pb[v]+1<vx.size())
			{
				double gt=-mn.get(pb[v]+1,vx.size());
				if(gt+EPS<f) return false;
			}
			mx.add(pb[v],f);
			nxt+=tm[v];
		}
		sum+=nxt;
		for(int j=0;j<vec[i].size();j++)
		{
			int v=vec[i][j];
			double f=vx[pb[v]]*(double) (1.0-x*(double) sum/(double) all);
			if(pb[v]>0)
			{
				double gt=mx.get(0,pb[v]);
				if(gt>f+EPS) return false;
			}
			mn.add(pb[v],-f);
		}
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pb[i]);
		vx.push_back(pb[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++) pb[i]=lower_bound(vx.begin(),vx.end(),pb[i])-vx.begin();
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tm[i]);
		all+=tm[i];
		pos[i]=PP(P(vx[pb[i]],tm[i]),i);
	}
	sort(pos,pos+n,comp);
	sz=0;
	for(int i=0;i<n;)
	{
		PP p=pos[i];
		for(;i<n&&!comp(pos[i],p)&&!comp(p,pos[i]);i++) vec[sz].push_back(pos[i].second);
		sz++;
	}
	double l=0,r=1.0;
	//l=r=0.625;
	for(int i=0;i<30;i++)
	{
		double d=(l+r)/2;
		if(check(d)) l=d;
		else r=d;
	}
	printf("%.10f\n",l);
	return 0;
}