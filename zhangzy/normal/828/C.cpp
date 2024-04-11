#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#define xxx 2333520
#define ll long long
using namespace std;
string s[xxx],ans;
int n,a[xxx]={0},b[xxx]={0},l[xxx]={0},al=0,k,x;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		l[i]=s[i].length();
		scanf("%d",&k);
		for (int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			al=max(al,x+l[i]-1);
			if (l[i]>l[a[x]]) a[x]=i;
		}
	}
	int x,y;
	for (int i=1;i<=al;)
	{
		if (!a[i])
		{
			ans+='a';
			i++;
		}
		else
		{
			x=i;
			y=x+l[a[x]];
			while (x<y&&y>=x+l[a[x]])
			{
				ans+=s[a[i]][x-i];
				x++;
			}
			i=x;
		}
	}
	cout<<ans;
}