#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#define N 1010
#define ll long long
#define db double
using namespace std;

int n,nn;
db r,mn;

struct Node
{
	db x, y;
};
Node mm[N],hav[N],tmp;

inline db jl(Node u,Node v)
{
	return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}

int main()
{
	register int i,j;
	register db k;
	int g;
	db tm;
	cin>>n>>r;
	for(i=1;i<=n;i++)
	{
		g=mn=-1;
		scanf("%lf",&k);
		for(j=1;j<=nn;j++)
		{
			if(abs(hav[j].x-k)<=2*r)
			{
				tm=hav[j].y+sqrt(4*r*r-(hav[j].x-k)*(hav[j].x-k));
				if(mn<tm)
				{
					mn=tm;
					g=j;
				}
			}
		}
		if(g==-1)
		{
			printf("%.10lf ",r);
			tmp.x=k;
			tmp.y=r;
			nn++;
			hav[nn]=tmp;
		}
		else
		{
			tmp.x=k;
			tmp.y=mn;
			printf("%.10lf ",mn);
			nn++;
			hav[nn]=tmp;
		}
	}
}