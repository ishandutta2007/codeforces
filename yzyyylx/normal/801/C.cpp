#include<iostream>
#include<cstdio>
#include<queue>
#define N 100100
#define P pair<double,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;

priority_queue<P>pq;
double ans,sum,p,v,zh[N],spe[N];
int n;

int main()
{
	int i,j;
	cin>>n>>v;
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&spe[i],&zh[i]);
		sum+=zh[i];
		p+=spe[i];
		pq.push(mp(zh[i]/spe[i],i));
	}
	if(v>=p)
	{
		cout<<-1;
		return 0;
	}
	ans=sum/(p-v);
//	cout<<pq.top().fi<<" ";
	for(;ans<pq.top().fi;)
	{
		sum-=zh[pq.top().se];
		p-=spe[pq.top().se];
		ans=sum/(p-v);
		pq.pop();
	}
	printf("%.10lf",ans);
}