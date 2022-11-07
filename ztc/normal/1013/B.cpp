#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,b;
	bool operator<(const node &u)const
	{
		if(v!=u.v)return v>u.v;
		else return b>u.b;
	}
	bool operator==(const node &u)const
	{
		return v==u.v;
	}
}a[200002],c;
int n,m,i,j,k,r=3;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		a[i].b=0;
		a[i].v=k;
		if((k&m)==k)
		{
			a[i+n].v=0x7fffffff;
			a[i+n].b=3;
		}
		else 
		{
			a[i+n].v=k&m;
			a[i+n].b=1;
		}
	}
	sort(a+1,a+(n<<1)+1);
	for(i=2;i<=(n<<1);i++)
	{
		if(a[i]==a[i-1])r=min(r,a[i].b+a[i-1].b);
	}
	if(r>=3)printf("-1");
	else printf("%d",r);
}