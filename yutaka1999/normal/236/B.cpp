#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

long long int p[10000002];

int div(int n)
{
	int u,sum=0;
	
	for(u=1;u*u<=n;u++)
	{
		if(n%u==0&&u*u!=n)
		{
			sum=(sum+2)%1073741824;
		}
		else if(u*u==n)
		{
			sum=(sum+1)%1073741824;
		}
	}
	
	return sum;
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	
	int i,j,k;
	long long int w=0;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			for(k=1;k<=c;k++)
			{
				if(p[i*j*k]==0) p[i*j*k]=div(i*j*k);
				
				w=(w+p[i*j*k])%1073741824;
			}
		}
	}
	cout<<w%1073741824<<endl;
	return 0;
}