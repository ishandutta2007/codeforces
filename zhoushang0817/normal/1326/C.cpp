#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,D=998244353;
long long n,m,p[N],A=1;
vector<int>a;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		if(p[i]>=n-m+1)
			a.push_back(i);
	for(int i=1;i<a.size();i++)
		(A*=a[i]-a[i-1])%=D;
	cout<<(2*n-m+1)*m/2<<' '<<A;
	return 0;
}