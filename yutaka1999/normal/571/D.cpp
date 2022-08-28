#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 500005
#define BT 512*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

struct segtree//a
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void update(int a,int b,int k,int l,int r,ll x)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]+=x;
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
		}
	}
	void update(int a,int b,ll x)
	{
		update(a,b,0,0,mum,x);
	}
	ll get(int k)
	{
		k+=mum-1;
		ll ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret+=seg[k];
		}
		return ret;
	}
};
struct segtree2//X
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-1;
	}
	void pass(int k)
	{
		if(seg[k]!=-1) seg[k*2+1]=seg[k*2+2]=seg[k];
		seg[k]=-1;
	}
	void update(int a,int b,int k,int l,int r,int x)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]=x;
		else
		{
			pass(k);
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
		}
	}
	void update(int a,int b,int x)
	{
		update(a,b,0,0,mum,x);
	}
	int get(int k)
	{
		k+=mum-1;
		int ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			if(seg[k]!=-1) ret=seg[k];
		}
		return ret;
	}
};
segtree s1;
segtree2 s2;
vector <P> vec[2][SIZE];
vector <PP> query[SIZE];
int id[2][SIZE];
int ch[2][SIZE];
int T[SIZE],A[SIZE],B[SIZE];
int nd[SIZE];
char str[SIZE];
bool use[2][SIZE];
ll ans[SIZE];
int now_id;

void dfs(int v,int tp)
{
	id[tp][v]=now_id++;
	for(int i=0;i<vec[tp][v].size();i++)
	{
		int to=vec[tp][v][i].second;
		dfs(to,tp);
	}
	ch[tp][v]=now_id;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s",&str);
		if(str[0]=='U'||str[0]=='M')
		{
			T[i]=str[0]=='U'?0:1;
			scanf("%d %d",&A[i],&B[i]);
			A[i]--,B[i]--;
			vec[T[i]][A[i]].push_back(P(i,B[i]));
			use[T[i]][B[i]]=true;
		}
		else
		{
			T[i]=str[0]=='A'?2:str[0]=='Z'?3:4;
			scanf("%d",&A[i]);
			A[i]--;
		}
	}
	for(int j=0;j<2;j++)
	{
		now_id=0;
		for(int i=0;i<n;i++)
		{
			if(!use[j][i])
			{
				dfs(i,j);
			}
		}
	}
	s2.init(n+2);
	int sz=0;
	for(int i=0;i<m;i++)
	{
		if(T[i]==3)
		{
			int v=A[i];
			int s=id[1][v],t=id[1][v]+1;
			int pos=lower_bound(vec[1][v].begin(),vec[1][v].end(),P(i,-1))-vec[1][v].begin()-1;
			if(pos>=0)
			{
				int to=vec[1][v][pos].second;
				t=ch[1][to];
			}
			//printf("%d %d : %d\n",s,t,i);
			s2.update(s,t,i);
		}
		else if(T[i]==4)
		{
			int v=A[i];
			int gt=s2.get(id[1][v]);
			//printf("%d : %d %d\n",i,id[1][v],gt);
			query[i].push_back(PP(v,P(1,i)));
			if(gt>0) query[gt-1].push_back(PP(v,P(-1,i)));/*
			sz++;
			if(sz==295&&n==1000)
			{
				printf("* %d %d\n",gt,i);
			}*/
		}
	}
	s1.init(n+2);
	for(int i=0;i<n;i++) nd[i]=1;
	for(int i=0;i<m;i++)
	{
		if(T[i]==0) nd[A[i]]+=nd[B[i]];
		else if(T[i]==2)
		{
			int v=A[i];
			int s=id[0][v],t=id[0][v]+1;
			int pos=lower_bound(vec[0][v].begin(),vec[0][v].end(),P(i,-1))-vec[0][v].begin()-1;
			if(pos>=0)
			{
				int to=vec[0][v][pos].second;
				t=ch[0][to];
			}
			s1.update(s,t,nd[v]);
		}
		for(int j=0;j<query[i].size();j++)
		{
			int v=query[i][j].first;
			P p=query[i][j].second;
			ll gt=s1.get(id[0][v]);
			ans[p.second]+=(ll) p.first*gt;
		}
	}
	for(int i=0;i<m;i++) if(T[i]==4) printf("%lld\n",ans[i]);
	return 0;
}