#include<bits/stdc++.h>
#define N 100010
using namespace std;

char a[N],b[N],c[N],d[N];
int ans=0,la,lb,lc,p1[N],p2[N],last,z=1;

void get1(int len)
{
	int i,j;
	p1[0]=-1;
	j=-1;
	for(i=1;i<=len;i++)
	{
		while(j>=0&&a[i]!=a[j+1])
		{
			j=p1[j];
		}
		j++;
		p1[i]=j;
	}
}

void get2(int len)
{
	int i,j;
	p2[0]=-1;
	j=-1;
	for(i=1;i<=len;i++)
	{
		while(j>=0&&b[i]!=b[j+1])
		{
			j=p2[j];
		}
		j++;
		p2[i]=j;
	}
}

int find1(int l1,int l2)
{
	int j=0,i;
	for(i=1;i<=l1;i++)
	{
		while(j>=0&&c[i]!=a[j+1])
		{
			j=p1[j];
		}
		j++;
		if(j==l2)
		{
			return i;
		}
	}
	return -1;
}

void find2(int l1,int l2)
{
	int j=0,i;
	for(i=last+1;i<=l1;i++)
	{
		while(j>=0&&c[i]!=b[j+1])
		{
			j=p2[j];
		}
		j++;
		if(j==l2)
		{
			ans+=z;
			return;
		}
	}
	return;
}

int main()
{
	int i,j,k;
	scanf("%s",c+1);
	lc=strlen(c+1);
	scanf("%s",a+1);
	la=strlen(a+1);
	scanf("%s",b+1);
	lb=strlen(b+1);
	
	get1(la);
	get2(lb);
	
	last=find1(lc,la);
	if(last!=-1)
	{
		find2(lc,lb);
	}
	z++;
	
	for(i=1;i<=lc;i++)
	{
		d[i]=c[i];
	}
	for(i=1;i<=lc;i++)
	{
		c[i]=d[lc-i+1];
	}
	
	last=find1(lc,la);
	if(last!=-1)
	{
		find2(lc,lb);
	}
	
	if(ans==0)
	{
		cout<<"fantasy";
	}
	if(ans==1)
	{
		cout<<"forward";
	}
	if(ans==2)
	{
		cout<<"backward";
	}
	if(ans==3)
	{
		cout<<"both";
	}
}