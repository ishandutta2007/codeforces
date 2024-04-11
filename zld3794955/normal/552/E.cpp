#include<bits/stdc++.h>
using namespace std;
const int N=5050,M=40;
char ch[N]={};
int n,m,a[M]={};
long long calc(int l,int r)
{
	//cout<<"l="<<l<<" r="<<r<<endl;
	long long tmp=1,sum=0,ans=0;
	for(int i=l;i<=r;++i)
	{
		if(isdigit(ch[i]))
			tmp*=ch[i]-'0';
		if(ch[i]=='+')
			sum+=tmp,tmp=1;
	}
	sum+=tmp,tmp=1;
	//cout<<"sum="<<sum<<endl;
	for(int i=1;i<=n;++i)
	{
		if(i==l)
			tmp*=sum,i=r;
		else
		{
			if(isdigit(ch[i]))
				tmp*=ch[i]-'0';
			if(ch[i]=='+')
				ans+=tmp,tmp=1;
		}
		//cout<<"ans="<<ans<<" tmp="<<tmp<<endl;
	}
	ans+=tmp,tmp=1;
	return ans;
}
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	a[++m]=1;
	for(int i=1;i<=n;++i)
		if(ch[i]=='*')
			a[++m]=i-1,a[++m]=i+1;
	a[++m]=n;
	long long ans=0;
	for(int i=1;i<=m;++i)
		for(int j=i;j<=m;++j)
			ans=max(ans,calc(a[i],a[j]));
	cout<<ans<<endl;
	return 0;
}