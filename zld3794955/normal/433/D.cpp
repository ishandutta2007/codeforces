#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const int N=1010,M=1010;
int n,m,q,a[N][M]={};
set<int>l[N],r[M]={};
void init()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
	{
		l[i].insert(0);
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
				l[i].insert(j);
		}
		l[i].insert(m+1);
	}
	for(int j=1;j<=m;++j)
	{
		r[j].insert(0);
		for(int i=1;i<=n;++i)
			if(a[i][j]==0)
				r[j].insert(i);
		r[j].insert(n+1);
	}
}
int left_work(int x,int y)
{
	int S=0,a[M]={},u=n+1,d=0;
	int tmp=0x7fffffff;
	for(int j=y;j>=1;--j)
	{
		if(r[j].count(x))
			break;
		set<int>::iterator down=r[j].lower_bound(x);
		set<int>::iterator up=down--;
		u=min(u,*up);
		d=max(d,*down);
		a[j]=u-d-1;
	}
	for(int j=y;j>=1;--j)
	{
		tmp=min(tmp,a[j]);
		S=max(tmp*(y-j+1),S);
	}
	return S;
}
int right_work(int x,int y)
{
	int S=0,a[M]={},u=n+1,d=0;
	int tmp=0x7fffffff;
	for(int j=y;j<=m;++j)
	{
		if(r[j].count(x))
			break;
		set<int>::iterator down=r[j].lower_bound(x);
		set<int>::iterator up=down--;
		u=min(u,*up);
		d=max(d,*down);
		a[j]=u-d-1;
	}
	for(int j=y;j<=m;++j)
	{
		tmp=min(tmp,a[j]);
		S=max(tmp*(j-y+1),S);
	}
	return S;
}
int up_work(int x,int y)
{
	int S=0,a[N]={},u=m+1,d=0;
	int tmp=0x7fffffff;
	for(int i=x;i>=1;--i)
	{
		if(l[i].count(y))
			break;
		set<int>::iterator down=l[i].lower_bound(y);
		set<int>::iterator up=down--;
		u=min(u,*up);
		d=max(d,*down);
		a[i]=u-d-1;
	}
	for(int i=x;i>=1;--i)
	{
		tmp=min(tmp,a[i]);
		S=max(tmp*(x-i+1),S);
	}
	return S;
}
int down_work(int x,int y)
{
	int S=0,a[N]={},u=m+1,d=0;
	int tmp=0x7fffffff;
	for(int i=x;i<=n;++i)
	{
		if(l[i].count(y))
			break;
		set<int>::iterator down=l[i].lower_bound(y);
		set<int>::iterator up=down--;
		u=min(u,*up);
		d=max(d,*down);
		a[i]=u-d-1;
	}
	for(int i=x;i<=n;++i)
	{
		tmp=min(tmp,a[i]);
		S=max(tmp*(i-x+1),S);
	}
	return S;
}
void work()
{
	int op,x,y;
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			if(a[x][y]==1)
			{
				l[x].insert(y);
				r[y].insert(x);
				a[x][y]=0;
			}
			else
			{
				l[x].erase(y);
				r[y].erase(x);
                                a[x][y]=1;
			}
		}
		if(op==2)
		{
			int ans=0;
			//cout<<left_work(x,y)<<endl;
			ans=max(ans,left_work(x,y));
			//cout<<right_work(x,y)<<endl;
			ans=max(ans,right_work(x,y));
			//cout<<up_work(x,y)<<endl;
			ans=max(ans,up_work(x,y));
			//cout<<down_work(x,y)<<endl;
			ans=max(ans,down_work(x,y));
			printf("%d\n",ans);
			//cout<<endl;
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}