#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define DEP 45

using namespace std;
typedef long long int ll;

struct trie
{
	struct nod
	{
		nod *l,*r;
		nod(nod *l=NULL,nod *r=NULL):l(l),r(r){}
	};
	nod start;
	void add(ll a)
	{
		nod *at=&start;
		for(int i=DEP;i>=0;i--)
		{
			if(a>>i&1)
			{
				if(at->l==NULL) at->l=new nod();
				at=at->l;
			}
			else
			{
				if(at->r==NULL) at->r=new nod();
				at=at->r;
			}
		}
	}
	ll maxor(ll a)
	{
		ll xr=0;
		nod *at=&start;
		for(int i=DEP;i>=0;i--)
		{
			if(((a>>i&1)&&at->r!=NULL)||at->l==NULL)
			{
				at=at->r;
			}
			else
			{
				xr+=1LL<<i;
				at=at->l;
			}
		}
		return a^xr;
	}
};
trie tr;
ll sum[SIZE][2];
ll in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%I64d",&in[i]);
	for(int i=0;i<n;i++)
	{
		sum[i][0]=in[i];
		if(i>0) sum[i][0]^=sum[i-1][0];
	}
	sum[n][0]=0;
	for(int i=n-1;i>=0;i--)
	{
		sum[i][1]=in[i];
		sum[i][1]^=sum[i+1][1];
	}
	ll ret=0;
	for(int i=n-1;i>=0;i--)
	{
		tr.add(sum[i+1][1]);
		ret=max(ret,tr.maxor(sum[i][0]));
	}ret=max(ret,tr.maxor(0));
	printf("%I64d\n",ret);
	return 0;
}