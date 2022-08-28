#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef pair <int,int> P;

bool cross_P(P p,P q)
{
	if(p.first>q.first) swap(p,q);
	return q.first<=p.second+1;
}
P merge(P p,P q)
{
	return P(min(p.first,q.first),max(p.second,q.second));
}
struct segtree// or 
{
	vector <P> seg[BT];
	vector <int> vx[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			seg[i].clear();
			vx[i].clear();
		}
	}
	void add(int k,int x)
	{
		k+=mum-1;
		vx[k].push_back(x);
		while(k>0)
		{
			k=(k-1)/2;
			vx[k].push_back(x);
		}
	}
	void build()
	{
		for(int i=mum-1;i<mum*2;i++)
		{
			sort(vx[i].begin(),vx[i].end());
			int bef=0;
			for(int j=0;j<vx[i].size();j++)
			{
				int to=vx[i][j];
				if(bef<to) seg[i].push_back(P(bef,to-1));
				bef=to+1;
			}
			seg[i].push_back(P(bef,BT));
		}
		for(int i=mum-2;i>=0;i--)
		{
			sort(vx[i].begin(),vx[i].end());
			seg[i]=seg[i*2+1];
			for(int j=0;j<seg[i*2+2].size();j++) seg[i].push_back(seg[i*2+2][j]);
			sort(seg[i].begin(),seg[i].end());
			int mx=-1;
			for(int j=0;j<seg[i].size();j++)
			{
				P p=seg[i][j];
				mx=max(mx,p.second);
				seg[i][j]=P(p.first,mx);
			}
		}
	}
	bool have_seg(int k,int s,int t)//[s,t]
	{
		int pos=lower_bound(seg[k].begin(),seg[k].end(),P(s+1,-1))-seg[k].begin()-1;
		if(pos==-1) return false;
		return t<=seg[k][pos].second;
	}
	bool have_pt(int k,int s,int t)//[s,t]_
	{
		int pos=lower_bound(vx[k].begin(),vx[k].end(),s)-vx[k].begin();
		if(pos==vx[k].size()) return false;
		return vx[k][pos]<=t;
	}
	int noncross(int a,int b,int k,int l,int r,int s,int t)//[s,t][search
	{
		if(b<=l||r<=a) return -1;
		if(a<=l&&r<=b)
		{
			if(!have_seg(k,s,t)) return -1;
			while(l+1<r)
			{
				if(have_seg(k*2+1,s,t))
				{
					k=k*2+1;
					r=(l+r)/2;
				}
				else
				{
					k=k*2+2;
					l=(l+r)/2;
				}
			}
			return l;
		}
		else
		{
			int vl=noncross(a,b,k*2+1,l,(l+r)/2,s,t);
			if(vl!=-1) return vl;
			return noncross(a,b,k*2+2,(l+r)/2,r,s,t);
		}
	}
	int noncross(int a,int b,int s,int t)
	{
		return noncross(a,b,0,0,mum,s,t);
	}
	int cross(int a,int b,int k,int l,int r,int s,int t)//[s,t]_[search
	{
		if(b<=l||r<=a) return -1;
		if(a<=l&&r<=b)
		{
			if(!have_pt(k,s,t)) return -1;
			while(l+1<r)
			{
				if(have_pt(k*2+1,s,t))
				{
					k=k*2+1;
					r=(l+r)/2;
				}
				else
				{
					k=k*2+2;
					l=(l+r)/2;
				}
			}
			return l;
		}
		else
		{
			int vl=cross(a,b,k*2+1,l,(l+r)/2,s,t);
			if(vl!=-1) return vl;
			return cross(a,b,k*2+2,(l+r)/2,r,s,t);
		}
	}
	int cross(int a,int b,int s,int t)
	{
		return cross(a,b,0,0,mum,s,t);
	}
};
segtree s1,s2;
int px[SIZE],py[SIZE];
vector <int> vx,vy;

int dfs(int a,int b,int c,int d)
{
	if(a>b||c>d) return 0;
	//x
	int gt=s1.cross(a,b+1,c,d);
	if(gt==-1) return 0;
	a=gt;
	gt=s1.noncross(a,b+1,c,d);
	if(gt!=-1) return dfs(a,gt-1,c,d)+dfs(gt+1,b,c,d);
	gt=s2.cross(c,d+1,a,b);
	c=gt;
	gt=s2.noncross(c,d+1,a,b);
	if(gt!=-1) return dfs(a,b,c,gt-1)+dfs(a,b,gt+1,d);
	//printf("[%d %d] [%d %d]\n",a,b,c,d);
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&px[i],&py[i]);
		vx.push_back(px[i]);
		vx.push_back(px[i]+1);
		vy.push_back(py[i]);
		vy.push_back(py[i]+1);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	s1.init(vx.size()+2);
	s2.init(vy.size()+2);
	for(int i=0;i<n;i++)
	{
		px[i]=lower_bound(vx.begin(),vx.end(),px[i])-vx.begin();
		py[i]=lower_bound(vy.begin(),vy.end(),py[i])-vy.begin();
		s1.add(px[i],py[i]);
		s2.add(py[i],px[i]);
	}
	s1.build();
	s2.build();
	printf("%d\n",dfs(0,vx.size(),0,vy.size()));
	return 0;
}