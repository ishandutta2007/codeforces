#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4,D=998244353;
int t,p[N],n;
signed main()
{
	cin>>t,p[0]=1;
	for(int i=1;i<N;i++)
		p[i]=p[i-1]*i%D;
	while(t--&&cin>>n)
		cout<<(n&1?0:p[n/2]*p[n/2]%D)<<'\n';
}