#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,f[N][N];
string s;
int main()
{
	cin>>n>>s;
	for(int i=1;i<n;i++)
		for(int j=0;j+i<n;j++)
		{
			f[j][j+i]=f[j+1][j+i]+1;
			for(int k=j;k<=j+i;k++)
				if(s[k]==s[j])
					f[j][j+i]=min(f[j][j+i],f[j][k-1]+f[k][j+i]);
		}
	cout<<f[0][n-1]+1;
	return 0;
}