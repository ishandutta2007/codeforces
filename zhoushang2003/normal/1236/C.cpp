#include<bits/stdc++.h>
using namespace std;
const int N=301;
int n,A[N][N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		if(i&1)
			for(int j=1;j<=n;j++)
				A[j][i]=(i-1)*n+j;
		else
			for(int j=1;j<=n;j++)
				A[n-j+1][i]=(i-1)*n+j;
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=n;j++)
			cout<<A[i][j]<<" ";
	return 0;
}