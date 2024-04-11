#include<bits/stdc++.h>
#define N 100010
using namespace std;

char a[N],b[N];
int la,lb,p1[N],p2[N],zda,zdb;

void get1(int m)
{
	int i,j;
	j=-1;
	p1[0]=-1;
	for(i=1;i<=m;i++)
	{
		while(j>=0&&a[j+1]!=a[i])
		{
			j=p1[j];
		}
		j++;
		p1[i]=j;
	}
}

void get2(int m)
{
	int i,j;
	j=-1;
	p2[0]=-1;
	for(i=1;i<=m;i++)
	{
		while(j>=0&&b[j+1]!=b[i])
		{
			j=p2[j];
		}
		j++;
		p2[i]=j;
	}
}

int fj(int m)
{
	int i,an=0;
	for(i=1;i<=m;i++)
	{
		if(m%i==0)
		{
			an++;
		}
	}
	return an;
}

int main()
{
	int i,j,k,p=0,q,x,y;
	scanf("%s",a+1);
	la=strlen(a+1);
	get1(la);
	scanf("%s",b+1);
	lb=strlen(b+1);
	get2(lb);
	
	if(la%(la-p1[la])==0)
	{
		x=la/(la-p1[la]);
		la=la-p1[la];
	}
	else
	{
		x=1;
	}
	if(lb%(lb-p2[lb])==0)
	{
		y=lb/(lb-p2[lb]);
		lb=lb-p2[lb];
	}
	else
	{
		y=1;
	}
	q=__gcd(x,y);
	
	if(la!=lb)
	{
		cout<<0;
		return 0;
	}
	
	for(i=1;i<=la;i++)
	{
		if(a[i]!=b[i])
		{
			cout<<0;
			return 0;
		}
	}
	cout<<fj(q);
}