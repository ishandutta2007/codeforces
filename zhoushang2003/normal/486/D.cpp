#include<bits/stdc++.h>
using namespace std;
const int N=2e3+1,D=1e9+7;
bool v[N];
long long d,n,m,x,y,w[N],f[N],A;
vector<int>a[N];
void S(int k)
{
	v[k]=true,f[k]=1;
	for(int i=0;i<a[k].size();i++)
		if(!v[a[k][i]]&&w[x]<=w[a[k][i]]&&w[a[k][i]]<=w[x]+d&&(w[a[k][i]]!=w[x]||a[k][i]<x))
			S(a[k][i]),(f[k]*=f[a[k][i]]+1)%=D;
}
int main()
{
	cin>>d>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	m=n-1;
	while(m--&&cin>>x>>y)
		a[x].push_back(y),a[y].push_back(x);
	for(int i=1;i<=n;i++)
		memset(f,0,sizeof(f)),memset(v,false,sizeof(v)),x=i,S(i),(A+=f[i])%=D;
	cout<<A;
	return 0;
}