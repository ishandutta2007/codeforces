#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=20;
int t,s[M][N],A,l,r;
int main()
{
	for(int i=0;i<M;i++)
		for(int j=1;j<N;j++)
			s[i][j]=s[i][j-1]+(j>>i&1);
	cin>>t;
	while(t--&&cin>>l>>r)
	{
		A=0;
		for(int i=0;i<M;i++)
			A=max(A,s[i][r]-s[i][l-1]);
		cout<<r-l+1-A<<'\n';
	}
}