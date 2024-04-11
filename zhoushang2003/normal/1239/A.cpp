#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1,D=1e9+7;
long long n,m,f[N][3];
int main()
{
	cin>>n>>m;
	f[1][0]=2;
	for(int i=2;i<=max(n,m);i++)
		(f[i][0]=f[i-1][0]+f[i-1][1])%=D,f[i][1]=f[i-1][0];
	cout<<(f[n][0]+f[n][1]+f[m][0]+f[m][1]-2+D)%D;
	return 0;
}