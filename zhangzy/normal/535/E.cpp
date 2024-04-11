//2.0  
/*10000sr
*/ 
%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define eps 0.00000000000001
using namespace std;
struct point{
	long double x,y;
	int s,r;
}a[10011];
vector<int>v[10011];
int mar[10011]={0};
int n,win[200100],ok[10011],ss,rr,g=0;
struct hand_stack{
	int val[10000000],siz;
}sk;

int turnleft(point p1,point p2,point p3)
{
	return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x)>eps?1:0;
	// 
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&ss,&rr);
		if (rr>mar[ss])
		{
			mar[ss]=rr;
			v[ss].clear();
			v[ss].push_back(i);
		}
		else
		{
			if (rr==mar[ss])
				v[ss].push_back(i);
		}
	}
	
	int miw=1;
	for (int i=1;i<=10000;i++)
		if (mar[i])
		{
			g++;
			a[g].s=i;
			a[g].r=mar[i];
			a[g].x=(long double)10000/(long double)a[g].s;
			a[g].y=(long double)10000/(long double)a[g].r;
			if (a[g].r>=a[miw].r)
				miw=g;
		}
	// 
	
	sk.siz=0;
	a[miw-1].x=a[miw].x+1;
	a[miw-1].y=a[miw].y;
	// 
	sk.val[++sk.siz]=miw-1;
	for (int i=miw;i<=g;i++)
	{
		sk.val[++sk.siz]=i;
		while (sk.siz>=3)
		{
			if ( !turnleft( a[sk.val[sk.siz-2]] , a[sk.val[sk.siz-1]] , a[sk.val[sk.siz]] ) )
				break;
			else
			{
				sk.val[sk.siz-1]=sk.val[sk.siz];
				sk.siz--;
			}
		}
	}
	for (int i=2;i<=sk.siz;i++)
		ok[sk.val[i]]=1;
	// 
	
	for (int i=1;i<=g;i++)
		if (ok[i])
			for (int j=0;j<v[a[i].s].size();j++)
				win[v[a[i].s][j]]=1;
	for (int i=1;i<=n;i++)
		if (win[i])
			printf("%d ",i);
	// 
}