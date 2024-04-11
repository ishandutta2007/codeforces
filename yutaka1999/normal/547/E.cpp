#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef pair <int,int> P;
typedef pair <P,P> PP;

struct segtree
{
	vector <int> seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i].clear();
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k].push_back(x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k].push_back(x);
		}
	}
	void build()
	{
		for(int i=0;i<mum*2;i++)
		{
			sort(seg[i].begin(),seg[i].end());
		}
	}
	int get(int a,int b,int k,int l,int r,int S,int T)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return upper_bound(seg[k].begin(),seg[k].end(),T)-lower_bound(seg[k].begin(),seg[k].end(),S);
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2,S,T);
			int vr=get(a,b,k*2+2,(l+r)/2,r,S,T);
			return vl+vr;
		}
	}
	int get(int a,int b,int S,int T)
	{
		return get(a,b,0,0,mum,S,T);
	}
};
struct segtree2
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=BT;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int right(int p,int lim)//ppElimT
	{
		int L=-1,R=-1,K=-1;
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(m<=p)
			{
				l=m;
				k=k*2+2;
			}
			else
			{
				if(seg[k*2+2]<lim) {L=m,R=r,K=k*2+2;}
				r=m;
				k=k*2+1;
			}
		}
		if(seg[k]<lim) {L=l,R=r,K=k;};
		if(K==-1) return mum-1;
		while(L+1<R)
		{
			if(seg[K*2+1]<lim)
			{
				R=(L+R)/2;
				K=K*2+1;
			}
			else
			{
				L=(L+R)/2;
				K=K*2+2;
			}
		}
		return L;
	}
	int left(int p,int lim)//plimT
	{
		int L=-1,R=-1,K=-1;
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(m<=p)
			{
				if(seg[k*2+1]<lim) {L=l,R=m,K=k*2+1;}
				l=m;
				k=k*2+2;
			}
			else
			{
				r=m;
				k=k*2+1;
			}
		}
		if(K==-1) return -1;
		while(L+1<R)
		{
			if(seg[K*2+2]<lim)
			{
				L=(L+R)/2;
				K=K*2+2;
			}
			else
			{
				R=(L+R)/2;
				K=K*2+1;
			}
		}
		return L;
	}
};
segtree seg;
segtree2 seg2;
string S[SIZE];
vector <int> rank[SIZE];
PP tmp[SIZE];
P sa[SIZE];
int lcp[SIZE];
int left[SIZE],right[SIZE];
char str[SIZE];
int n,q;

void build_SA()
{
	int mx=0;
	for(int i=0;i<n;i++)
	{
		mx=max(mx,(int) S[i].size());
		for(int j=0;j<S[i].size();j++)
		{
			rank[i].push_back(S[i][j]-'a');
		}
	}
	for(int k=1;k<=2*mx;k<<=1)
	{
		int sz=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<S[i].size();j++)
			{
				tmp[sz++]=PP(P(rank[i][j],j+k<S[i].size()?rank[i][j+k]:-1),P(i,j));
			}
		}
		sort(tmp,tmp+sz);
		if(k<=mx)
		{
			for(int i=0;i<sz;)
			{
				int f=i;
				for(;i<sz&&tmp[i].first==tmp[f].first;i++)
				{
					P p=tmp[i].second;
					rank[p.first][p.second]=f;
				}
			}
		}
		else
		{
			for(int i=0;i<sz;i++)
			{
				P p=tmp[i].second;
				rank[p.first][p.second]=i;
			}
		}
	}
	int sz=0;
	for(int i=0;i<n;i++)
	{
		sz+=S[i].size();
		for(int j=0;j<rank[i].size();j++)
		{
			sa[rank[i][j]]=P(i,j);
		}
	}
	for(int i=0;i<n;i++)
	{
		int H=0;
		for(int j=0;j<S[i].size();j++)
		{
			if(H>0) H--;
			if(rank[i][j]==sz-1) continue;
			int f=sa[rank[i][j]+1].first;
			int s=sa[rank[i][j]+1].second;
			while(j+H<S[i].size()&&s+H<S[f].size()&&S[i][j+H]==S[f][s+H]) H++;
			lcp[rank[i][j]]=H;
		}
	}
	seg.init(sz+2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<rank[i].size();j++)
		{
			seg.add(rank[i][j],i);
		}
	}
	seg.build();
	seg2.init(sz+2);
	for(int i=0;i<sz-1;i++) seg2.add(i,lcp[i]);
	for(int i=0;i<n;i++)
	{
		int r=rank[i][0];
		left[i]=seg2.left(r,S[i].size())+1;
		right[i]=seg2.right(r,S[i].size());
	}/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<S[i].size();j++) printf("%d ",rank[i][j]);
		puts("");
	}
	for(int i=0;i<sz-1;i++) printf("%d ",lcp[i]);puts("");
	for(int i=0;i<n;i++) printf("%d %d\n",left[i],right[i]);*/
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		S[i]=str;
	}
	build_SA();
	int sz=0;
	for(int i=0;i<n;i++) sz+=S[i].size();
	for(int i=0;i<q;i++)
	{
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);l--;r--;k--;
		printf("%d\n",seg.get(left[k],right[k]+1,l,r));
	}
	return 0;
}