#include<bits/stdc++.h>
using namespace std;
const int N=4040;
int n,ans=0,w[N]={},next[N]={},last[N]={};
long long v[N]={},d[N]={},p[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>v[i]>>d[i]>>p[i];
	for(int i=1;i<=n;++i)
		next[i]=i+1,last[i]=i-1;
	next[0]=1;
	for(int i=1;i<=n;i=next[i])
	{
		w[++ans]=i;
		for(int j=next[i],t=v[i]; j<=n && t; j=next[j],--t)
			p[j]-=t;
		long long s=0;
		for(int j=next[i];j<=n;j=next[j])
		{
			p[j]-=s;
			if(p[j]<0ll)
			{
				next[last[j]]=next[j];
				last[next[j]]=last[j];
				s+=d[j];
			}
		}	
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;++i)
		cout<<w[i]<<' ';
	cout<<endl;
	return 0;
}