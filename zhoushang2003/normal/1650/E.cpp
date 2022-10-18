#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,d,a[N],b[N],x,y,A,p,q,l;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>d)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],b[i]=a[i]-a[i-1]-1;
		x=min_element(b+1,b+n+1)-b,A=0;
		for(int i=max(1,x-1);i<=x;i++)
		{
			p=d,q=l=0;
			for(int j=1;j<=n;j++)
				if(j!=i)
					y=a[j]-l-1,p=min(p,y),q=max(q,y),l=a[j];
			A=max(A,min(p,max((q-1)/2,d-l-1)));
		}
		cout<<A<<'\n';
	}
}