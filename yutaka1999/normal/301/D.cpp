#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#define SIZE 200005

using namespace std;
typedef pair <int,int> P;

struct BIT
{
	int bit[SIZE];
	int n;
	
	void add(int k)//plus 1
	{
		while(k<=n)
		{
			bit[k]++;
			k+=k&-k;
		}
	}
	int sum(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
};
BIT bit;
struct Q
{
	int l,r,n;
	int v;
	Q(int l=-1,int r=-1,int n=-1,int v=-1):l(l),r(r),n(n),v(v){}
};
bool comp1(const Q&l,const Q&r)
{
	return l.l>r.l;
}
bool comp2(const Q&l,const Q&r)
{
	return l.n<r.n;
}
Q ans[SIZE];
int pla[SIZE];
int rui[SIZE];
int in[SIZE];
vector <int> vec[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	memset(in,-1,sizeof(in));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		pla[in[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j*j<=in[i];j++)
		{
			if(in[i]%j==0)
			{
				int one=j,two=in[i]/j;
				if(pla[one]!=-1) vec[min(i,pla[one])].push_back(max(i,pla[one]));
				if(one!=two&&pla[two]!=-1) vec[min(i,pla[two])].push_back(max(i,pla[two]));
			}
		}
	}
	bit.n=n+5;
	for(int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);l--;r--;
		ans[i].l=l;
		ans[i].r=r;
		ans[i].n=i;
	}
	sort(ans,ans+m,comp1);
	int pos=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<vec[i].size();j++) bit.add(vec[i][j]+1);
		while(pos<m&&ans[pos].l==i)
		{
			ans[pos].v=bit.sum(ans[pos].r+1);
			pos++;
		}
	}
	sort(ans,ans+m,comp2);
	for(int i=0;i<m;i++) printf("%d\n",ans[i].v);
	return 0;
}