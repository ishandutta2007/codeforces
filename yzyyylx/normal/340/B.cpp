#include<bits/stdc++.h>
using namespace std;

double x[310],y[310];
int n,i,j,k;

double mj(int a,int b,int c)
{
	double a1,b1,a2,b2;
	a1=x[b]-x[a],a2=x[c]-x[b];
	b1=y[b]-y[a],b2=y[c]-y[b];
	return a1*b2-a2*b1;
}

int main()
{
	double s=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			double s1=0,s2=0;
			for(k=0;k<n;k++)
			{
				if(k!=i&&k!=j)
				{
					double t=mj(i,j,k);
					if(t>0)
					{
						s1=max(s1,t/2.0);
					}
					else
					{
						s2=max(s2,-t/2.0);
					}
				}
			}
			if(s1>0&&s2>0&&s1+s2>s)
			{
				s=s1+s2;
			}
		}
	}
	printf("%.6lf",s);
	return 0;
}