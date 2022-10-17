#include<bits/stdc++.h>
using namespace std;
/*
6
0 0 0 0 0
1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
*/

const long long N=1010;
long long an[N],ans=0,a[N],b[N],c[N],d[N],e[N],n,dc[N];

int js(long long p,long long q)
{
	long long sum,ji1,ji2,ji3,ji4,ji5;
	ji1=a[p]-a[q];
	ji2=b[p]-b[q];
	ji3=c[p]-c[q];
	ji4=d[p]-d[q];
	ji5=e[p]-e[q];
	sum=ji1*ji1+ji2*ji2+ji3*ji3+ji4*ji4+ji5*ji5;
	return sum;
}

int jy(long long j,long long b1,long long b2)
{
	if(js(j,b1)+js(j,b2)<=js(b1,b2))
	return 0;
	else return 1;
}

int main()
{
	long long i,j,k,pd,pd2;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];/*
		if(a[i]<0) a[i]=-a[i];
		if(b[i]<0) b[i]=-b[i];
		if(c[i]<0) c[i]=-c[i];
		if(d[i]<0) d[i]=-d[i];
		if(e[i]<0) e[i]=-e[i];*/
	}
	if(n<3)
	{
		cout<<n<<endl;
		for(i=1;i<=n;i++)
		cout<<i<<endl;
		return 0;
	}
	
	for(i=1;i<=n;i++)
	{
		pd=0;
		for(j=1;j<=n;j++)
		{
			if(j!=i)
			{
				pd2=0;
				for(k=j+1;k<=n;k++)
				{
					if(k!=i)
					{
						if(jy(i,j,k)==1)
						{
							pd2=1;
							break;
						}
			    	}
				}
				if(pd2==1)
				{
					pd=1;
					break;
				}
		    }
		}
		if(pd==0)
		{
			ans++;
			an[ans]=i;
		}
	}
	
	cout<<ans<<endl;
	for(i=1;i<=ans;i++)
	cout<<an[i]<<endl;
}