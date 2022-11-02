#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=1000000007;
int n,b[N]={};
long long f[N][N]={};
bool v[N][N]={};
long long calc(int l,int r)
{
	if(l>r)
		return 1;
	if(v[l][r])
		return f[l][r];
	v[l][r]=true;
	int tmp=b[r+1];
	b[r+1]=N;
	for(int i=l;i<=r;++i)
		if(b[l]<b[i+1])
			(f[l][r]+=calc(l+1,i)*calc(i+1,r))%=mod;
	b[r+1]=tmp; 
	return f[l][r];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>b[i];
	cout<<calc(2,n)<<endl;
	return 0;
}