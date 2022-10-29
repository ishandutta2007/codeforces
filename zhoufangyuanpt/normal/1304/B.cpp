#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string s[110],st;
int p[110];
int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	int pp=0,ss=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)
		{
			st=s[i];
			reverse(s[i].begin(),s[i].end());
			for(int j=i+1;j<=n;j++)
			{
				if(p[j]>0)continue;
				if(s[i]==s[j])
				{
					ss+=2;
					p[i]=j;p[j]=i;break;
				}
			}
			if(pp==0&&p[i]==0&&st==s[i])ss++,pp=p[i]=i;
			reverse(s[i].begin(),s[i].end());
		}
	}
	cout<<ss*m<<endl;
	for(int i=1;i<=n;i++)
	{
		if(p[i]>0&&i<p[i])cout<<s[i];
	}
	if(pp>0)cout<<s[pp];
	for(int i=n;i>=1;i--)
	{
		if(p[i]>0&&i<p[i])cout<<s[p[i]];
	}
	cout<<endl;
	return 0;
}