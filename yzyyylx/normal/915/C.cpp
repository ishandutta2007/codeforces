#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

string a,b,ans;
int num[20],n,n2[20];
bool use[20];

bool find(int u,int v)
{
	int i,now=1;
	for(; use[now]||now==v; now++);
	for(i=u+1; i<=n; i++)
	{
		if(num[now]<n2[i]) return 1;
		if(num[now]>n2[i]) return 0;
		for(now++; use[now]||now==v; now++);
	}
	return 1;
}

int main()
{
	int i,j;
	cin>>a>>b;
	for(i=0; i<a.size(); i++)
	{
		num[i+1]=a[i]-48;
	}
	sort(num+1,num+a.size()+1);
	if(b.size()>a.size())
	{
		for(i=a.size(); i>=1; i--)
		{
			cout<<num[i];
		}
		return 0;
	}
	if(a.size()>b.size())
	{
		for(i=1;i+a.size()-b.size()<=a.size();i++)
		{
			num[i]=num[i+a.size()-b.size()];
		}
		for(i=1;i<=a.size()-b.size();i++) ans=ans+'0';
	}
	n=b.size();
	for(i=0; i<b.size(); i++)
	{
		n2[i+1]=b[i]-48;
	}
	for(i=1; i<=n; i++)
	{
		for(j=n; j>=1; j--)
		{
			if(use[j]) continue;
			if(num[j]<=n2[i]) break;
		}
		if(num[j]==n2[i]&&find(i,j))
		{
			ans=ans+char(num[j]+48);
			use[j]=1;
			continue;
		}
		else if(num[j]==n2[i]) for(; num[j]==n2[i]||use[j]; --j);
		use[j]=1;
		cout<<ans<<num[j];
		for(j=n; j>=1; j--)
		{
			if(use[j]) continue;
			cout<<num[j];
		}
		return 0;
	}
	for(i=0; i<ans.size(); i++)
	{
		if(ans[i]!='0')
		{
			break;
		}
	}
	for(;i<ans.size();i++) cout<<ans[i];
}