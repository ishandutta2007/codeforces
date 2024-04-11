#include<bits/stdc++.h>
using namespace std;

int n,num[10010];

int g(int u)
{
	if(u<0) u+=n;
	if(u>=n) u-=n;
	return u;
}

int main()
{
	int i,j;
	cin>>n;
	if(n==1||n==0)
	{
		cout<<"Yes";
		return 0;
	}
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		num[i+n]=num[i];
	}
	
	for(i=1;i<=n;i++)
	{
		bool p,q,k;
		int a,b,c,d,e,f;
		p=q=false;
		for(j=i;j<=i+n-1;j++)
		{
			if(num[j]!=j-i)
			{
				if(p==true)
				{
					q=true;
					break;
				}
				else
				{
					p=true;
					k=j;
					a=num[j]-j+i;
					b=num[j+1]-j+i-1;
					c=num[j+2]-j+i-2;
					d=j-i-num[j];
					e=j-i+1-num[j+1];
					f=j-i+2-num[j+2];
					a=g(a);
					b=g(b);
					c=g(c);
					d=g(d);
					e=g(e);
					f=g(f);
					j+=3;
				}
			}
			if(q==true) continue;
			if(k%2==0)
			{
				if(d==f&&d==b)
				{
					cout<<"Yes";
					return 0;
				}
			}
			if(k%2!=0)
			{
				if(a==c&&a==e)
				{
					cout<<"Yes";
					return 0;
				}
			}
		}
	}
	cout<<"No";
	return 0;
}