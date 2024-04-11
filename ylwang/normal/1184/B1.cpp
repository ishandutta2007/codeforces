#include<bits/stdc++.h>
using namespace std;
int a[100001];
struct enemy
{
	int d,g;
	bool operator<(const enemy& ano)const
	{
		return d<ano.d; 
	}
}e[100001];
int sum[100001];
int main()
{
	int s,b;
	scanf("%d %d",&s,&b);
	for(int i=1;i<=s;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=b;i++)
		scanf("%d %d",&e[i].d,&e[i].g);
	sort(e+1,e+b+1);
	for(int i=1;i<=b;i++)
		sum[i]=sum[i-1]+e[i].g;
	e[0].d=0;
	for(int i=1;i<=s;i++)
	{
		int L=0,R=b;
		while(L<R)
		{
			int mid=(L+R+1)>>1;
			if(e[mid].d<=a[i])
				L=mid;
			else
				R=mid-1;
		}
		printf("%d ",sum[L]);
	}
	putchar('\n');
	return 0;
}