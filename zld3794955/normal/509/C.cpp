#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n,a[N][N]={},l[N]={};
bool tryy(int t,int d,int s)
{
	if(d==0)
	{
		for(int i=l[t];i>=1;--i)
		{
			if(a[t][i]<a[t-1][i])
				return false;
			if(a[t][i]>a[t-1][i])
				return true;
		}
		return false;
	}
	a[t][d]=max(a[t-1][d],s-9*(d-1));
	if(a[t][d]>s)
		return false;
	if(a[t][d]==a[t-1][d])
	{
		if(tryy(t,d-1,s-a[t][d]))
			return true;
		else
			++a[t][d];
	}
	if(a[t][d]>min(s,9))
		return false;
	s-=a[t][d];
	for(int i=1;i<d;++i)
	{
		a[t][i]=min(s,9);
		s-=min(s,9);
	}
	return true;
}
int main()
{	
	cin>>n;
	for(int i=1,s=0;i<=n;++i)
	{
		cin>>s;
		l[i]=max(l[i-1],(s+8)/9)+10;
		tryy(i,l[i],s);
		while(a[i][l[i]]==0)
			--l[i];
		for(int j=1;j<=l[i];++j)
			s-=a[i][j];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=l[i];j>=1;--j)
			cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}