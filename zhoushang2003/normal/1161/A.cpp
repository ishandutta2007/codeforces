#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool v[N];
int n,k,a[N],f[N][3],A;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	for(int i=k;i>=1;i--)
		v[a[i]]=true,f[a[i]][0]=v[a[i]-1],f[a[i]][1]=v[a[i]],f[a[i]][2]=v[a[i]+1];
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			if(1<=i+j-1&&i+j-1<=n&&!f[i][j])
				A++;
	cout<<A;
	return 0;
}