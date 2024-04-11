#include <bits/stdc++.h>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

struct BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		k++;
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		k++;
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
BIT bit[3];
set <int> st[3];
set <int>::iterator it;
int A[SIZE];
char str[SIZE];
int n;

int ctoi(char c)
{
	if(c=='R') return 0;
	if(c=='P') return 1;
	if(c=='S') return 2;
	return -1;
}
int get(int l,int r,int c)
{
	l=max(l,0);
	r=min(r,n-1);
	if(l>r) return 0;
	return bit[c].get(l,r);
}
void rm(int v)
{
	st[A[v]].erase(v);
	bit[A[v]].add(v,-1);
}
void ins(int v)
{
	st[A[v]].insert(v);
	bit[A[v]].add(v,1);
}
int query()
{
	int ret=0;
	for(int i=0;i<3;i++)
	{
		int x=i,y=i+1,z=i-1;
		if(z<0) z+=3;
		if(y>=3) y-=3;
		int my=n,mz=n;
		it=st[y].begin();
		if(it!=st[y].end()) my=*it;
		it=st[z].begin();
		if(it!=st[z].end()) mz=*it;
		int My=-1,Mz=-1;
		it=st[y].end();
		if(it!=st[y].begin())
		{
			it--;
			My=*it;
		}
		it=st[z].end();
		if(it!=st[z].begin())
		{
			it--;
			Mz=*it;
		}
		ret+=st[x].size();
		if(my<mz)
		{
			if(Mz<My)
			{
				if(mz<Mz)
				{
					ret-=get(my,mz,x);
					ret-=get(Mz,My,x);
				}
				else
				{
					ret-=get(min(my,Mz),max(mz,My),x);
				}
			}
			else
			{
				ret-=get(my,mz,x);
			}
		}
		else if(Mz<My)
		{
			ret-=get(Mz,My,x);
		}
		//printf("%d * %d %d : %d %d\n",ret,my,mz,Mz,My);
	}
	return ret;
}
int main()
{
	int Q;
	scanf("%d %d",&n,&Q);
	scanf("%s",&str);
	for(int i=0;i<3;i++) bit[i].init();
	for(int i=0;i<n;i++)
	{
		A[i]=ctoi(str[i]);
		ins(i);
	}
	printf("%d\n",query());
	while(Q--)
	{
		int t;
		scanf("%d %s",&t,&str);t--;
		rm(t);
		A[t]=ctoi(str[0]);
		ins(t);
		printf("%d\n",query());
	}
	return 0;
}