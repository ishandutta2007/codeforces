#include<bits/stdc++.h>
using namespace std;
const int N=101;
int t,n,A[N],B[N],x,y,M;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		M=0;
		for(int i=0;i<9;i++)
		{
			x=y=0;
			for(int j=1;j<=n;j++)
				if(j>>i&1)
					A[++x]=j;
				else
					B[++y]=j;
			if(x>=1&&y>=1)
			{
				cout<<x<<" "<<y<<" ";
				for(int j=1;j<=x;j++)
					cout<<A[j]<<" ";
				for(int j=1;j<=y;j++)
					cout<<B[j]<<" ";
				cout<<'\n';
				fflush(stdout);
				cin>>x;
				M=max(M,x);
			}
		}
		cout<<-1<<" "<<M<<'\n';
		fflush(stdout);
	}
	return 0;
}