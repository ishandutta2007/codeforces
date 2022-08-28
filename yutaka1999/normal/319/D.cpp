#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 50005
#define SQR 500
#define B1 8939LL
#define M1 1000000007LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct UF
{
	int par[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++) par[i]=i;
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)//x->y
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		par[x]=y;
	}
};
UF uf;
vector <P> query[SIZE];
ll h1[SIZE],r1[SIZE];
int h2[SIZE];
int rank[SIZE],sa[SIZE];
int lcp[SIZE],cnt[SIZE];
set <int> nd[SIZE];
set <int>::iterator it,its;
P pos[SIZE];
char str[SIZE];
char A[SIZE];

void init()
{
	r1[0]=1;
	for(int i=1;i<SIZE;i++) r1[i]=r1[i-1]*B1%M1;
}
ll get_hash1(int s,int t)
{
	return (h1[t]-(s==0?0:h1[s-1]*r1[t-s+1]%M1)+M1)%M1;
}
int get_hash2(int s,int t)
{
	return h2[t]-(s==0?0:h2[s-1]);
}
int main()
{
	init();
	scanf("%s",&str);
	int n=strlen(str);
	int sz=n;
	for(int i=0;i<sz;i++) A[i]=str[i];
	//SQR
	for(int i=1;i<=SQR;i++)
	{
		int ns=0;
		for(int j=0;j<sz;j++)
		{
			h1[ns]=h2[ns]=A[j]-'a'+1;
			if(ns>0)
			{
				h1[ns]+=h1[ns-1]*B1%M1;
				h2[ns]+=h2[ns-1];
				if(h1[ns]>=M1) h1[ns]-=M1;
			}
			A[ns++]=A[j];
			if(ns>=2*i)
			{
				ll g1=get_hash1(ns-i,ns-1);
				int f1=get_hash2(ns-i,ns-1);
				ll g2=get_hash1(ns-2*i,ns-i-1);
				int f2=get_hash2(ns-2*i,ns-i-1);
				if(g1==g2&&f1==f2) ns-=i;
			}
		}
		//if(i<=3) printf("%d %d\n",sz,ns);
		sz=ns;
	}
	//for(int i=0;i<sz;i++) printf("%c",A[i]);puts("");
	while(1)
	{
		//XXT
		//--> SA \z ( O(n*logn)  )
		for(int i=0;i<sz;i++) rank[i]=A[i]-'a';
		for(int k=1;k<=sz;k<<=1)
		{
			int lim=max(30,sz);
			for(int i=0;i<=lim;i++)
			{
				query[i].clear();
				cnt[i]=0;
			}
			for(int i=0;i<sz;i++)
			{
				int s=rank[i],t=i+k<sz?rank[i+k]:-1;
				query[t+1].push_back(P(s,i));
				cnt[s+1]++;
			}
			for(int i=1;i<=lim;i++) cnt[i]+=cnt[i-1];
			for(int i=0;i<=lim;i++)
			{
				for(int j=0;j<query[i].size();j++)
				{
					P p=query[i][j];
					rank[p.second]=cnt[p.first];
				}
				for(int j=0;j<query[i].size();j++)
				{
					P p=query[i][j];
					cnt[p.first]++;
				}
			}
		}
		for(int i=0;i<sz;i++) sa[rank[i]]=i;
		int H=0;
		for(int i=0;i<sz;i++)
		{
			if(H>0) H--;
			if(rank[i]==sz-1) continue;
			int to=sa[rank[i]+1];
			while(i+H<sz&&to+H<sz&&A[i+H]==A[to+H]) H++;
			lcp[rank[i]]=H;
		}
		//XXAi<jA
		//i`j` |j-i| 
		//lcp  --> }[WeN
		//A2lcp}[W
		for(int i=0;i<sz-1;i++) pos[i]=P(lcp[i],i);
		for(int i=0;i<sz;i++)
		{
			nd[i].clear();
			nd[i].insert(sa[i]);
		}
		sort(pos,pos+sz-1);
		uf.init(sz+2);
		P nxt=P(sz,-1);
		for(int i=sz-2;i>=0;i--)
		{
			int v=pos[i].second,L=pos[i].first;
			//vv+1}[W
			int l=uf.find(v),r=v+1;
			uf.unite(r,l);
			if(nd[l].size()<nd[r].size()) swap(nd[l],nd[r]);
			for(it=nd[r].begin();it!=nd[r].end();it++)
			{
				int v=*it;
				its=nd[l].lower_bound(v);
				if(its!=nd[l].end())
				{
					int to=*its;
					if(to-v<=L) nxt=min(nxt,P(to-v,v));
				}
				if(its!=nd[l].begin())
				{
					its--;
					int to=*its;
					if(v-to<=L) nxt=min(nxt,P(v-to,to));
				}
				nd[l].insert(v);
			}
		}
		//for(int i=0;i<sz;i++) printf("%d ",rank[i]);puts("");
		//printf("%d : %d %d\n",sz,nxt.first,nxt.second);
		if(nxt.second==-1) break;
		int ns=0;
		for(int i=0;i<sz;i++)
		{
			if(nxt.second<=i&&i<nxt.first+nxt.second) continue;
			A[ns++]=A[i];
		}
		sz=ns;
	}
	for(int i=0;i<sz;i++) printf("%c",A[i]);puts("");
	return 0;
}