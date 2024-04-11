#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1; 
int n,x[N],y[N],p,q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	while(true)
	{
		p=0;
		for(int i=1;i<=n;i++)
			if((x[i]+y[i])&1)
				p++;
		if(p>0&&p<n)
		{
			cout<<p<<'\n';
			for(int i=1;i<=n;i++)
				if((x[i]+y[i])&1)
					cout<<i<<' ';
			return 0;
		}
		if(p==n)
			for(int i=1;i<=n;i++)
				x[i]--;
		for(int i=1;i<=n;i++)
			p=(x[i]-y[i])/2,q=(x[i]+y[i])/2,x[i]=p,y[i]=q;
	}
}