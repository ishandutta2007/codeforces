#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cassert>
#define SIZE 32

using namespace std;
typedef pair <int,int> P;

int mp[SIZE][SIZE],in[SIZE][SIZE];
bool use[SIZE][SIZE];
int now[SIZE];
vector <P> vec[SIZE*SIZE];
int cnt[SIZE*SIZE];
P ret[1000005];
int sz;

void ins(P p)
{
	ret[sz++]=p;
	if(sz>=1000005) sz=0;
}
void prt()
{
	printf("%d\n",sz-1);
	for(int i=0;i<sz;i++)
	{
		printf("%d %d\n",ret[i].first+1,ret[i].second+1);
	}
}
P R(P p)
{
	int x=p.first,y=p.second;
	swap(in[x][y],in[x][y+1]);
	ins(P(x,y+1));
	return P(x,y+1);
}
P L(P p)
{
	int x=p.first,y=p.second;
	swap(in[x][y],in[x][y-1]);
	ins(P(x,y-1));
	return P(x,y-1);
}
P U(P p)
{
	int x=p.first,y=p.second;
	swap(in[x][y],in[x-1][y]);
	ins(P(x-1,y));
	return P(x-1,y);
}
P D(P p)
{
	int x=p.first,y=p.second;
	swap(in[x][y],in[x+1][y]);
	ins(P(x+1,y));
	return P(x+1,y);
}
int n,m;
void see()
{
	puts("");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",in[i][j]);
		puts("");
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a;
			scanf("%d",&a);
			vec[a].push_back(P(i,j));
			in[i][j]=a;
			cnt[a]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&mp[i][j]);
			cnt[mp[i][j]]--;
			if(cnt[mp[i][j]]<0)
			{
				puts("-1");
				return 0;
			}
		}
	}
	if(n==1)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=i+1;j<m;j++)
			{
				for(int k=0;k<i;k++) now[k]=in[0][k];
				for(int k=i;k<j;k++) now[k]=in[0][k+1];
				now[j]=in[0][i];
				for(int k=j+1;k<m;k++) now[k]=in[0][k];
				bool ok=true;
				for(int k=0;k<m;k++) if(now[k]!=mp[0][k]) ok=false;
				if(ok)
				{
					for(int k=i;k<=j;k++) ins(P(0,k));
					prt();
					return 0;
				}
				for(int k=0;k<i;k++) now[k]=in[0][k];
				for(int k=i+1;k<=j;k++) now[k]=in[0][k-1];
				now[i]=in[0][j];
				for(int k=j+1;k<m;k++) now[k]=in[0][k];
				ok=true;
				for(int k=0;k<m;k++) if(now[k]!=mp[0][k]) ok=false;
				if(ok)
				{
					for(int k=j;k>=i;k--) ins(P(0,k));
					prt();
					return 0;
				}
			}
		}
		puts("-1");
		return 0;
	}
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=0;k<i;k++) now[k]=in[k][0];
				for(int k=i;k<j;k++) now[k]=in[k+1][0];
				now[j]=in[i][0];
				for(int k=j+1;k<n;k++) now[k]=in[k][0];
				bool ok=true;
				for(int k=0;k<n;k++) if(now[k]!=mp[k][0]) ok=false;
				if(ok)
				{
					for(int k=i;k<=j;k++) ins(P(k,0));
					prt();
					return 0;
				}
				for(int k=0;k<i;k++) now[k]=in[k][0];
				for(int k=i+1;k<=j;k++) now[k]=in[k-1][0];
				now[i]=in[j][0];
				for(int k=j+1;k<n;k++) now[k]=in[k][0];
				ok=true;
				for(int k=0;k<n;k++) if(now[k]!=mp[k][0]) ok=false;
				if(ok)
				{
					for(int k=j;k>=i;k--) ins(P(k,0));
					prt();
					return 0;
				}
			}
		}
		puts("-1");
		return 0;
	}
	P p=vec[mp[0][0]][0];
	ins(p);
	for(int i=n-1;i>=2;i--)
	{
		for(int j=0;j<m;j++)
		{
			use[i][j]=true;
			while(p.second<j) p=R(p);
			while(p.first!=i) p=D(p);
			while(p.second!=j) p=L(p);
			int v=mp[i][j];
			//printf("%d %d %d %d[%d %d]\n",i,j,in[i][j],v,p.first,p.second);
			//see();
			P tg;
			for(int k=0;k<n;k++)
			{
				for(int l=m-1;l>=0;l--)
				{
					if(in[k][l]==v&&!use[k][l])
					{
						tg=P(k,l);
					}
				}
			}
			int lt=min(max(0,j-1),tg.second);
			int rt=max(min(m-1,j+1),tg.second);
			int up=min(i-1,tg.first);
			if(up!=i-1)
			{
				while(1)
				{
					if(j<rt)
					{
						p=R(p);
						if(in[i][j]==v) break;
					}
					else
					{
						p=U(p);
						if(in[i][j]==v) break;
					}
					while(p.second<rt) p=R(p);
					while(p.first>up) p=U(p);
					while(p.second>lt) p=L(p);
					while(p.first<i-1) p=D(p);
	 				if(j==0) p=D(p);
					else
					{
						while(p.second<j-1) p=R(p);
						swap(in[i-1][j-1],in[i][j]);
						p=P(i,j);
						ret[sz++]=p;
					}
				}
			}
			else
			{
				int x=tg.second;
				if(x==j) p=U(p);
				else if(x<j)
				{
					while(1)
					{
						p=U(p);
						if(in[i][j]==v) break;
						p=U(p);
						while(p.second>x) p=L(p);
						p=D(p);
						while(p.second<j-1) p=R(p);
						p=P(i,j);
						swap(in[i-1][j-1],in[i][j]);
						ret[sz++]=P(i,j);
					}
				}
				else
				{
					while(1)
					{
						p=R(p);
						if(in[i][j]==v) break;
						while(p.second<m-1) p=R(p);
						p=U(p);
						while(p.second>j) p=L(p);
						p=D(p);
					}
				}
			}
		}
	}
	//if(n==19&&m==26) return 0;
	for(int i=m-1;i>0;i--)
	{
		while(p.second<i) p=R(p);
		if(p.first!=1) p=D(p);
		int v=mp[1][i];
		//see();
		while(1)
		{
			p=U(p);
			if(in[1][i]==v) break;
			while(p.second>0) p=L(p);
			p=D(p);
			while(p.second<i) p=R(p);
			//see();
		}
		v=mp[0][i];
		while(1)
		{
			p=L(p);
			if(in[0][i]==v) break;
			while(p.second>0) p=L(p);
			p=D(p);
			while(p.second<i-1) p=R(p);
			swap(in[1][i-1],in[0][i]);
			p=P(0,i);
			ret[sz++]=p;
			//see();
		}
		//	see();
	}
	if(p!=P(0,0))
	{
		p=U(p);
	}
	prt();
	return 0;
}