#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005
#define BT 1024*128*2

using namespace std;

struct Q
{
	int s,t,f,id;
	Q(int s=0,int t=0,int f=0,int id=0):s(s),t(t),f(f),id(id){}
};
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
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return BT;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
vector <Q> vec[2][SIZE];
vector <int> pnt[2][SIZE];
bool ok[SIZE*2];

void solve(int pos,int n,int m)
{
	seg.init(n+2);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<pnt[pos][i].size();j++)
		{
			int t=pnt[pos][i][j];
			seg.add(t,i);
			//printf("%d %d\n",t,i);
		}
		for(int j=0;j<vec[pos][i].size();j++)
		{
			Q q=vec[pos][i][j];
			//printf("[%d %d]%d %d %d\n",q.s,q.t,q.id,seg.get(q.s,q.t+1),q.f);
			if(seg.get(q.s,q.t+1)>=q.f)
			{
				ok[q.id]=true;
			}
		}
	}
}
int main()
{
	int n,m,k,q;
	scanf("%d %d %d %d",&n,&m,&k,&q);
	for(int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);x--;y--;
		pnt[0][x].push_back(y);//0 ... solve(0,m,n)
		pnt[1][y].push_back(x);//1 ... solve(1,n,m)
	}
	for(int i=0;i<q;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);a--;b--;c--;d--;
		//(a,b) -> (c,d)
		vec[0][c].push_back(Q(b,d,a,i));
		vec[1][d].push_back(Q(a,c,b,i));
	}
	memset(ok,false,sizeof(ok));
	solve(0,m,n);
	solve(1,n,m);
	for(int i=0;i<q;i++)
	{
		if(ok[i]) puts("YES");
		else puts("NO");
	}
	return 0;
}