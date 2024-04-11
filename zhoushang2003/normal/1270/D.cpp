#include<bits/stdc++.h>
using namespace std;
const int N=501;
bool v[N];
int n,k,x,y,A,B,a,b,c;
int main()
{
	cin>>n>>k;
	if(k==1)
	{
		cout<<'!'<<' '<<1;
		return 0;
	}
	for(int i=1;i<=n-k+1;i++)
	{
		cout<<'?'<<' ';
		for(int j=1;j<=n;j++)
			if(!v[j]&&c<k)
			{
				cout<<j<<" ";
				c++;
			}
		c=0;
		cout<<'\n';
		fflush(stdout);
		cin>>x>>y;
		v[x]=true;
		A=B,a=b,B=x,b=y;
	}
	if(a>b)
		swap(a,b),swap(A,B);
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			v[i]=true;
			cout<<'?'<<' '<<A<<' '<<B<<' ';
			for(int j=1;j<=n;j++)
				if(!v[j])
					cout<<j<<" ";
			cout<<'\n';
			fflush(stdout);
			cin>>x>>y;
			if(y==b)
				c++;
			v[i]=false;
		}
	cout<<'!'<<' '<<c+1;
	return 0;
}