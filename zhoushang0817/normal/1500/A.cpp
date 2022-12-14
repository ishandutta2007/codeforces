#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1,M=2500001;
int n,a[N],q[N],t,A[2*M],B[2*M];
vector<int>c[M],v;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],c[a[i]].push_back(i);
	for(int i=1;i<M;i++)
		if(c[i].size()>3)
		{
			cout<<"YES"<<'\n'<<c[i][0]<<' '<<c[i][1]<<' '<<c[i][2]<<' '<<c[i][3];
			return 0;
		}
		else if(c[i].size()>1)
			q[++t]=i,A[2*i]=c[i][0],B[2*i]=c[i][1];
	if(t>1)
	{
		cout<<"YES"<<'\n'<<c[q[1]][0]<<' '<<c[q[2]][0]<<' '<<c[q[1]][1]<<' '<<c[q[2]][1];
		return 0;
	}
	for(int i=1;i<M;i++)
		if(c[i].size())
			v.push_back(c[i][0]);
	for(int i=0;i<v.size();i++)
		for(int j=i+1;j<v.size();j++)
		{
			t=a[v[i]]+a[v[j]];
			if(A[t])
			{
				cout<<"YES"<<'\n'<<A[t]<<' '<<B[t]<<' '<<v[i]<<' '<<v[j];
				return 0;
			}
			A[t]=v[i],B[t]=v[j];
		}
	cout<<"NO";
	return 0;
}