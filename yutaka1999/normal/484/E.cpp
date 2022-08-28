#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define SIZE 100005
#define BT 1024*128*2

using namespace std;
typedef pair <int,int> PP;

struct P
{
	int m,l,r;
	bool up;
	P(int m=0,int l=0,int r=0,bool up=false):m(m),l(l),r(r),up(up){}
};
P unite(P l,P r)
{
	P ret;
	ret.l=l.l+(l.up?r.l:0);
	ret.r=r.r+(r.up?l.r:0);
	ret.m=max(l.r+r.l,max(l.m,r.m));
	ret.up=l.up&&r.up;
	return ret;
}
struct segtree
{
	P seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=P(0,0,0,false);
	}
	void add(int k)
	{
		k+=mum-1;
		seg[k]=P(1,1,1,true);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=unite(seg[k*2+1],seg[k*2+2]);
		}
	}
	P get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return P(0,0,0,false);
		if(a<=l&&r<=b) return seg[k];
		else
		{
			P vl=get(a,b,k*2+1,l,(l+r)/2);
			P vr=get(a,b,k*2+2,(l+r)/2,r);
			return unite(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum).m;
	}
};
segtree seg;
PP pos[SIZE];
vector <int> query[SIZE];
int st[SIZE],ed[SIZE];
int left[SIZE],right[SIZE],len[SIZE];
int n,m;

void div_conq()
{
	for(int i=0;i<n;i++) query[i].clear();
	bool up=true;
	for(int i=0;i<m;i++)
	{
		if(st[i]<ed[i])
		{
			up=false;
			query[(st[i]+ed[i])/2].push_back(i);
		}
	}
	if(up) return;
	seg.init(n+2);
	for(int i=0;i<n;i++)
	{
		int pl=pos[i].second;
		seg.add(pl);
		for(int j=0;j<query[i].size();j++)
		{
			int q=query[i][j];
			int g=seg.get(left[q],right[q]+1);
			if(g>=len[q])
			{
				ed[q]=i;
			}
			else
			{
				st[q]=i+1;
			}
		}
	}
	div_conq();
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int h;
		scanf("%d",&h);
		pos[i]=PP(-h,i);
	}
	sort(pos,pos+n);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&left[i],&right[i],&len[i]);
		left[i]--;right[i]--;
		st[i]=0;
		ed[i]=n-1;
	}
	div_conq();
	for(int i=0;i<m;i++) printf("%d\n",-pos[st[i]].first);
	return 0;
}