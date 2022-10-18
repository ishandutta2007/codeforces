#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,A[N],v[N],c,x,y;
pair<int,int>a[N],b[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i].first,a[i].second=i,A[i]=v[i]=0;
		for(int i=1;i<=n;i++)
			cin>>b[i].first,b[i].second=i;
		sort(a+1,a+n+1),sort(b+1,b+n+1),c=0;
		for(int i=n;i;i--)
		{
			x=a[i].second,y=b[i].second,c+=!v[x],v[x]=1,c+=!v[y],v[y]=A[x]=1;
			if(c==n-i+1)
				break;
		}
		for(int i=1;i<=n;i++)
			cout<<A[i];
		cout<<'\n';
	}
}