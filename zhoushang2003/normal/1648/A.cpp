#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int n,m,x,s,A;
vector<int>a[N],b[N];
void S(vector<int>&v)
{
	sort(v.begin(),v.end()),s=0;
	for(int i=0;i<v.size();i++)
		A+=i*v[i]-s,s+=v[i];
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>x,a[x].push_back(i),b[x].push_back(j);
	for(int i=1;i<N;i++)
		S(a[i]),S(b[i]);
	cout<<A;
}