#include<bits/stdc++.h>
using namespace std;
const int N=101;
int t,n,a[N],A[N],v[N],c;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
		memset(v,0,sizeof(v)),c=0;
		for(int i=2*n;i>=1;i--)
			if(!v[a[i]])
				A[++c]=a[i],v[a[i]]=1;
		for(int i=c;i>=1;i--)
			cout<<A[i]<<' ';
		cout<<'\n';
	}
	return 0;
}