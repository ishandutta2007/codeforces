#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define SIZE 100005
#define BT 1024*128*2
#define SQR 100

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,P> PP;
typedef pair <int,P> PQ;

struct segtree
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-1;
	}
	void ins(int k,int x)
	{
		seg[k+mum-1]=x;
	}
	void build()
	{
		for(int i=mum-2;i>=0;i--)
		{
			seg[i]=min(seg[i*2+1],seg[i*2+2]);
		}
	}
	int nxtR(int start,int lim)//lim(start)
	{
		int L,R,K=-1;
		int l=0,r=mum,k=0;
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(m<=start)
			{
				l=m;
				k=k*2+2;
			}
			else
			{
				if(seg[k*2+2]<lim)
				{
					L=m;
					R=r;
					K=k*2+2;
				}
				r=m;
				k=k*2+1;
			}
		}
		if(seg[k]<lim) return l;
		if(K==-1) return -1;
		while(R-L>1)
		{
			int m=(L+R)/2;
			if(seg[K*2+1]<lim)
			{
				R=m;
				K=K*2+1;
			}
			else
			{
				L=m;
				K=K*2+2;
			}
		}
		return L;
	}
	int nxtL(int start,int lim)//lim(start)
	{
		if(start==0) return -1;
		int L,R,K=-1;
		int l=0,r=mum,k=0;
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(start<=m)
			{
				r=m;
				k=k*2+1;
			}
			else
			{
				if(seg[k*2+1]<lim)
				{
					L=l;
					R=m;
					K=k*2+1;
				}
				l=m;
				k=k*2+2;
			}
		}
		if(seg[k]<lim) return l;
		if(K==-1) return -1;
		while(R-L>1)
		{
			int m=(L+R)/2;
			if(seg[K*2+2]<lim)
			{
				L=m;
				K=K*2+2;
			}
			else
			{
				R=m;
				K=K*2+1;
			}
		}
		return L;
	}
};
struct BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t)
	{
		return get(t)-get(s-1);
	}
};
BIT bit;
segtree seg;
vector <int> rnk[SIZE];
vector <PQ> query[SIZE];
vector <int> add[SIZE],rem[SIZE];
int left[SIZE],right[SIZE];
string str[SIZE];
char in[SIZE];
PP tmp[SIZE];
P sa[SIZE];
int lcp[SIZE];
int imos[SIZE];
ll ans[SIZE],cnt[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int all=0;
	for(int i=0;i<n;i++)
	{
		scanf("%s",&in);
		str[i]=in;
		all+=str[i].size();
		rnk[i].resize(str[i].size());
		for(int j=0;j<str[i].size();j++) rnk[i][j]=str[i][j]-'a';
	}
	for(int k=1;k<=2*all;k<<=1)
	{
		int sz=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<str[i].size();j++)
			{
				tmp[sz++]=PP(P(rnk[i][j],j+k<str[i].size()?rnk[i][j+k]:-1),P(i,j));
			}
		}
		sort(tmp,tmp+sz);
		for(int i=0;i<sz;)
		{
			if(k<=all)
			{
				int s=i;
				for(;i<sz&&tmp[i].first==tmp[s].first;i++)
				{
					P p=tmp[i].second;
					rnk[p.first][p.second]=s;
				}
			}
			else
			{
				P p=tmp[i].second;
				rnk[p.first][p.second]=i;
				i++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<str[i].size();j++)
		{
			sa[rnk[i][j]]=P(i,j);
			//printf("%d ",rnk[i][j]);
		}
		//puts("");
	}
	for(int i=0;i<n;i++)
	{
		int h=0;
		for(int j=0;j<str[i].size();j++)
		{
			if(h>0) h--;
			if(rnk[i][j]==all-1) continue;
			int s=sa[rnk[i][j]+1].first,t=sa[rnk[i][j]+1].second;
			while(j+h<str[i].size()&&t+h<str[s].size()&&str[i][j+h]==str[s][t+h]) h++;
			lcp[rnk[i][j]]=h;
		}
	}
	seg.init(all+2);
	for(int i=0;i<all-1;i++) seg.ins(i,lcp[i]);
	seg.build();
	for(int i=0;i<n;i++)
	{
		int v=rnk[i][0];
		left[i]=seg.nxtL(v,str[i].size())+1;
		right[i]=seg.nxtR(v,str[i].size());
		if(right[i]==-1) right[i]=all-1;
		add[left[i]].push_back(i);
		rem[right[i]].push_back(i);
		//printf("%d : %d %d\n",i,left[i],right[i]);
	}
	for(int i=0;i<q;i++)
	{
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		l--;r--;k--;
		query[k].push_back(PQ(i,P(l,r)));
	}
	for(int i=0;i<n;i++)
	{
		if(query[i].size()>=SQR)
		{
			memset(imos,0,sizeof(imos));
			for(int j=0;j<str[i].size();j++) imos[rnk[i][j]]++;
			for(int j=1;j<all;j++) imos[j]+=imos[j-1];
			for(int j=0;j<n;j++)
			{
				cnt[j]=imos[right[j]]-(left[j]==0?0:imos[left[j]-1]);
				if(j>0) cnt[j]+=cnt[j-1];
			}
			for(int j=0;j<query[i].size();j++)
			{
				P p=query[i][j].second;
				int s=p.first,t=p.second;
				ans[query[i][j].first]=cnt[t]-(s==0?0:cnt[s-1]);
			}
		}
	}
	bit.init();
	for(int i=0;i<all;i++)
	{
		for(int j=0;j<add[i].size();j++)
		{
			int v=add[i][j];
			bit.add(v+1,1);
		}
		int s=sa[i].first,t=sa[i].second;
		if(query[s].size()<SQR)
		{
			for(int j=0;j<query[s].size();j++)
			{
				P p=query[s][j].second;
				ans[query[s][j].first]+=bit.get(p.first+1,p.second+1);
			}
		}
		for(int j=0;j<rem[i].size();j++)
		{
			int v=rem[i][j];
			bit.add(v+1,-1);
		}
	}
	for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
	return 0;
}