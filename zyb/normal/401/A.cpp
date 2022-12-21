#include<stdio.h>
using namespace std;
inline int abs(int o)
{
	if (o<0)
	return -o;
	else return o;
}
inline int min(int o,int p)
{
	if (o<p)
	return o;
	else return p;
}
int main()
{
	int i,j,m,n,s=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&j);
		s+=j;
	}
	s=abs(s);
	int ans=0;
	while (s!=0)
	{
		ans++;
		s=s-min(m,s);
	}
	printf("%d",ans);
}