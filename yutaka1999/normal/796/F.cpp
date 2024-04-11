#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 300005
#define BT 512*1024*2
#define INF 1000000005
#define BB 40

using namespace std;

struct segtree2
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-1;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return -1;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
struct segtree1//range min
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
	void pass(int k)
	{
		seg[k*2+1]=min(seg[k*2+1],seg[k]);
		seg[k*2+2]=min(seg[k*2+2],seg[k]);
		seg[k]=INF;
	}
	void erase(int x)
	{
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			pass(k);
			int m=(l+r)/2;
			if(x<m)
			{
				r=m;
				k=k*2+1;
			}
			else
			{
				l=m;
				k=k*2+2;
			}
		}
		seg[k]=INF;
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
segtree1 s1;
segtree2 s2;
int L[SIZE],R[SIZE],X[SIZE];
int pos[SIZE],dt[SIZE];
int tp[SIZE];
int mx[SIZE],nowA[SIZE];
set <int> st[SIZE];
set <int>::iterator it;
vector <int> vec[BB];
bool use[SIZE];
bool ng[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	s1.init(n+2);
	s2.init(n+2);
	memset(nowA,-1,sizeof(nowA));
	memset(use,false,sizeof(use));
	for(int i=0;i<m;i++)
	{
		scanf("%d",&tp[i]);
		if(tp[i]==1)
		{
			scanf("%d %d %d",&L[i],&R[i],&X[i]);L[i]--,R[i]--;
			s1.update(L[i],R[i]+1,X[i]);
			int gt=s2.get(L[i],R[i]+1);
			if(gt>X[i])
			{
				puts("NO");
				return 0;
			}
			use[i]=gt==X[i];
		}
		else
		{
			scanf("%d %d",&pos[i],&dt[i]);
			pos[i]--;
			int gt=s1.get(pos[i]);
			gt=min(gt,1000000000);
			if(nowA[pos[i]]==-1) mx[pos[i]]=gt;
			nowA[pos[i]]=dt[i];
			s2.add(pos[i],dt[i]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(nowA[i]==-1)
		{
			mx[i]=s1.get(i);
			mx[i]=min(mx[i],1000000000);
		}
	}
	vector <int> vx;
	for(int i=0;i<n;i++) vx.push_back(mx[i]);
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++)
	{
		mx[i]=lower_bound(vx.begin(),vx.end(),mx[i])-vx.begin();
		st[mx[i]].insert(i);
	}
	for(int i=0;i<m;i++)
	{
		if(tp[i]==1&&!use[i])
		{
			int t=lower_bound(vx.begin(),vx.end(),X[i])-vx.begin();
			if(t==vx.size()||vx[t]!=X[i])
			{
				puts("NO");
				return 0;
			}
			it=st[t].lower_bound(L[i]);
			if(it==st[t].end()||*it>R[i])
			{
				puts("NO");
				return 0;
			}
			int to=*it;
			it++;
			if(it==st[t].end()||*it>R[i])
			{
				ng[to]=true;
			}
		}
		else
		{
			int v=pos[i];
			st[mx[v]].erase(v);
		}
	}
	for(int i=0;i<n;i++)
	{
		mx[i]=vx[mx[i]];
		int vl=mx[i];
		if(vl>0)
		{
			int cnt=0;
			while(vl>0)
			{
				vl/=2;
				cnt++;
			}
			vec[cnt-1].push_back(i);
		}
	}
	int ret=0;
	for(int i=BB-1;i>=0;i--)
	{
		if(vec[i].empty()) continue;
		if(ret>>i&1)
		{
			bool U=true;
			for(int j=0;j<vec[i].size();j++)
			{
				int v=vec[i][j];
				if(!ng[v]&&U)
				{
					mx[v]=((mx[v]>>(i+1))<<(i+1))+(1<<i)-1;
					U=false;
				}
				ret|=mx[v];
			}
			if(!U) break;
		}
		else
		{
			if(vec[i].size()==1)
			{
				int v=vec[i][0];
				if(!ng[v])
				{
					int zan=mx[v]-((mx[v]>>i)<<i);
					ret|=1<<i;
					if(zan>0)
					{
						int vl=zan,cnt=0;
						while(vl>0)
						{
							vl/=2;
							cnt++;
						}
						vec[cnt-1].push_back(v);
					}
				}
				else ret|=mx[v];
			}
			else
			{
				bool up=false;
				for(int j=0;j<vec[i].size();j++)
				{
					int v=vec[i][j];
					up|=!ng[v];
				}
				if(up)
				{
					for(int j=0;j<vec[i].size();j++)
					{
						int v=vec[i][j];
						if(!ng[v])
						{
							mx[v]=((mx[v]>>(i+1))<<(i+1))+(1<<i)-1;
							break;
						}
					}
					ret|=(1<<(i+1))-1;
					break;
				}
				else
				{
					for(int j=0;j<vec[i].size();j++)
					{
						int v=vec[i][j];
						ret|=mx[v];
					}
				}
			}
		}
	}
	puts("YES");
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",mx[i]);
	}puts("");
	return 0;
}