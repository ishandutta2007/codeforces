#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
#define SIZE 100005
#define MX 400005
#define BT 512*1024*2
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=INF;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]=min(seg[k],v);
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	int get(int k)
	{
		k+=mum-1;
		int ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret=min(ret,seg[k]);
		}
		return ret;
	}
};
segtree seg;
int left[SIZE],right[SIZE],vt[SIZE];
vector <int> vx;
vector <P> vp;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&left[i],&right[i],&vt[i]);right[i]--;
		vx.push_back(left[i]);
		vx.push_back(right[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<vx.size();i++)
	{
		vp.push_back(P(vx[i],vx[i]));
		if(i+1<vx.size()&&vx[i]+1<=vx[i+1]-1) vp.push_back(P(vx[i]+1,vx[i+1]-1));
	}
	seg.init(vp.size()+2);
	for(int i=0;i<m;i++)
	{
		left[i]=lower_bound(vp.begin(),vp.end(),P(left[i],left[i]))-vp.begin();
		right[i]=lower_bound(vp.begin(),vp.end(),P(right[i],right[i]))-vp.begin();
		seg.update(left[i],right[i]+1,vt[i]);
	}
	for(int i=0;i<vp.size();i++)
	{
		int gt=seg.get(i);
		P p=vp[i];
		int ft=gt-p.second,lt=gt-p.first;
		if(gt==INF) ft=lt=INF;
		vp[i]=P(ft,lt);
	}
	sort(vp.begin(),vp.end());
	priority_queue <int,vector <int>,greater <int> > que;
	ll sum=0;
	int pos=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		while(pos<vp.size()&&vp[pos].first<=t)
		{
			que.push(vp[pos].second);
			sum-=(ll) vp[pos++].first-1;
			cnt++;
		}
		while(!que.empty()&&que.top()<=t)
		{
			sum+=(ll) que.top();
			que.pop();
			cnt--;
		}
		printf("%llld\n",sum+(ll) t*(ll) cnt);
	}
	return 0;
}