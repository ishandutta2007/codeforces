#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int tp[SIZE];
int dep[SIZE];
P get(int v)
{
	if(tp[v]!=v)
	{
		P p=get(tp[v]);
		tp[v]=p.first;
		dep[v]+=p.second;
		if(dep[v]>=MOD) dep[v]-=MOD;
	}
	return P(tp[v],dep[v]);
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(dep,0,sizeof(dep));
	for(int i=0;i<n;i++) tp[i]=i;
	int ret=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<a;j++)
		{
			int v,x;
			scanf("%d %d",&v,&x);v--;
			P p=get(v);
			x+=p.second;
			if(x>=MOD) x-=MOD;
			else if(x<0) x+=MOD;
			tp[p.first]=i;
			dep[p.first]=x;
			ret+=x;
			if(ret>=MOD) ret-=MOD;
			//printf("%d %d %d\n",v,p.first,p.second);
		}
	}
	printf("%d\n",ret);
	return 0;
}