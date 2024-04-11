%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string s,ss;int l,ll,f[1001000];
int m,w[1001000],a[1001000],tot=0;
char bs[1001000];
int main()
{
	cin>>ll>>m;
	cin>>s;
	l=s.length();
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
		w[i]--;
	}
	sort(w+1,w+m+1);
	for (int i=1;i<=m;i++)
		a[w[i]]=1;
	f[0]=0;
	int p;
	for (int i=1;i<l;i++)
	{
		f[i]=0;
		p=i-1;
		while (p>=0)
		{
			if (s[i]==s[f[p]])
			{
				f[i]=f[p]+1;
				break;
			}
			else
				if (p==0)
					break;
				else
					p=f[p-1];	
		}
	}
	p=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=l-1;j>=0;j--)
		{
			if (bs[w[i]+j]>0) break;
			bs[w[i]+j]=s[j];
		}
	}
	for (int i=0;i<ll;i++)
	{
		if (bs[i]==0)
		{
			tot++;
			bs[i]=' ';
		}
		ss+=bs[i];
	}
	//cout<<tot<<endl<<ss<<endl;
	p=0;
	for (int i=0;i<ll;i)
	{
		if (ss[i]==s[p])
			{p++;i++;}
		else
			if (p>0)
				p=f[p-1];
			else
				i++;
		if (p==l)
		{
			a[i-l]=0;
			//printf(" %d\n",i);
		}
	}
	for (int i=0;i<ll;i++)
		if (a[i])
		{
			printf("0");
			return 0;
		}
	long long ans=1;
	for (int i=1;i<=tot;i++)
		ans=(ans*26)%1000000007;
	cout<<ans;
}